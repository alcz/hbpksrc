/*
 * hbpk-hmake.prg - Clone de la commande make (port Harbour 3.2 du source Pascal de Sylvain Maltais)
 *
 * Original : @author Sylvain Maltais (support@gladir.com) - https://www.gladir.com/linux-0
 * License is MIT
 *
 * Conventions du portage :
 *   - Les enregistrements Pascal (TVar, TRule, TBuilt) deviennent des tables de hachage.
 *   - Les tableaux fixes deviennent des tableaux dynamiques (plus de limites MaxVars, MaxRules...).
 *   - Les String[n]/255 caracteres deviennent des chaines Harbour (plus de troncature a 255).
 *   - Toutes les comparaisons de chaines utilisent == (SET EXACT ON est aussi active).
 *   - Les parametres "Var" Pascal deviennent des parametres passes par reference (@).
 *
 * Note : Harbour n'accepte pas "AS type" apres la liste de parametres d'une FUNCTION ;
 *        le type de retour est donc indique en commentaire : FUNCTION f( x AS NUMERIC ) /* AS LOGICAL */
 *
 * Compilation :  hbmk2 hbpk-hmake.prg -o hmake
 */

#include "fileio.ch"
#include "set.ch"

REQUEST HB_GT_STD_DEFAULT   /* sortie standard sans sequences d'ecran */

#define ORG_DEFAULT   1
#define ORG_ENV       2
#define ORG_FILE      3
#define ORG_ENVOVER   4
#define ORG_OVERRIDE  5
#define ORG_CMD       7
#define MAX_IF        24
#define TAB           Chr( 9 )

/* ----- Base de donnees ----- */
STATIC s_aVars     := {}
STATIC s_hVarIdx   := { => }
STATIC s_aRules    := {}
STATIC s_aCmds     := {}
STATIC s_aBuilt    := {}
STATIC s_aPhony    := {}
STATIC s_aSuffixes := {}
STATIC s_aIfActive := {}
STATIC s_aIfDone   := {}
STATIC s_nIfTop    := 1
STATIC s_aMakeFiles := {}
STATIC s_aIncDirs   := {}
STATIC s_aGoals     := {}
STATIC s_aAssumeOld := {}
STATIC s_aAssumeNew := {}
STATIC s_aCmdVars   := {}
STATIC s_aCurRules  := {}
STATIC s_aRecCmds   := {}
STATIC s_cDefaultGoal := ""
STATIC s_hExport := { => }      /* variables exportees vers les commandes (hb_SetEnv) */
STATIC s_lExportAll := .F.

/* ----- Etat de l'expansion ----- */
STATIC s_cAutoTarget := ""
STATIC s_cAutoFirst  := ""
STATIC s_cAutoAll    := ""
STATIC s_cAutoPlus   := ""
STATIC s_cAutoNewer  := ""
STATIC s_cAutoStem   := ""

/* ----- Options et etat global ----- */
STATIC s_lAlways := .F., s_lDry := .F., s_lSilent := .F., s_lKeep := .F., s_lIgnore := .F.
STATIC s_lTouch := .F., s_lQuestion := .F., s_lEnvOver := .F., s_lNoRules := .F.
STATIC s_lNoVars := .F., s_lPrintDb := .F., s_lPrintDir := .F., s_lDebug := .F.
STATIC s_lWarnUndef := .F., s_lNoPrintDir := .F.
STATIC s_lSilentAll := .F., s_lIgnoreAll := .F.
STATIC s_lErrors := .F., s_lDidRun := .F., s_lAnyRebuild := .F.
STATIC s_lDirChanged := .F., s_lWantVersion := .F., s_lWantHelp := .F.
STATIC s_nLineNo := 0
STATIC s_cCurFile := ""
STATIC s_cProgName := ""

/* ====================================================================== */

PROCEDURE Main()

   LOCAL nI AS NUMERIC
   LOCAL nK AS NUMERIC
   LOCAL cCwd AS STRING
   LOCAL cL AS STRING
   LOCAL lFound AS LOGICAL
   LOCAL cName AS STRING
   LOCAL cVal AS STRING
   LOCAL nRi AS NUMERIC
   LOCAL nB AS NUMERIC

   Set( _SET_EXACT, .T. )

   s_cProgName := hb_ProgName()
   s_aIfActive := Array( MAX_IF + 2 )
   s_aIfDone   := Array( MAX_IF + 2 )
   AFill( s_aIfActive, .F. )
   AFill( s_aIfDone, .F. )
   s_aIfActive[ 1 ] := .T.
   s_nIfTop := 1

   ParseArgs( hb_AParams() )

   IF s_lWantHelp
      ShowHelp()
      MkHalt( 0 )
   ENDIF
   IF s_lWantVersion
      PutOut( "GNU Make 4.4 (clone)" )
      PutOut( "Ce programme est un clone ecrit en Harbour (port du source Pascal)." )
      MkHalt( 0 )
   ENDIF

   InitBuiltins()

   FOR nI := 1 TO Len( s_aCmdVars )
      cL := s_aCmdVars[ nI ]
      nK := At( "=", cL )
      IF nK > 1 .AND. SubStr( cL, nK - 1, 1 ) == ":"
         cName := MkTrim( Left( cL, nK - 2 ) )
         cVal  := Expand( SubStr( cL, nK + 1 ), 0 )
         SetVar( cName, cVal, .T., ORG_CMD )
      ELSE
         SetVar( MkTrim( Left( cL, nK - 1 ) ), SubStr( cL, nK + 1 ), .F., ORG_CMD )
      ENDIF
      s_hExport[ MkTrim( Left( cL, nK - 1 - iif( nK > 1 .AND. SubStr( cL, nK - 1, 1 ) == ":", 1, 0 ) ) ) ] := .T.
   NEXT

   cCwd := hb_DirSepDel( hb_cwd() )
   IF ( s_lDirChanged .OR. s_lPrintDir ) .AND. ! s_lNoPrintDir
      PutOut( "make: Entering directory '" + cCwd + "'" )
      s_lPrintDir := .T.
   ENDIF

   /* lecture des makefiles */
   lFound := .F.
   IF Len( s_aMakeFiles ) == 0
      IF FileTime( "GNUmakefile" ) > 0
         s_aMakeFiles := { "GNUmakefile" }
      ELSEIF FileTime( "makefile" ) > 0
         s_aMakeFiles := { "makefile" }
      ELSEIF FileTime( "Makefile" ) > 0
         s_aMakeFiles := { "Makefile" }
      ENDIF
   ENDIF
   FOR nI := 1 TO Len( s_aMakeFiles )
      ParseFile( s_aMakeFiles[ nI ], 0, .F. )
      lFound := .T.
   NEXT
   IF ! lFound .AND. Len( s_aGoals ) == 0
      Die( "No targets specified and no makefile found.  Stop." )
   ENDIF
   IF Len( s_aGoals ) == 0
      IF s_cDefaultGoal == ""
         Die( "No targets.  Stop." )
      ENDIF
      s_aGoals := { s_cDefaultGoal }
   ENDIF

   /* MAKECMDGOALS */
   cL := ""
   FOR nI := 1 TO Len( s_aGoals )
      cL += " " + s_aGoals[ nI ]
   NEXT
   SetVar( "MAKECMDGOALS", MkTrim( cL ), .T., ORG_DEFAULT )

   IF s_lPrintDb
      PrintDb()
   ENDIF

   s_lAnyRebuild := .F.
   FOR nI := 1 TO Len( s_aGoals )
      s_lDidRun := .F.
      IF UpdateTarget( s_aGoals[ nI ], "", 0 )
         nB := FindBuilt( s_aGoals[ nI ] )
         IF nB > 0 .AND. ! s_aBuilt[ nB ][ "updated" ] .AND. ! s_lQuestion
            nRi := FindExplicit( s_aGoals[ nI ] )
            IF nRi > 0
               IF s_aRules[ nRi ][ "ccnt" ] > 0
                  Warn( "'" + s_aGoals[ nI ] + "' is up to date." )
               ELSE
                  Warn( "Nothing to be done for '" + s_aGoals[ nI ] + "'." )
               ENDIF
            ELSE
               Warn( "'" + s_aGoals[ nI ] + "' is up to date." )
            ENDIF
         ENDIF
      ENDIF
   NEXT

   IF s_lPrintDir
      PutOut( "make: Leaving directory '" + cCwd + "'" )
   ENDIF
   IF s_lErrors
      MkHalt( 2 )
   ENDIF
   IF s_lQuestion .AND. s_lAnyRebuild
      MkHalt( 1 )
   ENDIF

   RETURN

/* ------------------------- Aide / sorties ------------------------- */

STATIC PROCEDURE ShowUsage()

   PutOut( "Usage: make [ -f makefile ] [ option ] ... target ..." )

   RETURN

STATIC PROCEDURE ShowHelp()

   PutOut( "MAKE : Cette commande permet de lancer le moteur de production, lequel effectue des" )
   PutOut( "commandes permettant la creation des fichiers." )
   PutOut( "" )
   ShowUsage()
   PutOut( "" )
   PutOut( "  -b, -m                       Ignorees (compatibilite)" )
   PutOut( "  -B, --always-make            Reconstruit toutes les cibles" )
   PutOut( "  -C dir, --directory=dir      Change de repertoire avant de lire les makefiles" )
   PutOut( "  -d, --debug[=FLAGS]          Informations de debogage" )
   PutOut( "  -e, --environment-overrides  Les variables d'environnement ont priorite" )
   PutOut( "  -f file, --file=file         Makefile a utiliser (repetable)" )
   PutOut( "  -i, --ignore-errors          Ignore les erreurs des commandes" )
   PutOut( "  -I dir, --include-dir=dir    Repertoire de recherche pour include" )
   PutOut( "  -j [n], -l [n]               Acceptes (execution toujours sequentielle)" )
   PutOut( "  -k, --keep-going             Continue malgre les erreurs" )
   PutOut( "  -L, --check-symlink-times    Accepte, sans effet" )
   PutOut( "  -n, --dry-run, --just-print, --recon  Affiche les commandes sans les executer" )
   PutOut( "  --no-builtin-rules, -r       Retire les regles implicites predefinies" )
   PutOut( "  --no-builtin-variables, -R   Retire les variables predefinies" )
   PutOut( "  -o file, --old-file=file, --assume-old=file  Considere le fichier comme ancien" )
   PutOut( "  -p, --print-data-base        Affiche la base de donnees (regles et variables)" )
   PutOut( "  -q, --question               Mode question (code de retour 1 si a refaire)" )
   PutOut( "  -s, --silent, --quiet        Mode silencieux" )
   PutOut( "  -S, --no-keep-going, --stop  Arrete a la premiere erreur" )
   PutOut( "  -t, --touch                  Met a jour les dates au lieu d'executer" )
   PutOut( "  -v, --version                Affiche la version" )
   PutOut( "  -w, --print-directory        Affiche le repertoire courant" )
   PutOut( "  -W file, --what-if=file, --new-file=file, --assume-new=file" )
   PutOut( "                               Considere le fichier comme modifie" )
   PutOut( "  --warn-undefined-variables   Avertit des variables non definies" )
   PutOut( "  VAR=valeur                   Definit une variable (priorite maximale)" )
   PutOut( "  --help, /?                   Affiche cette aide" )

   RETURN

STATIC PROCEDURE PutOut( cS AS STRING )

   OutStd( cS + hb_eol() )

   RETURN

STATIC PROCEDURE PutErr( cS AS STRING )

   OutErr( cS + hb_eol() )

   RETURN

STATIC PROCEDURE MkHalt( nCode AS NUMERIC )

   ErrorLevel( nCode )
   QUIT

   RETURN

STATIC PROCEDURE Die( cS AS STRING )

   PutErr( "make: *** " + cS )
   MkHalt( 2 )

   RETURN

STATIC PROCEDURE Warn( cS AS STRING )

   PutErr( "make: " + cS )

   RETURN

/* ------------------------- Utilitaires de chaines ------------------------- */

STATIC FUNCTION IntStr( n AS NUMERIC ) /* AS STRING */
   RETURN hb_NToS( n )

STATIC FUNCTION InSet( cCh AS STRING, cSet AS STRING ) /* AS LOGICAL */
   RETURN Len( cCh ) == 1 .AND. cCh $ cSet

/* Equivalent du Trim Pascal : espaces, tabulations, CR */
STATIC FUNCTION MkTrim( cS AS STRING ) /* AS STRING */

   LOCAL nA AS NUMERIC
   LOCAL nB AS NUMERIC

   nA := 1
   nB := Len( cS )
   DO WHILE nA <= nB .AND. InSet( SubStr( cS, nA, 1 ), " " + TAB + Chr( 13 ) )
      nA++
   ENDDO
   DO WHILE nB >= nA .AND. InSet( SubStr( cS, nB, 1 ), " " + TAB + Chr( 13 ) )
      nB--
   ENDDO

   RETURN SubStr( cS, nA, nB - nA + 1 )

STATIC FUNCTION IsBlankCh( cC AS STRING ) /* AS LOGICAL */
   RETURN cC == " " .OR. cC == TAB

/* Mots separes par des blancs */
STATIC FUNCTION NextWord( cS AS STRING, nP AS NUMERIC, cW AS STRING ) /* AS LOGICAL */

   LOCAL nJ AS NUMERIC

   DO WHILE nP <= Len( cS ) .AND. IsBlankCh( SubStr( cS, nP, 1 ) )
      nP++
   ENDDO
   IF nP > Len( cS )
      RETURN .F.
   ENDIF
   nJ := nP
   DO WHILE nJ <= Len( cS ) .AND. ! IsBlankCh( SubStr( cS, nJ, 1 ) )
      nJ++
   ENDDO
   cW := SubStr( cS, nP, nJ - nP )
   nP := nJ

   RETURN .T.

STATIC FUNCTION WordCount( cS AS STRING ) /* AS NUMERIC */

   LOCAL nP AS NUMERIC
   LOCAL nN AS NUMERIC
   LOCAL cW AS STRING

   nP := 1
   nN := 0
   DO WHILE NextWord( cS, @nP, @cW )
      nN++
   ENDDO

   RETURN nN

STATIC FUNCTION WordN( cS AS STRING, nN AS NUMERIC ) /* AS STRING */

   LOCAL nP AS NUMERIC
   LOCAL nK AS NUMERIC
   LOCAL cW AS STRING

   nP := 1
   nK := 0
   DO WHILE NextWord( cS, @nP, @cW )
      nK++
      IF nK == nN
         RETURN cW
      ENDIF
   ENDDO

   RETURN ""

STATIC FUNCTION JoinWords( aW AS ARRAY ) /* AS STRING */

   LOCAL cR AS STRING
   LOCAL cW AS STRING

   cR := ""
   FOR EACH cW IN aW
      IF ! cR == ""
         cR += " "
      ENDIF
      cR += cW
   NEXT

   RETURN cR

STATIC FUNCTION IsInt( cS AS STRING ) /* AS LOGICAL */

   LOCAL nI AS NUMERIC
   LOCAL cT AS STRING

   cT := MkTrim( cS )
   IF cT == ""
      RETURN .F.
   ENDIF
   FOR nI := 1 TO Len( cT )
      IF ! InSet( SubStr( cT, nI, 1 ), "0123456789" )
         RETURN .F.
      ENDIF
   NEXT

   RETURN .T.

/* ------------------------- Temps et fichiers ------------------------- */

STATIC FUNCTION NowPacked() /* AS NUMERIC */
   RETURN hb_TToN( hb_DateTime() )

STATIC FUNCTION FileTime( cN AS STRING ) /* AS NUMERIC */

   LOCAL tDT

   IF cN == ""
      RETURN 0
   ENDIF
   IF hb_FGetDateTime( cN, @tDT )
      RETURN Max( hb_TToN( tDT ), 0.000001 )
   ENDIF

   RETURN 0

STATIC FUNCTION TmpName() /* AS STRING */

   LOCAL hF
   LOCAL cN AS STRING

   cN := ""
   hF := hb_FTempCreateEx( @cN, NIL, "make", ".tmp" )
   IF hF != F_ERROR
      FClose( hF )
   ENDIF

   RETURN cN

STATIC PROCEDURE TouchFile( cN AS STRING )

   LOCAL hF

   IF FileTime( cN ) > 0
      hb_FSetDateTime( cN, hb_DateTime() )
   ELSE
      hF := FCreate( cN )
      IF hF != F_ERROR
         FClose( hF )
      ENDIF
   ENDIF

   RETURN

STATIC FUNCTION MkFExpand( cW AS STRING ) /* AS STRING */

   LOCAL cS AS STRING

   cS := hb_DirSepDel( hb_cwd() )
   IF InSet( Left( cW, 1 ), "/\" ) .OR. SubStr( cW, 2, 1 ) == ":"
      RETURN cW
   ENDIF

   RETURN cS + hb_ps() + cW

/* ------------------------- Execution de commandes ------------------------- */

STATIC FUNCTION RunCmd( cCmd AS STRING ) /* AS NUMERIC */

   LOCAL nRet AS NUMERIC

   nRet := hb_run( cCmd )
   IF nRet < 0
      nRet := 127
   ELSEIF hb_ps() == "/" .AND. nRet >= 256
      nRet := Int( nRet / 256 )      /* hb_run() rend le statut brut de wait() sous Unix */
   ENDIF

   RETURN nRet

STATIC FUNCTION ShellOutput( cCmd AS STRING ) /* AS STRING */

   LOCAL cTmp AS STRING
   LOCAL cData AS STRING
   LOCAL cL AS STRING
   LOCAL cR AS STRING

   cTmp := TmpName()
   RunCmd( cCmd + ' > "' + cTmp + '"' )
   cR := ""
   cData := hb_MemoRead( cTmp )
   FErase( cTmp )
   FOR EACH cL IN hb_ATokens( StrTran( cData, Chr( 13 ), "" ), Chr( 10 ) )
      IF ! cR == ""
         cR += " "
      ENDIF
      cR += MkTrim( cL )
   NEXT

   RETURN MkTrim( cR )

/* ------------------------- Variables ------------------------- */

STATIC FUNCTION FindVar( cN AS STRING ) /* AS NUMERIC */
   RETURN hb_HGetDef( s_hVarIdx, cN, 0 )

STATIC PROCEDURE SetVar( cN AS STRING, cV AS STRING, lSimple AS LOGICAL, nOrg AS NUMERIC )

   LOCAL nI AS NUMERIC

   nI := FindVar( cN )
   IF nI == 0
      AAdd( s_aVars, { "name" => cN, "val" => "", "simple" => .F., "org" => 0 } )
      nI := Len( s_aVars )
      s_hVarIdx[ cN ] := nI
   ENDIF
   IF nOrg < s_aVars[ nI ][ "org" ]
      RETURN
   ENDIF
   s_aVars[ nI ][ "val" ]    := cV
   s_aVars[ nI ][ "simple" ] := lSimple
   s_aVars[ nI ][ "org" ]    := nOrg

   RETURN

STATIC FUNCTION IsPhony( cN AS STRING ) /* AS LOGICAL */

   LOCAL cP AS STRING

   FOR EACH cP IN s_aPhony
      IF cP == cN
         RETURN .T.
      ENDIF
   NEXT

   RETURN .F.

STATIC FUNCTION OriginName( nOrg AS NUMERIC, cFileName AS STRING ) /* AS STRING */

   SWITCH nOrg
   CASE ORG_DEFAULT
      RETURN "default"
   CASE ORG_ENV
   CASE ORG_ENVOVER
      RETURN "environment"
   CASE ORG_FILE
      RETURN cFileName
   CASE ORG_OVERRIDE
      RETURN "override"
   ENDSWITCH

   RETURN "command line"

/* ------------------------- Motifs (%) ------------------------- */

STATIC FUNCTION PatMatch( cPat AS STRING, cW AS STRING, cStem AS STRING ) /* AS LOGICAL */

   LOCAL nP AS NUMERIC
   LOCAL cPre AS STRING
   LOCAL cSuf AS STRING

   cStem := ""
   nP := At( "%", cPat )
   IF nP == 0
      RETURN cPat == cW
   ENDIF
   cPre := Left( cPat, nP - 1 )
   cSuf := SubStr( cPat, nP + 1 )
   IF Len( cW ) < Len( cPre ) + Len( cSuf )
      RETURN .F.
   ENDIF
   IF ! Left( cW, Len( cPre ) ) == cPre
      RETURN .F.
   ENDIF
   IF ! Right( cW, Len( cSuf ) ) == cSuf
      RETURN .F.
   ENDIF
   cStem := SubStr( cW, Len( cPre ) + 1, Len( cW ) - Len( cPre ) - Len( cSuf ) )

   RETURN .T.

STATIC FUNCTION ReplaceStem( cRepl AS STRING, cStem AS STRING ) /* AS STRING */

   LOCAL nP AS NUMERIC

   nP := At( "%", cRepl )
   IF nP == 0
      RETURN cRepl
   ENDIF

   RETURN Left( cRepl, nP - 1 ) + cStem + SubStr( cRepl, nP + 1 )

STATIC FUNCTION ReplaceAll( cS AS STRING, cOld AS STRING, cNew AS STRING ) /* AS STRING */

   IF cOld == ""
      RETURN cS
   ENDIF

   RETURN StrTran( cS, cOld, cNew )

/* Separe des arguments aux virgules de premier niveau */
STATIC FUNCTION SplitArgs( cA AS STRING, nMax AS NUMERIC, nN AS NUMERIC ) /* AS ARRAY */

   LOCAL aArgs AS ARRAY
   LOCAL nI AS NUMERIC
   LOCAL nD AS NUMERIC
   LOCAL cC AS STRING

   aArgs := Array( 6 )
   AFill( aArgs, "" )
   nN := 1
   nD := 0
   FOR nI := 1 TO Len( cA )
      cC := SubStr( cA, nI, 1 )
      IF cC == "(" .OR. cC == "{"
         nD++
      ELSEIF cC == ")" .OR. cC == "}"
         nD--
      ENDIF
      IF cC == "," .AND. nD == 0 .AND. nN < nMax
         nN++
      ELSE
         aArgs[ nN ] += cC
      ENDIF
   NEXT

   RETURN aArgs

STATIC FUNCTION SortedUnique( cS AS STRING ) /* AS STRING */

   LOCAL aW AS ARRAY
   LOCAL aR AS ARRAY
   LOCAL nP AS NUMERIC
   LOCAL cX AS STRING
   LOCAL nI AS NUMERIC

   aW := {}
   nP := 1
   DO WHILE NextWord( cS, @nP, @cX )
      AAdd( aW, cX )
   ENDDO
   ASort( aW )
   aR := {}
   FOR nI := 1 TO Len( aW )
      IF nI == 1 .OR. ! aW[ nI ] == aW[ nI - 1 ]
         AAdd( aR, aW[ nI ] )
      ENDIF
   NEXT

   RETURN JoinWords( aR )

STATIC FUNCTION Wildcard( cPats AS STRING ) /* AS STRING */

   LOCAL nP AS NUMERIC
   LOCAL nI AS NUMERIC
   LOCAL cPat AS STRING
   LOCAL cDir AS STRING
   LOCAL aNames AS ARRAY
   LOCAL aE

   aNames := {}
   nP := 1
   DO WHILE NextWord( cPats, @nP, @cPat )
      nI := Len( cPat )
      DO WHILE nI > 0 .AND. ! InSet( SubStr( cPat, nI, 1 ), "/\" )
         nI--
      ENDDO
      cDir := Left( cPat, nI )
      FOR EACH aE IN Directory( cPat, "HSD" )
         IF ! aE[ 1 ] == "." .AND. ! aE[ 1 ] == ".."
            AAdd( aNames, cDir + aE[ 1 ] )
         ENDIF
      NEXT
   ENDDO
   ASort( aNames )

   RETURN JoinWords( aNames )

STATIC FUNCTION DirPart( cW AS STRING ) /* AS STRING */

   LOCAL nI AS NUMERIC

   nI := Len( cW )
   DO WHILE nI > 0 .AND. ! InSet( SubStr( cW, nI, 1 ), "/\" )
      nI--
   ENDDO
   IF nI == 0
      RETURN "./"
   ENDIF

   RETURN Left( cW, nI )

STATIC FUNCTION NotDirPart( cW AS STRING ) /* AS STRING */

   LOCAL nI AS NUMERIC

   nI := Len( cW )
   DO WHILE nI > 0 .AND. ! InSet( SubStr( cW, nI, 1 ), "/\" )
      nI--
   ENDDO

   RETURN SubStr( cW, nI + 1 )

STATIC FUNCTION SuffixPart( cW AS STRING ) /* AS STRING */

   LOCAL nI AS NUMERIC

   nI := Len( cW )
   DO WHILE nI > 0 .AND. ! SubStr( cW, nI, 1 ) == "." .AND. ! InSet( SubStr( cW, nI, 1 ), "/\" )
      nI--
   ENDDO
   IF nI > 0 .AND. SubStr( cW, nI, 1 ) == "."
      RETURN SubStr( cW, nI )
   ENDIF

   RETURN ""

/* ------------------------- Fonctions $(...) ------------------------- */

STATIC FUNCTION IsFuncName( cN AS STRING ) /* AS LOGICAL */
   RETURN ( "|" + cN + "|" ) $ ;
      "|subst|patsubst|strip|findstring|filter|filter-out|sort|word|wordlist|words|firstword|" + ;
      "lastword|addprefix|addsuffix|basename|suffix|notdir|dir|abspath|realpath|wildcard|shell|" + ;
      "if|foreach|origin|info|warning|error|"

STATIC FUNCTION EvalFunc( cFn AS STRING, cA AS STRING, nDepth AS NUMERIC ) /* AS STRING */

   LOCAL aArgs AS ARRAY
   LOCAL nN AS NUMERIC
   LOCAL nI AS NUMERIC
   LOCAL nK AS NUMERIC
   LOCAL nP AS NUMERIC
   LOCAL nNum AS NUMERIC
   LOCAL nNum2 AS NUMERIC
   LOCAL cR AS STRING
   LOCAL cW AS STRING
   LOCAL cX AS STRING
   LOCAL cStem AS STRING
   LOCAL cPat AS STRING
   LOCAL cLst AS STRING
   LOCAL cS1 AS STRING
   LOCAL lMatch AS LOGICAL

   cR := ""
   cStem := ""

   IF cFn == "if"
      aArgs := SplitArgs( cA, 3, @nN )
      IF ! Empty( MkTrim( Expand( aArgs[ 1 ], nDepth + 1 ) ) )
         cR := Expand( aArgs[ 2 ], nDepth + 1 )
      ELSEIF nN >= 3
         cR := Expand( aArgs[ 3 ], nDepth + 1 )
      ENDIF
      RETURN cR
   ENDIF

   IF cFn == "foreach"
      aArgs := SplitArgs( cA, 3, @nN )
      cS1 := MkTrim( Expand( aArgs[ 1 ], nDepth + 1 ) )
      cLst := Expand( aArgs[ 2 ], nDepth + 1 )
      nP := 1
      DO WHILE NextWord( cLst, @nP, @cW )
         SetVar( cS1, cW, .T., ORG_OVERRIDE )
         IF ! cR == ""
            cR += " "
         ENDIF
         cR += Expand( aArgs[ 3 ], nDepth + 1 )
      ENDDO
      RETURN cR
   ENDIF

   IF ( "|" + cFn + "|" ) $ "|strip|sort|words|firstword|lastword|basename|suffix|notdir|dir|" + ;
         "abspath|realpath|wildcard|shell|info|warning|error|origin|"
      nN := 1
      aArgs := Array( 6 )
      AFill( aArgs, "" )
      aArgs[ 1 ] := Expand( cA, nDepth + 1 )
   ELSE
      aArgs := SplitArgs( cA, 3, @nN )
      FOR nI := 1 TO nN
         aArgs[ nI ] := Expand( aArgs[ nI ], nDepth + 1 )
      NEXT
   ENDIF

   DO CASE
   CASE cFn == "subst"
      cR := ReplaceAll( aArgs[ 3 ], aArgs[ 1 ], aArgs[ 2 ] )

   CASE cFn == "patsubst"
      nP := 1
      DO WHILE NextWord( aArgs[ 3 ], @nP, @cW )
         IF ! cR == ""
            cR += " "
         ENDIF
         IF PatMatch( MkTrim( aArgs[ 1 ] ), cW, @cStem )
            cR += ReplaceStem( MkTrim( aArgs[ 2 ] ), cStem )
         ELSE
            cR += cW
         ENDIF
      ENDDO

   CASE cFn == "strip"
      nP := 1
      DO WHILE NextWord( aArgs[ 1 ], @nP, @cW )
         IF ! cR == ""
            cR += " "
         ENDIF
         cR += cW
      ENDDO

   CASE cFn == "findstring"
      IF At( aArgs[ 1 ], aArgs[ 2 ] ) > 0
         cR := aArgs[ 1 ]
      ENDIF

   CASE cFn == "filter" .OR. cFn == "filter-out"
      nP := 1
      DO WHILE NextWord( aArgs[ 2 ], @nP, @cW )
         lMatch := .F.
         nK := 1
         DO WHILE NextWord( aArgs[ 1 ], @nK, @cPat )
            IF PatMatch( cPat, cW, @cStem )
               lMatch := .T.
            ENDIF
         ENDDO
         IF lMatch == ( cFn == "filter" )
            IF ! cR == ""
               cR += " "
            ENDIF
            cR += cW
         ENDIF
      ENDDO

   CASE cFn == "sort"
      cR := SortedUnique( aArgs[ 1 ] )

   CASE cFn == "word"
      IF IsInt( aArgs[ 1 ] )
         nNum := Val( MkTrim( aArgs[ 1 ] ) )
         IF nNum >= 1
            cR := WordN( aArgs[ 2 ], nNum )
         ENDIF
      ENDIF

   CASE cFn == "wordlist"
      IF IsInt( aArgs[ 1 ] ) .AND. IsInt( aArgs[ 2 ] )
         nNum  := Val( MkTrim( aArgs[ 1 ] ) )
         nNum2 := Val( MkTrim( aArgs[ 2 ] ) )
         FOR nI := Max( nNum, 1 ) TO nNum2
            cX := WordN( aArgs[ 3 ], nI )
            IF ! cX == ""
               IF ! cR == ""
                  cR += " "
               ENDIF
               cR += cX
            ENDIF
         NEXT
      ENDIF

   CASE cFn == "words"
      cR := IntStr( WordCount( aArgs[ 1 ] ) )

   CASE cFn == "firstword"
      cR := WordN( aArgs[ 1 ], 1 )

   CASE cFn == "lastword"
      cR := WordN( aArgs[ 1 ], WordCount( aArgs[ 1 ] ) )

   CASE cFn == "addprefix" .OR. cFn == "addsuffix"
      nP := 1
      DO WHILE NextWord( aArgs[ 2 ], @nP, @cW )
         IF ! cR == ""
            cR += " "
         ENDIF
         IF cFn == "addprefix"
            cR += aArgs[ 1 ] + cW
         ELSE
            cR += cW + aArgs[ 1 ]
         ENDIF
      ENDDO

   CASE ( "|" + cFn + "|" ) $ "|basename|suffix|notdir|dir|abspath|realpath|"
      nP := 1
      DO WHILE NextWord( aArgs[ 1 ], @nP, @cW )
         IF ! cR == ""
            cR += " "
         ENDIF
         DO CASE
         CASE cFn == "basename"
            cX := SuffixPart( cW )
            cR += Left( cW, Len( cW ) - Len( cX ) )
         CASE cFn == "suffix"
            cR += SuffixPart( cW )
         CASE cFn == "notdir"
            cR += NotDirPart( cW )
         CASE cFn == "dir"
            cR += DirPart( cW )
         OTHERWISE
            cR += MkFExpand( cW )
         ENDCASE
      ENDDO

   CASE cFn == "wildcard"
      cR := Wildcard( aArgs[ 1 ] )

   CASE cFn == "shell"
      cR := ShellOutput( aArgs[ 1 ] )

   CASE cFn == "origin"
      nK := FindVar( MkTrim( aArgs[ 1 ] ) )
      IF nK == 0
         cR := "undefined"
      ELSE
         cR := OriginName( s_aVars[ nK ][ "org" ], "file" )
      ENDIF

   CASE cFn == "info"
      PutOut( aArgs[ 1 ] )

   CASE cFn == "warning"
      Warn( s_cCurFile + ":" + IntStr( s_nLineNo ) + ": " + aArgs[ 1 ] )

   CASE cFn == "error"
      PutErr( s_cCurFile + ":" + IntStr( s_nLineNo ) + ": *** " + aArgs[ 1 ] + ".  Stop." )
      MkHalt( 2 )

   OTHERWISE
      Warn( "fonction inconnue: " + cFn )
   ENDCASE

   RETURN cR

/* Valeur d'une variable (avec variables automatiques) */
STATIC FUNCTION VarValue( cName AS STRING, nDepth AS NUMERIC ) /* AS STRING */

   LOCAL nI AS NUMERIC
   LOCAL nP AS NUMERIC
   LOCAL cC AS STRING
   LOCAL cV AS STRING
   LOCAL cR AS STRING
   LOCAL cW AS STRING
   LOCAL cD AS STRING

   IF Len( cName ) == 1 .OR. ( Len( cName ) == 2 .AND. InSet( SubStr( cName, 2, 1 ), "DF" ) )
      cC := Left( cName, 1 )
      IF InSet( cC, "@<^+?*%" )
         DO CASE
         CASE cC == "@" ; cV := s_cAutoTarget
         CASE cC == "<" ; cV := s_cAutoFirst
         CASE cC == "^" ; cV := s_cAutoAll
         CASE cC == "+" ; cV := s_cAutoPlus
         CASE cC == "?" ; cV := s_cAutoNewer
         CASE cC == "*" ; cV := s_cAutoStem
         OTHERWISE      ; cV := ""
         ENDCASE
         IF Len( cName ) == 2
            cR := ""
            nP := 1
            DO WHILE NextWord( cV, @nP, @cW )
               IF ! cR == ""
                  cR += " "
               ENDIF
               IF SubStr( cName, 2, 1 ) == "D"
                  cD := DirPart( cW )
                  IF cD == "./"
                     cR += "."
                  ELSE
                     cR += Left( cD, Len( cD ) - 1 )
                  ENDIF
               ELSE
                  cR += NotDirPart( cW )
               ENDIF
            ENDDO
            cV := cR
         ENDIF
         RETURN cV
      ENDIF
   ENDIF

   nI := FindVar( cName )
   IF nI == 0
      IF s_lWarnUndef
         Warn( s_cCurFile + ":" + IntStr( s_nLineNo ) + ": warning: undefined variable '" + cName + "'" )
      ENDIF
      RETURN ""
   ENDIF
   IF s_aVars[ nI ][ "simple" ]
      RETURN s_aVars[ nI ][ "val" ]
   ENDIF
   IF nDepth > 40
      Die( "Recursive variable '" + cName + "' references itself (eventually).  Stop." )
   ENDIF

   RETURN Expand( s_aVars[ nI ][ "val" ], nDepth + 1 )

STATIC FUNCTION EvalRef( cContent AS STRING, nDepth AS NUMERIC ) /* AS STRING */

   LOCAL nP AS NUMERIC
   LOCAL nQ AS NUMERIC
   LOCAL nI AS NUMERIC
   LOCAL cFn AS STRING
   LOCAL cNm AS STRING
   LOCAL cCnt AS STRING
   LOCAL cPat AS STRING
   LOCAL cRepl AS STRING
   LOCAL cStem AS STRING
   LOCAL cW AS STRING
   LOCAL cR AS STRING
   LOCAL cBase AS STRING

   cStem := ""

   /* fonction ? */
   nP := 1
   DO WHILE nP <= Len( cContent ) .AND. ! IsBlankCh( SubStr( cContent, nP, 1 ) )
      nP++
   ENDDO
   IF nP <= Len( cContent )
      cFn := Left( cContent, nP - 1 )
      IF IsFuncName( cFn )
         DO WHILE nP <= Len( cContent ) .AND. IsBlankCh( SubStr( cContent, nP, 1 ) )
            nP++
         ENDDO
         RETURN EvalFunc( cFn, SubStr( cContent, nP ), nDepth )
      ENDIF
   ENDIF

   cCnt := Expand( cContent, nDepth + 1 )

   /* reference avec substitution : $(VAR:a=b) */
   nP := At( ":", cCnt )
   IF nP > 0
      nQ := At( "=", SubStr( cCnt, nP + 1 ) )
      IF nQ > 0
         cNm   := Left( cCnt, nP - 1 )
         cPat  := SubStr( cCnt, nP + 1, nQ - 1 )
         cRepl := SubStr( cCnt, nP + nQ + 1 )
         cBase := VarValue( cNm, nDepth )
         cR := ""
         nI := 1
         IF ! "%" $ cPat
            cPat  := "%" + cPat
            cRepl := "%" + cRepl
         ENDIF
         DO WHILE NextWord( cBase, @nI, @cW )
            IF ! cR == ""
               cR += " "
            ENDIF
            IF PatMatch( cPat, cW, @cStem )
               cR += ReplaceStem( cRepl, cStem )
            ELSE
               cR += cW
            ENDIF
         ENDDO
         RETURN cR
      ENDIF
   ENDIF

   RETURN VarValue( cCnt, nDepth )

STATIC FUNCTION Expand( cS AS STRING, nDepth AS NUMERIC ) /* AS STRING */

   LOCAL cR AS STRING
   LOCAL cCnt AS STRING
   LOCAL nI AS NUMERIC
   LOCAL nD AS NUMERIC
   LOCAL nStart AS NUMERIC
   LOCAL cC AS STRING
   LOCAL cOp AS STRING
   LOCAL cCl AS STRING

   IF nDepth > 50
      RETURN cS
   ENDIF
   cR := ""
   nI := 1
   DO WHILE nI <= Len( cS )
      cC := SubStr( cS, nI, 1 )
      IF ! cC == "$"
         cR += cC
         nI++
      ELSE
         nI++
         IF nI > Len( cS )
            cR += "$"
            EXIT
         ENDIF
         cC := SubStr( cS, nI, 1 )
         IF cC == "$"
            cR += "$"
            nI++
         ELSEIF cC == "(" .OR. cC == "{"
            cOp := cC
            cCl := iif( cC == "(", ")", "}" )
            nStart := nI + 1
            nD := 1
            nI++
            DO WHILE nI <= Len( cS ) .AND. nD > 0
               IF SubStr( cS, nI, 1 ) == cOp
                  nD++
               ELSEIF SubStr( cS, nI, 1 ) == cCl
                  nD--
               ENDIF
               nI++
            ENDDO
            IF nD > 0
               cCnt := SubStr( cS, nStart )
            ELSE
               cCnt := SubStr( cS, nStart, nI - nStart - 1 )
            ENDIF
            cR += EvalRef( cCnt, nDepth )
         ELSE
            cR += VarValue( cC, nDepth )
            nI++
         ENDIF
      ENDIF
   ENDDO

   RETURN cR

/* ------------------------- Regles ------------------------- */

STATIC FUNCTION FindExplicit( cT AS STRING ) /* AS NUMERIC */

   LOCAL nI AS NUMERIC

   FOR nI := 1 TO Len( s_aRules )
      IF ! s_aRules[ nI ][ "ispat" ] .AND. s_aRules[ nI ][ "targ" ] == cT
         RETURN nI
      ENDIF
   NEXT

   RETURN 0

STATIC FUNCTION IsSuffix( cS AS STRING ) /* AS LOGICAL */

   LOCAL cX AS STRING

   FOR EACH cX IN s_aSuffixes
      IF cX == cS
         RETURN .T.
      ENDIF
   NEXT

   RETURN .F.

STATIC PROCEDURE AddSuffix( cS AS STRING )

   IF ! cS == "" .AND. ! IsSuffix( cS )
      AAdd( s_aSuffixes, cS )
   ENDIF

   RETURN

/* Cree une regle (ou fusionne les prerequis) et retourne son indice */
STATIC FUNCTION AddRule( cT AS STRING, cPre AS STRING, cOrdPre AS STRING, lIsPat AS LOGICAL, lBuiltin AS LOGICAL ) /* AS NUMERIC */

   LOCAL nI AS NUMERIC
   LOCAL nIdx AS NUMERIC
   LOCAL cTarg AS STRING
   LOCAL cP AS STRING

   cTarg := cT
   cP := cPre

   /* regle de suffixe : .c.o ou .c */
   IF Left( cTarg, 1 ) == "." .AND. ! "%" $ cTarg .AND. Empty( MkTrim( cPre ) ) .AND. ! lIsPat
      IF IsSuffix( cTarg )
         cP := "%" + cTarg
         cTarg := "%"
         lIsPat := .T.
      ELSE
         FOR nI := 2 TO Len( cTarg ) - 1
            IF SubStr( cTarg, nI, 1 ) == "." .AND. IsSuffix( Left( cTarg, nI - 1 ) ) .AND. IsSuffix( SubStr( cTarg, nI ) )
               cP := "%" + Left( cTarg, nI - 1 )
               cTarg := "%" + SubStr( cTarg, nI )
               lIsPat := .T.
               EXIT
            ENDIF
         NEXT
      ENDIF
   ENDIF

   nIdx := 0
   IF ! lIsPat
      nIdx := FindExplicit( cTarg )
   ENDIF
   IF nIdx == 0
      AAdd( s_aRules, { ;
         "targ"    => cTarg, ;
         "pre"     => MkTrim( cP ), ;
         "ordpre"  => MkTrim( cOrdPre ), ;
         "cfirst"  => 0, ;
         "ccnt"    => 0, ;
         "ispat"   => lIsPat, ;
         "builtin" => lBuiltin, ;
         "line"    => s_nLineNo } )
      nIdx := Len( s_aRules )
   ELSE
      s_aRules[ nIdx ][ "pre" ]    := MkTrim( s_aRules[ nIdx ][ "pre" ] + " " + cP )
      s_aRules[ nIdx ][ "ordpre" ] := MkTrim( s_aRules[ nIdx ][ "ordpre" ] + " " + cOrdPre )
   ENDIF

   RETURN nIdx

STATIC PROCEDURE FlushRecipe()

   LOCAL nFirst AS NUMERIC
   LOCAL nR AS NUMERIC
   LOCAL cC AS STRING

   IF Len( s_aRecCmds ) > 0 .AND. Len( s_aCurRules ) > 0
      nFirst := Len( s_aCmds ) + 1
      FOR EACH cC IN s_aRecCmds
         AAdd( s_aCmds, cC )
      NEXT
      FOR EACH nR IN s_aCurRules
         s_aRules[ nR ][ "cfirst" ] := nFirst
         s_aRules[ nR ][ "ccnt" ]   := Len( s_aRecCmds )
      NEXT
   ENDIF
   s_aRecCmds := {}

   RETURN

STATIC PROCEDURE AddRecipe( cL AS STRING )

   AAdd( s_aRecCmds, cL )

   RETURN

/* ------------------------- Analyse du makefile ------------------------- */

STATIC FUNCTION StripComment( cL AS STRING ) /* AS STRING */

   LOCAL nI AS NUMERIC

   nI := 1
   DO WHILE nI <= Len( cL )
      IF SubStr( cL, nI, 1 ) == "\" .AND. nI < Len( cL ) .AND. SubStr( cL, nI + 1, 1 ) == "#"
         nI += 2
      ELSEIF SubStr( cL, nI, 1 ) == "#"
         RETURN Left( cL, nI - 1 )
      ELSE
         nI++
      ENDIF
   ENDDO

   RETURN cL

/* Classe une ligne : 1 affectation, 2 regle, 0 autre */
STATIC FUNCTION Classify( cL AS STRING, nP1 AS NUMERIC, nOpLen AS NUMERIC, cOp AS STRING ) /* AS NUMERIC */

   LOCAL nI AS NUMERIC
   LOCAL nD AS NUMERIC
   LOCAL cC AS STRING

   nD := 0
   nI := 1
   DO WHILE nI <= Len( cL )
      cC := SubStr( cL, nI, 1 )
      IF cC == "$" .AND. nI < Len( cL ) .AND. InSet( SubStr( cL, nI + 1, 1 ), "({" )
         nD++
         nI += 2
         LOOP
      ENDIF
      IF nD > 0 .AND. ( cC == ")" .OR. cC == "}" )
         nD--
      ELSEIF nD == 0
         IF cC == "="
            cOp := "="
            nP1 := nI
            nOpLen := 1
            IF nI > 1 .AND. SubStr( cL, nI - 1, 1 ) == ":"
               cOp := ":="
               nP1 := nI - 1
               nOpLen := 2
               IF nP1 > 1 .AND. SubStr( cL, nP1 - 1, 1 ) == ":"
                  nP1--
                  nOpLen++
               ENDIF
            ELSEIF nI > 1 .AND. SubStr( cL, nI - 1, 1 ) == "+"
               cOp := "+="
               nP1 := nI - 1
               nOpLen := 2
            ELSEIF nI > 1 .AND. SubStr( cL, nI - 1, 1 ) == "?"
               cOp := "?="
               nP1 := nI - 1
               nOpLen := 2
            ELSEIF nI > 1 .AND. SubStr( cL, nI - 1, 1 ) == "!"
               cOp := "!="
               nP1 := nI - 1
               nOpLen := 2
            ENDIF
            RETURN 1
         ELSEIF cC == ":"
            IF nI < Len( cL ) .AND. SubStr( cL, nI + 1, 1 ) == "="
               cOp := ":="
               nP1 := nI
               nOpLen := 2
               RETURN 1
            ENDIF
            IF nI < Len( cL ) - 1 .AND. SubStr( cL, nI + 1, 1 ) == ":" .AND. SubStr( cL, nI + 2, 1 ) == "="
               cOp := ":="
               nP1 := nI
               nOpLen := 3
               RETURN 1
            ENDIF
            /* "C:\..." ou "C:/..." : lettre de lecteur, pas une regle */
            IF ! ( nI >= 2 .AND. InSet( Upper( SubStr( cL, nI - 1, 1 ) ), "ABCDEFGHIJKLMNOPQRSTUVWXYZ" ) ;
                  .AND. ( nI == 2 .OR. IsBlankCh( SubStr( cL, nI - 2, 1 ) ) ) ;
                  .AND. nI < Len( cL ) .AND. InSet( SubStr( cL, nI + 1, 1 ), "\/" ) )
               nP1 := nI
               RETURN 2
            ENDIF
         ENDIF
      ENDIF
      nI++
   ENDDO

   RETURN 0

STATIC PROCEDURE DoAssign( cL AS STRING, nP1 AS NUMERIC, nOpLen AS NUMERIC, cOp AS STRING, nOrg AS NUMERIC )

   LOCAL cNm AS STRING
   LOCAL cV AS STRING
   LOCAL cOld AS STRING
   LOCAL nI AS NUMERIC

   cNm := MkTrim( Expand( Left( cL, nP1 - 1 ), 0 ) )
   cV  := MkTrim( SubStr( cL, nP1 + nOpLen ) )
   IF cNm == ""
      RETURN
   ENDIF
   nI := FindVar( cNm )
   DO CASE
   CASE cOp == ":="
      SetVar( cNm, Expand( cV, 0 ), .T., nOrg )
   CASE cOp == "?="
      IF nI == 0
         SetVar( cNm, cV, .F., nOrg )
      ENDIF
   CASE cOp == "+="
      IF nI == 0
         SetVar( cNm, cV, .F., nOrg )
      ELSE
         IF nOrg < s_aVars[ nI ][ "org" ]
            RETURN
         ENDIF
         IF s_aVars[ nI ][ "simple" ]
            cOld := s_aVars[ nI ][ "val" ] + " " + Expand( cV, 0 )
         ELSE
            cOld := s_aVars[ nI ][ "val" ] + " " + cV
         ENDIF
         s_aVars[ nI ][ "val" ] := MkTrim( cOld )
      ENDIF
   CASE cOp == "!="
      SetVar( cNm, ShellOutput( Expand( cV, 0 ) ), .T., nOrg )
   OTHERWISE
      SetVar( cNm, cV, .F., nOrg )
   ENDCASE

   RETURN

STATIC PROCEDURE DoSpecial( cT AS STRING, cPre AS STRING )

   LOCAL nP AS NUMERIC
   LOCAL cW AS STRING

   DO CASE
   CASE cT == ".PHONY"
      nP := 1
      DO WHILE NextWord( cPre, @nP, @cW )
         AAdd( s_aPhony, cW )
      ENDDO
   CASE cT == ".SUFFIXES"
      IF MkTrim( cPre ) == ""
         s_aSuffixes := {}
      ELSE
         nP := 1
         DO WHILE NextWord( cPre, @nP, @cW )
            AddSuffix( cW )
         ENDDO
      ENDIF
   CASE cT == ".EXPORT_ALL_VARIABLES"
      s_lExportAll := .T.
   CASE cT == ".SILENT"
      IF MkTrim( cPre ) == ""
         s_lSilentAll := .T.
      ENDIF
   CASE cT == ".IGNORE"
      IF MkTrim( cPre ) == ""
         s_lIgnoreAll := .T.
      ENDIF
   ENDCASE

   RETURN

STATIC FUNCTION IsSpecialIgnored( cT AS STRING ) /* AS LOGICAL */
   RETURN ( "|" + cT + "|" ) $ ;
      "|.PRECIOUS|.SECONDARY|.INTERMEDIATE|.DELETE_ON_ERROR|.NOTPARALLEL|.ONESHELL|" + ;
      ".EXPORT_ALL_VARIABLES|.POSIX|.LOW_RESOLUTION_TIME|.SECONDEXPANSION|"

STATIC FUNCTION TopColon( cS AS STRING ) /* AS NUMERIC */

   LOCAL nI AS NUMERIC
   LOCAL nD AS NUMERIC

   nD := 0
   FOR nI := 1 TO Len( cS )
      IF SubStr( cS, nI, 1 ) == "$" .AND. nI < Len( cS ) .AND. InSet( SubStr( cS, nI + 1, 1 ), "({" )
         nD++
      ELSEIF nD > 0 .AND. InSet( SubStr( cS, nI, 1 ), ")}" )
         nD--
      ELSEIF nD == 0 .AND. SubStr( cS, nI, 1 ) == ":"
         RETURN nI
      ENDIF
   NEXT

   RETURN 0

STATIC PROCEDURE DoRule( cL AS STRING, nColon AS NUMERIC )

   LOCAL cLeft AS STRING
   LOCAL cRight AS STRING
   LOCAL cInlCmd AS STRING
   LOCAL cPreS AS STRING
   LOCAL cOrdS AS STRING
   LOCAL cTP AS STRING
   LOCAL cPP AS STRING
   LOCAL cStem AS STRING
   LOCAL cW AS STRING
   LOCAL cNp AS STRING
   LOCAL cPr AS STRING
   LOCAL nI AS NUMERIC
   LOCAL nP AS NUMERIC
   LOCAL nK AS NUMERIC
   LOCAL nIdx AS NUMERIC
   LOCAL nQ AS NUMERIC
   LOCAL lStatic AS LOGICAL

   cPreS := ""
   cOrdS := ""
   cTP := ""
   cPP := ""
   cStem := ""

   FlushRecipe()
   s_aCurRules := {}
   cLeft := Expand( Left( cL, nColon - 1 ), 0 )
   cRight := SubStr( cL, nColon + 1 )
   IF Len( cRight ) > 0 .AND. Left( cRight, 1 ) == ":"
      cRight := SubStr( cRight, 2 )
   ENDIF

   /* commande en ligne apres ; */
   cInlCmd := ""
   nP := 0
   FOR nI := 1 TO Len( cRight )
      IF SubStr( cRight, nI, 1 ) == ";" .AND. nP == 0
         nP := nI
      ENDIF
   NEXT
   IF nP > 0
      cInlCmd := MkTrim( SubStr( cRight, nP + 1 ) )
      cRight := Left( cRight, nP - 1 )
   ENDIF

   lStatic := .F.
   nK := TopColon( cRight )
   IF nK > 0
      lStatic := .T.
      cTP := MkTrim( Expand( Left( cRight, nK - 1 ), 0 ) )
      cPP := MkTrim( Expand( SubStr( cRight, nK + 1 ), 0 ) )
   ELSE
      cRight := Expand( cRight, 0 )
      cPreS := cRight
      cOrdS := ""
      nQ := At( "|", cRight )
      IF nQ > 0
         cPreS := Left( cRight, nQ - 1 )
         cOrdS := SubStr( cRight, nQ + 1 )
      ENDIF
   ENDIF

   nI := 1
   DO WHILE NextWord( cLeft, @nI, @cW )
      IF lStatic
         IF PatMatch( cTP, cW, @cStem )
            cNp := ""
            nP := 1
            DO WHILE NextWord( cPP, @nP, @cPr )
               cNp += " " + ReplaceStem( cPr, cStem )
            ENDDO
            nIdx := AddRule( cW, cNp, "", .F., .F. )
         ELSE
            nIdx := 0
         ENDIF
      ELSEIF Left( cW, 1 ) == "." .AND. ( cW == ".PHONY" .OR. cW == ".SUFFIXES" .OR. cW == ".SILENT" ;
            .OR. cW == ".IGNORE" .OR. IsSpecialIgnored( cW ) )
         DoSpecial( cW, cPreS )
         nIdx := 0
      ELSE
         nIdx := AddRule( cW, cPreS, cOrdS, "%" $ cW, .F. )
         IF s_cDefaultGoal == "" .AND. ! s_aRules[ nIdx ][ "ispat" ] .AND. ! Left( cW, 1 ) == "."
            s_cDefaultGoal := cW
         ENDIF
      ENDIF
      IF nIdx > 0
         AAdd( s_aCurRules, nIdx )
      ENDIF
   ENDDO
   IF ! cInlCmd == ""
      AddRecipe( cInlCmd )
   ENDIF

   RETURN

/* ------------------------- Conditionnelles ------------------------- */

STATIC FUNCTION EvalIfeq( cA AS STRING ) /* AS LOGICAL */

   LOCAL cS AS STRING
   LOCAL nI AS NUMERIC
   LOCAL nD AS NUMERIC
   LOCAL nQ AS NUMERIC
   LOCAL cX AS STRING
   LOCAL cY AS STRING
   LOCAL cC AS STRING

   cS := MkTrim( Expand( cA, 0 ) )
   IF cS == ""
      RETURN .F.
   ENDIF
   IF Left( cS, 1 ) == "("
      nD := 0
      nQ := 0
      FOR nI := 2 TO Len( cS )
         IF InSet( SubStr( cS, nI, 1 ), "({" )
            nD++
         ELSEIF InSet( SubStr( cS, nI, 1 ), ")}" )
            nD--
         ELSEIF SubStr( cS, nI, 1 ) == "," .AND. nD == 0 .AND. nQ == 0
            nQ := nI
         ENDIF
      NEXT
      IF nQ == 0
         RETURN .F.
      ENDIF
      cX := MkTrim( SubStr( cS, 2, nQ - 2 ) )
      cY := MkTrim( SubStr( cS, nQ + 1, Len( cS ) - nQ - 1 ) )
      RETURN cX == cY
   ENDIF

   cC := Left( cS, 1 )
   IF ! InSet( cC, "'" + '"' )
      RETURN .F.
   ENDIF
   nI := 2
   DO WHILE nI <= Len( cS ) .AND. ! SubStr( cS, nI, 1 ) == cC
      nI++
   ENDDO
   cX := SubStr( cS, 2, nI - 2 )
   cS := MkTrim( SubStr( cS, nI + 1 ) )
   IF cS == ""
      RETURN .F.
   ENDIF
   cY := SubStr( cS, 2, Len( cS ) - 2 )

   RETURN cX == cY

STATIC FUNCTION EvalCond( cDir AS STRING, cRest AS STRING ) /* AS LOGICAL */

   LOCAL cNm AS STRING
   LOCAL nI AS NUMERIC
   LOCAL lDef AS LOGICAL

   DO CASE
   CASE cDir == "ifeq"
      RETURN EvalIfeq( cRest )
   CASE cDir == "ifneq"
      RETURN ! EvalIfeq( cRest )
   ENDCASE

   cNm := MkTrim( Expand( cRest, 0 ) )
   nI := FindVar( cNm )
   lDef := .F.
   IF nI > 0
      IF ! s_aVars[ nI ][ "val" ] == ""
         lDef := .T.
      ENDIF
   ENDIF

   RETURN iif( cDir == "ifdef", lDef, ! lDef )

/* ---- Lecture logique : gere les lignes continuees par \ ---- */
STATIC FUNCTION ReadLogical( hF AS HASH, cL AS STRING, lRecipe AS LOGICAL ) /* AS LOGICAL */

   LOCAL nN AS NUMERIC
   LOCAL nI AS NUMERIC
   LOCAL cT AS STRING

   IF hF[ "pos" ] > Len( hF[ "lines" ] )
      RETURN .F.
   ENDIF
   cL := hF[ "lines" ][ hF[ "pos" ] ]
   hF[ "pos" ]++
   s_nLineNo++
   lRecipe := Len( cL ) > 0 .AND. Left( cL, 1 ) == TAB

   DO WHILE .T.
      nN := 0
      nI := Len( cL )
      DO WHILE nI > 0 .AND. SubStr( cL, nI, 1 ) == "\"
         nN++
         nI--
      ENDDO
      IF nN % 2 == 0
         EXIT
      ENDIF
      cL := Left( cL, Len( cL ) - 1 )
      IF hF[ "pos" ] > Len( hF[ "lines" ] )
         EXIT
      ENDIF
      cT := hF[ "lines" ][ hF[ "pos" ] ]
      hF[ "pos" ]++
      s_nLineNo++
      cL := cL + " " + MkTrim( cT )
   ENDDO

   RETURN .T.

STATIC FUNCTION FindInclude( cNm AS STRING ) /* AS STRING */

   LOCAL cD AS STRING

   IF FileTime( cNm ) > 0
      RETURN cNm
   ENDIF
   FOR EACH cD IN s_aIncDirs
      IF FileTime( cD + "/" + cNm ) > 0
         RETURN cD + "/" + cNm
      ENDIF
   NEXT

   RETURN ""

STATIC PROCEDURE ParseFile( cName AS STRING, nDepth AS NUMERIC, lOptional AS LOGICAL )

   LOCAL hF AS HASH
   LOCAL aLines AS ARRAY
   LOCAL cL AS STRING
   LOCAL cT AS STRING
   LOCAL cDir AS STRING
   LOCAL cRest AS STRING
   LOCAL cNm AS STRING
   LOCAL cW AS STRING
   LOCAL cFull AS STRING
   LOCAL cBody AS STRING
   LOCAL cOp AS STRING
   LOCAL cSaveFile AS STRING
   LOCAL nSaveLine AS NUMERIC
   LOCAL lRecipe AS LOGICAL
   LOCAL lCond AS LOGICAL
   LOCAL nP1 AS NUMERIC
   LOCAL nOpLen AS NUMERIC
   LOCAL nK AS NUMERIC
   LOCAL nI AS NUMERIC
   LOCAL nOrg AS NUMERIC
   LOCAL nBase AS NUMERIC

   cFull := FindInclude( cName )
   IF cFull == ""
      IF ! lOptional
         Die( cName + ": No such file or directory.  Stop." )
      ENDIF
      RETURN
   ENDIF
   aLines := hb_ATokens( StrTran( hb_MemoRead( cFull ), Chr( 13 ), "" ), Chr( 10 ) )
   IF Len( aLines ) > 0 .AND. aLines[ Len( aLines ) ] == ""
      ASize( aLines, Len( aLines ) - 1 )
   ENDIF
   hF := { "lines" => aLines, "pos" => 1 }

   cSaveFile := s_cCurFile
   nSaveLine := s_nLineNo
   s_cCurFile := cFull
   s_nLineNo := 0
   nBase := s_nIfTop
   s_aCurRules := {}
   s_aRecCmds := {}

   cL := ""
   lRecipe := .F.
   cOp := ""
   nP1 := 0
   nOpLen := 0

   DO WHILE ReadLogical( hF, @cL, @lRecipe )
      IF lRecipe
         IF s_aIfActive[ s_nIfTop ] .AND. Len( s_aCurRules ) > 0
            cT := SubStr( cL, 2 )
            IF ! MkTrim( cT ) == ""
               AddRecipe( cT )
            ENDIF
         ENDIF
         LOOP
      ENDIF
      cL := StripComment( cL )
      cT := MkTrim( cL )
      IF cT == ""
         LOOP
      ENDIF

      /* directive ? */
      nK := 1
      DO WHILE nK <= Len( cT ) .AND. ! IsBlankCh( SubStr( cT, nK, 1 ) )
         nK++
      ENDDO
      cDir := Left( cT, nK - 1 )
      cRest := MkTrim( SubStr( cT, nK ) )

      IF cDir == "ifdef" .OR. cDir == "ifndef" .OR. cDir == "ifeq" .OR. cDir == "ifneq"
         FlushRecipe()
         IF s_nIfTop >= MAX_IF + 1
            Die( "conditionnelles trop imbriquees.  Stop." )
         ENDIF
         lCond := .F.
         IF s_aIfActive[ s_nIfTop ]
            lCond := EvalCond( cDir, cRest )
         ENDIF
         s_nIfTop++
         s_aIfActive[ s_nIfTop ] := s_aIfActive[ s_nIfTop - 1 ] .AND. lCond
         s_aIfDone[ s_nIfTop ] := lCond
         LOOP
      ENDIF
      IF cDir == "else"
         FlushRecipe()
         IF s_nIfTop <= nBase
            Die( s_cCurFile + ":" + IntStr( s_nLineNo ) + ": extraneous 'else'.  Stop." )
         ENDIF
         IF cRest == ""
            s_aIfActive[ s_nIfTop ] := s_aIfActive[ s_nIfTop - 1 ] .AND. ! s_aIfDone[ s_nIfTop ]
            s_aIfDone[ s_nIfTop ] := .T.
         ELSE
            nK := 1
            DO WHILE nK <= Len( cRest ) .AND. ! IsBlankCh( SubStr( cRest, nK, 1 ) )
               nK++
            ENDDO
            lCond := .F.
            IF s_aIfActive[ s_nIfTop - 1 ] .AND. ! s_aIfDone[ s_nIfTop ]
               lCond := EvalCond( Left( cRest, nK - 1 ), MkTrim( SubStr( cRest, nK ) ) )
            ENDIF
            s_aIfActive[ s_nIfTop ] := s_aIfActive[ s_nIfTop - 1 ] .AND. ! s_aIfDone[ s_nIfTop ] .AND. lCond
            IF lCond
               s_aIfDone[ s_nIfTop ] := .T.
            ENDIF
         ENDIF
         LOOP
      ENDIF
      IF cDir == "endif"
         FlushRecipe()
         IF s_nIfTop <= nBase
            Die( s_cCurFile + ":" + IntStr( s_nLineNo ) + ": extraneous 'endif'.  Stop." )
         ENDIF
         s_nIfTop--
         LOOP
      ENDIF
      IF ! s_aIfActive[ s_nIfTop ]
         LOOP
      ENDIF

      IF cDir == "include" .OR. cDir == "-include" .OR. cDir == "sinclude"
         FlushRecipe()
         s_aCurRules := {}
         cRest := Expand( cRest, 0 )
         nI := 1
         DO WHILE NextWord( cRest, @nI, @cW )
            ParseFile( cW, nDepth + 1, ! cDir == "include" )
         ENDDO
         LOOP
      ENDIF
      IF cDir == "unexport"
         cRest := Expand( cRest, 0 )
         nI := 1
         DO WHILE NextWord( cRest, @nI, @cW )
            hb_HDel( s_hExport, cW )
         ENDDO
         LOOP
      ENDIF
      IF cDir == "export" .AND. cRest == ""
         s_lExportAll := .T.
         LOOP
      ENDIF
      IF cDir == "vpath" .OR. cDir == "VPATH"
         LOOP
      ENDIF

      IF cDir == "define"
         FlushRecipe()
         cNm := MkTrim( cRest )
         cOp := "="
         IF Len( cNm ) > 0 .AND. Right( cNm, 1 ) == "="
            cNm := MkTrim( Left( cNm, Len( cNm ) - 1 ) )
            IF Len( cNm ) > 0 .AND. Right( cNm, 1 ) == ":"
               cNm := MkTrim( Left( cNm, Len( cNm ) - 1 ) )
               cOp := ":="
            ENDIF
         ENDIF
         cBody := ""
         DO WHILE ReadLogical( hF, @cL, @lRecipe )
            IF MkTrim( cL ) == "endef"
               EXIT
            ENDIF
            IF ! cBody == ""
               cBody += Chr( 10 )
            ENDIF
            cBody += cL
         ENDDO
         IF cOp == ":="
            SetVar( Expand( cNm, 0 ), Expand( cBody, 0 ), .T., ORG_FILE )
         ELSE
            SetVar( Expand( cNm, 0 ), cBody, .F., ORG_FILE )
         ENDIF
         LOOP
      ENDIF

      nOrg := ORG_FILE
      IF cDir == "override"
         nOrg := ORG_OVERRIDE
         cT := cRest
      ELSEIF cDir == "export"
         cT := cRest
      ENDIF
      cOp := ""
      nK := Classify( cT, @nP1, @nOpLen, @cOp )
      IF nK == 0 .AND. cDir == "export"
         /* export VAR1 VAR2 ... */
         cRest := Expand( cRest, 0 )
         nI := 1
         DO WHILE NextWord( cRest, @nI, @cW )
            s_hExport[ cW ] := .T.
         ENDDO
         LOOP
      ENDIF
      DO CASE
      CASE nK == 1
         FlushRecipe()
         s_aCurRules := {}
         DoAssign( cT, nP1, nOpLen, cOp, nOrg )
         IF cDir == "export"
            s_hExport[ MkTrim( Expand( Left( cT, nP1 - 1 ), 0 ) ) ] := .T.
         ENDIF
      CASE nK == 2
         DoRule( cT, nP1 )
      OTHERWISE
         Warn( s_cCurFile + ":" + IntStr( s_nLineNo ) + ": *** missing separator.  Stop." )
         MkHalt( 2 )
      ENDCASE
   ENDDO
   FlushRecipe()
   IF s_nIfTop > nBase
      Die( s_cCurFile + ": missing 'endif'.  Stop." )
   ENDIF
   s_cCurFile := cSaveFile
   s_nLineNo := nSaveLine

   RETURN

/* ------------------------- Moteur de production ------------------------- */

STATIC FUNCTION FindBuilt( cT AS STRING ) /* AS NUMERIC */

   LOCAL nI AS NUMERIC

   FOR nI := 1 TO Len( s_aBuilt )
      IF s_aBuilt[ nI ][ "name" ] == cT
         RETURN nI
      ENDIF
   NEXT

   RETURN 0

STATIC FUNCTION IsAssumeOld( cT AS STRING ) /* AS LOGICAL */
   RETURN AScan( s_aAssumeOld, {| c | c == cT } ) > 0

STATIC FUNCTION IsAssumeNew( cT AS STRING ) /* AS LOGICAL */
   RETURN AScan( s_aAssumeNew, {| c | c == cT } ) > 0

STATIC FUNCTION FindImplicit( cT AS STRING, nD AS NUMERIC, nRi AS NUMERIC, cStem AS STRING ) /* AS LOGICAL */

   LOCAL nPass AS NUMERIC
   LOCAL nI AS NUMERIC
   LOCAL nP AS NUMERIC
   LOCAL lOk AS LOGICAL
   LOCAL cPr AS STRING
   LOCAL cW2 AS STRING

   /* passe 0 : regles du makefile ; passe 1 : regles predefinies */
   FOR nPass := 0 TO 1
      FOR nI := 1 TO Len( s_aRules )
         IF s_aRules[ nI ][ "ispat" ] .AND. s_aRules[ nI ][ "builtin" ] == ( nPass == 1 ) .AND. s_aRules[ nI ][ "ccnt" ] > 0
            IF PatMatch( s_aRules[ nI ][ "targ" ], cT, @cStem )
               lOk := .T.
               nP := 1
               DO WHILE lOk .AND. NextWord( s_aRules[ nI ][ "pre" ], @nP, @cPr )
                  cW2 := ReplaceStem( cPr, cStem )
                  IF ! cW2 == cT .AND. ! CanMake( cW2, nD - 1 )
                     lOk := .F.
                  ENDIF
                  IF cW2 == cT
                     lOk := .F.
                  ENDIF
               ENDDO
               IF lOk
                  nRi := nI
                  RETURN .T.
               ENDIF
            ENDIF
         ENDIF
      NEXT
   NEXT

   RETURN .F.

STATIC FUNCTION CanMake( cW AS STRING, nD AS NUMERIC ) /* AS LOGICAL */

   LOCAL nRi AS NUMERIC
   LOCAL cStem AS STRING

   nRi := 0
   cStem := ""
   IF FileTime( cW ) > 0
      RETURN .T.
   ENDIF
   IF IsPhony( cW )
      RETURN .T.
   ENDIF
   IF FindExplicit( cW ) > 0
      RETURN .T.
   ENDIF
   IF nD > 0 .AND. FindImplicit( cW, nD, @nRi, @cStem )
      RETURN .T.
   ENDIF

   RETURN .F.

/* Publie les variables exportees dans l'environnement des commandes (hb_SetEnv) */
STATIC PROCEDURE ExportEnv()

   LOCAL hV AS HASH
   LOCAL cName AS STRING
   LOCAL nI AS NUMERIC
   LOCAL lOk AS LOGICAL

   FOR EACH hV IN s_aVars
      cName := hV[ "name" ]
      IF cName == "MAKELEVEL" .OR. ;
            ! ( s_lExportAll .AND. hV[ "org" ] != ORG_DEFAULT .OR. hb_HHasKey( s_hExport, cName ) )
         LOOP
      ENDIF
      /* nom valide : lettres, chiffres, _ */
      lOk := Len( cName ) > 0
      FOR nI := 1 TO Len( cName )
         IF ! InSet( SubStr( cName, nI, 1 ), "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789_" )
            lOk := .F.
            EXIT
         ENDIF
      NEXT
      IF lOk
         hb_SetEnv( cName, iif( hV[ "simple" ], hV[ "val" ], Expand( hV[ "val" ], 0 ) ) )
      ENDIF
   NEXT
   /* niveau de recursion pour les $(MAKE) enfants */
   nI := FindVar( "MAKELEVEL" )
   hb_SetEnv( "MAKELEVEL", hb_NToS( iif( nI > 0, Val( s_aVars[ nI ][ "val" ] ), 0 ) + 1 ) )

   RETURN

STATIC FUNCTION RunRecipe( cT AS STRING, nFirst AS NUMERIC, nCnt AS NUMERIC ) /* AS LOGICAL */

   LOCAL nI AS NUMERIC
   LOCAL nK AS NUMERIC
   LOCAL nP AS NUMERIC
   LOCAL nCode AS NUMERIC
   LOCAL cRaw AS STRING
   LOCAL cPart AS STRING
   LOCAL cCmd AS STRING
   LOCAL cExp AS STRING
   LOCAL lSilent AS LOGICAL
   LOCAL lIgn AS LOGICAL
   LOCAL lForce AS LOGICAL

   IF ! s_lDry
      ExportEnv()
   ENDIF
   FOR nI := nFirst TO nFirst + nCnt - 1
      cRaw := s_aCmds[ nI ]
      lForce := "$(MAKE)" $ cRaw .OR. "${MAKE}" $ cRaw
      cExp := Expand( cRaw, 0 )
      nK := 1
      DO WHILE nK <= Len( cExp )
         nP := nK
         DO WHILE nP <= Len( cExp ) .AND. ! SubStr( cExp, nP, 1 ) == Chr( 10 )
            nP++
         ENDDO
         cPart := SubStr( cExp, nK, nP - nK )
         nK := nP + 1
         cCmd := MkTrim( cPart )
         lSilent := s_lSilentAll .OR. s_lSilent
         lIgn := s_lIgnoreAll .OR. s_lIgnore
         DO WHILE Len( cCmd ) > 0 .AND. InSet( Left( cCmd, 1 ), "@-+ " + TAB )
            IF Left( cCmd, 1 ) == "@"
               lSilent := .T.
            ELSEIF Left( cCmd, 1 ) == "-"
               lIgn := .T.
            ELSEIF Left( cCmd, 1 ) == "+"
               lForce := .T.
            ENDIF
            cCmd := SubStr( cCmd, 2 )
         ENDDO
         IF cCmd == ""
            LOOP
         ENDIF
         IF ! lSilent .OR. ( s_lDry .AND. ! lForce )
            PutOut( cCmd )
         ENDIF
         IF s_lDry .AND. ! lForce
            LOOP
         ENDIF
         s_lDidRun := .T.
         nCode := RunCmd( cCmd )
         IF nCode != 0
            IF lIgn
               Warn( "[" + cT + "] Error " + IntStr( nCode ) + " (ignored)" )
            ELSE
               Warn( "*** [" + cT + "] Error " + IntStr( nCode ) )
               RETURN .F.
            ENDIF
         ENDIF
      ENDDO
   NEXT

   RETURN .T.

STATIC FUNCTION UpdateTarget( cT AS STRING, cParent AS STRING, nDepth AS NUMERIC ) /* AS LOGICAL */

   LOCAL nB AS NUMERIC
   LOCAL nRi AS NUMERIC
   LOCAL nIi AS NUMERIC
   LOCAL nP AS NUMERIC
   LOCAL nX AS NUMERIC
   LOCAL cPre AS STRING
   LOCAL cOrdP AS STRING
   LOCAL cPlus AS STRING
   LOCAL cAll AS STRING
   LOCAL cNewer AS STRING
   LOCAL cFirst AS STRING
   LOCAL cW AS STRING
   LOCAL cStem AS STRING
   LOCAL cImp AS STRING
   LOCAL nTTime AS NUMERIC
   LOCAL nNewest AS NUMERIC
   LOCAL nPTime AS NUMERIC
   LOCAL lNeed AS LOGICAL
   LOCAL lPreUpd AS LOGICAL
   LOCAL lFailed AS LOGICAL
   LOCAL lPhon AS LOGICAL
   LOCAL lHasCmd AS LOGICAL
   LOCAL nCFirst AS NUMERIC
   LOCAL nCCnt AS NUMERIC

   nB := FindBuilt( cT )
   IF nB > 0
      IF s_aBuilt[ nB ][ "state" ] == 1
         Warn( "Circular " + cParent + " <- " + cT + " dependency dropped." )
         RETURN .T.
      ENDIF
      RETURN ! s_aBuilt[ nB ][ "failed" ]
   ENDIF

   AAdd( s_aBuilt, { "name" => cT, "state" => 1, "time" => 0, "updated" => .F., "failed" => .F. } )
   nB := Len( s_aBuilt )

   lPhon := IsPhony( cT )
   nRi := FindExplicit( cT )
   cPre := ""
   cOrdP := ""
   nCFirst := 0
   nCCnt := 0
   cStem := ""
   nIi := 0
   IF nRi > 0
      cPre := s_aRules[ nRi ][ "pre" ]
      cOrdP := s_aRules[ nRi ][ "ordpre" ]
      nCFirst := s_aRules[ nRi ][ "cfirst" ]
      nCCnt := s_aRules[ nRi ][ "ccnt" ]
   ENDIF
   IF nCCnt == 0 .AND. ! lPhon
      IF FindImplicit( cT, 2, @nIi, @cStem )
         /* GNU make : le prerequis de la regle implicite passe en premier ($<) */
         cImp := ""
         nP := 1
         DO WHILE NextWord( s_aRules[ nIi ][ "pre" ], @nP, @cW )
            cImp += " " + ReplaceStem( cW, cStem )
         ENDDO
         cPre := MkTrim( cImp + " " + cPre )
         nCFirst := s_aRules[ nIi ][ "cfirst" ]
         nCCnt := s_aRules[ nIi ][ "ccnt" ]
         nRi := nIi
      ELSE
         cStem := ""
      ENDIF
   ENDIF

   IF nRi == 0
      /* cible sans regle */
      nRi := FindExplicit( ".DEFAULT" )
      IF nRi > 0 .AND. FileTime( cT ) == 0
         nCFirst := s_aRules[ nRi ][ "cfirst" ]
         nCCnt := s_aRules[ nRi ][ "ccnt" ]
      ELSEIF FileTime( cT ) > 0
         s_aBuilt[ nB ][ "state" ] := 2
         s_aBuilt[ nB ][ "time" ] := iif( IsAssumeNew( cT ), 1000000000000, FileTime( cT ) )   /* -W : fichier source repute modifie */
         RETURN .T.
      ELSE
         s_aBuilt[ nB ][ "state" ] := 2
         s_aBuilt[ nB ][ "failed" ] := .T.
         IF ! cParent == ""
            Warn( "*** No rule to make target '" + cT + "', needed by '" + cParent + "'.  Stop." )
         ELSE
            Warn( "*** No rule to make target '" + cT + "'.  Stop." )
         ENDIF
         s_lErrors := .T.
         IF ! s_lKeep
            MkHalt( 2 )
         ENDIF
         RETURN .F.
      ENDIF
   ENDIF
   lHasCmd := nCCnt > 0
   IF IsAssumeOld( cT )
      s_aBuilt[ nB ][ "state" ] := 2
      s_aBuilt[ nB ][ "time" ] := FileTime( cT )
      RETURN .T.
   ENDIF

   /* prerequis */
   lFailed := .F.
   lPreUpd := .F.
   nNewest := 0
   cFirst := ""
   cAll := ""
   cPlus := ""
   nP := 1
   DO WHILE NextWord( cPre, @nP, @cW )
      IF ! UpdateTarget( cW, cT, nDepth + 1 )
         lFailed := .T.
      ENDIF
      nX := FindBuilt( cW )
      IF nX > 0
         nPTime := s_aBuilt[ nX ][ "time" ]
         IF s_aBuilt[ nX ][ "updated" ]
            lPreUpd := .T.
         ENDIF
         IF nPTime > nNewest
            nNewest := nPTime
         ENDIF
      ENDIF
      IF cFirst == ""
         cFirst := cW
      ENDIF
      cPlus += " " + cW
      IF At( " " + cW + " ", " " + cAll + " " ) == 0
         cAll += " " + cW
      ENDIF
   ENDDO
   nP := 1
   DO WHILE NextWord( cOrdP, @nP, @cW )
      IF ! UpdateTarget( cW, cT, nDepth + 1 )
         lFailed := .T.
      ENDIF
   ENDDO
   IF lFailed
      s_aBuilt[ nB ][ "state" ] := 2
      s_aBuilt[ nB ][ "failed" ] := .T.
      Warn( "Target '" + cT + "' not remade because of errors." )
      RETURN .F.
   ENDIF

   IF IsAssumeNew( cT )
      nTTime := 1000000000000
   ELSE
      nTTime := FileTime( cT )
   ENDIF
   lNeed := lPhon .OR. s_lAlways .OR. nTTime == 0 .OR. nNewest > nTTime .OR. lPreUpd
   IF ! lNeed
      s_aBuilt[ nB ][ "state" ] := 2
      s_aBuilt[ nB ][ "time" ] := nTTime
      RETURN .T.
   ENDIF
   IF ! lHasCmd
      s_aBuilt[ nB ][ "state" ] := 2
      s_aBuilt[ nB ][ "updated" ] := lPreUpd .OR. ( lPhon .AND. ! Empty( cPre ) )
      IF nTTime > 0
         s_aBuilt[ nB ][ "time" ] := nTTime
      ELSE
         s_aBuilt[ nB ][ "time" ] := NowPacked()
      ENDIF
      IF s_aBuilt[ nB ][ "updated" ]
         s_lAnyRebuild := .T.
      ENDIF
      RETURN .T.
   ENDIF

   /* variables automatiques */
   cNewer := ""
   nP := 1
   DO WHILE NextWord( cPre, @nP, @cW )
      nX := FindBuilt( cW )
      IF nX > 0 .AND. ( nTTime == 0 .OR. s_aBuilt[ nX ][ "time" ] > nTTime .OR. s_aBuilt[ nX ][ "updated" ] )
         IF At( " " + cW + " ", " " + cNewer + " " ) == 0
            cNewer += " " + cW
         ENDIF
      ENDIF
   ENDDO
   s_cAutoTarget := cT
   s_cAutoFirst  := cFirst
   s_cAutoAll    := MkTrim( cAll )
   s_cAutoPlus   := MkTrim( cPlus )
   s_cAutoNewer  := MkTrim( cNewer )
   s_cAutoStem   := cStem
   s_lAnyRebuild := .T.

   IF s_lQuestion
      s_aBuilt[ nB ][ "state" ] := 2
      s_aBuilt[ nB ][ "updated" ] := .T.
      s_aBuilt[ nB ][ "time" ] := NowPacked()
      RETURN .T.
   ENDIF

   IF s_lTouch .AND. ! lPhon
      IF ! s_lSilent
         PutOut( "touch " + cT )
      ENDIF
      IF ! s_lDry
         TouchFile( cT )
      ENDIF
   ELSE
      IF ! RunRecipe( cT, nCFirst, nCCnt )
         s_aBuilt[ nB ][ "state" ] := 2
         s_aBuilt[ nB ][ "failed" ] := .T.
         s_lErrors := .T.
         IF ! s_lKeep
            MkHalt( 2 )
         ENDIF
         RETURN .F.
      ENDIF
   ENDIF
   s_aBuilt[ nB ][ "state" ] := 2
   s_aBuilt[ nB ][ "updated" ] := .T.
   nTTime := FileTime( cT )
   IF s_lDry .OR. nTTime == 0 .OR. lPhon
      nTTime := NowPacked()
   ENDIF
   s_aBuilt[ nB ][ "time" ] := nTTime

   RETURN .T.

/* ------------------------- Base de donnees et initialisation ------------------------- */

STATIC PROCEDURE PrintDb()

   LOCAL hV AS HASH
   LOCAL hR AS HASH
   LOCAL nJ AS NUMERIC
   LOCAL cS AS STRING

   PutOut( "# Variables" )
   PutOut( "" )
   FOR EACH hV IN s_aVars
      PutOut( "# " + OriginName( hV[ "org" ], "makefile" ) )
      PutOut( hV[ "name" ] + iif( hV[ "simple" ], " := ", " = " ) + hV[ "val" ] )
   NEXT
   PutOut( "" )
   PutOut( "# Implicit Rules" )
   FOR EACH hR IN s_aRules
      IF hR[ "ispat" ]
         PutOut( hR[ "targ" ] + ": " + hR[ "pre" ] )
         FOR nJ := hR[ "cfirst" ] TO hR[ "cfirst" ] + hR[ "ccnt" ] - 1
            PutOut( TAB + s_aCmds[ nJ ] )
         NEXT
      ENDIF
   NEXT
   PutOut( "" )
   PutOut( "# Files" )
   FOR EACH cS IN s_aPhony
      PutOut( ".PHONY: " + cS )
   NEXT
   FOR EACH hR IN s_aRules
      IF ! hR[ "ispat" ]
         cS := hR[ "targ" ] + ":"
         IF ! hR[ "pre" ] == ""
            cS += " " + hR[ "pre" ]
         ENDIF
         IF ! hR[ "ordpre" ] == ""
            cS += " | " + hR[ "ordpre" ]
         ENDIF
         PutOut( cS )
         FOR nJ := hR[ "cfirst" ] TO hR[ "cfirst" ] + hR[ "ccnt" ] - 1
            PutOut( TAB + s_aCmds[ nJ ] )
         NEXT
      ENDIF
   NEXT

   RETURN

STATIC PROCEDURE BuiltinRule( cT AS STRING, cPre AS STRING, cCmd AS STRING )

   LOCAL nIdx AS NUMERIC

   nIdx := AddRule( cT, cPre, "", .T., .T. )
   AAdd( s_aCmds, cCmd )
   s_aRules[ nIdx ][ "cfirst" ] := Len( s_aCmds )
   s_aRules[ nIdx ][ "ccnt" ] := 1

   RETURN

STATIC PROCEDURE ImportEnv()

   LOCAL cTmp AS STRING
   LOCAL cData AS STRING
   LOCAL cLine AS STRING
   LOCAL nEq AS NUMERIC

   /* Harbour ne sait pas enumerer l'environnement : on passe par "env" / "set" */
   cTmp := TmpName()
   RunCmd( iif( hb_ps() == "\", "set", "env" ) + ' > "' + cTmp + '"' )
   cData := hb_MemoRead( cTmp )
   FErase( cTmp )
   FOR EACH cLine IN hb_ATokens( StrTran( cData, Chr( 13 ), "" ), Chr( 10 ) )
      nEq := At( "=", cLine )
      IF nEq > 1
         s_hExport[ Left( cLine, nEq - 1 ) ] := .T.
         IF s_lEnvOver
            SetVar( Left( cLine, nEq - 1 ), SubStr( cLine, nEq + 1 ), .F., ORG_ENVOVER )
         ELSE
            SetVar( Left( cLine, nEq - 1 ), SubStr( cLine, nEq + 1 ), .F., ORG_ENV )
         ENDIF
      ENDIF
   NEXT

   RETURN

STATIC PROCEDURE InitBuiltins()

   LOCAL cS AS STRING
   LOCAL cShell AS STRING

   IF ! s_lNoVars
      SetVar( "CC", "cc", .F., ORG_DEFAULT )
      SetVar( "CXX", "g++", .F., ORG_DEFAULT )
      SetVar( "CPP", "$(CC) -E", .F., ORG_DEFAULT )
      SetVar( "AS", "as", .F., ORG_DEFAULT )
      SetVar( "AR", "ar", .F., ORG_DEFAULT )
      SetVar( "ARFLAGS", "rv", .F., ORG_DEFAULT )
      SetVar( "LD", "ld", .F., ORG_DEFAULT )
      SetVar( "RM", "rm -f", .F., ORG_DEFAULT )
      SetVar( "COMPILE.c", "$(CC) $(CFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -c", .F., ORG_DEFAULT )
      SetVar( "COMPILE.cc", "$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(TARGET_ARCH) -c", .F., ORG_DEFAULT )
      SetVar( "COMPILE.s", "$(AS) $(ASFLAGS) $(TARGET_MACH)", .F., ORG_DEFAULT )
      SetVar( "LINK.o", "$(CC) $(LDFLAGS) $(TARGET_ARCH)", .F., ORG_DEFAULT )
      SetVar( "LINK.c", "$(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(TARGET_ARCH)", .F., ORG_DEFAULT )
      SetVar( "OUTPUT_OPTION", "-o $@", .F., ORG_DEFAULT )
   ENDIF
   SetVar( "MAKE", s_cProgName, .F., ORG_DEFAULT )
   SetVar( "MAKELEVEL", hb_NToS( Int( Val( GetEnv( "MAKELEVEL" ) ) ) ), .F., ORG_DEFAULT )
   cS := hb_DirSepDel( hb_cwd() )
   SetVar( "CURDIR", cS, .T., ORG_DEFAULT )
   IF hb_ps() == "\"
      cShell := GetEnv( "COMSPEC" )
   ELSE
      cShell := "/bin/sh"
   ENDIF
   SetVar( "SHELL", cShell, .F., ORG_DEFAULT )

   IF ! s_lNoRules
      s_aSuffixes := {}
      AEval( { ".out", ".a", ".ln", ".o", ".c", ".cc", ".C", ".cpp", ".p", ".f", ;
         ".s", ".S", ".h", ".y", ".l" }, {| c | AddSuffix( c ) } )
      BuiltinRule( "%.o", "%.c",   "$(COMPILE.c) $(OUTPUT_OPTION) $<" )
      BuiltinRule( "%.o", "%.cc",  "$(COMPILE.cc) $(OUTPUT_OPTION) $<" )
      BuiltinRule( "%.o", "%.cpp", "$(COMPILE.cc) $(OUTPUT_OPTION) $<" )
      BuiltinRule( "%.o", "%.C",   "$(COMPILE.cc) $(OUTPUT_OPTION) $<" )
      BuiltinRule( "%.o", "%.s",   "$(COMPILE.s) -o $@ $<" )
      BuiltinRule( "%",   "%.o",   "$(LINK.o) $^ $(LOADLIBES) $(LDLIBS) -o $@" )
      BuiltinRule( "%",   "%.c",   "$(LINK.c) $^ $(LOADLIBES) $(LDLIBS) -o $@" )
   ENDIF

   /* variables d'environnement */
   ImportEnv()

   RETURN

/* ------------------------- Options ------------------------- */

STATIC FUNCTION LongToShort( cN AS STRING, cCh AS STRING ) /* AS LOGICAL */

   LOCAL aTab AS ARRAY
   LOCAL aE
   LOCAL nCnt AS NUMERIC
   LOCAL cFound AS STRING

   aTab := { ;
      { "always-make", "B" }, { "assume-new", "W" }, { "assume-old", "o" }, ;
      { "check-symlink-times", "L" }, { "debug", "d" }, { "directory", "C" }, ;
      { "dry-run", "n" }, { "environment-overrides", "e" }, { "file", "f" }, ;
      { "makefile", "f" }, { "ignore-errors", "i" }, { "include-dir", "I" }, ;
      { "jobs", "j" }, { "just-print", "n" }, { "keep-going", "k" }, ;
      { "load-average", "l" }, { "new-file", "W" }, { "no-builtin-rules", "r" }, ;
      { "no-builtin-variables", "R" }, { "no-keep-going", "S" }, { "old-file", "o" }, ;
      { "print-data-base", "p" }, { "print-directory", "w" }, { "question", "q" }, ;
      { "quiet", "s" }, { "recon", "n" }, { "silent", "s" }, { "stop", "S" }, ;
      { "touch", "t" }, { "version", "v" }, { "what-if", "W" }, ;
      { "warn-undefined-variables", "U" }, { "no-print-directory", "N" }, { "help", "h" } }

   nCnt := 0
   cFound := ""
   FOR EACH aE IN aTab
      IF aE[ 1 ] == cN
         cCh := aE[ 2 ]
         RETURN .T.
      ENDIF
      IF Len( cN ) > 0 .AND. Left( aE[ 1 ], Len( cN ) ) == cN
         nCnt++
         cFound := aE[ 2 ]
      ENDIF
   NEXT
   IF nCnt == 1
      cCh := cFound
      RETURN .T.
   ENDIF

   RETURN .F.

STATIC PROCEDURE ApplyOption( cCh AS STRING, cV AS STRING )

   SWITCH cCh
   CASE "B" ; s_lAlways := .T. ; EXIT
   CASE "W" ; AAdd( s_aAssumeNew, cV ) ; EXIT
   CASE "o" ; AAdd( s_aAssumeOld, cV ) ; EXIT
   CASE "L"
   CASE "b"
   CASE "m"
   CASE "j"
   CASE "l"
   CASE "z"
   CASE "y"
      EXIT
   CASE "d" ; s_lDebug := .T. ; EXIT
   CASE "C"
      IF DirChange( cV ) != 0
         Warn( "*** impossible de changer de repertoire: " + cV )
         MkHalt( 2 )
      ENDIF
      s_lDirChanged := .T.
      EXIT
   CASE "n" ; s_lDry := .T. ; EXIT
   CASE "e" ; s_lEnvOver := .T. ; EXIT
   CASE "f" ; AAdd( s_aMakeFiles, cV ) ; EXIT
   CASE "i" ; s_lIgnore := .T. ; EXIT
   CASE "I" ; AAdd( s_aIncDirs, cV ) ; EXIT
   CASE "k" ; s_lKeep := .T. ; EXIT
   CASE "r" ; s_lNoRules := .T. ; EXIT
   CASE "R"
      s_lNoVars := .T.
      s_lNoRules := .T.
      EXIT
   CASE "S" ; s_lKeep := .F. ; EXIT
   CASE "p" ; s_lPrintDb := .T. ; EXIT
   CASE "w" ; s_lPrintDir := .T. ; EXIT
   CASE "N" ; s_lNoPrintDir := .T. ; EXIT
   CASE "q" ; s_lQuestion := .T. ; EXIT
   CASE "s" ; s_lSilent := .T. ; EXIT
   CASE "t" ; s_lTouch := .T. ; EXIT
   CASE "v" ; s_lWantVersion := .T. ; EXIT
   CASE "U" ; s_lWarnUndef := .T. ; EXIT
   CASE "h" ; s_lWantHelp := .T. ; EXIT
   ENDSWITCH

   RETURN

STATIC FUNCTION AllDigits( cS AS STRING ) /* AS LOGICAL */

   LOCAL nI AS NUMERIC

   IF cS == ""
      RETURN .F.
   ENDIF
   FOR nI := 1 TO Len( cS )
      IF ! InSet( SubStr( cS, nI, 1 ), "0123456789." )
         RETURN .F.
      ENDIF
   NEXT

   RETURN .T.

STATIC PROCEDURE ParseArgs( aArgs AS ARRAY )

   LOCAL nI AS NUMERIC
   LOCAL nJ AS NUMERIC
   LOCAL nEq AS NUMERIC
   LOCAL cA AS STRING
   LOCAL cV AS STRING
   LOCAL cName AS STRING
   LOCAL cCh AS STRING

   cCh := ""
   nI := 1
   DO WHILE nI <= Len( aArgs )
      cA := aArgs[ nI ]
      DO CASE
      CASE cA == "/?"
         s_lWantHelp := .T.

      CASE Left( cA, 2 ) == "--"
         nEq := At( "=", cA )
         IF nEq > 0
            cName := SubStr( cA, 3, nEq - 3 )
            cV := SubStr( cA, nEq + 1 )
         ELSE
            cName := SubStr( cA, 3 )
            cV := ""
         ENDIF
         IF ! LongToShort( cName, @cCh )
            PutErr( "make: unrecognized option '" + cA + "'" )
            ShowUsage()
            MkHalt( 2 )
         ENDIF
         IF InSet( cCh, "fCIoW" ) .AND. nEq == 0
            nI++
            IF nI <= Len( aArgs )
               cV := aArgs[ nI ]
            ENDIF
         ENDIF
         ApplyOption( cCh, cV )

      CASE Left( cA, 2 ) == "+f"
         cV := SubStr( cA, 3 )
         IF cV == ""
            nI++
            IF nI <= Len( aArgs )
               cV := aArgs[ nI ]
            ENDIF
         ENDIF
         ApplyOption( "f", cV )

      CASE Len( cA ) > 1 .AND. Left( cA, 1 ) == "-"
         nJ := 2
         DO WHILE nJ <= Len( cA )
            cCh := SubStr( cA, nJ, 1 )
            nJ++
            IF InSet( cCh, "fCIoW" )
               cV := SubStr( cA, nJ )
               IF cV == ""
                  nI++
                  IF nI <= Len( aArgs )
                     cV := aArgs[ nI ]
                  ENDIF
               ENDIF
               ApplyOption( cCh, cV )
               nJ := Len( cA ) + 1
            ELSEIF InSet( cCh, "jl" )
               cV := SubStr( cA, nJ )
               IF cV == "" .AND. nI < Len( aArgs ) .AND. AllDigits( aArgs[ nI + 1 ] )
                  nI++
               ENDIF
               nJ := Len( cA ) + 1
            ELSEIF InSet( cCh, "BLbmdneikrRSpwqstvh" )
               ApplyOption( cCh, "" )
            ELSE
               PutErr( "make: invalid option -- '" + cCh + "'" )
               ShowUsage()
               MkHalt( 2 )
            ENDIF
         ENDDO

      CASE At( "=", cA ) > 1
         AAdd( s_aCmdVars, cA )

      OTHERWISE
         AAdd( s_aGoals, cA )
      ENDCASE
      nI++
   ENDDO

   RETURN
