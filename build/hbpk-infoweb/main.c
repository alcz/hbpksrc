/*
 * Harbour 3.2.0dev (r2510161334)
 * Generated C source from "main.prg"
 */

#include "hbvmpub.h"
#include "hbpcode.h"
#include "hbinit.h"
#include "hbxvm.h"


HB_FUNC( MAIN );
HB_FUNC_EXTERN( HB_DIREXISTS );
HB_FUNC_EXTERN( HB_DIRCREATE );
HB_FUNC_EXTERN( __PP_INIT );
HB_FUNC_EXTERN( QOUT );
HB_FUNC_STATIC( SCANDIRECTORY );
HB_FUNC_STATIC( BUILDREGISTRY );
HB_FUNC_STATIC( GENERATEINDEXPAGE );
HB_FUNC_STATIC( GENERATEPACKAGEPAGES );
HB_FUNC_EXTERN( DIRECTORY );
HB_FUNC_EXTERN( HB_PS );
HB_FUNC_EXTERN( FILE );
HB_FUNC_STATIC( PARSEMAKEFILE );
HB_FUNC_EXTERN( AADD );
HB_FUNC_EXTERN( MEMOREAD );
HB_FUNC_EXTERN( HB_ATOKENS );
HB_FUNC_EXTERN( HB_EOL );
HB_FUNC_STATIC( EVALUATEVARS );
HB_FUNC_STATIC( EXTRACTTARGETS );
HB_FUNC_EXTERN( HB_HASH );
HB_FUNC_STATIC( EXTRACTPLATFORMDEPS );
HB_FUNC_EXTERN( HB_HGETDEF );
HB_FUNC_EXTERN( ALLTRIM );
HB_FUNC_EXTERN( EMPTY );
HB_FUNC_EXTERN( __MVPRIVATE );
HB_FUNC_EXTERN( INITMAKEPRE );
HB_FUNC_STATIC( STRIPCOMMENT );
HB_FUNC_EXTERN( LEFT );
HB_FUNC_STATIC( GETFIRSTWORD );
HB_FUNC_EXTERN( SUBSTR );
HB_FUNC_EXTERN( LEN );
HB_FUNC_STATIC( EXPANDSHELLVARS2 );
HB_FUNC_STATIC( APPLYMAKEMACROS );
HB_FUNC_STATIC( ISCONDACTIVE );
HB_FUNC_STATIC( EVALCONDITION );
HB_FUNC_EXTERN( ATAIL );
HB_FUNC_EXTERN( ASIZE );
HB_FUNC_EXTERN( AT );
HB_FUNC_STATIC( EXPANDSHELLVARS );
HB_FUNC_STATIC( NORMALIZEPATH );
HB_FUNC_EXTERN( HB_FNAMEMERGE );
HB_FUNC_EXTERN( HB_FNAMEDIR );
HB_FUNC_EXTERN( HB_HCLEAR );
HB_FUNC_EXTERN( HB_STRSHRINK );
HB_FUNC_STATIC( CLASSIFYLINE );
HB_FUNC_EXTERN( UPPER );
HB_FUNC_EXTERN( HB_VALTOEXP );
HB_FUNC_STATIC( PARSECONDARGS );
HB_FUNC_EXTERN( STRTRAN );
HB_FUNC_EXTERN( HB_HHASKEY );
HB_FUNC_STATIC( RATPAREN );
HB_FUNC_STATIC( EXTRACTQUOTEDARG );
HB_FUNC_EXTERN( HB_AT );
HB_FUNC_EXTERN( ISLOWER );
HB_FUNC_EXTERN( __BREAKBLOCK );
HB_FUNC_EXTERN( __PP_PROCESS );
HB_FUNC_EXTERN( OCCURS );
HB_FUNC( PROCESSMACROS );
HB_FUNC_STATIC( REGISTERKEY );
HB_FUNC_STATIC( GETHEADER );
HB_FUNC_STATIC( DETECTFETCH );
HB_FUNC_STATIC( HB_HTMLENCODE );
HB_FUNC_EXTERN( LOWER );
HB_FUNC_EXTERN( HB_MEMOWRIT );
HB_FUNC_STATIC( GETFOOTER );
HB_FUNC_STATIC( VARSNOTSHOWN );
HB_FUNC_STATIC( COMPAREDEPS );
HB_FUNC_STATIC( RENDERDEPENDENCYLIST );
HB_FUNC_EXTERN( RIGHT );
HB_FUNC_EXTERN( ASCAN );
HB_FUNC( ARRAYTOSPACELIST );
HB_FUNC( SHE );
HB_FUNC_EXTERN( LTRIM );
HB_FUNC( RUNSIMULATEDSHELL );
HB_FUNC( SEDEMULATE );
HB_FUNC( GETMAKEVAR );
HB_FUNC_EXTERN( STUFF );
HB_FUNC_EXTERN( HB_MACROBLOCK );
HB_FUNC_EXTERN( VALTYPE );
HB_FUNC_EXTERN( STR );
HB_FUNC_EXTERN( DTOC );
HB_FUNC_EXTERN( HB_ISHASH );
HB_FUNC_STATIC( SEDAPPLYONE );
HB_FUNC_STATIC( SEDFINDDELIM );
HB_FUNC_STATIC( SEDUNESCAPE );
HB_FUNC_INITSTATICS();


HB_INIT_SYMBOLS_BEGIN( hb_vm_SymbolInit_MAIN )
{ "MAIN", {HB_FS_PUBLIC | HB_FS_FIRST | HB_FS_LOCAL}, {HB_FUNCNAME( MAIN )}, NULL },
{ "HB_DIREXISTS", {HB_FS_PUBLIC}, {HB_FUNCNAME( HB_DIREXISTS )}, NULL },
{ "HB_DIRCREATE", {HB_FS_PUBLIC}, {HB_FUNCNAME( HB_DIRCREATE )}, NULL },
{ "__PP_INIT", {HB_FS_PUBLIC}, {HB_FUNCNAME( __PP_INIT )}, NULL },
{ "QOUT", {HB_FS_PUBLIC}, {HB_FUNCNAME( QOUT )}, NULL },
{ "SCANDIRECTORY", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( SCANDIRECTORY )}, NULL },
{ "BUILDREGISTRY", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( BUILDREGISTRY )}, NULL },
{ "GENERATEINDEXPAGE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( GENERATEINDEXPAGE )}, NULL },
{ "GENERATEPACKAGEPAGES", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( GENERATEPACKAGEPAGES )}, NULL },
{ "DIRECTORY", {HB_FS_PUBLIC}, {HB_FUNCNAME( DIRECTORY )}, NULL },
{ "HB_PS", {HB_FS_PUBLIC}, {HB_FUNCNAME( HB_PS )}, NULL },
{ "FILE", {HB_FS_PUBLIC}, {HB_FUNCNAME( FILE )}, NULL },
{ "PARSEMAKEFILE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( PARSEMAKEFILE )}, NULL },
{ "AADD", {HB_FS_PUBLIC}, {HB_FUNCNAME( AADD )}, NULL },
{ "MEMOREAD", {HB_FS_PUBLIC}, {HB_FUNCNAME( MEMOREAD )}, NULL },
{ "HB_ATOKENS", {HB_FS_PUBLIC}, {HB_FUNCNAME( HB_ATOKENS )}, NULL },
{ "HB_EOL", {HB_FS_PUBLIC}, {HB_FUNCNAME( HB_EOL )}, NULL },
{ "EVALUATEVARS", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( EVALUATEVARS )}, NULL },
{ "EXTRACTTARGETS", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( EXTRACTTARGETS )}, NULL },
{ "HB_HASH", {HB_FS_PUBLIC}, {HB_FUNCNAME( HB_HASH )}, NULL },
{ "EXTRACTPLATFORMDEPS", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( EXTRACTPLATFORMDEPS )}, NULL },
{ "HB_HGETDEF", {HB_FS_PUBLIC}, {HB_FUNCNAME( HB_HGETDEF )}, NULL },
{ "ALLTRIM", {HB_FS_PUBLIC}, {HB_FUNCNAME( ALLTRIM )}, NULL },
{ "EMPTY", {HB_FS_PUBLIC}, {HB_FUNCNAME( EMPTY )}, NULL },
{ "P_PLATSHORT", {HB_FS_PUBLIC | HB_FS_MEMVAR}, {NULL}, NULL },
{ "__MVPRIVATE", {HB_FS_PUBLIC}, {HB_FUNCNAME( __MVPRIVATE )}, NULL },
{ "INITMAKEPRE", {HB_FS_PUBLIC}, {HB_FUNCNAME( INITMAKEPRE )}, NULL },
{ "STRIPCOMMENT", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( STRIPCOMMENT )}, NULL },
{ "LEFT", {HB_FS_PUBLIC}, {HB_FUNCNAME( LEFT )}, NULL },
{ "GETFIRSTWORD", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( GETFIRSTWORD )}, NULL },
{ "SUBSTR", {HB_FS_PUBLIC}, {HB_FUNCNAME( SUBSTR )}, NULL },
{ "LEN", {HB_FS_PUBLIC}, {HB_FUNCNAME( LEN )}, NULL },
{ "EXPANDSHELLVARS2", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( EXPANDSHELLVARS2 )}, NULL },
{ "APPLYMAKEMACROS", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( APPLYMAKEMACROS )}, NULL },
{ "ISCONDACTIVE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( ISCONDACTIVE )}, NULL },
{ "EVALCONDITION", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( EVALCONDITION )}, NULL },
{ "ATAIL", {HB_FS_PUBLIC}, {HB_FUNCNAME( ATAIL )}, NULL },
{ "ASIZE", {HB_FS_PUBLIC}, {HB_FUNCNAME( ASIZE )}, NULL },
{ "AT", {HB_FS_PUBLIC}, {HB_FUNCNAME( AT )}, NULL },
{ "EXPANDSHELLVARS", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( EXPANDSHELLVARS )}, NULL },
{ "NORMALIZEPATH", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( NORMALIZEPATH )}, NULL },
{ "HB_FNAMEMERGE", {HB_FS_PUBLIC}, {HB_FUNCNAME( HB_FNAMEMERGE )}, NULL },
{ "HB_FNAMEDIR", {HB_FS_PUBLIC}, {HB_FUNCNAME( HB_FNAMEDIR )}, NULL },
{ "HB_HCLEAR", {HB_FS_PUBLIC}, {HB_FUNCNAME( HB_HCLEAR )}, NULL },
{ "HB_STRSHRINK", {HB_FS_PUBLIC}, {HB_FUNCNAME( HB_STRSHRINK )}, NULL },
{ "CLASSIFYLINE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( CLASSIFYLINE )}, NULL },
{ "UPPER", {HB_FS_PUBLIC}, {HB_FUNCNAME( UPPER )}, NULL },
{ "HB_VALTOEXP", {HB_FS_PUBLIC}, {HB_FUNCNAME( HB_VALTOEXP )}, NULL },
{ "PARSECONDARGS", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( PARSECONDARGS )}, NULL },
{ "STRTRAN", {HB_FS_PUBLIC}, {HB_FUNCNAME( STRTRAN )}, NULL },
{ "HB_HHASKEY", {HB_FS_PUBLIC}, {HB_FUNCNAME( HB_HHASKEY )}, NULL },
{ "RATPAREN", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( RATPAREN )}, NULL },
{ "EXTRACTQUOTEDARG", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( EXTRACTQUOTEDARG )}, NULL },
{ "HB_AT", {HB_FS_PUBLIC}, {HB_FUNCNAME( HB_AT )}, NULL },
{ "ISLOWER", {HB_FS_PUBLIC}, {HB_FUNCNAME( ISLOWER )}, NULL },
{ "__BREAKBLOCK", {HB_FS_PUBLIC}, {HB_FUNCNAME( __BREAKBLOCK )}, NULL },
{ "__PP_PROCESS", {HB_FS_PUBLIC}, {HB_FUNCNAME( __PP_PROCESS )}, NULL },
{ "DESCRIPTION", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "OCCURS", {HB_FS_PUBLIC}, {HB_FUNCNAME( OCCURS )}, NULL },
{ "PROCESSMACROS", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( PROCESSMACROS )}, NULL },
{ "REGISTERKEY", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( REGISTERKEY )}, NULL },
{ "GETHEADER", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( GETHEADER )}, NULL },
{ "DETECTFETCH", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( DETECTFETCH )}, NULL },
{ "HB_HTMLENCODE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( HB_HTMLENCODE )}, NULL },
{ "LOWER", {HB_FS_PUBLIC}, {HB_FUNCNAME( LOWER )}, NULL },
{ "HB_MEMOWRIT", {HB_FS_PUBLIC}, {HB_FUNCNAME( HB_MEMOWRIT )}, NULL },
{ "GETFOOTER", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( GETFOOTER )}, NULL },
{ "VARSNOTSHOWN", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( VARSNOTSHOWN )}, NULL },
{ "COMPAREDEPS", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( COMPAREDEPS )}, NULL },
{ "RENDERDEPENDENCYLIST", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( RENDERDEPENDENCYLIST )}, NULL },
{ "__ENUMKEY", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "RIGHT", {HB_FS_PUBLIC}, {HB_FUNCNAME( RIGHT )}, NULL },
{ "ASCAN", {HB_FS_PUBLIC}, {HB_FUNCNAME( ASCAN )}, NULL },
{ "ARRAYTOSPACELIST", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( ARRAYTOSPACELIST )}, NULL },
{ "SHE", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( SHE )}, NULL },
{ "LTRIM", {HB_FS_PUBLIC}, {HB_FUNCNAME( LTRIM )}, NULL },
{ "RUNSIMULATEDSHELL", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( RUNSIMULATEDSHELL )}, NULL },
{ "P_PLATFORM", {HB_FS_PUBLIC | HB_FS_MEMVAR}, {NULL}, NULL },
{ "SEDEMULATE", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( SEDEMULATE )}, NULL },
{ "GETMAKEVAR", {HB_FS_PUBLIC | HB_FS_LOCAL}, {HB_FUNCNAME( GETMAKEVAR )}, NULL },
{ "STUFF", {HB_FS_PUBLIC}, {HB_FUNCNAME( STUFF )}, NULL },
{ "HB_MACROBLOCK", {HB_FS_PUBLIC}, {HB_FUNCNAME( HB_MACROBLOCK )}, NULL },
{ "EVAL", {HB_FS_PUBLIC | HB_FS_MESSAGE}, {NULL}, NULL },
{ "VALTYPE", {HB_FS_PUBLIC}, {HB_FUNCNAME( VALTYPE )}, NULL },
{ "STR", {HB_FS_PUBLIC}, {HB_FUNCNAME( STR )}, NULL },
{ "DTOC", {HB_FS_PUBLIC}, {HB_FUNCNAME( DTOC )}, NULL },
{ "HB_ISHASH", {HB_FS_PUBLIC}, {HB_FUNCNAME( HB_ISHASH )}, NULL },
{ "SEDAPPLYONE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( SEDAPPLYONE )}, NULL },
{ "SEDFINDDELIM", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( SEDFINDDELIM )}, NULL },
{ "SEDUNESCAPE", {HB_FS_STATIC | HB_FS_LOCAL}, {HB_FUNCNAME( SEDUNESCAPE )}, NULL },
{ "(_INITSTATICS00001)", {HB_FS_INITEXIT | HB_FS_LOCAL}, {hb_INITSTATICS}, NULL }
HB_INIT_SYMBOLS_EX_END( hb_vm_SymbolInit_MAIN, "main.prg", 0x0, 0x0003 )

#if defined( HB_PRAGMA_STARTUP )
   #pragma startup hb_vm_SymbolInit_MAIN
#elif defined( HB_DATASEG_STARTUP )
   #define HB_DATASEG_BODY    HB_DATASEG_FUNC( hb_vm_SymbolInit_MAIN )
   #include "hbiniseg.h"
#endif

HB_FUNC( MAIN )
{
   HB_BOOL fValue;
   do {
	hb_xvmFrame( 5, 0 );
	hb_xvmSetLine( 47 );
	hb_xvmPushStringConst( "build", 5 );
	hb_xvmPopLocal( 1 );
	hb_xvmSetLine( 48 );
	hb_xvmPushStringConst( "docs", 4 );
	hb_xvmPopLocal( 2 );
	hb_xvmSetLine( 49 );
	hb_xvmArrayGen( 0 );
	hb_xvmPopLocal( 3 );
	hb_xvmSetLine( 52 );
	hb_xvmPushFuncSymbol( symbols + 1 );
	hb_xvmPushLocal( 2 );
	if( hb_xvmFunction( 1 ) ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( fValue )
		goto lab00001;
	hb_xvmSetLine( 53 );
	hb_xvmPushFuncSymbol( symbols + 2 );
	hb_xvmPushLocal( 2 );
	if( hb_xvmDo( 1 ) ) break;
lab00001: ;
	hb_xvmSetLine( 56 );
	hb_xvmPushFuncSymbol( symbols + 3 );
	if( hb_xvmFunction( 0 ) ) break;
	hb_xvmPopLocal( 4 );
	hb_xvmSetLine( 59 );
	hb_xvmPushFuncSymbol( symbols + 4 );
	hb_xvmPushStringConst( "Scanning build directory...", 27 );
	if( hb_xvmDo( 1 ) ) break;
	hb_xvmSetLine( 60 );
	hb_xvmPushFuncSymbol( symbols + 5 );
	hb_xvmPushLocal( 1 );
	hb_xvmPushLocal( 4 );
	hb_xvmPushLocal( 3 );
	if( hb_xvmDo( 3 ) ) break;
	hb_xvmSetLine( 63 );
	hb_xvmPushFuncSymbol( symbols + 4 );
	hb_xvmPushStringConst( "Building Provider Registry...", 29 );
	if( hb_xvmDo( 1 ) ) break;
	hb_xvmSetLine( 64 );
	hb_xvmPushFuncSymbol( symbols + 6 );
	hb_xvmPushLocal( 3 );
	if( hb_xvmFunction( 1 ) ) break;
	hb_xvmPopLocal( 5 );
	hb_xvmSetLine( 67 );
	hb_xvmPushFuncSymbol( symbols + 4 );
	hb_xvmPushStringConst( "Generating HTML pages in ./docs ...", 35 );
	if( hb_xvmDo( 1 ) ) break;
	hb_xvmSetLine( 68 );
	hb_xvmPushFuncSymbol( symbols + 7 );
	hb_xvmPushLocal( 3 );
	hb_xvmPushLocal( 2 );
	if( hb_xvmDo( 2 ) ) break;
	hb_xvmSetLine( 69 );
	hb_xvmPushFuncSymbol( symbols + 8 );
	hb_xvmPushLocal( 3 );
	hb_xvmPushLocal( 5 );
	hb_xvmPushLocal( 2 );
	if( hb_xvmDo( 3 ) ) break;
	hb_xvmSetLine( 71 );
	hb_xvmPushFuncSymbol( symbols + 4 );
	hb_xvmPushStringConst( "Done! Open ./docs/index.html to view.", 37 );
	if( hb_xvmDo( 1 ) ) break;
	hb_xvmSetLine( 72 );
	/* *** END PROC *** */
   } while( 0 );
}

HB_FUNC_STATIC( SCANDIRECTORY )
{
   HB_BOOL fValue;
   do {
	hb_xvmFrame( 5, 3 );
	hb_xvmSetLine( 75 );
	hb_xvmPushFuncSymbol( symbols + 9 );
	hb_xvmPushLocal( 1 );
	hb_xvmPushFuncSymbol( symbols + 10 );
	if( hb_xvmFunction( 0 ) ) break;
	if( hb_xvmPlus() ) break;
	hb_xvmPushStringConst( "*", 1 );
	if( hb_xvmPlus() ) break;
	hb_xvmPushStringConst( "D", 1 );
	if( hb_xvmFunction( 2 ) ) break;
	hb_xvmPopLocal( 4 );
	hb_xvmSetLine( 78 );
	hb_xvmPushLocal( 4 );
	hb_xvmPushLocalByRef( 5 );
	if( hb_xvmEnumStart( 1, 1 ) ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00004;
lab00001: ;
	hb_xvmSetLine( 79 );
	hb_xvmPushLocal( 5 );
	if( hb_xvmArrayItemPush( 1L ) ) break;
	hb_xvmPushStringConst( ".", 1 );
	if( hb_xvmExactlyEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( fValue )
		goto lab00003;
	hb_xvmPushLocal( 5 );
	if( hb_xvmArrayItemPush( 1L ) ) break;
	hb_xvmPushStringConst( "..", 2 );
	if( hb_xvmExactlyEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( fValue )
		goto lab00003;
	hb_xvmSetLine( 80 );
	hb_xvmPushLocal( 1 );
	hb_xvmPushFuncSymbol( symbols + 10 );
	if( hb_xvmFunction( 0 ) ) break;
	if( hb_xvmPlus() ) break;
	hb_xvmPushLocal( 5 );
	if( hb_xvmArrayItemPush( 1L ) ) break;
	hb_xvmLocalAdd( 6 );
	hb_xvmSetLine( 81 );
	hb_xvmPushStringConst( "D", 1 );
	hb_xvmPushLocal( 5 );
	if( hb_xvmArrayItemPush( 5L ) ) break;
	if( hb_xvmInstring() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00003;
	hb_xvmSetLine( 82 );
	hb_xvmPushLocal( 5 );
	if( hb_xvmArrayItemPush( 1L ) ) break;
	hb_xvmPopLocal( 7 );
	hb_xvmSetLine( 83 );
	hb_xvmPushFuncSymbol( symbols + 11 );
	hb_xvmPushLocal( 6 );
	hb_xvmPushFuncSymbol( symbols + 10 );
	if( hb_xvmFunction( 0 ) ) break;
	if( hb_xvmPlus() ) break;
	hb_xvmPushStringConst( "Makefile", 8 );
	if( hb_xvmPlus() ) break;
	if( hb_xvmFunction( 1 ) ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00002;
	hb_xvmSetLine( 84 );
	hb_xvmPushFuncSymbol( symbols + 12 );
	hb_xvmPushLocal( 6 );
	hb_xvmPushLocal( 7 );
	hb_xvmPushLocal( 2 );
	if( hb_xvmFunction( 3 ) ) break;
	hb_xvmPopLocal( 8 );
	hb_xvmSetLine( 85 );
	hb_xvmPushFuncSymbol( symbols + 13 );
	hb_xvmPushLocal( 3 );
	hb_xvmPushLocal( 8 );
	if( hb_xvmDo( 2 ) ) break;
lab00002: ;
	hb_xvmSetLine( 87 );
	hb_xvmPushFuncSymbol( symbols + 5 );
	hb_xvmPushLocal( 6 );
	hb_xvmPushLocal( 2 );
	hb_xvmPushLocal( 3 );
	if( hb_xvmDo( 3 ) ) break;
lab00003: ;
	hb_xvmSetLine( 90 );
	if( hb_xvmEnumNext() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( fValue )
		goto lab00001;
lab00004: ;
	hb_xvmEnumEnd();
	hb_xvmSetLine( 91 );
	/* *** END PROC *** */
   } while( 0 );
}

HB_FUNC_STATIC( PARSEMAKEFILE )
{
   HB_BOOL fValue;
   do {
	hb_xvmFrame( 13, 3 );
	hb_xvmSetLine( 94 );
	hb_xvmPushLocal( 1 );
	hb_xvmPushFuncSymbol( symbols + 10 );
	if( hb_xvmFunction( 0 ) ) break;
	if( hb_xvmPlus() ) break;
	hb_xvmPushStringConst( "Makefile", 8 );
	hb_xvmLocalAdd( 4 );
	hb_xvmSetLine( 95 );
	hb_xvmPushFuncSymbol( symbols + 14 );
	hb_xvmPushLocal( 4 );
	if( hb_xvmFunction( 1 ) ) break;
	hb_xvmPopLocal( 5 );
	hb_xvmSetLine( 96 );
	hb_xvmPushFuncSymbol( symbols + 15 );
	hb_xvmPushLocal( 5 );
	hb_xvmPushFuncSymbol( symbols + 16 );
	if( hb_xvmFunction( 0 ) ) break;
	if( hb_xvmFunction( 2 ) ) break;
	hb_xvmPopLocal( 6 );
	hb_xvmSetLine( 99 );
	hb_xvmArrayGen( 0 );
	hb_xvmPopLocal( 12 );
	hb_xvmArrayGen( 0 );
	hb_xvmPopLocal( 13 );
	hb_xvmSetLine( 105 );
	hb_xvmPushFuncSymbol( symbols + 17 );
	hb_xvmPushLocal( 6 );
	hb_xvmPushLocal( 3 );
	hb_xvmPushStringConst( "LINUX", 5 );
	hb_xvmPushLocal( 1 );
	hb_xvmPushNil();
	hb_xvmPushLocal( 12 );
	if( hb_xvmFunction( 6 ) ) break;
	hb_xvmPopLocal( 7 );
	hb_xvmSetLine( 106 );
	hb_xvmPushFuncSymbol( symbols + 17 );
	hb_xvmPushLocal( 6 );
	hb_xvmPushLocal( 3 );
	hb_xvmPushStringConst( "WIN", 3 );
	hb_xvmPushLocal( 1 );
	hb_xvmPushNil();
	hb_xvmPushLocal( 13 );
	if( hb_xvmFunction( 6 ) ) break;
	hb_xvmPopLocal( 8 );
	hb_xvmSetLine( 112 );
	hb_xvmPushFuncSymbol( symbols + 18 );
	hb_xvmPushLocal( 12 );
	hb_xvmPushLocal( 7 );
	if( hb_xvmFunction( 2 ) ) break;
	hb_xvmPopLocal( 10 );
	hb_xvmSetLine( 113 );
	hb_xvmPushFuncSymbol( symbols + 18 );
	hb_xvmPushLocal( 13 );
	hb_xvmPushLocal( 8 );
	if( hb_xvmFunction( 2 ) ) break;
	hb_xvmPopLocal( 11 );
	hb_xvmSetLine( 115 );
	hb_xvmPushFuncSymbol( symbols + 19 );
	if( hb_xvmFunction( 0 ) ) break;
	hb_xvmPopLocal( 9 );
	hb_xvmSetLine( 116 );
	hb_xvmPushLocal( 2 );
	hb_xvmPushLocal( 9 );
	hb_xvmPushStringConst( "DIR_NAME", 8 );
	if( hb_xvmArrayPop() ) break;
	hb_xvmSetLine( 117 );
	hb_xvmPushLocal( 1 );
	hb_xvmPushLocal( 9 );
	hb_xvmPushStringConst( "PATH", 4 );
	if( hb_xvmArrayPop() ) break;
	hb_xvmSetLine( 118 );
	hb_xvmPushLocal( 5 );
	hb_xvmPushLocal( 9 );
	hb_xvmPushStringConst( "RAW_SRC", 7 );
	if( hb_xvmArrayPop() ) break;
	hb_xvmSetLine( 119 );
	hb_xvmPushLocal( 7 );
	hb_xvmPushLocal( 9 );
	hb_xvmPushStringConst( "EVAL_LINUX", 10 );
	if( hb_xvmArrayPop() ) break;
	hb_xvmSetLine( 120 );
	hb_xvmPushLocal( 8 );
	hb_xvmPushLocal( 9 );
	hb_xvmPushStringConst( "EVAL_WIN", 8 );
	if( hb_xvmArrayPop() ) break;
	hb_xvmSetLine( 121 );
	hb_xvmPushLocal( 10 );
	hb_xvmPushLocal( 9 );
	hb_xvmPushStringConst( "TARGETS_LINUX", 13 );
	if( hb_xvmArrayPop() ) break;
	hb_xvmSetLine( 122 );
	hb_xvmPushLocal( 11 );
	hb_xvmPushLocal( 9 );
	hb_xvmPushStringConst( "TARGETS_WIN", 11 );
	if( hb_xvmArrayPop() ) break;
	hb_xvmSetLine( 125 );
	hb_xvmPushFuncSymbol( symbols + 20 );
	hb_xvmPushLocal( 7 );
	if( hb_xvmFunction( 1 ) ) break;
	hb_xvmPushLocal( 9 );
	hb_xvmPushStringConst( "DEPS_LINUX", 10 );
	if( hb_xvmArrayPop() ) break;
	hb_xvmSetLine( 126 );
	hb_xvmPushFuncSymbol( symbols + 20 );
	hb_xvmPushLocal( 8 );
	if( hb_xvmFunction( 1 ) ) break;
	hb_xvmPushLocal( 9 );
	hb_xvmPushStringConst( "DEPS_WIN", 8 );
	if( hb_xvmArrayPop() ) break;
	hb_xvmSetLine( 130 );
	hb_xvmPushFuncSymbol( symbols + 21 );
	hb_xvmPushLocal( 7 );
	hb_xvmPushStringConst( "DIR_NAME", 8 );
	hb_xvmPushFuncSymbol( symbols + 21 );
	hb_xvmPushLocal( 7 );
	hb_xvmPushStringConst( "NAME", 4 );
	hb_xvmPushLocal( 2 );
	if( hb_xvmFunction( 3 ) ) break;
	if( hb_xvmFunction( 3 ) ) break;
	hb_xvmPushLocal( 9 );
	hb_xvmPushStringConst( "CANONICAL", 9 );
	if( hb_xvmArrayPop() ) break;
	hb_xvmSetLine( 135 );
	hb_xvmPushFuncSymbol( symbols + 21 );
	hb_xvmPushLocal( 7 );
	hb_xvmPushStringConst( "PACKAGES", 8 );
	hb_xvmPushFuncSymbol( symbols + 21 );
	hb_xvmPushLocal( 7 );
	hb_xvmPushStringConst( "SUBDIRS", 7 );
	hb_xvmPushFuncSymbol( symbols + 21 );
	hb_xvmPushLocal( 7 );
	hb_xvmPushStringConst( "DIRS", 4 );
	hb_xvmPushStringConst( "", 0 );
	if( hb_xvmFunction( 3 ) ) break;
	if( hb_xvmFunction( 3 ) ) break;
	if( hb_xvmFunction( 3 ) ) break;
	hb_xvmPopLocal( 14 );
	hb_xvmSetLine( 137 );
	hb_xvmPushFuncSymbol( symbols + 15 );
	hb_xvmPushLocal( 14 );
	hb_xvmPushStringConst( " ", 1 );
	if( hb_xvmFunction( 2 ) ) break;
	hb_xvmPopLocal( 15 );
	hb_xvmSetLine( 138 );
	hb_xvmArrayGen( 0 );
	hb_xvmPushLocal( 9 );
	hb_xvmPushStringConst( "CHILDREN", 8 );
	if( hb_xvmArrayPop() ) break;
	hb_xvmSetLine( 139 );
	hb_xvmPushLocal( 15 );
	hb_xvmPushLocalByRef( 16 );
	if( hb_xvmEnumStart( 1, 1 ) ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00003;
lab00001: ;
	hb_xvmSetLine( 140 );
	hb_xvmPushFuncSymbol( symbols + 22 );
	hb_xvmPushLocal( 16 );
	if( hb_xvmFunction( 1 ) ) break;
	hb_xvmPopLocal( 16 );
	hb_xvmSetLine( 141 );
	hb_xvmPushFuncSymbol( symbols + 23 );
	hb_xvmPushLocal( 16 );
	if( hb_xvmFunction( 1 ) ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( fValue )
		goto lab00002;
	hb_xvmSetLine( 142 );
	hb_xvmPushFuncSymbol( symbols + 13 );
	hb_xvmPushLocal( 9 );
	hb_xvmPushStringConst( "CHILDREN", 8 );
	if( hb_xvmArrayPush() ) break;
	hb_xvmPushLocal( 16 );
	if( hb_xvmDo( 2 ) ) break;
lab00002: ;
	hb_xvmSetLine( 144 );
	if( hb_xvmEnumNext() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( fValue )
		goto lab00001;
lab00003: ;
	hb_xvmEnumEnd();
	hb_xvmSetLine( 145 );
	hb_xvmPushLocal( 9 );
	hb_xvmRetValue();
	/* *** END PROC *** */
   } while( 0 );
}

HB_FUNC_STATIC( EVALUATEVARS )
{
   HB_BOOL fValue;
   do {
	hb_xvmFrame( 20, 6 );
	hb_xvmSetLine( 150 );
	hb_xvmPushLogical( HB_FALSE );
	hb_xvmPopLocal( 17 );
	hb_xvmSetLine( 151 );
	hb_xvmArrayGen( 0 );
	hb_xvmPopLocal( 18 );
	hb_xvmSetLine( 157 );
	hb_xvmPushLocal( 3 );
	hb_xvmPushFuncSymbol( symbols + 25 );
	hb_xvmPushSymbol( symbols + 24 );
	if( hb_xvmDo( 1 ) ) break;
	if( hb_xvmPopMemvar( symbols + 24 ) ) break;
	hb_xvmSetLine( 159 );
	hb_xvmPushLocal( 5 );
	hb_xvmPushNil();
	if( hb_xvmExactlyEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00001;
	hb_xvmSetLine( 160 );
	hb_xvmPushFuncSymbol( symbols + 19 );
	if( hb_xvmFunction( 0 ) ) break;
	hb_xvmPopLocal( 5 );
	hb_xvmSetLine( 161 );
	hb_xvmPushStringConst( "/bin", 4 );
	hb_xvmPushLocal( 5 );
	hb_xvmPushStringConst( "PATH", 4 );
	if( hb_xvmArrayPop() ) break;
	hb_xvmSetLine( 162 );
	hb_xvmPushLocal( 3 );
	hb_xvmPushStringConst( "WIN", 3 );
	if( hb_xvmExactlyEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00001;
	hb_xvmSetLine( 163 );
	hb_xvmPushStringConst( "MINGW64", 7 );
	hb_xvmPushLocal( 5 );
	hb_xvmPushStringConst( "MSYSTEM", 7 );
	if( hb_xvmArrayPop() ) break;
lab00001: ;
	hb_xvmSetLine( 167 );
	hb_xvmPushLocal( 6 );
	hb_xvmPushNil();
	if( hb_xvmExactlyEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00002;
	hb_xvmSetLine( 168 );
	hb_xvmArrayGen( 0 );
	hb_xvmPopLocal( 6 );
lab00002: ;
	hb_xvmSetLine( 175 );
	hb_xvmPushFuncSymbol( symbols + 26 );
	if( hb_xvmFunction( 0 ) ) break;
	hb_xvmPopLocal( 12 );
	hb_xvmSetLine( 177 );
	hb_xvmPushLocal( 1 );
	hb_xvmPushLocalByRef( 7 );
	if( hb_xvmEnumStart( 1, 1 ) ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00030;
lab00003: ;
	hb_xvmSetLine( 178 );
	hb_xvmPushFuncSymbol( symbols + 22 );
	hb_xvmPushFuncSymbol( symbols + 27 );
	hb_xvmPushLocal( 7 );
	if( hb_xvmFunction( 1 ) ) break;
	if( hb_xvmFunction( 1 ) ) break;
	hb_xvmPopLocal( 8 );
	hb_xvmSetLine( 180 );
	hb_xvmPushFuncSymbol( symbols + 23 );
	hb_xvmPushLocal( 8 );
	if( hb_xvmFunction( 1 ) ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( fValue )
		goto lab00004;
	hb_xvmPushFuncSymbol( symbols + 28 );
	hb_xvmPushLocal( 8 );
	hb_xvmPushInteger( 1 );
	if( hb_xvmFunction( 2 ) ) break;
	hb_xvmPushStringConst( "#", 1 );
	if( hb_xvmExactlyEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00005;
lab00004: ;
	hb_xvmSetLine( 181 );
	goto lab00029;
lab00005: ;
	hb_xvmSetLine( 184 );
	hb_xvmPushFuncSymbol( symbols + 29 );
	hb_xvmPushLocal( 8 );
	if( hb_xvmFunction( 1 ) ) break;
	hb_xvmPopLocal( 19 );
	hb_xvmSetLine( 186 );
	hb_xvmPushLocal( 19 );
	hb_xvmPushStringConst( "DO-FETCH:", 9 );
	if( hb_xvmExactlyEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00006;
	hb_xvmSetLine( 187 );
	goto lab00030;
lab00006: ;
	hb_xvmSetLine( 192 );
	hb_xvmPushLocal( 19 );
	hb_xvmPushStringConst( "IFEQ", 4 );
	if( hb_xvmExactlyEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( fValue )
		goto lab00007;
	hb_xvmPushLocal( 19 );
	hb_xvmPushStringConst( "IFNEQ", 5 );
	if( hb_xvmExactlyEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( fValue )
		goto lab00007;
	hb_xvmPushLocal( 19 );
	hb_xvmPushStringConst( "IFDEF", 5 );
	if( hb_xvmExactlyEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( fValue )
		goto lab00007;
	hb_xvmPushLocal( 19 );
	hb_xvmPushStringConst( "IFNDEF", 6 );
	if( hb_xvmExactlyEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00009;
lab00007: ;
	hb_xvmSetLine( 194 );
	hb_xvmPushFuncSymbol( symbols + 22 );
	hb_xvmPushFuncSymbol( symbols + 30 );
	hb_xvmPushLocal( 8 );
	hb_xvmPushFuncSymbol( symbols + 31 );
	hb_xvmPushLocal( 19 );
	if( hb_xvmFunction( 1 ) ) break;
	if( hb_xvmAddInt( 1L ) ) break;
	if( hb_xvmFunction( 2 ) ) break;
	if( hb_xvmFunction( 1 ) ) break;
	hb_xvmPopLocal( 20 );
	hb_xvmSetLine( 195 );
	hb_xvmPushFuncSymbol( symbols + 32 );
	hb_xvmPushLocal( 20 );
	hb_xvmPushLocal( 5 );
	if( hb_xvmFunction( 2 ) ) break;
	hb_xvmPopLocal( 20 );
	hb_xvmSetLine( 196 );
	hb_xvmPushFuncSymbol( symbols + 33 );
	hb_xvmPushLocal( 20 );
	hb_xvmPushLocal( 12 );
	hb_xvmPushLogical( HB_TRUE );
	if( hb_xvmFunction( 3 ) ) break;
	hb_xvmPopLocal( 20 );
	hb_xvmSetLine( 197 );
	hb_xvmPushFuncSymbol( symbols + 34 );
	hb_xvmPushLocal( 18 );
	if( hb_xvmFunction( 1 ) ) break;
	hb_xvmPopLocal( 22 );
	hb_xvmSetLine( 198 );
	hb_xvmPushFuncSymbol( symbols + 35 );
	hb_xvmPushLocal( 19 );
	hb_xvmPushLocal( 20 );
	hb_xvmPushLocal( 5 );
	if( hb_xvmFunction( 3 ) ) break;
	hb_xvmPopLocal( 23 );
	hb_xvmSetLine( 200 );
	hb_xvmPushFuncSymbol( symbols + 19 );
	if( hb_xvmFunction( 0 ) ) break;
	hb_xvmPopLocal( 21 );
	hb_xvmSetLine( 201 );
	hb_xvmPushLocal( 22 );
	hb_xvmDuplicate();
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00008;
	hb_stackPop();
	hb_xvmPushLocal( 23 );
lab00008: ;
	hb_xvmPushLocal( 21 );
	hb_xvmPushStringConst( "ACTIVE", 6 );
	if( hb_xvmArrayPop() ) break;
	hb_xvmSetLine( 202 );
	hb_xvmPushLocal( 23 );
	hb_xvmPushLocal( 21 );
	hb_xvmPushStringConst( "TAKEN", 5 );
	if( hb_xvmArrayPop() ) break;
	hb_xvmSetLine( 203 );
	hb_xvmPushLocal( 22 );
	hb_xvmPushLocal( 21 );
	hb_xvmPushStringConst( "PARENT_ACTIVE", 13 );
	if( hb_xvmArrayPop() ) break;
	hb_xvmSetLine( 205 );
	hb_xvmPushFuncSymbol( symbols + 13 );
	hb_xvmPushLocal( 18 );
	hb_xvmPushLocal( 21 );
	if( hb_xvmDo( 2 ) ) break;
	hb_xvmSetLine( 206 );
	goto lab00029;
lab00009: ;
	hb_xvmSetLine( 208 );
	hb_xvmPushLocal( 19 );
	hb_xvmPushStringConst( "ELSE", 4 );
	if( hb_xvmExactlyEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00016;
	hb_xvmSetLine( 210 );
	hb_xvmPushFuncSymbol( symbols + 31 );
	hb_xvmPushLocal( 18 );
	if( hb_xvmFunction( 1 ) ) break;
	if( hb_xvmGreaterThenIntIs( 0L, &fValue ) ) break;
	if( !fValue )
		goto lab00015;
	hb_xvmSetLine( 211 );
	hb_xvmPushFuncSymbol( symbols + 36 );
	hb_xvmPushLocal( 18 );
	if( hb_xvmFunction( 1 ) ) break;
	hb_xvmPopLocal( 21 );
	hb_xvmSetLine( 212 );
	hb_xvmPushFuncSymbol( symbols + 22 );
	hb_xvmPushFuncSymbol( symbols + 30 );
	hb_xvmPushLocal( 8 );
	hb_xvmPushFuncSymbol( symbols + 31 );
	hb_xvmPushLocal( 19 );
	if( hb_xvmFunction( 1 ) ) break;
	if( hb_xvmAddInt( 1L ) ) break;
	if( hb_xvmFunction( 2 ) ) break;
	if( hb_xvmFunction( 1 ) ) break;
	hb_xvmPopLocal( 20 );
	hb_xvmSetLine( 214 );
	hb_xvmPushFuncSymbol( symbols + 23 );
	hb_xvmPushLocal( 20 );
	if( hb_xvmFunction( 1 ) ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( fValue )
		goto lab00013;
	hb_xvmSetLine( 216 );
	hb_xvmPushFuncSymbol( symbols + 29 );
	hb_xvmPushLocal( 20 );
	if( hb_xvmFunction( 1 ) ) break;
	hb_xvmPopLocal( 24 );
	hb_xvmSetLine( 217 );
	hb_xvmPushFuncSymbol( symbols + 22 );
	hb_xvmPushFuncSymbol( symbols + 30 );
	hb_xvmPushLocal( 20 );
	hb_xvmPushFuncSymbol( symbols + 31 );
	hb_xvmPushLocal( 24 );
	if( hb_xvmFunction( 1 ) ) break;
	if( hb_xvmAddInt( 1L ) ) break;
	if( hb_xvmFunction( 2 ) ) break;
	if( hb_xvmFunction( 1 ) ) break;
	hb_xvmPopLocal( 25 );
	hb_xvmSetLine( 218 );
	hb_xvmPushFuncSymbol( symbols + 33 );
	hb_xvmPushLocal( 25 );
	hb_xvmPushLocal( 12 );
	if( hb_xvmFunction( 2 ) ) break;
	hb_xvmPopLocal( 25 );
	hb_xvmSetLine( 220 );
	hb_xvmPushLocal( 21 );
	hb_xvmPushStringConst( "TAKEN", 5 );
	if( hb_xvmArrayPush() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00010;
	hb_xvmSetLine( 221 );
	hb_xvmPushLogical( HB_FALSE );
	hb_xvmPushLocal( 21 );
	hb_xvmPushStringConst( "ACTIVE", 6 );
	if( hb_xvmArrayPop() ) break;
	goto lab00015;
lab00010: ;
	hb_xvmSetLine( 223 );
	hb_xvmPushFuncSymbol( symbols + 35 );
	hb_xvmPushLocal( 24 );
	hb_xvmPushLocal( 25 );
	hb_xvmPushLocal( 5 );
	if( hb_xvmFunction( 3 ) ) break;
	hb_xvmPopLocal( 23 );
	hb_xvmSetLine( 224 );
	hb_xvmPushLocal( 21 );
	hb_xvmPushStringConst( "PARENT_ACTIVE", 13 );
	if( hb_xvmArrayPush() ) break;
	hb_xvmDuplicate();
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00011;
	hb_stackPop();
	hb_xvmPushLocal( 23 );
lab00011: ;
	hb_xvmPushLocal( 21 );
	hb_xvmPushStringConst( "ACTIVE", 6 );
	if( hb_xvmArrayPop() ) break;
	hb_xvmSetLine( 225 );
	hb_xvmPushLocal( 21 );
	hb_xvmPushStringConst( "TAKEN", 5 );
	if( hb_xvmArrayPush() ) break;
	hb_xvmDuplicate();
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( fValue )
		goto lab00012;
	hb_stackPop();
	hb_xvmPushLocal( 21 );
	hb_xvmPushStringConst( "ACTIVE", 6 );
	if( hb_xvmArrayPush() ) break;
lab00012: ;
	hb_xvmPushLocal( 21 );
	hb_xvmPushStringConst( "TAKEN", 5 );
	if( hb_xvmArrayPop() ) break;
	goto lab00015;
lab00013: ;
	hb_xvmSetLine( 229 );
	hb_xvmPushLocal( 21 );
	hb_xvmPushStringConst( "TAKEN", 5 );
	if( hb_xvmArrayPush() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00014;
	hb_xvmSetLine( 230 );
	hb_xvmPushLogical( HB_FALSE );
	hb_xvmPushLocal( 21 );
	hb_xvmPushStringConst( "ACTIVE", 6 );
	if( hb_xvmArrayPop() ) break;
	goto lab00015;
lab00014: ;
	hb_xvmSetLine( 232 );
	hb_xvmPushLocal( 21 );
	hb_xvmPushStringConst( "PARENT_ACTIVE", 13 );
	if( hb_xvmArrayPush() ) break;
	hb_xvmPushLocal( 21 );
	hb_xvmPushStringConst( "ACTIVE", 6 );
	if( hb_xvmArrayPop() ) break;
	hb_xvmSetLine( 233 );
	hb_xvmPushLocal( 21 );
	hb_xvmPushStringConst( "ACTIVE", 6 );
	if( hb_xvmArrayPush() ) break;
	hb_xvmPushLocal( 21 );
	hb_xvmPushStringConst( "TAKEN", 5 );
	if( hb_xvmArrayPop() ) break;
lab00015: ;
	hb_xvmSetLine( 237 );
	goto lab00029;
lab00016: ;
	hb_xvmSetLine( 239 );
	hb_xvmPushLocal( 19 );
	hb_xvmPushStringConst( "ENDIF", 5 );
	if( hb_xvmExactlyEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00018;
	hb_xvmSetLine( 241 );
	hb_xvmPushFuncSymbol( symbols + 31 );
	hb_xvmPushLocal( 18 );
	if( hb_xvmFunction( 1 ) ) break;
	if( hb_xvmGreaterThenIntIs( 0L, &fValue ) ) break;
	if( !fValue )
		goto lab00017;
	hb_xvmSetLine( 242 );
	hb_xvmPushFuncSymbol( symbols + 37 );
	hb_xvmPushLocal( 18 );
	hb_xvmPushFuncSymbol( symbols + 31 );
	hb_xvmPushLocal( 18 );
	if( hb_xvmFunction( 1 ) ) break;
	if( hb_xvmAddInt( -1L ) ) break;
	if( hb_xvmDo( 2 ) ) break;
lab00017: ;
	hb_xvmSetLine( 244 );
	goto lab00029;
lab00018: ;
	hb_xvmSetLine( 250 );
	hb_xvmPushFuncSymbol( symbols + 34 );
	hb_xvmPushLocal( 18 );
	if( hb_xvmFunction( 1 ) ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( fValue )
		goto lab00019;
	hb_xvmSetLine( 251 );
	goto lab00029;
lab00019: ;
	hb_xvmSetLine( 255 );
	hb_xvmPushFuncSymbol( symbols + 28 );
	hb_xvmPushLocal( 8 );
	hb_xvmPushInteger( 8 );
	if( hb_xvmFunction( 2 ) ) break;
	hb_xvmPushStringConst( "include ", 8 );
	if( hb_xvmExactlyEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( fValue )
		goto lab00020;
	hb_xvmPushFuncSymbol( symbols + 28 );
	hb_xvmPushLocal( 8 );
	hb_xvmPushInteger( 9 );
	if( hb_xvmFunction( 2 ) ) break;
	hb_xvmPushStringConst( "-include ", 9 );
	if( hb_xvmExactlyEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00023;
lab00020: ;
	hb_xvmSetLine( 256 );
	hb_xvmPushFuncSymbol( symbols + 22 );
	hb_xvmPushFuncSymbol( symbols + 30 );
	hb_xvmPushLocal( 8 );
	hb_xvmPushFuncSymbol( symbols + 38 );
	hb_xvmPushStringConst( " ", 1 );
	hb_xvmPushLocal( 8 );
	if( hb_xvmFunction( 2 ) ) break;
	if( hb_xvmAddInt( 1L ) ) break;
	if( hb_xvmFunction( 2 ) ) break;
	if( hb_xvmFunction( 1 ) ) break;
	hb_xvmPopLocal( 13 );
	hb_xvmSetLine( 259 );
	hb_xvmPushFuncSymbol( symbols + 39 );
	hb_xvmPushLocal( 13 );
	hb_xvmPushLocal( 5 );
	if( hb_xvmFunction( 2 ) ) break;
	hb_xvmPopLocal( 13 );
	hb_xvmSetLine( 266 );
	hb_xvmPushFuncSymbol( symbols + 40 );
	hb_xvmPushLocal( 13 );
	if( hb_xvmFunction( 1 ) ) break;
	hb_xvmPopLocal( 13 );
	hb_xvmSetLine( 269 );
	hb_xvmPushFuncSymbol( symbols + 41 );
	hb_xvmPushLocal( 4 );
	hb_xvmPushLocal( 13 );
	if( hb_xvmFunction( 2 ) ) break;
	hb_xvmPopLocal( 14 );
	hb_xvmSetLine( 270 );
	hb_xvmPushFuncSymbol( symbols + 40 );
	hb_xvmPushLocal( 14 );
	if( hb_xvmFunction( 1 ) ) break;
	hb_xvmPopLocal( 14 );
	hb_xvmSetLine( 272 );
	hb_xvmPushFuncSymbol( symbols + 11 );
	hb_xvmPushLocal( 14 );
	if( hb_xvmFunction( 1 ) ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00021;
	hb_xvmSetLine( 273 );
	hb_xvmPushFuncSymbol( symbols + 14 );
	hb_xvmPushLocal( 14 );
	if( hb_xvmFunction( 1 ) ) break;
	hb_xvmPopLocal( 15 );
	hb_xvmSetLine( 274 );
	hb_xvmPushFuncSymbol( symbols + 15 );
	hb_xvmPushLocal( 15 );
	hb_xvmPushFuncSymbol( symbols + 16 );
	if( hb_xvmFunction( 0 ) ) break;
	if( hb_xvmFunction( 2 ) ) break;
	hb_xvmPopLocal( 16 );
	hb_xvmSetLine( 279 );
	hb_xvmPushFuncSymbol( symbols + 17 );
	hb_xvmPushLocal( 16 );
	hb_xvmPushLocal( 2 );
	hb_xvmPushLocal( 3 );
	hb_xvmPushFuncSymbol( symbols + 42 );
	hb_xvmPushLocal( 14 );
	if( hb_xvmFunction( 1 ) ) break;
	hb_xvmPushLocal( 5 );
	hb_xvmPushLocal( 6 );
	if( hb_xvmDo( 6 ) ) break;
	goto lab00022;
lab00021: ;
	hb_xvmSetLine( 280 );
	hb_xvmPushFuncSymbol( symbols + 28 );
	hb_xvmPushLocal( 8 );
	hb_xvmPushInteger( 8 );
	if( hb_xvmFunction( 2 ) ) break;
	hb_xvmPushStringConst( "include ", 8 );
	if( hb_xvmExactlyEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00022;
	hb_xvmSetLine( 282 );
	hb_xvmPushFuncSymbol( symbols + 4 );
	hb_xvmPushStringConst( "Warning: Included file not found:", 33 );
	hb_xvmPushLocal( 14 );
	if( hb_xvmDo( 2 ) ) break;
lab00022: ;
	hb_xvmSetLine( 285 );
	goto lab00029;
lab00023: ;
	hb_xvmSetLine( 288 );
	hb_xvmPushFuncSymbol( symbols + 28 );
	hb_xvmPushLocal( 8 );
	hb_xvmPushInteger( 8 );
	if( hb_xvmFunction( 2 ) ) break;
	hb_xvmPushStringConst( "$(error ", 8 );
	if( hb_xvmExactlyEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00024;
	hb_xvmSetLine( 289 );
	hb_xvmPushFuncSymbol( symbols + 43 );
	hb_xvmPushLocal( 5 );
	if( hb_xvmDo( 1 ) ) break;
	hb_xvmSetLine( 290 );
	hb_xvmPushFuncSymbol( symbols + 44 );
	hb_xvmPushLocal( 8 );
	if( hb_xvmFunction( 1 ) ) break;
	hb_xvmPopLocal( 8 );
	hb_xvmSetLine( 291 );
	hb_xvmPushFuncSymbol( symbols + 30 );
	hb_xvmPushLocal( 8 );
	hb_xvmPushInteger( 9 );
	if( hb_xvmFunction( 2 ) ) break;
	hb_xvmPushLocal( 5 );
	hb_xvmPushStringConst( "!!!ERROR!!!", 11 );
	if( hb_xvmArrayPop() ) break;
	hb_xvmSetLine( 292 );
	hb_xvmPushLocal( 5 );
	hb_xvmRetValue();
	/* *** END PROC *** */
	break;
lab00024: ;
	hb_xvmSetLine( 296 );
	hb_xvmPushFuncSymbol( symbols + 45 );
	hb_xvmPushLocal( 8 );
	if( hb_xvmFunction( 1 ) ) break;
	hb_xvmPopLocal( 26 );
	hb_xvmSetLine( 297 );
	hb_xvmPushLocal( 26 );
	if( hb_xvmArrayItemPush( 1L ) ) break;
	if( hb_xvmGreaterThenIntIs( 0L, &fValue ) ) break;
	if( !fValue )
		goto lab00025;
	hb_xvmSetLine( 298 );
	hb_xvmPushLogical( HB_TRUE );
	hb_xvmPopLocal( 17 );
lab00025: ;
	hb_xvmSetLine( 304 );
	hb_xvmPushLocal( 17 );
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( fValue )
		goto lab00026;
	hb_xvmSetLine( 305 );
	hb_xvmPushFuncSymbol( symbols + 22 );
	hb_xvmPushFuncSymbol( symbols + 33 );
	hb_xvmPushLocal( 8 );
	hb_xvmPushLocal( 12 );
	if( hb_xvmFunction( 2 ) ) break;
	if( hb_xvmFunction( 1 ) ) break;
	hb_xvmPopLocal( 8 );
lab00026: ;
	hb_xvmSetLine( 316 );
	hb_xvmPushFuncSymbol( symbols + 13 );
	hb_xvmPushLocal( 6 );
	hb_xvmPushLocal( 7 );
	if( hb_xvmDo( 2 ) ) break;
	hb_xvmSetLine( 319 );
	hb_xvmPushFuncSymbol( symbols + 28 );
	hb_xvmPushFuncSymbol( symbols + 46 );
	hb_xvmPushLocal( 8 );
	if( hb_xvmFunction( 1 ) ) break;
	hb_xvmPushInteger( 7 );
	if( hb_xvmFunction( 2 ) ) break;
	hb_xvmPushStringConst( "EXPORT ", 7 );
	if( hb_xvmExactlyEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00027;
	hb_xvmSetLine( 320 );
	hb_xvmPushFuncSymbol( symbols + 22 );
	hb_xvmPushFuncSymbol( symbols + 30 );
	hb_xvmPushLocal( 8 );
	hb_xvmPushInteger( 8 );
	if( hb_xvmFunction( 2 ) ) break;
	if( hb_xvmFunction( 1 ) ) break;
	hb_xvmPopLocal( 8 );
lab00027: ;
	hb_xvmSetLine( 324 );
	hb_xvmPushFuncSymbol( symbols + 45 );
	hb_xvmPushLocal( 8 );
	if( hb_xvmFunction( 1 ) ) break;
	hb_xvmPopLocal( 26 );
	hb_xvmSetLine( 325 );
	hb_xvmPushLocal( 26 );
	if( hb_xvmArrayItemPush( 2L ) ) break;
	if( hb_xvmGreaterThenIntIs( 0L, &fValue ) ) break;
	if( !fValue )
		goto lab00028;
	hb_xvmSetLine( 326 );
	hb_xvmPushFuncSymbol( symbols + 38 );
	hb_xvmPushStringConst( "=", 1 );
	hb_xvmPushLocal( 8 );
	if( hb_xvmFunction( 2 ) ) break;
	hb_xvmPopLocal( 9 );
	hb_xvmSetLine( 327 );
	hb_xvmPushFuncSymbol( symbols + 22 );
	hb_xvmPushFuncSymbol( symbols + 28 );
	hb_xvmPushLocal( 8 );
	hb_xvmPushLocal( 26 );
	if( hb_xvmArrayItemPush( 2L ) ) break;
	if( hb_xvmAddInt( -1L ) ) break;
	if( hb_xvmFunction( 2 ) ) break;
	if( hb_xvmFunction( 1 ) ) break;
	hb_xvmPopLocal( 10 );
	hb_xvmSetLine( 329 );
	hb_xvmPushFuncSymbol( symbols + 22 );
	hb_xvmPushFuncSymbol( symbols + 30 );
	hb_xvmPushLocal( 8 );
	hb_xvmPushLocal( 9 );
	if( hb_xvmAddInt( 1L ) ) break;
	if( hb_xvmFunction( 2 ) ) break;
	if( hb_xvmFunction( 1 ) ) break;
	hb_xvmPopLocal( 11 );
	hb_xvmSetLine( 330 );
	hb_xvmPushFuncSymbol( symbols + 39 );
	hb_xvmPushLocal( 11 );
	hb_xvmPushLocal( 5 );
	if( hb_xvmFunction( 2 ) ) break;
	hb_xvmPopLocal( 11 );
	hb_xvmSetLine( 332 );
	hb_xvmPushLocal( 11 );
	hb_xvmPushLocal( 5 );
	hb_xvmPushFuncSymbol( symbols + 46 );
	hb_xvmPushLocal( 10 );
	if( hb_xvmFunction( 1 ) ) break;
	if( hb_xvmArrayPop() ) break;
lab00028: ;
	hb_xvmSetLine( 334 );
lab00029: ;
	if( hb_xvmEnumNext() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( fValue )
		goto lab00003;
lab00030: ;
	hb_xvmEnumEnd();
	hb_xvmSetLine( 336 );
	hb_xvmPushFuncSymbol( symbols + 4 );
	hb_xvmPushFuncSymbol( symbols + 47 );
	hb_xvmPushLocal( 5 );
	if( hb_xvmFunction( 1 ) ) break;
	if( hb_xvmDo( 1 ) ) break;
	hb_xvmSetLine( 337 );
	hb_xvmPushLocal( 5 );
	hb_xvmRetValue();
	/* *** END PROC *** */
   } while( 0 );
}

HB_FUNC_STATIC( ISCONDACTIVE )
{
   HB_BOOL fValue;
   do {
	hb_xvmFrame( 2, 1 );
	hb_xvmSetLine( 344 );
	hb_xvmPushLogical( HB_TRUE );
	hb_xvmPopLocal( 2 );
	hb_xvmSetLine( 346 );
	hb_xvmPushLocal( 1 );
	hb_xvmPushLocalByRef( 3 );
	if( hb_xvmEnumStart( 1, 1 ) ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00003;
lab00001: ;
	hb_xvmSetLine( 347 );
	hb_xvmPushLocal( 2 );
	hb_xvmDuplicate();
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00002;
	hb_stackPop();
	hb_xvmPushLocal( 3 );
	hb_xvmPushStringConst( "ACTIVE", 6 );
	if( hb_xvmArrayPush() ) break;
lab00002: ;
	hb_xvmPopLocal( 2 );
	hb_xvmSetLine( 348 );
	if( hb_xvmEnumNext() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( fValue )
		goto lab00001;
lab00003: ;
	hb_xvmEnumEnd();
	hb_xvmSetLine( 350 );
	hb_xvmPushLocal( 2 );
	hb_xvmRetValue();
	/* *** END PROC *** */
   } while( 0 );
}

HB_FUNC_STATIC( EVALCONDITION )
{
   HB_BOOL fValue;
   do {
	hb_xvmFrame( 4, 3 );
	hb_xvmSetLine( 357 );
	hb_xvmPushLocal( 1 );
	hb_xvmPushStringConst( "IFEQ", 4 );
	if( hb_xvmExactlyEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( fValue )
		goto lab00001;
	hb_xvmPushLocal( 1 );
	hb_xvmPushStringConst( "IFNEQ", 5 );
	if( hb_xvmExactlyEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00002;
lab00001: ;
	hb_xvmSetLine( 358 );
	hb_xvmPushFuncSymbol( symbols + 48 );
	hb_xvmPushLocal( 2 );
	hb_xvmPushLocal( 3 );
	if( hb_xvmFunction( 2 ) ) break;
	hb_xvmPopLocal( 4 );
	hb_xvmSetLine( 359 );
	hb_xvmPushLocal( 4 );
	if( hb_xvmArrayItemPush( 1L ) ) break;
	hb_xvmPushLocal( 4 );
	if( hb_xvmArrayItemPush( 2L ) ) break;
	if( hb_xvmExactlyEqual() ) break;
	hb_xvmPopLocal( 5 );
	hb_xvmSetLine( 360 );
	hb_xvmPushLocal( 1 );
	hb_xvmPushStringConst( "IFNEQ", 5 );
	if( hb_xvmExactlyEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00006;
	hb_xvmSetLine( 361 );
	hb_xvmPushLocal( 5 );
	if( hb_xvmNot() ) break;
	hb_xvmPopLocal( 5 );
	goto lab00006;
lab00002: ;
	hb_xvmSetLine( 363 );
	hb_xvmPushLocal( 1 );
	hb_xvmPushStringConst( "IFDEF", 5 );
	if( hb_xvmExactlyEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( fValue )
		goto lab00003;
	hb_xvmPushLocal( 1 );
	hb_xvmPushStringConst( "IFNDEF", 6 );
	if( hb_xvmExactlyEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00005;
lab00003: ;
	hb_xvmSetLine( 364 );
	hb_xvmPushFuncSymbol( symbols + 46 );
	hb_xvmPushFuncSymbol( symbols + 22 );
	hb_xvmPushFuncSymbol( symbols + 49 );
	hb_xvmPushFuncSymbol( symbols + 49 );
	hb_xvmPushLocal( 2 );
	hb_xvmPushStringConst( "$(", 2 );
	hb_xvmPushStringConst( "", 0 );
	if( hb_xvmFunction( 3 ) ) break;
	hb_xvmPushStringConst( ")", 1 );
	hb_xvmPushStringConst( "", 0 );
	if( hb_xvmFunction( 3 ) ) break;
	if( hb_xvmFunction( 1 ) ) break;
	if( hb_xvmFunction( 1 ) ) break;
	hb_xvmPopLocal( 6 );
	hb_xvmSetLine( 365 );
	hb_xvmPushFuncSymbol( symbols + 50 );
	hb_xvmPushLocal( 3 );
	hb_xvmPushLocal( 6 );
	if( hb_xvmFunction( 2 ) ) break;
	hb_xvmDuplicate();
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00004;
	hb_stackPop();
	hb_xvmPushFuncSymbol( symbols + 23 );
	hb_xvmPushLocal( 3 );
	hb_xvmPushLocal( 6 );
	if( hb_xvmArrayPush() ) break;
	if( hb_xvmFunction( 1 ) ) break;
	if( hb_xvmNot() ) break;
lab00004: ;
	hb_xvmPopLocal( 7 );
	hb_xvmSetLine( 366 );
	hb_xvmCopyLocals( 7, 5 );
	hb_xvmSetLine( 367 );
	hb_xvmPushLocal( 1 );
	hb_xvmPushStringConst( "IFNDEF", 6 );
	if( hb_xvmExactlyEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00006;
	hb_xvmSetLine( 368 );
	hb_xvmPushLocal( 5 );
	if( hb_xvmNot() ) break;
	hb_xvmPopLocal( 5 );
	goto lab00006;
lab00005: ;
	hb_xvmSetLine( 373 );
	hb_xvmPushLogical( HB_FALSE );
	hb_xvmPopLocal( 5 );
lab00006: ;
	hb_xvmSetLine( 376 );
	hb_xvmPushLocal( 5 );
	hb_xvmRetValue();
	/* *** END PROC *** */
   } while( 0 );
}

HB_FUNC_STATIC( PARSECONDARGS )
{
   HB_BOOL fValue;
   do {
	hb_xvmFrame( 7, 2 );
	hb_xvmSetLine( 382 );
	hb_xvmPushStringConst( "", 0 );
	hb_xvmPopLocal( 3 );
	hb_xvmPushStringConst( "", 0 );
	hb_xvmPopLocal( 4 );
	hb_xvmSetLine( 385 );
	hb_xvmPushFuncSymbol( symbols + 28 );
	hb_xvmPushLocal( 1 );
	hb_xvmPushInteger( 1 );
	if( hb_xvmFunction( 2 ) ) break;
	hb_xvmPushStringConst( "(", 1 );
	if( hb_xvmExactlyEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00002;
	hb_xvmSetLine( 386 );
	hb_xvmPushFuncSymbol( symbols + 51 );
	hb_xvmPushLocal( 1 );
	if( hb_xvmFunction( 1 ) ) break;
	hb_xvmPopLocal( 7 );
	hb_xvmSetLine( 387 );
	hb_xvmPushLocal( 7 );
	if( hb_xvmGreaterThenIntIs( 0L, &fValue ) ) break;
	if( !fValue )
		goto lab00007;
	hb_xvmSetLine( 388 );
	hb_xvmPushFuncSymbol( symbols + 30 );
	hb_xvmPushLocal( 1 );
	hb_xvmPushInteger( 2 );
	hb_xvmPushLocal( 7 );
	if( hb_xvmAddInt( -2L ) ) break;
	if( hb_xvmFunction( 3 ) ) break;
	hb_xvmPopLocal( 5 );
	hb_xvmSetLine( 389 );
	hb_xvmPushFuncSymbol( symbols + 38 );
	hb_xvmPushStringConst( ",", 1 );
	hb_xvmPushLocal( 5 );
	if( hb_xvmFunction( 2 ) ) break;
	hb_xvmPopLocal( 6 );
	hb_xvmSetLine( 390 );
	hb_xvmPushLocal( 6 );
	if( hb_xvmGreaterThenIntIs( 0L, &fValue ) ) break;
	if( !fValue )
		goto lab00001;
	hb_xvmSetLine( 391 );
	hb_xvmPushFuncSymbol( symbols + 22 );
	hb_xvmPushFuncSymbol( symbols + 30 );
	hb_xvmPushLocal( 5 );
	hb_xvmPushInteger( 1 );
	hb_xvmPushLocal( 6 );
	if( hb_xvmAddInt( -1L ) ) break;
	if( hb_xvmFunction( 3 ) ) break;
	if( hb_xvmFunction( 1 ) ) break;
	hb_xvmPopLocal( 3 );
	hb_xvmSetLine( 392 );
	hb_xvmPushFuncSymbol( symbols + 22 );
	hb_xvmPushFuncSymbol( symbols + 30 );
	hb_xvmPushLocal( 5 );
	hb_xvmPushLocal( 6 );
	if( hb_xvmAddInt( 1L ) ) break;
	if( hb_xvmFunction( 2 ) ) break;
	if( hb_xvmFunction( 1 ) ) break;
	hb_xvmPopLocal( 4 );
	goto lab00007;
lab00001: ;
	hb_xvmSetLine( 394 );
	hb_xvmPushFuncSymbol( symbols + 22 );
	hb_xvmPushLocal( 5 );
	if( hb_xvmFunction( 1 ) ) break;
	hb_xvmPopLocal( 3 );
	goto lab00007;
lab00002: ;
	hb_xvmSetLine( 397 );
	hb_xvmPushFuncSymbol( symbols + 28 );
	hb_xvmPushLocal( 1 );
	hb_xvmPushInteger( 1 );
	if( hb_xvmFunction( 2 ) ) break;
	hb_xvmPushStringConst( "\"", 1 );
	if( hb_xvmExactlyEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( fValue )
		goto lab00003;
	hb_xvmPushFuncSymbol( symbols + 28 );
	hb_xvmPushLocal( 1 );
	hb_xvmPushInteger( 1 );
	if( hb_xvmFunction( 2 ) ) break;
	hb_xvmPushStringConst( "'", 1 );
	if( hb_xvmExactlyEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00005;
lab00003: ;
	hb_xvmSetLine( 398 );
	hb_xvmPushFuncSymbol( symbols + 28 );
	hb_xvmPushLocal( 1 );
	hb_xvmPushInteger( 1 );
	if( hb_xvmFunction( 2 ) ) break;
	hb_xvmPopLocal( 8 );
	hb_xvmSetLine( 399 );
	hb_xvmPushFuncSymbol( symbols + 52 );
	hb_xvmPushLocal( 1 );
	hb_xvmPushLocal( 8 );
	hb_xvmPushLocalByRef( 9 );
	if( hb_xvmFunction( 3 ) ) break;
	hb_xvmPopLocal( 3 );
	hb_xvmSetLine( 400 );
	hb_xvmPushFuncSymbol( symbols + 22 );
	hb_xvmPushLocal( 9 );
	if( hb_xvmFunction( 1 ) ) break;
	hb_xvmPopLocal( 9 );
	hb_xvmSetLine( 401 );
	hb_xvmPushFuncSymbol( symbols + 23 );
	hb_xvmPushLocal( 9 );
	if( hb_xvmFunction( 1 ) ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( fValue )
		goto lab00007;
	hb_xvmPushFuncSymbol( symbols + 28 );
	hb_xvmPushLocal( 9 );
	hb_xvmPushInteger( 1 );
	if( hb_xvmFunction( 2 ) ) break;
	hb_xvmPushStringConst( "\"", 1 );
	if( hb_xvmExactlyEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( fValue )
		goto lab00004;
	hb_xvmPushFuncSymbol( symbols + 28 );
	hb_xvmPushLocal( 9 );
	hb_xvmPushInteger( 1 );
	if( hb_xvmFunction( 2 ) ) break;
	hb_xvmPushStringConst( "'", 1 );
	if( hb_xvmExactlyEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00007;
lab00004: ;
	hb_xvmSetLine( 402 );
	hb_xvmPushFuncSymbol( symbols + 28 );
	hb_xvmPushLocal( 9 );
	hb_xvmPushInteger( 1 );
	if( hb_xvmFunction( 2 ) ) break;
	hb_xvmPopLocal( 8 );
	hb_xvmSetLine( 403 );
	hb_xvmPushFuncSymbol( symbols + 52 );
	hb_xvmPushLocal( 9 );
	hb_xvmPushLocal( 8 );
	hb_xvmPushLocalByRef( 9 );
	if( hb_xvmFunction( 3 ) ) break;
	hb_xvmPopLocal( 4 );
	goto lab00007;
lab00005: ;
	hb_xvmSetLine( 407 );
	hb_xvmPushFuncSymbol( symbols + 38 );
	hb_xvmPushStringConst( ",", 1 );
	hb_xvmPushLocal( 1 );
	if( hb_xvmFunction( 2 ) ) break;
	hb_xvmPopLocal( 6 );
	hb_xvmSetLine( 408 );
	hb_xvmPushLocal( 6 );
	if( hb_xvmGreaterThenIntIs( 0L, &fValue ) ) break;
	if( !fValue )
		goto lab00006;
	hb_xvmSetLine( 409 );
	hb_xvmPushFuncSymbol( symbols + 22 );
	hb_xvmPushFuncSymbol( symbols + 28 );
	hb_xvmPushLocal( 1 );
	hb_xvmPushLocal( 6 );
	if( hb_xvmAddInt( -1L ) ) break;
	if( hb_xvmFunction( 2 ) ) break;
	if( hb_xvmFunction( 1 ) ) break;
	hb_xvmPopLocal( 3 );
	hb_xvmSetLine( 410 );
	hb_xvmPushFuncSymbol( symbols + 22 );
	hb_xvmPushFuncSymbol( symbols + 30 );
	hb_xvmPushLocal( 1 );
	hb_xvmPushLocal( 6 );
	if( hb_xvmAddInt( 1L ) ) break;
	if( hb_xvmFunction( 2 ) ) break;
	if( hb_xvmFunction( 1 ) ) break;
	hb_xvmPopLocal( 4 );
	goto lab00007;
lab00006: ;
	hb_xvmSetLine( 412 );
	hb_xvmPushFuncSymbol( symbols + 22 );
	hb_xvmPushLocal( 1 );
	if( hb_xvmFunction( 1 ) ) break;
	hb_xvmPopLocal( 3 );
lab00007: ;
	hb_xvmSetLine( 416 );
	hb_xvmPushFuncSymbol( symbols + 39 );
	hb_xvmPushLocal( 3 );
	hb_xvmPushLocal( 2 );
	if( hb_xvmFunction( 2 ) ) break;
	hb_xvmPopLocal( 3 );
	hb_xvmSetLine( 417 );
	hb_xvmPushFuncSymbol( symbols + 39 );
	hb_xvmPushLocal( 4 );
	hb_xvmPushLocal( 2 );
	if( hb_xvmFunction( 2 ) ) break;
	hb_xvmPopLocal( 4 );
	hb_xvmSetLine( 419 );
	hb_xvmPushLocal( 3 );
	hb_xvmPushLocal( 4 );
	hb_xvmArrayGen( 2 );
	hb_xvmRetValue();
	/* *** END PROC *** */
   } while( 0 );
}

HB_FUNC_STATIC( RATPAREN )
{
   HB_BOOL fValue;
   do {
	hb_xvmFrame( 1, 1 );
	hb_xvmSetLine( 426 );
	hb_xvmPushFuncSymbol( symbols + 31 );
	hb_xvmPushLocal( 1 );
	if( hb_xvmFunction( 1 ) ) break;
	hb_xvmPushUnRef();
	hb_xvmPopLocal( 2 );
	goto lab00003;
lab00001: ;
	hb_xvmSetLine( 427 );
	hb_xvmPushFuncSymbol( symbols + 30 );
	hb_xvmPushLocal( 1 );
	hb_xvmPushLocal( 2 );
	hb_xvmPushInteger( 1 );
	if( hb_xvmFunction( 3 ) ) break;
	hb_xvmPushStringConst( ")", 1 );
	if( hb_xvmExactlyEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00002;
	hb_xvmSetLine( 428 );
	hb_xvmPushLocal( 2 );
	hb_xvmRetValue();
	/* *** END PROC *** */
	break;
lab00002: ;
	hb_xvmSetLine( 426 );
	if( hb_xvmLocalAddInt( 2, -1 ) ) break;
	hb_xvmPushLocal( 2 );
lab00003: ;
	if( hb_xvmLessThenIntIs( 1L, &fValue ) ) break;
	if( !fValue )
		goto lab00001;
	hb_xvmSetLine( 432 );
	hb_xvmRetInt( 0L );
	/* *** END PROC *** */
   } while( 0 );
}

HB_FUNC_STATIC( EXTRACTQUOTEDARG )
{
   HB_BOOL fValue;
   do {
	hb_xvmFrame( 3, 3 );
	hb_xvmSetLine( 437 );
	hb_xvmPushStringConst( "", 0 );
	hb_xvmPopLocal( 6 );
	hb_xvmSetLine( 439 );
	hb_xvmPushFuncSymbol( symbols + 38 );
	hb_xvmPushLocal( 2 );
	hb_xvmPushLocal( 1 );
	if( hb_xvmFunction( 2 ) ) break;
	hb_xvmPopLocal( 4 );
	hb_xvmSetLine( 440 );
	hb_xvmPushLocal( 4 );
	if( hb_xvmGreaterThenIntIs( 0L, &fValue ) ) break;
	if( !fValue )
		goto lab00002;
	hb_xvmSetLine( 441 );
	hb_xvmPushFuncSymbol( symbols + 38 );
	hb_xvmPushLocal( 2 );
	hb_xvmPushFuncSymbol( symbols + 30 );
	hb_xvmPushLocal( 1 );
	hb_xvmPushLocal( 4 );
	if( hb_xvmAddInt( 1L ) ) break;
	if( hb_xvmFunction( 2 ) ) break;
	if( hb_xvmFunction( 2 ) ) break;
	hb_xvmPopLocal( 5 );
	hb_xvmSetLine( 442 );
	hb_xvmPushLocal( 5 );
	if( hb_xvmGreaterThenIntIs( 0L, &fValue ) ) break;
	if( !fValue )
		goto lab00001;
	hb_xvmSetLine( 443 );
	hb_xvmPushFuncSymbol( symbols + 30 );
	hb_xvmPushLocal( 1 );
	hb_xvmPushLocal( 4 );
	if( hb_xvmAddInt( 1L ) ) break;
	hb_xvmPushLocal( 5 );
	if( hb_xvmAddInt( -1L ) ) break;
	if( hb_xvmFunction( 3 ) ) break;
	hb_xvmPopLocal( 6 );
	hb_xvmSetLine( 444 );
	hb_xvmPushFuncSymbol( symbols + 30 );
	hb_xvmPushLocal( 1 );
	hb_xvmPushLocal( 4 );
	hb_xvmPushLocal( 5 );
	if( hb_xvmPlus() ) break;
	if( hb_xvmAddInt( 1L ) ) break;
	if( hb_xvmFunction( 2 ) ) break;
	hb_xvmPopLocal( 3 );
	goto lab00003;
lab00001: ;
	hb_xvmSetLine( 446 );
	hb_xvmPushStringConst( "", 0 );
	hb_xvmPopLocal( 3 );
	goto lab00003;
lab00002: ;
	hb_xvmSetLine( 449 );
	hb_xvmCopyLocals( 1, 3 );
lab00003: ;
	hb_xvmSetLine( 452 );
	hb_xvmPushLocal( 6 );
	hb_xvmRetValue();
	/* *** END PROC *** */
   } while( 0 );
}

HB_FUNC_STATIC( NORMALIZEPATH )
{
   HB_BOOL fValue;
   do {
	hb_xvmFrame( 0, 1 );
	hb_xvmSetLine( 460 );
	hb_xvmPushFuncSymbol( symbols + 10 );
	if( hb_xvmFunction( 0 ) ) break;
	hb_xvmPushStringConst( "\\", 1 );
	if( hb_xvmExactlyEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00001;
	hb_xvmSetLine( 461 );
	hb_xvmPushFuncSymbol( symbols + 49 );
	hb_xvmPushLocal( 1 );
	hb_xvmPushStringConst( "/", 1 );
	hb_xvmPushStringConst( "\\", 1 );
	if( hb_xvmDo( 3 ) ) break;
	/* *** END PROC *** */
	break;
lab00001: ;
	hb_xvmSetLine( 463 );
	hb_xvmPushFuncSymbol( symbols + 49 );
	hb_xvmPushLocal( 1 );
	hb_xvmPushStringConst( "\\", 1 );
	hb_xvmPushStringConst( "/", 1 );
	if( hb_xvmDo( 3 ) ) break;
	/* *** END PROC *** */
   } while( 0 );
}

HB_FUNC_STATIC( STRIPCOMMENT )
{
   HB_BOOL fValue;
   do {
	hb_xvmFrame( 2, 1 );
	hb_xvmSetLine( 469 );
	hb_xvmLocalSetInt( 2, 1L );
	hb_xvmPushFuncSymbol( symbols + 31 );
	hb_xvmPushLocal( 1 );
	if( hb_xvmFunction( 1 ) ) break;
	hb_xvmPopLocal( 3 );
lab00001: ;
	hb_xvmSetLine( 471 );
	hb_xvmPushLocal( 2 );
	hb_xvmPushLocal( 3 );
	if( hb_xvmLessEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00004;
	hb_xvmSetLine( 472 );
	hb_xvmPushFuncSymbol( symbols + 30 );
	hb_xvmPushLocal( 1 );
	hb_xvmPushLocal( 2 );
	hb_xvmPushInteger( 1 );
	if( hb_xvmFunction( 3 ) ) break;
	hb_xvmPushStringConst( "#", 1 );
	if( hb_xvmExactlyEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00003;
	hb_xvmSetLine( 473 );
	hb_xvmPushLocal( 2 );
	if( hb_xvmEqualIntIs( 1L, &fValue ) ) break;
	if( fValue )
		goto lab00002;
	hb_xvmPushFuncSymbol( symbols + 30 );
	hb_xvmPushLocal( 1 );
	hb_xvmPushLocal( 2 );
	if( hb_xvmAddInt( -1L ) ) break;
	hb_xvmPushInteger( 1 );
	if( hb_xvmFunction( 3 ) ) break;
	hb_xvmPushStringConst( "\\", 1 );
	if( hb_xvmNotEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00003;
lab00002: ;
	hb_xvmSetLine( 474 );
	hb_xvmPushFuncSymbol( symbols + 28 );
	hb_xvmPushLocal( 1 );
	hb_xvmPushLocal( 2 );
	if( hb_xvmAddInt( -1L ) ) break;
	if( hb_xvmDo( 2 ) ) break;
	/* *** END PROC *** */
	break;
lab00003: ;
	hb_xvmSetLine( 477 );
	if( hb_xvmLocalInc( 2 ) ) break;
	goto lab00001;
lab00004: ;
	hb_xvmSetLine( 480 );
	hb_xvmPushLocal( 1 );
	hb_xvmRetValue();
	/* *** END PROC *** */
   } while( 0 );
}

HB_FUNC_STATIC( CLASSIFYLINE )
{
   HB_BOOL fValue;
   do {
	hb_xvmFrame( 5, 1 );
	hb_xvmSetLine( 492 );
	hb_xvmPushFuncSymbol( symbols + 38 );
	hb_xvmPushStringConst( "=", 1 );
	hb_xvmPushLocal( 1 );
	if( hb_xvmFunction( 2 ) ) break;
	hb_xvmPopLocal( 2 );
	hb_xvmSetLine( 493 );
	hb_xvmPushFuncSymbol( symbols + 38 );
	hb_xvmPushStringConst( ":", 1 );
	hb_xvmPushLocal( 1 );
	if( hb_xvmFunction( 2 ) ) break;
	hb_xvmPopLocal( 3 );
	hb_xvmSetLine( 494 );
	hb_xvmLocalSetInt( 4, 0L );
	hb_xvmLocalSetInt( 5, 0L );
	hb_xvmSetLine( 497 );
	hb_xvmPushLocal( 2 );
	if( hb_xvmGreaterThenIntIs( 0L, &fValue ) ) break;
	if( !fValue )
		goto lab00002;
	hb_xvmSetLine( 498 );
	hb_xvmCopyLocals( 2, 4 );
	hb_xvmSetLine( 499 );
	hb_xvmPushLocal( 2 );
	if( hb_xvmGreaterThenIntIs( 1L, &fValue ) ) break;
	if( !fValue )
		goto lab00002;
	hb_xvmSetLine( 500 );
	hb_xvmPushFuncSymbol( symbols + 30 );
	hb_xvmPushLocal( 1 );
	hb_xvmPushLocal( 2 );
	if( hb_xvmAddInt( -1L ) ) break;
	hb_xvmPushInteger( 1 );
	if( hb_xvmFunction( 3 ) ) break;
	hb_xvmPopLocal( 6 );
	hb_xvmSetLine( 501 );
	hb_xvmPushLocal( 6 );
	hb_xvmPushStringConst( ":", 1 );
	if( hb_xvmExactlyEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( fValue )
		goto lab00001;
	hb_xvmPushLocal( 6 );
	hb_xvmPushStringConst( "+", 1 );
	if( hb_xvmExactlyEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( fValue )
		goto lab00001;
	hb_xvmPushLocal( 6 );
	hb_xvmPushStringConst( "\?", 1 );
	if( hb_xvmExactlyEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00002;
lab00001: ;
	hb_xvmSetLine( 502 );
	hb_xvmPushLocal( 2 );
	if( hb_xvmAddInt( -1L ) ) break;
	hb_xvmPopLocal( 4 );
	hb_xvmSetLine( 503 );
	hb_xvmPushLocal( 6 );
	hb_xvmPushStringConst( ":", 1 );
	if( hb_xvmExactlyEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00002;
	hb_xvmPushLocal( 2 );
	if( hb_xvmGreaterThenIntIs( 2L, &fValue ) ) break;
	if( !fValue )
		goto lab00002;
	hb_xvmPushFuncSymbol( symbols + 30 );
	hb_xvmPushLocal( 1 );
	hb_xvmPushLocal( 2 );
	if( hb_xvmAddInt( -2L ) ) break;
	hb_xvmPushInteger( 1 );
	if( hb_xvmFunction( 3 ) ) break;
	hb_xvmPushStringConst( ":", 1 );
	if( hb_xvmExactlyEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00002;
	hb_xvmSetLine( 504 );
	hb_xvmPushLocal( 2 );
	if( hb_xvmAddInt( -2L ) ) break;
	hb_xvmPopLocal( 4 );
lab00002: ;
	hb_xvmSetLine( 510 );
	hb_xvmPushLocal( 3 );
	if( hb_xvmGreaterThenIntIs( 0L, &fValue ) ) break;
	if( !fValue )
		goto lab00004;
	hb_xvmPushLocal( 4 );
	if( hb_xvmEqualIntIs( 0L, &fValue ) ) break;
	if( fValue )
		goto lab00003;
	hb_xvmPushLocal( 3 );
	hb_xvmPushLocal( 4 );
	if( hb_xvmLess() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00004;
lab00003: ;
	hb_xvmSetLine( 511 );
	hb_xvmCopyLocals( 3, 5 );
lab00004: ;
	hb_xvmSetLine( 514 );
	hb_xvmPushLocal( 5 );
	hb_xvmPushLocal( 4 );
	hb_xvmArrayGen( 2 );
	hb_xvmRetValue();
	/* *** END PROC *** */
   } while( 0 );
}

HB_FUNC_STATIC( GETFIRSTWORD )
{
   HB_BOOL fValue;
   do {
	hb_xvmFrame( 3, 1 );
	hb_xvmSetLine( 519 );
	hb_xvmLocalSetInt( 2, 1L );
	hb_xvmPushFuncSymbol( symbols + 31 );
	hb_xvmPushLocal( 1 );
	if( hb_xvmFunction( 1 ) ) break;
	hb_xvmPopLocal( 3 );
lab00001: ;
	hb_xvmSetLine( 521 );
	hb_xvmPushLocal( 2 );
	hb_xvmPushLocal( 3 );
	if( hb_xvmLessEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00002;
	hb_xvmSetLine( 522 );
	hb_xvmPushFuncSymbol( symbols + 30 );
	hb_xvmPushLocal( 1 );
	hb_xvmPushLocal( 2 );
	hb_xvmPushInteger( 1 );
	if( hb_xvmFunction( 3 ) ) break;
	hb_xvmPopLocal( 4 );
	hb_xvmSetLine( 523 );
	hb_xvmPushLocal( 4 );
	hb_xvmPushStringConst( " ", 1 );
	if( hb_xvmExactlyEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( fValue )
		goto lab00002;
	hb_xvmPushLocal( 4 );
	hb_xvmPushStringConst( "\x09", 1 );
	if( hb_xvmExactlyEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( fValue )
		goto lab00002;
	hb_xvmPushLocal( 4 );
	hb_xvmPushStringConst( "(", 1 );
	if( hb_xvmExactlyEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( fValue )
		goto lab00002;
	hb_xvmSetLine( 526 );
	if( hb_xvmLocalInc( 2 ) ) break;
	goto lab00001;
lab00002: ;
	hb_xvmSetLine( 529 );
	hb_xvmPushFuncSymbol( symbols + 46 );
	hb_xvmPushFuncSymbol( symbols + 28 );
	hb_xvmPushLocal( 1 );
	hb_xvmPushLocal( 2 );
	if( hb_xvmAddInt( -1L ) ) break;
	if( hb_xvmFunction( 2 ) ) break;
	if( hb_xvmDo( 1 ) ) break;
	/* *** END PROC *** */
   } while( 0 );
}

HB_FUNC_STATIC( EXPANDSHELLVARS )
{
   HB_BOOL fValue;
   do {
	hb_xvmFrame( 6, 2 );
	hb_xvmSetLine( 534 );
	hb_xvmCopyLocals( 1, 3 );
lab00001: ;
	hb_xvmSetLine( 537 );
	hb_xvmPushFuncSymbol( symbols + 38 );
	hb_xvmPushStringConst( "$(", 2 );
	hb_xvmPushLocal( 3 );
	if( hb_xvmFunction( 2 ) ) break;
	hb_xvmPushUnRef();
	hb_xvmPopLocal( 6 );
	if( hb_xvmGreaterThenIntIs( 0L, &fValue ) ) break;
	if( fValue )
		goto lab00002;
	hb_xvmPushFuncSymbol( symbols + 38 );
	hb_xvmPushStringConst( "${", 2 );
	hb_xvmPushLocal( 3 );
	if( hb_xvmFunction( 2 ) ) break;
	hb_xvmPushUnRef();
	hb_xvmPopLocal( 6 );
	if( hb_xvmGreaterThenIntIs( 0L, &fValue ) ) break;
	if( !fValue )
		goto lab00005;
lab00002: ;
	hb_xvmSetLine( 538 );
	hb_xvmPushFuncSymbol( symbols + 38 );
	hb_xvmPushFuncSymbol( symbols + 30 );
	hb_xvmPushLocal( 3 );
	hb_xvmPushLocal( 6 );
	if( hb_xvmAddInt( 1L ) ) break;
	hb_xvmPushInteger( 1 );
	if( hb_xvmFunction( 3 ) ) break;
	hb_xvmPushStringConst( "(", 1 );
	if( hb_xvmExactlyEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00003;
	hb_xvmPushStringConst( ")", 1 );
	goto lab00004;
lab00003: ;
	hb_xvmPushStringConst( "}", 1 );
lab00004: ;
	hb_xvmPushLocal( 3 );
	if( hb_xvmFunction( 2 ) ) break;
	hb_xvmPopLocal( 7 );
	hb_xvmSetLine( 539 );
	hb_xvmPushLocal( 7 );
	hb_xvmPushLocal( 6 );
	if( hb_xvmGreater() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00005;
	hb_xvmSetLine( 540 );
	hb_xvmPushFuncSymbol( symbols + 30 );
	hb_xvmPushLocal( 3 );
	hb_xvmPushLocal( 6 );
	if( hb_xvmAddInt( 2L ) ) break;
	hb_xvmPushLocal( 7 );
	hb_xvmPushLocal( 6 );
	if( hb_xvmMinus() ) break;
	if( hb_xvmAddInt( -2L ) ) break;
	if( hb_xvmFunction( 3 ) ) break;
	hb_xvmPopLocal( 8 );
	hb_xvmSetLine( 541 );
	hb_xvmPushFuncSymbol( symbols + 22 );
	hb_xvmPushLocal( 8 );
	if( hb_xvmFunction( 1 ) ) break;
	hb_xvmPopLocal( 4 );
	hb_xvmSetLine( 542 );
	hb_xvmPushFuncSymbol( symbols + 21 );
	hb_xvmPushLocal( 2 );
	hb_xvmPushLocal( 4 );
	hb_xvmPushStringConst( "", 0 );
	if( hb_xvmFunction( 3 ) ) break;
	hb_xvmPopLocal( 5 );
	hb_xvmSetLine( 543 );
	hb_xvmPushFuncSymbol( symbols + 28 );
	hb_xvmPushLocal( 3 );
	hb_xvmPushLocal( 6 );
	if( hb_xvmAddInt( -1L ) ) break;
	if( hb_xvmFunction( 2 ) ) break;
	hb_xvmPushLocal( 5 );
	if( hb_xvmPlus() ) break;
	hb_xvmPushFuncSymbol( symbols + 30 );
	hb_xvmPushLocal( 3 );
	hb_xvmPushLocal( 7 );
	if( hb_xvmAddInt( 1L ) ) break;
	if( hb_xvmFunction( 2 ) ) break;
	hb_xvmLocalAdd( 3 );
	goto lab00001;
lab00005: ;
	hb_xvmSetLine( 548 );
	hb_xvmPushLocal( 3 );
	hb_xvmRetValue();
	/* *** END PROC *** */
   } while( 0 );
}

HB_FUNC_STATIC( EXPANDSHELLVARS2 )
{
   HB_BOOL fValue;
   do {
	hb_xvmFrame( 6, 2 );
	hb_xvmSetLine( 551 );
	hb_xvmCopyLocals( 1, 3 );
	hb_xvmSetLine( 552 );
	hb_xvmLocalSetInt( 7, 0L );
lab00001: ;
	hb_xvmSetLine( 554 );
	hb_xvmPushFuncSymbol( symbols + 53 );
	hb_xvmPushStringConst( "$(", 2 );
	hb_xvmPushLocal( 3 );
	hb_xvmPushLocal( 7 );
	if( hb_xvmFunction( 3 ) ) break;
	hb_xvmPushUnRef();
	hb_xvmPopLocal( 6 );
	if( hb_xvmGreaterThenIntIs( 0L, &fValue ) ) break;
	if( fValue )
		goto lab00002;
	hb_xvmPushFuncSymbol( symbols + 53 );
	hb_xvmPushStringConst( "${", 2 );
	hb_xvmPushLocal( 3 );
	hb_xvmPushLocal( 7 );
	if( hb_xvmFunction( 3 ) ) break;
	hb_xvmPushUnRef();
	hb_xvmPopLocal( 6 );
	if( hb_xvmGreaterThenIntIs( 0L, &fValue ) ) break;
	if( !fValue )
		goto lab00006;
lab00002: ;
	hb_xvmSetLine( 555 );
	hb_xvmPushFuncSymbol( symbols + 38 );
	hb_xvmPushFuncSymbol( symbols + 30 );
	hb_xvmPushLocal( 3 );
	hb_xvmPushLocal( 6 );
	if( hb_xvmAddInt( 1L ) ) break;
	hb_xvmPushInteger( 1 );
	if( hb_xvmFunction( 3 ) ) break;
	hb_xvmPushStringConst( "(", 1 );
	if( hb_xvmExactlyEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00003;
	hb_xvmPushStringConst( ")", 1 );
	goto lab00004;
lab00003: ;
	hb_xvmPushStringConst( "}", 1 );
lab00004: ;
	hb_xvmPushLocal( 3 );
	if( hb_xvmFunction( 2 ) ) break;
	hb_xvmPopLocal( 7 );
	hb_xvmSetLine( 556 );
	hb_xvmPushFuncSymbol( symbols + 54 );
	hb_xvmPushFuncSymbol( symbols + 30 );
	hb_xvmPushLocal( 3 );
	hb_xvmPushLocal( 6 );
	if( hb_xvmAddInt( 2L ) ) break;
	hb_xvmPushInteger( 1 );
	if( hb_xvmFunction( 3 ) ) break;
	if( hb_xvmFunction( 1 ) ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00005;
	hb_xvmSetLine( 557 );
	hb_xvmPushLocal( 6 );
	if( hb_xvmAddInt( 1L ) ) break;
	hb_xvmPopLocal( 7 );
	goto lab00001;
lab00005: ;
	hb_xvmSetLine( 560 );
	hb_xvmPushLocal( 7 );
	hb_xvmPushLocal( 6 );
	if( hb_xvmGreater() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00006;
	hb_xvmSetLine( 561 );
	hb_xvmPushFuncSymbol( symbols + 30 );
	hb_xvmPushLocal( 3 );
	hb_xvmPushLocal( 6 );
	if( hb_xvmAddInt( 2L ) ) break;
	hb_xvmPushLocal( 7 );
	hb_xvmPushLocal( 6 );
	if( hb_xvmMinus() ) break;
	if( hb_xvmAddInt( -2L ) ) break;
	if( hb_xvmFunction( 3 ) ) break;
	hb_xvmPopLocal( 8 );
	hb_xvmSetLine( 562 );
	hb_xvmPushFuncSymbol( symbols + 22 );
	hb_xvmPushLocal( 8 );
	if( hb_xvmFunction( 1 ) ) break;
	hb_xvmPopLocal( 4 );
	hb_xvmSetLine( 563 );
	hb_xvmPushFuncSymbol( symbols + 21 );
	hb_xvmPushLocal( 2 );
	hb_xvmPushLocal( 4 );
	hb_xvmPushStringConst( "", 0 );
	if( hb_xvmFunction( 3 ) ) break;
	hb_xvmPopLocal( 5 );
	hb_xvmSetLine( 564 );
	hb_xvmPushFuncSymbol( symbols + 28 );
	hb_xvmPushLocal( 3 );
	hb_xvmPushLocal( 6 );
	if( hb_xvmAddInt( -1L ) ) break;
	if( hb_xvmFunction( 2 ) ) break;
	hb_xvmPushLocal( 5 );
	if( hb_xvmPlus() ) break;
	hb_xvmPushFuncSymbol( symbols + 30 );
	hb_xvmPushLocal( 3 );
	hb_xvmPushLocal( 7 );
	if( hb_xvmAddInt( 1L ) ) break;
	if( hb_xvmFunction( 2 ) ) break;
	hb_xvmLocalAdd( 3 );
	goto lab00001;
lab00006: ;
	hb_xvmSetLine( 569 );
	hb_xvmPushLocal( 3 );
	hb_xvmRetValue();
	/* *** END PROC *** */
   } while( 0 );
}

HB_FUNC_STATIC( APPLYMAKEMACROS )
{
   HB_BOOL fValue;
   do {
	hb_xvmFrame( 3, 3 );
	hb_xvmSetLine( 582 );
	hb_xvmCopyLocals( 1, 4 );
	hb_xvmSetLine( 584 );
	hb_xvmPushLocal( 2 );
	hb_xvmPushNil();
	if( hb_xvmExactlyEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00001;
	hb_xvmSetLine( 585 );
	hb_xvmPushLocal( 4 );
	hb_xvmRetValue();
	/* *** END PROC *** */
	break;
lab00001: ;
	hb_xvmSetLine( 588 );
	hb_xvmPushStringConst( "/*", 2 );
	hb_xvmPushLocal( 4 );
	if( hb_xvmInstring() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00002;
	hb_xvmSetLine( 589 );
	hb_xvmPushFuncSymbol( symbols + 49 );
	hb_xvmPushLocal( 4 );
	hb_xvmPushStringConst( "/*", 2 );
	hb_xvmPushStringConst( "__SHELL_GLOB_SLASH_STAR__", 25 );
	if( hb_xvmFunction( 3 ) ) break;
	hb_xvmPopLocal( 4 );
lab00002: ;
	hb_xvmSetLine( 592 );
	hb_xvmPushStringConst( "//", 2 );
	hb_xvmPushLocal( 4 );
	if( hb_xvmInstring() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00003;
	hb_xvmSetLine( 593 );
	hb_xvmPushFuncSymbol( symbols + 49 );
	hb_xvmPushLocal( 4 );
	hb_xvmPushStringConst( "//", 2 );
	hb_xvmPushStringConst( "__SLASH_SLASH__", 15 );
	if( hb_xvmFunction( 3 ) ) break;
	hb_xvmPopLocal( 4 );
lab00003: ;
	hb_xvmSetLine( 596 );
	hb_xvmPushFuncSymbol( symbols + 23 );
	hb_xvmPushLocal( 3 );
	if( hb_xvmFunction( 1 ) ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00004;
	hb_xvmSetLine( 597 );
	hb_xvmPushFuncSymbol( symbols + 49 );
	hb_xvmPushLocal( 4 );
	hb_xvmPushStringConst( "$", 1 );
	hb_xvmPushStringConst( "__MORE_SPACE__ $", 16 );
	if( hb_xvmFunction( 3 ) ) break;
	hb_xvmPopLocal( 4 );
lab00004: ;
	hb_xvmSetLine( 599 );
	hb_xvmPushFuncSymbol( symbols + 49 );
	hb_xvmPushLocal( 4 );
	hb_xvmPushStringConst( "|", 1 );
	hb_xvmPushStringConst( "__PIPE_CHR__", 12 );
	if( hb_xvmFunction( 3 ) ) break;
	hb_xvmPopLocal( 4 );
	hb_xvmSetLine( 601 );
	hb_xvmSeqBegin();
	for( ;; ) {
	hb_xvmPushFuncSymbol( symbols + 55 );
	if( hb_xvmFunction( 0 ) ) break;
	if( hb_xvmSeqBlock() ) break;
	hb_xvmSetLine( 602 );
	hb_xvmPushFuncSymbol( symbols + 56 );
	hb_xvmPushLocal( 2 );
	hb_xvmPushLocal( 4 );
	if( hb_xvmFunction( 2 ) ) break;
	hb_xvmPopLocal( 5 );
	hb_stackPop();
	if( hb_xvmSeqEndTest() ) break;
	goto lab00005;
	}
	hb_xvmSetLine( 603 );
	if( hb_xvmSeqRecover() ) break;
	hb_xvmPopLocal( 6 );
	hb_xvmSetLine( 604 );
	hb_xvmPushFuncSymbol( symbols + 4 );
	hb_xvmPushSymbol( symbols + 57 );
	hb_xvmPushLocal( 6 );
	if( hb_xvmSend( 0 ) ) break;
	hb_xvmPushStringConst( ":", 1 );
	hb_xvmPushLocal( 4 );
	if( hb_xvmDo( 3 ) ) break;
	hb_xvmSetLine( 605 );
	hb_xvmCopyLocals( 4, 5 );
lab00005: ;
	hb_xvmSetLine( 607 );
	hb_xvmPushFuncSymbol( symbols + 38 );
	hb_xvmPushStringConst( "error", 5 );
	hb_xvmPushLocal( 4 );
	if( hb_xvmFunction( 2 ) ) break;
	if( hb_xvmGreaterThenIntIs( 0L, &fValue ) ) break;
	if( !fValue )
		goto lab00006;
	hb_xvmSetLine( 608 );
	hb_xvmPushFuncSymbol( symbols + 4 );
	hb_xvmPushLocal( 5 );
	if( hb_xvmDo( 1 ) ) break;
lab00006: ;
	hb_xvmSetLine( 610 );
	hb_xvmPushFuncSymbol( symbols + 23 );
	hb_xvmPushLocal( 5 );
	if( hb_xvmFunction( 1 ) ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( fValue )
		goto lab00009;
	hb_xvmSetLine( 612 );
	hb_xvmPushFuncSymbol( symbols + 58 );
	hb_xvmPushStringConst( "&(", 2 );
	hb_xvmPushLocal( 4 );
	if( hb_xvmFunction( 2 ) ) break;
	hb_xvmPushFuncSymbol( symbols + 58 );
	hb_xvmPushStringConst( "&(", 2 );
	hb_xvmPushLocal( 5 );
	if( hb_xvmFunction( 2 ) ) break;
	if( hb_xvmNotEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00007;
	hb_xvmSetLine( 613 );
	hb_xvmPushFuncSymbol( symbols + 49 );
	hb_xvmPushLocal( 5 );
	hb_xvmPushStringConst( "__SHELL_GLOB_SLASH_STAR__", 25 );
	hb_xvmPushStringConst( "/*", 2 );
	if( hb_xvmFunction( 3 ) ) break;
	hb_xvmPopLocal( 5 );
	hb_xvmSetLine( 614 );
	hb_xvmPushFuncSymbol( symbols + 49 );
	hb_xvmPushLocal( 5 );
	hb_xvmPushStringConst( "__SLASH_SLASH__", 15 );
	hb_xvmPushStringConst( "//", 2 );
	if( hb_xvmFunction( 3 ) ) break;
	hb_xvmPopLocal( 5 );
	hb_xvmSetLine( 615 );
	hb_xvmPushFuncSymbol( symbols + 49 );
	hb_xvmPushLocal( 5 );
	hb_xvmPushStringConst( "__MORE_SPACE__ ", 15 );
	hb_xvmPushStringConst( "", 0 );
	if( hb_xvmFunction( 3 ) ) break;
	hb_xvmPopLocal( 5 );
	hb_xvmSetLine( 616 );
	hb_xvmPushFuncSymbol( symbols + 49 );
	hb_xvmPushLocal( 5 );
	hb_xvmPushStringConst( "__PIPE_CHR__", 12 );
	hb_xvmPushStringConst( "|", 1 );
	if( hb_xvmFunction( 3 ) ) break;
	hb_xvmPopLocal( 5 );
	hb_xvmSetLine( 617 );
	hb_xvmPushFuncSymbol( symbols + 59 );
	hb_xvmPushLocal( 5 );
	if( hb_xvmFunction( 1 ) ) break;
	hb_xvmPopLocal( 5 );
	goto lab00008;
lab00007: ;
	hb_xvmSetLine( 619 );
	hb_xvmPushFuncSymbol( symbols + 49 );
	hb_xvmPushLocal( 4 );
	hb_xvmPushStringConst( "__SHELL_GLOB_SLASH_STAR__", 25 );
	hb_xvmPushStringConst( "/*", 2 );
	if( hb_xvmFunction( 3 ) ) break;
	hb_xvmPopLocal( 5 );
	hb_xvmSetLine( 620 );
	hb_xvmPushFuncSymbol( symbols + 49 );
	hb_xvmPushLocal( 5 );
	hb_xvmPushStringConst( "__SLASH_SLASH__", 15 );
	hb_xvmPushStringConst( "//", 2 );
	if( hb_xvmFunction( 3 ) ) break;
	hb_xvmPopLocal( 5 );
	hb_xvmSetLine( 621 );
	hb_xvmPushFuncSymbol( symbols + 49 );
	hb_xvmPushLocal( 5 );
	hb_xvmPushStringConst( "__MORE_SPACE__ ", 15 );
	hb_xvmPushStringConst( "", 0 );
	if( hb_xvmFunction( 3 ) ) break;
	hb_xvmPopLocal( 5 );
	hb_xvmSetLine( 622 );
	hb_xvmPushFuncSymbol( symbols + 49 );
	hb_xvmPushLocal( 5 );
	hb_xvmPushStringConst( "__PIPE_CHR__", 12 );
	hb_xvmPushStringConst( "|", 1 );
	if( hb_xvmFunction( 3 ) ) break;
	hb_xvmPopLocal( 5 );
lab00008: ;
	hb_xvmSetLine( 624 );
	hb_xvmPushFuncSymbol( symbols + 22 );
	hb_xvmPushLocal( 5 );
	if( hb_xvmFunction( 1 ) ) break;
	hb_xvmPopLocal( 4 );
lab00009: ;
	hb_xvmSetLine( 627 );
	hb_xvmPushLocal( 4 );
	hb_xvmRetValue();
	/* *** END PROC *** */
   } while( 0 );
}

HB_FUNC_STATIC( EXTRACTTARGETS )
{
   HB_BOOL fValue;
   do {
	hb_xvmFrame( 12, 2 );
	hb_xvmSetLine( 631 );
	hb_xvmArrayGen( 0 );
	hb_xvmPopLocal( 10 );
	hb_xvmSetLine( 634 );
	hb_xvmPushLocal( 1 );
	hb_xvmPushLocalByRef( 3 );
	if( hb_xvmEnumStart( 1, 1 ) ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00009;
lab00001: ;
	hb_xvmSetLine( 635 );
	hb_xvmPushFuncSymbol( symbols + 22 );
	hb_xvmPushFuncSymbol( symbols + 27 );
	hb_xvmPushLocal( 3 );
	if( hb_xvmFunction( 1 ) ) break;
	if( hb_xvmFunction( 1 ) ) break;
	hb_xvmPopLocal( 4 );
	hb_xvmSetLine( 637 );
	hb_xvmPushFuncSymbol( symbols + 45 );
	hb_xvmPushLocal( 4 );
	if( hb_xvmFunction( 1 ) ) break;
	hb_xvmPopLocal( 14 );
	hb_xvmSetLine( 638 );
	hb_xvmPushLocal( 14 );
	if( hb_xvmArrayItemPush( 1L ) ) break;
	if( hb_xvmGreaterThenIntIs( 0L, &fValue ) ) break;
	if( !fValue )
		goto lab00008;
	hb_xvmSetLine( 639 );
	hb_xvmPushLocal( 14 );
	if( hb_xvmArrayItemPush( 1L ) ) break;
	hb_xvmPopLocal( 5 );
	hb_xvmSetLine( 640 );
	hb_xvmPushFuncSymbol( symbols + 39 );
	hb_xvmPushFuncSymbol( symbols + 22 );
	hb_xvmPushFuncSymbol( symbols + 28 );
	hb_xvmPushLocal( 4 );
	hb_xvmPushLocal( 5 );
	if( hb_xvmAddInt( -1L ) ) break;
	if( hb_xvmFunction( 2 ) ) break;
	if( hb_xvmFunction( 1 ) ) break;
	hb_xvmPushLocal( 2 );
	if( hb_xvmFunction( 2 ) ) break;
	hb_xvmPopLocal( 6 );
	hb_xvmSetLine( 641 );
	hb_xvmPushFuncSymbol( symbols + 39 );
	hb_xvmPushFuncSymbol( symbols + 22 );
	hb_xvmPushFuncSymbol( symbols + 30 );
	hb_xvmPushLocal( 4 );
	hb_xvmPushLocal( 5 );
	if( hb_xvmAddInt( 1L ) ) break;
	if( hb_xvmFunction( 2 ) ) break;
	if( hb_xvmFunction( 1 ) ) break;
	hb_xvmPushLocal( 2 );
	if( hb_xvmFunction( 2 ) ) break;
	hb_xvmPopLocal( 7 );
	hb_xvmSetLine( 643 );
	hb_xvmPushFuncSymbol( symbols + 23 );
	hb_xvmPushLocal( 6 );
	if( hb_xvmFunction( 1 ) ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( fValue )
		goto lab00008;
	hb_xvmSetLine( 644 );
	hb_xvmPushFuncSymbol( symbols + 15 );
	hb_xvmPushLocal( 6 );
	hb_xvmPushStringConst( " ", 1 );
	if( hb_xvmFunction( 2 ) ) break;
	hb_xvmPopLocal( 11 );
	hb_xvmSetLine( 645 );
	hb_xvmPushFuncSymbol( symbols + 15 );
	hb_xvmPushLocal( 7 );
	hb_xvmPushStringConst( " ", 1 );
	if( hb_xvmFunction( 2 ) ) break;
	hb_xvmPopLocal( 12 );
	hb_xvmSetLine( 647 );
	hb_xvmPushLocal( 11 );
	hb_xvmPushLocalByRef( 8 );
	if( hb_xvmEnumStart( 1, 1 ) ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00007;
lab00002: ;
	hb_xvmSetLine( 648 );
	hb_xvmPushFuncSymbol( symbols + 22 );
	hb_xvmPushLocal( 8 );
	if( hb_xvmFunction( 1 ) ) break;
	hb_xvmPopLocal( 8 );
	hb_xvmSetLine( 649 );
	hb_xvmPushFuncSymbol( symbols + 23 );
	hb_xvmPushLocal( 8 );
	if( hb_xvmFunction( 1 ) ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( fValue )
		goto lab00006;
	hb_xvmSetLine( 650 );
	hb_xvmPushFuncSymbol( symbols + 19 );
	if( hb_xvmFunction( 0 ) ) break;
	hb_xvmPopLocal( 13 );
	hb_xvmSetLine( 651 );
	hb_xvmPushLocal( 8 );
	hb_xvmPushLocal( 13 );
	hb_xvmPushStringConst( "NAME", 4 );
	if( hb_xvmArrayPop() ) break;
	hb_xvmSetLine( 652 );
	hb_xvmArrayGen( 0 );
	hb_xvmPushLocal( 13 );
	hb_xvmPushStringConst( "DEPS", 4 );
	if( hb_xvmArrayPop() ) break;
	hb_xvmSetLine( 654 );
	hb_xvmPushLocal( 12 );
	hb_xvmPushLocalByRef( 9 );
	if( hb_xvmEnumStart( 1, 1 ) ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00005;
lab00003: ;
	hb_xvmSetLine( 655 );
	hb_xvmPushFuncSymbol( symbols + 22 );
	hb_xvmPushLocal( 9 );
	if( hb_xvmFunction( 1 ) ) break;
	hb_xvmPopLocal( 9 );
	hb_xvmSetLine( 656 );
	hb_xvmPushFuncSymbol( symbols + 23 );
	hb_xvmPushLocal( 9 );
	if( hb_xvmFunction( 1 ) ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( fValue )
		goto lab00004;
	hb_xvmSetLine( 657 );
	hb_xvmPushFuncSymbol( symbols + 13 );
	hb_xvmPushLocal( 13 );
	hb_xvmPushStringConst( "DEPS", 4 );
	if( hb_xvmArrayPush() ) break;
	hb_xvmPushLocal( 9 );
	if( hb_xvmDo( 2 ) ) break;
lab00004: ;
	hb_xvmSetLine( 659 );
	if( hb_xvmEnumNext() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( fValue )
		goto lab00003;
lab00005: ;
	hb_xvmEnumEnd();
	hb_xvmSetLine( 661 );
	hb_xvmPushFuncSymbol( symbols + 13 );
	hb_xvmPushLocal( 10 );
	hb_xvmPushLocal( 13 );
	if( hb_xvmDo( 2 ) ) break;
lab00006: ;
	hb_xvmSetLine( 663 );
	if( hb_xvmEnumNext() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( fValue )
		goto lab00002;
lab00007: ;
	hb_xvmEnumEnd();
lab00008: ;
	hb_xvmSetLine( 666 );
	if( hb_xvmEnumNext() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( fValue )
		goto lab00001;
lab00009: ;
	hb_xvmEnumEnd();
	hb_xvmSetLine( 667 );
	hb_xvmPushLocal( 10 );
	hb_xvmRetValue();
	/* *** END PROC *** */
   } while( 0 );
}

HB_FUNC_STATIC( BUILDREGISTRY )
{
   HB_BOOL fValue;
   do {
	hb_xvmFrame( 5, 1 );
	hb_xvmSetLine( 670 );
	hb_xvmPushFuncSymbol( symbols + 19 );
	if( hb_xvmFunction( 0 ) ) break;
	hb_xvmPopLocal( 2 );
	hb_xvmSetLine( 673 );
	hb_xvmPushLocal( 1 );
	hb_xvmPushLocalByRef( 3 );
	if( hb_xvmEnumStart( 1, 1 ) ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00005;
lab00001: ;
	hb_xvmSetLine( 674 );
	hb_xvmPushFuncSymbol( symbols + 46 );
	hb_xvmPushLocal( 3 );
	hb_xvmPushStringConst( "CANONICAL", 9 );
	if( hb_xvmArrayPush() ) break;
	if( hb_xvmFunction( 1 ) ) break;
	hb_xvmPopLocal( 4 );
	hb_xvmSetLine( 675 );
	hb_xvmPushFuncSymbol( symbols + 60 );
	hb_xvmPushLocal( 2 );
	hb_xvmPushLocal( 4 );
	hb_xvmPushLocal( 3 );
	if( hb_xvmDo( 3 ) ) break;
	hb_xvmSetLine( 676 );
	hb_xvmPushFuncSymbol( symbols + 60 );
	hb_xvmPushLocal( 2 );
	hb_xvmPushFuncSymbol( symbols + 46 );
	hb_xvmPushLocal( 3 );
	hb_xvmPushStringConst( "DIR_NAME", 8 );
	if( hb_xvmArrayPush() ) break;
	if( hb_xvmFunction( 1 ) ) break;
	hb_xvmPushLocal( 3 );
	if( hb_xvmDo( 3 ) ) break;
	hb_xvmSetLine( 678 );
	hb_xvmPushFuncSymbol( symbols + 21 );
	hb_xvmPushLocal( 3 );
	hb_xvmPushStringConst( "EVAL_LINUX", 10 );
	if( hb_xvmArrayPush() ) break;
	hb_xvmPushStringConst( "PKGNAME", 7 );
	hb_xvmPushFuncSymbol( symbols + 21 );
	hb_xvmPushLocal( 3 );
	hb_xvmPushStringConst( "EVAL_WIN", 8 );
	if( hb_xvmArrayPush() ) break;
	hb_xvmPushStringConst( "PKGNAME", 7 );
	hb_xvmPushStringConst( "", 0 );
	if( hb_xvmFunction( 3 ) ) break;
	if( hb_xvmFunction( 3 ) ) break;
	hb_xvmPopLocal( 5 );
	hb_xvmSetLine( 680 );
	hb_xvmPushLocal( 5 );
	hb_xvmPushLocal( 3 );
	hb_xvmPushStringConst( "EVAL_LINUX", 10 );
	if( hb_xvmArrayPush() ) break;
	hb_xvmPushStringConst( "PROVIDES", 8 );
	if( hb_xvmArrayPop() ) break;
	hb_xvmSetLine( 681 );
	hb_xvmPushLocal( 5 );
	hb_xvmPushLocal( 3 );
	hb_xvmPushStringConst( "EVAL_WIN", 8 );
	if( hb_xvmArrayPush() ) break;
	hb_xvmPushStringConst( "PROVIDES", 8 );
	if( hb_xvmArrayPop() ) break;
	hb_xvmSetLine( 683 );
	hb_xvmPushFuncSymbol( symbols + 23 );
	hb_xvmPushLocal( 5 );
	if( hb_xvmFunction( 1 ) ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( fValue )
		goto lab00004;
	hb_xvmSetLine( 684 );
	hb_xvmPushFuncSymbol( symbols + 15 );
	hb_xvmPushLocal( 5 );
	hb_xvmPushStringConst( " ", 1 );
	if( hb_xvmFunction( 2 ) ) break;
	hb_xvmPushLocalByRef( 6 );
	if( hb_xvmEnumStart( 1, 1 ) ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00003;
lab00002: ;
	hb_xvmSetLine( 685 );
	hb_xvmPushFuncSymbol( symbols + 60 );
	hb_xvmPushLocal( 2 );
	hb_xvmPushFuncSymbol( symbols + 46 );
	hb_xvmPushFuncSymbol( symbols + 22 );
	hb_xvmPushLocal( 6 );
	if( hb_xvmFunction( 1 ) ) break;
	if( hb_xvmFunction( 1 ) ) break;
	hb_xvmPushLocal( 3 );
	if( hb_xvmDo( 3 ) ) break;
	hb_xvmSetLine( 686 );
	if( hb_xvmEnumNext() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( fValue )
		goto lab00002;
lab00003: ;
	hb_xvmEnumEnd();
lab00004: ;
	hb_xvmSetLine( 688 );
	if( hb_xvmEnumNext() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( fValue )
		goto lab00001;
lab00005: ;
	hb_xvmEnumEnd();
	hb_xvmSetLine( 689 );
	hb_xvmPushLocal( 2 );
	hb_xvmRetValue();
	/* *** END PROC *** */
   } while( 0 );
}

HB_FUNC_STATIC( REGISTERKEY )
{
   HB_BOOL fValue;
   do {
	hb_xvmFrame( 0, 3 );
	hb_xvmSetLine( 692 );
	hb_xvmPushFuncSymbol( symbols + 23 );
	hb_xvmPushLocal( 2 );
	if( hb_xvmFunction( 1 ) ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( fValue )
		goto lab00002;
	hb_xvmSetLine( 693 );
	hb_xvmPushFuncSymbol( symbols + 50 );
	hb_xvmPushLocal( 1 );
	hb_xvmPushLocal( 2 );
	if( hb_xvmFunction( 2 ) ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( fValue )
		goto lab00001;
	hb_xvmSetLine( 694 );
	hb_xvmArrayGen( 0 );
	hb_xvmPushLocal( 1 );
	hb_xvmPushLocal( 2 );
	if( hb_xvmArrayPop() ) break;
lab00001: ;
	hb_xvmSetLine( 696 );
	hb_xvmPushFuncSymbol( symbols + 13 );
	hb_xvmPushLocal( 1 );
	hb_xvmPushLocal( 2 );
	if( hb_xvmArrayPush() ) break;
	hb_xvmPushLocal( 3 );
	if( hb_xvmDo( 2 ) ) break;
lab00002: ;
	hb_xvmSetLine( 698 );
	/* *** END PROC *** */
   } while( 0 );
}

HB_FUNC_STATIC( GENERATEINDEXPAGE )
{
   HB_BOOL fValue;
   do {
	hb_xvmFrame( 4, 2 );
	hb_xvmSetLine( 701 );
	hb_xvmPushFuncSymbol( symbols + 61 );
	hb_xvmPushStringConst( "Package Catalog", 15 );
	if( hb_xvmFunction( 1 ) ) break;
	hb_xvmPopLocal( 3 );
	hb_xvmSetLine( 702 );
	hb_xvmPushFuncSymbol( symbols + 31 );
	hb_xvmPushLocal( 3 );
	if( hb_xvmFunction( 1 ) ) break;
	hb_xvmPopLocal( 6 );
	hb_xvmSetLine( 704 );
	hb_xvmPushLocalByRef( 3 );
	hb_xvmPushStringConst( "<h1>harbour.zip Package Catalog</h1>", 36 );
	hb_xvmPushFuncSymbol( symbols + 16 );
	if( hb_xvmFunction( 0 ) ) break;
	if( hb_xvmPlus() ) break;
	if( hb_xvmPlusEqPop() ) break;
	hb_xvmSetLine( 705 );
	hb_xvmPushLocalByRef( 3 );
	hb_xvmPushStringConst( "<table class=\"pkg-table\">", 25 );
	hb_xvmPushFuncSymbol( symbols + 16 );
	if( hb_xvmFunction( 0 ) ) break;
	if( hb_xvmPlus() ) break;
	if( hb_xvmPlusEqPop() ) break;
	hb_xvmSetLine( 706 );
	hb_xvmPushLocalByRef( 3 );
	hb_xvmPushStringConst( "<tr><th>Canonical Name</th><th>Directory</th><th>Provides</th><th>Fetch Type</th></tr>", 86 );
	hb_xvmPushFuncSymbol( symbols + 16 );
	if( hb_xvmFunction( 0 ) ) break;
	if( hb_xvmPlus() ) break;
	if( hb_xvmPlusEqPop() ) break;
	hb_xvmSetLine( 708 );
	hb_xvmPushLocal( 1 );
	hb_xvmPushLocalByRef( 4 );
	if( hb_xvmEnumStart( 1, 1 ) ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00006;
lab00001: ;
	hb_xvmSetLine( 718 );
	hb_xvmPushFuncSymbol( symbols + 28 );
	hb_xvmPushLocal( 4 );
	hb_xvmPushStringConst( "DIR_NAME", 8 );
	if( hb_xvmArrayPush() ) break;
	hb_xvmPushInteger( 2 );
	if( hb_xvmFunction( 2 ) ) break;
	hb_xvmPushStringConst( "hb", 2 );
	if( hb_xvmExactlyEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( fValue )
		goto lab00002;
	hb_xvmPushFuncSymbol( symbols + 28 );
	hb_xvmPushLocal( 4 );
	hb_xvmPushStringConst( "DIR_NAME", 8 );
	if( hb_xvmArrayPush() ) break;
	hb_xvmPushInteger( 7 );
	if( hb_xvmFunction( 2 ) ) break;
	hb_xvmPushStringConst( "harbour", 7 );
	if( hb_xvmExactlyEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( fValue )
		goto lab00002;
	hb_xvmPushFuncSymbol( symbols + 28 );
	hb_xvmPushLocal( 4 );
	hb_xvmPushStringConst( "DIR_NAME", 8 );
	if( hb_xvmArrayPush() ) break;
	hb_xvmPushInteger( 5 );
	if( hb_xvmFunction( 2 ) ) break;
	hb_xvmPushStringConst( "hwgui", 5 );
	if( hb_xvmExactlyEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( fValue )
		goto lab00002;
	hb_xvmPushFuncSymbol( symbols + 28 );
	hb_xvmPushLocal( 4 );
	hb_xvmPushStringConst( "DIR_NAME", 8 );
	if( hb_xvmArrayPush() ) break;
	hb_xvmPushInteger( 3 );
	if( hb_xvmFunction( 2 ) ) break;
	hb_xvmPushStringConst( "hix", 3 );
	if( hb_xvmExactlyEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( fValue )
		goto lab00002;
	hb_xvmPushFuncSymbol( symbols + 28 );
	hb_xvmPushLocal( 4 );
	hb_xvmPushStringConst( "DIR_NAME", 8 );
	if( hb_xvmArrayPush() ) break;
	hb_xvmPushInteger( 3 );
	if( hb_xvmFunction( 2 ) ) break;
	hb_xvmPushStringConst( "zig", 3 );
	if( hb_xvmExactlyEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( fValue )
		goto lab00002;
	hb_xvmPushFuncSymbol( symbols + 28 );
	hb_xvmPushLocal( 4 );
	hb_xvmPushStringConst( "DIR_NAME", 8 );
	if( hb_xvmArrayPush() ) break;
	hb_xvmPushInteger( 7 );
	if( hb_xvmFunction( 2 ) ) break;
	hb_xvmPushStringConst( "nappgui", 7 );
	if( hb_xvmExactlyEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( fValue )
		goto lab00002;
	hb_xvmPushLocal( 4 );
	hb_xvmPushStringConst( "DIR_NAME", 8 );
	if( hb_xvmArrayPush() ) break;
	hb_xvmPushStringConst( "cmake", 5 );
	if( hb_xvmEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( fValue )
		goto lab00002;
	hb_xvmPushLocal( 4 );
	hb_xvmPushStringConst( "DIR_NAME", 8 );
	if( hb_xvmArrayPush() ) break;
	hb_xvmPushStringConst( "curl", 4 );
	if( hb_xvmEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( fValue )
		goto lab00002;
	hb_xvmPushFuncSymbol( symbols + 28 );
	hb_xvmPushLocal( 4 );
	hb_xvmPushStringConst( "DIR_NAME", 8 );
	if( hb_xvmArrayPush() ) break;
	hb_xvmPushInteger( 7 );
	if( hb_xvmFunction( 2 ) ) break;
	hb_xvmPushStringConst( "openssl", 7 );
	if( hb_xvmExactlyEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( fValue )
		goto lab00002;
	hb_xvmPushFuncSymbol( symbols + 28 );
	hb_xvmPushLocal( 4 );
	hb_xvmPushStringConst( "DIR_NAME", 8 );
	if( hb_xvmArrayPush() ) break;
	hb_xvmPushInteger( 4 );
	if( hb_xvmFunction( 2 ) ) break;
	hb_xvmPushStringConst( "leto", 4 );
	if( hb_xvmExactlyEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( fValue )
		goto lab00002;
	hb_xvmSetLine( 720 );
	goto lab00005;
lab00002: ;
	hb_xvmSetLine( 722 );
	hb_xvmPushFuncSymbol( symbols + 50 );
	hb_xvmPushLocal( 4 );
	hb_xvmPushStringConst( "EVAL_LINUX", 10 );
	if( hb_xvmArrayPush() ) break;
	hb_xvmPushStringConst( "!!!ERROR!!!", 11 );
	if( hb_xvmFunction( 2 ) ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( fValue )
		goto lab00003;
	hb_xvmSetLine( 723 );
	hb_xvmPushFuncSymbol( symbols + 62 );
	hb_xvmPushLocal( 4 );
	hb_xvmPushStringConst( "EVAL_LINUX", 10 );
	if( hb_xvmArrayPush() ) break;
	if( hb_xvmFunction( 1 ) ) break;
	hb_xvmPopLocal( 5 );
	goto lab00004;
lab00003: ;
	hb_xvmSetLine( 725 );
	hb_xvmPushFuncSymbol( symbols + 62 );
	hb_xvmPushLocal( 4 );
	hb_xvmPushStringConst( "EVAL_WIN", 8 );
	if( hb_xvmArrayPush() ) break;
	if( hb_xvmFunction( 1 ) ) break;
	hb_xvmPopLocal( 5 );
lab00004: ;
	hb_xvmSetLine( 727 );
	hb_xvmPushLocalByRef( 3 );
	hb_xvmPushStringConst( "<tr>", 4 );
	if( hb_xvmPlusEqPop() ) break;
	hb_xvmSetLine( 728 );
	hb_xvmPushLocalByRef( 3 );
	hb_xvmPushStringConst( "<td><a href=\"", 13 );
	hb_xvmPushLocal( 4 );
	hb_xvmPushStringConst( "DIR_NAME", 8 );
	if( hb_xvmArrayPush() ) break;
	if( hb_xvmPlus() ) break;
	hb_xvmPushStringConst( ".html\"><strong>", 15 );
	if( hb_xvmPlus() ) break;
	hb_xvmPushFuncSymbol( symbols + 63 );
	hb_xvmPushLocal( 4 );
	hb_xvmPushStringConst( "CANONICAL", 9 );
	if( hb_xvmArrayPush() ) break;
	if( hb_xvmFunction( 1 ) ) break;
	if( hb_xvmPlus() ) break;
	hb_xvmPushStringConst( "</strong></a></td>", 18 );
	if( hb_xvmPlus() ) break;
	if( hb_xvmPlusEqPop() ) break;
	hb_xvmSetLine( 729 );
	hb_xvmPushLocalByRef( 3 );
	hb_xvmPushStringConst( "<td><code>", 10 );
	hb_xvmPushFuncSymbol( symbols + 63 );
	hb_xvmPushLocal( 4 );
	hb_xvmPushStringConst( "DIR_NAME", 8 );
	if( hb_xvmArrayPush() ) break;
	if( hb_xvmFunction( 1 ) ) break;
	if( hb_xvmPlus() ) break;
	hb_xvmPushStringConst( "</code></td>", 12 );
	if( hb_xvmPlus() ) break;
	if( hb_xvmPlusEqPop() ) break;
	hb_xvmSetLine( 730 );
	hb_xvmPushLocalByRef( 3 );
	hb_xvmPushStringConst( "<td>", 4 );
	hb_xvmPushFuncSymbol( symbols + 63 );
	hb_xvmPushFuncSymbol( symbols + 21 );
	hb_xvmPushLocal( 4 );
	hb_xvmPushStringConst( "EVAL_LINUX", 10 );
	if( hb_xvmArrayPush() ) break;
	hb_xvmPushStringConst( "PROVIDES", 8 );
	hb_xvmPushFuncSymbol( symbols + 21 );
	hb_xvmPushLocal( 4 );
	hb_xvmPushStringConst( "EVAL_WIN", 8 );
	if( hb_xvmArrayPush() ) break;
	hb_xvmPushStringConst( "PROVIDES", 8 );
	hb_xvmPushStringConst( "-", 1 );
	if( hb_xvmFunction( 3 ) ) break;
	if( hb_xvmFunction( 3 ) ) break;
	if( hb_xvmFunction( 1 ) ) break;
	if( hb_xvmPlus() ) break;
	hb_xvmPushStringConst( "</td>", 5 );
	if( hb_xvmPlus() ) break;
	if( hb_xvmPlusEqPop() ) break;
	hb_xvmSetLine( 731 );
	hb_xvmPushLocalByRef( 3 );
	hb_xvmPushStringConst( "<td><span class=\"badge-fetch ", 29 );
	hb_xvmPushFuncSymbol( symbols + 64 );
	hb_xvmPushFuncSymbol( symbols + 28 );
	hb_xvmPushLocal( 5 );
	hb_xvmPushInteger( 3 );
	if( hb_xvmFunction( 2 ) ) break;
	if( hb_xvmFunction( 1 ) ) break;
	if( hb_xvmPlus() ) break;
	hb_xvmPushStringConst( "\">", 2 );
	if( hb_xvmPlus() ) break;
	hb_xvmPushLocal( 5 );
	if( hb_xvmPlus() ) break;
	hb_xvmPushStringConst( "</span></td>", 12 );
	if( hb_xvmPlus() ) break;
	if( hb_xvmPlusEqPop() ) break;
	hb_xvmSetLine( 732 );
	hb_xvmPushLocalByRef( 3 );
	hb_xvmPushStringConst( "</tr>", 5 );
	hb_xvmPushFuncSymbol( symbols + 16 );
	if( hb_xvmFunction( 0 ) ) break;
	if( hb_xvmPlus() ) break;
	if( hb_xvmPlusEqPop() ) break;
	hb_xvmSetLine( 733 );
lab00005: ;
	if( hb_xvmEnumNext() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( fValue )
		goto lab00001;
lab00006: ;
	hb_xvmEnumEnd();
	hb_xvmSetLine( 735 );
	hb_xvmPushLocalByRef( 3 );
	hb_xvmPushStringConst( "</table>", 8 );
	hb_xvmPushFuncSymbol( symbols + 16 );
	if( hb_xvmFunction( 0 ) ) break;
	if( hb_xvmPlus() ) break;
	if( hb_xvmPlusEqPop() ) break;
	hb_xvmSetLine( 737 );
	hb_xvmPushFuncSymbol( symbols + 65 );
	hb_xvmPushLocal( 2 );
	hb_xvmPushFuncSymbol( symbols + 10 );
	if( hb_xvmFunction( 0 ) ) break;
	if( hb_xvmPlus() ) break;
	hb_xvmPushStringConst( "midx.inc.html", 13 );
	if( hb_xvmPlus() ) break;
	hb_xvmPushFuncSymbol( symbols + 30 );
	hb_xvmPushLocal( 3 );
	hb_xvmPushLocal( 6 );
	if( hb_xvmAddInt( 1L ) ) break;
	if( hb_xvmFunction( 2 ) ) break;
	if( hb_xvmDo( 2 ) ) break;
	hb_xvmSetLine( 739 );
	hb_xvmPushLocalByRef( 3 );
	hb_xvmPushFuncSymbol( symbols + 66 );
	if( hb_xvmFunction( 0 ) ) break;
	if( hb_xvmPlusEqPop() ) break;
	hb_xvmSetLine( 741 );
	hb_xvmPushFuncSymbol( symbols + 65 );
	hb_xvmPushLocal( 2 );
	hb_xvmPushFuncSymbol( symbols + 10 );
	if( hb_xvmFunction( 0 ) ) break;
	if( hb_xvmPlus() ) break;
	hb_xvmPushStringConst( "index.html", 10 );
	if( hb_xvmPlus() ) break;
	hb_xvmPushLocal( 3 );
	if( hb_xvmDo( 2 ) ) break;
	hb_xvmSetLine( 742 );
	/* *** END PROC *** */
   } while( 0 );
}

HB_FUNC_STATIC( GENERATEPACKAGEPAGES )
{
   HB_BOOL fValue;
   do {
	hb_xvmFrame( 8, 3 );
	hb_xvmSetLine( 746 );
	hb_xvmPushFuncSymbol( symbols + 67 );
	if( hb_xvmFunction( 0 ) ) break;
	hb_xvmPopLocal( 10 );
	hb_xvmSetLine( 748 );
	hb_xvmPushLocal( 1 );
	hb_xvmPushLocalByRef( 4 );
	if( hb_xvmEnumStart( 1, 1 ) ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00033;
lab00001: ;
	hb_xvmSetLine( 749 );
	hb_xvmPushFuncSymbol( symbols + 50 );
	hb_xvmPushLocal( 4 );
	hb_xvmPushStringConst( "EVAL_LINUX", 10 );
	if( hb_xvmArrayPush() ) break;
	hb_xvmPushStringConst( "!!!ERROR!!!", 11 );
	if( hb_xvmFunction( 2 ) ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( fValue )
		goto lab00002;
	hb_xvmSetLine( 750 );
	hb_xvmPushFuncSymbol( symbols + 62 );
	hb_xvmPushLocal( 4 );
	hb_xvmPushStringConst( "EVAL_LINUX", 10 );
	if( hb_xvmArrayPush() ) break;
	if( hb_xvmFunction( 1 ) ) break;
	hb_xvmPopLocal( 7 );
	goto lab00003;
lab00002: ;
	hb_xvmSetLine( 752 );
	hb_xvmPushFuncSymbol( symbols + 62 );
	hb_xvmPushLocal( 4 );
	hb_xvmPushStringConst( "EVAL_WIN", 8 );
	if( hb_xvmArrayPush() ) break;
	if( hb_xvmFunction( 1 ) ) break;
	hb_xvmPopLocal( 7 );
lab00003: ;
	hb_xvmSetLine( 754 );
	hb_xvmPushFuncSymbol( symbols + 61 );
	hb_xvmPushStringConst( "Package: ", 9 );
	hb_xvmPushLocal( 4 );
	hb_xvmPushStringConst( "CANONICAL", 9 );
	if( hb_xvmArrayPush() ) break;
	if( hb_xvmPlus() ) break;
	if( hb_xvmFunction( 1 ) ) break;
	hb_xvmPopLocal( 5 );
	hb_xvmSetLine( 756 );
	hb_xvmPushLocalByRef( 5 );
	hb_xvmPushStringConst( "<h1>", 4 );
	hb_xvmPushFuncSymbol( symbols + 63 );
	hb_xvmPushLocal( 4 );
	hb_xvmPushStringConst( "CANONICAL", 9 );
	if( hb_xvmArrayPush() ) break;
	if( hb_xvmFunction( 1 ) ) break;
	if( hb_xvmPlus() ) break;
	hb_xvmPushStringConst( "</h1>", 5 );
	if( hb_xvmPlus() ) break;
	hb_xvmPushFuncSymbol( symbols + 16 );
	if( hb_xvmFunction( 0 ) ) break;
	if( hb_xvmPlus() ) break;
	if( hb_xvmPlusEqPop() ) break;
	hb_xvmSetLine( 759 );
	hb_xvmPushLocalByRef( 5 );
	hb_xvmPushStringConst( "<div class=\"meta-box\">", 22 );
	hb_xvmPushFuncSymbol( symbols + 16 );
	if( hb_xvmFunction( 0 ) ) break;
	if( hb_xvmPlus() ) break;
	if( hb_xvmPlusEqPop() ) break;
	hb_xvmSetLine( 760 );
	hb_xvmPushLocalByRef( 5 );
	hb_xvmPushStringConst( "  <div class=\"meta-row\"><div class=\"meta-label\">Directory:</div><div class=\"meta-value\"><code>", 94 );
	hb_xvmPushFuncSymbol( symbols + 63 );
	hb_xvmPushLocal( 4 );
	hb_xvmPushStringConst( "PATH", 4 );
	if( hb_xvmArrayPush() ) break;
	if( hb_xvmFunction( 1 ) ) break;
	if( hb_xvmPlus() ) break;
	hb_xvmPushStringConst( "</code></div></div>", 19 );
	if( hb_xvmPlus() ) break;
	hb_xvmPushFuncSymbol( symbols + 16 );
	if( hb_xvmFunction( 0 ) ) break;
	if( hb_xvmPlus() ) break;
	if( hb_xvmPlusEqPop() ) break;
	hb_xvmSetLine( 761 );
	hb_xvmPushLocalByRef( 5 );
	hb_xvmPushStringConst( "  <div class=\"meta-row\"><div class=\"meta-label\">Fetch Style:</div><div class=\"meta-value\"><span class=\"badge-fetch ", 115 );
	hb_xvmPushFuncSymbol( symbols + 64 );
	hb_xvmPushFuncSymbol( symbols + 28 );
	hb_xvmPushLocal( 7 );
	hb_xvmPushInteger( 3 );
	if( hb_xvmFunction( 2 ) ) break;
	if( hb_xvmFunction( 1 ) ) break;
	if( hb_xvmPlus() ) break;
	hb_xvmPushStringConst( "\">", 2 );
	if( hb_xvmPlus() ) break;
	hb_xvmPushLocal( 7 );
	if( hb_xvmPlus() ) break;
	hb_xvmPushStringConst( "</span></div></div>", 19 );
	if( hb_xvmPlus() ) break;
	hb_xvmPushFuncSymbol( symbols + 16 );
	if( hb_xvmFunction( 0 ) ) break;
	if( hb_xvmPlus() ) break;
	if( hb_xvmPlusEqPop() ) break;
	hb_xvmSetLine( 762 );
	hb_xvmPushLocalByRef( 5 );
	hb_xvmPushStringConst( "  <div class=\"meta-row\"><div class=\"meta-label\">From:</div><div class=\"meta-value\">", 83 );
	hb_xvmPushFuncSymbol( symbols + 16 );
	if( hb_xvmFunction( 0 ) ) break;
	if( hb_xvmPlus() ) break;
	if( hb_xvmPlusEqPop() ) break;
	hb_xvmSetLine( 763 );
	hb_xvmHashGen( 0 );
	hb_xvmPopLocal( 11 );
	hb_xvmSetLine( 764 );
	hb_xvmPushLocal( 4 );
	hb_xvmPushStringConst( "EVAL_LINUX", 10 );
	if( hb_xvmArrayPush() ) break;
	hb_xvmPushLocal( 4 );
	hb_xvmPushStringConst( "EVAL_WIN", 8 );
	if( hb_xvmArrayPush() ) break;
	hb_xvmArrayGen( 2 );
	hb_xvmPushLocalByRef( 8 );
	if( hb_xvmEnumStart( 1, 1 ) ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00009;
lab00004: ;
	hb_xvmSetLine( 765 );
	hb_xvmPushFuncSymbol( symbols + 50 );
	hb_xvmPushLocal( 11 );
	hb_xvmPushFuncSymbol( symbols + 21 );
	hb_xvmPushLocal( 8 );
	hb_xvmPushStringConst( "SRCURL", 6 );
	hb_xvmPushStringConst( "", 0 );
	if( hb_xvmFunction( 3 ) ) break;
	hb_xvmPushStringConst( "/", 1 );
	if( hb_xvmPlus() ) break;
	hb_xvmPushFuncSymbol( symbols + 21 );
	hb_xvmPushLocal( 8 );
	hb_xvmPushStringConst( "SOURCES", 7 );
	hb_xvmPushStringConst( "", 0 );
	if( hb_xvmFunction( 3 ) ) break;
	if( hb_xvmPlus() ) break;
	if( hb_xvmFunction( 2 ) ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00005;
	hb_xvmSetLine( 766 );
	goto lab00008;
lab00005: ;
	hb_xvmSetLine( 768 );
	hb_xvmPushFuncSymbol( symbols + 50 );
	hb_xvmPushLocal( 8 );
	hb_xvmPushStringConst( "SRCURL", 6 );
	if( hb_xvmFunction( 2 ) ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00006;
	hb_xvmSetLine( 769 );
	hb_xvmPushLocalByRef( 5 );
	hb_xvmPushStringConst( "    ", 4 );
	hb_xvmPushLocal( 8 );
	hb_xvmPushStringConst( "SRCURL", 6 );
	if( hb_xvmArrayPush() ) break;
	if( hb_xvmPlus() ) break;
	if( hb_xvmPlusEqPop() ) break;
lab00006: ;
	hb_xvmSetLine( 771 );
	hb_xvmPushFuncSymbol( symbols + 50 );
	hb_xvmPushLocal( 8 );
	hb_xvmPushStringConst( "SOURCES", 7 );
	if( hb_xvmFunction( 2 ) ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00007;
	hb_xvmSetLine( 773 );
	hb_xvmPushLocalByRef( 5 );
	hb_xvmPushStringConst( "/", 1 );
	hb_xvmPushFuncSymbol( symbols + 30 );
	hb_xvmPushLocal( 8 );
	hb_xvmPushStringConst( "SOURCES", 7 );
	if( hb_xvmArrayPush() ) break;
	hb_xvmPushFuncSymbol( symbols + 38 );
	hb_xvmPushStringConst( "@", 1 );
	hb_xvmPushLocal( 8 );
	hb_xvmPushStringConst( "SOURCES", 7 );
	if( hb_xvmArrayPush() ) break;
	if( hb_xvmFunction( 2 ) ) break;
	if( hb_xvmAddInt( 1L ) ) break;
	if( hb_xvmFunction( 2 ) ) break;
	if( hb_xvmPlus() ) break;
	hb_xvmPushStringConst( "</br>", 5 );
	if( hb_xvmPlus() ) break;
	hb_xvmPushFuncSymbol( symbols + 16 );
	if( hb_xvmFunction( 0 ) ) break;
	if( hb_xvmPlus() ) break;
	if( hb_xvmPlusEqPop() ) break;
lab00007: ;
	hb_xvmSetLine( 775 );
	hb_xvmPushNil();
	hb_xvmPushLocal( 11 );
	hb_xvmPushFuncSymbol( symbols + 21 );
	hb_xvmPushLocal( 8 );
	hb_xvmPushStringConst( "SRCURL", 6 );
	hb_xvmPushStringConst( "", 0 );
	if( hb_xvmFunction( 3 ) ) break;
	hb_xvmPushStringConst( "/", 1 );
	if( hb_xvmPlus() ) break;
	hb_xvmPushFuncSymbol( symbols + 21 );
	hb_xvmPushLocal( 8 );
	hb_xvmPushStringConst( "SOURCES", 7 );
	hb_xvmPushStringConst( "", 0 );
	if( hb_xvmFunction( 3 ) ) break;
	if( hb_xvmPlus() ) break;
	if( hb_xvmArrayPop() ) break;
	hb_xvmSetLine( 776 );
lab00008: ;
	if( hb_xvmEnumNext() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( fValue )
		goto lab00004;
lab00009: ;
	hb_xvmEnumEnd();
	hb_xvmSetLine( 777 );
	hb_xvmPushLocalByRef( 5 );
	hb_xvmPushStringConst( "  </div></div>", 14 );
	hb_xvmPushFuncSymbol( symbols + 16 );
	if( hb_xvmFunction( 0 ) ) break;
	if( hb_xvmPlus() ) break;
	if( hb_xvmPlusEqPop() ) break;
	hb_xvmSetLine( 778 );
	hb_xvmPushLocalByRef( 5 );
	hb_xvmPushStringConst( "</div>", 6 );
	hb_xvmPushFuncSymbol( symbols + 16 );
	if( hb_xvmFunction( 0 ) ) break;
	if( hb_xvmPlus() ) break;
	if( hb_xvmPlusEqPop() ) break;
	hb_xvmSetLine( 781 );
	hb_xvmPushFuncSymbol( symbols + 68 );
	hb_xvmPushLocal( 4 );
	hb_xvmPushStringConst( "DEPS_LINUX", 10 );
	if( hb_xvmArrayPush() ) break;
	hb_xvmPushLocal( 4 );
	hb_xvmPushStringConst( "DEPS_WIN", 8 );
	if( hb_xvmArrayPush() ) break;
	if( hb_xvmFunction( 2 ) ) break;
	if( hb_xvmNot() ) break;
	hb_xvmPopLocal( 9 );
	hb_xvmSetLine( 783 );
	hb_xvmPushLocal( 9 );
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( fValue )
		goto lab00010;
	hb_xvmSetLine( 785 );
	hb_xvmPushLocalByRef( 5 );
	hb_xvmPushStringConst( "<h2>Declared Dependencies</h2>", 30 );
	hb_xvmPushFuncSymbol( symbols + 16 );
	if( hb_xvmFunction( 0 ) ) break;
	if( hb_xvmPlus() ) break;
	if( hb_xvmPlusEqPop() ) break;
	hb_xvmSetLine( 786 );
	hb_xvmPushLocalByRef( 5 );
	hb_xvmPushFuncSymbol( symbols + 69 );
	hb_xvmPushLocal( 4 );
	hb_xvmPushStringConst( "DEPS_LINUX", 10 );
	if( hb_xvmArrayPush() ) break;
	hb_xvmPushLocal( 2 );
	if( hb_xvmFunction( 2 ) ) break;
	if( hb_xvmPlusEqPop() ) break;
	goto lab00011;
lab00010: ;
	hb_xvmSetLine( 789 );
	hb_xvmPushLocalByRef( 5 );
	hb_xvmPushStringConst( "<h2>Declared Dependencies <span class=\"badge-diff\">Platform Divergence</span></h2>", 82 );
	hb_xvmPushFuncSymbol( symbols + 16 );
	if( hb_xvmFunction( 0 ) ) break;
	if( hb_xvmPlus() ) break;
	if( hb_xvmPlusEqPop() ) break;
	hb_xvmSetLine( 790 );
	hb_xvmPushLocalByRef( 5 );
	hb_xvmPushStringConst( "<div class=\"platform-grid\">", 27 );
	hb_xvmPushFuncSymbol( symbols + 16 );
	if( hb_xvmFunction( 0 ) ) break;
	if( hb_xvmPlus() ) break;
	if( hb_xvmPlusEqPop() ) break;
	hb_xvmSetLine( 791 );
	hb_xvmPushLocalByRef( 5 );
	hb_xvmPushStringConst( "  <div class=\"platform-col\">", 28 );
	hb_xvmPushFuncSymbol( symbols + 16 );
	if( hb_xvmFunction( 0 ) ) break;
	if( hb_xvmPlus() ) break;
	if( hb_xvmPlusEqPop() ) break;
	hb_xvmSetLine( 792 );
	hb_xvmPushLocalByRef( 5 );
	hb_xvmPushStringConst( "    <h3>Linux Dependencies</h3>", 31 );
	hb_xvmPushFuncSymbol( symbols + 16 );
	if( hb_xvmFunction( 0 ) ) break;
	if( hb_xvmPlus() ) break;
	if( hb_xvmPlusEqPop() ) break;
	hb_xvmSetLine( 793 );
	hb_xvmPushLocalByRef( 5 );
	hb_xvmPushFuncSymbol( symbols + 69 );
	hb_xvmPushLocal( 4 );
	hb_xvmPushStringConst( "DEPS_LINUX", 10 );
	if( hb_xvmArrayPush() ) break;
	hb_xvmPushLocal( 2 );
	hb_xvmPushLocal( 4 );
	hb_xvmPushStringConst( "DEPS_WIN", 8 );
	if( hb_xvmArrayPush() ) break;
	if( hb_xvmFunction( 3 ) ) break;
	if( hb_xvmPlusEqPop() ) break;
	hb_xvmSetLine( 794 );
	hb_xvmPushLocalByRef( 5 );
	hb_xvmPushStringConst( "  </div>", 8 );
	hb_xvmPushFuncSymbol( symbols + 16 );
	if( hb_xvmFunction( 0 ) ) break;
	if( hb_xvmPlus() ) break;
	if( hb_xvmPlusEqPop() ) break;
	hb_xvmSetLine( 795 );
	hb_xvmPushLocalByRef( 5 );
	hb_xvmPushStringConst( "  <div class=\"platform-col\">", 28 );
	hb_xvmPushFuncSymbol( symbols + 16 );
	if( hb_xvmFunction( 0 ) ) break;
	if( hb_xvmPlus() ) break;
	if( hb_xvmPlusEqPop() ) break;
	hb_xvmSetLine( 796 );
	hb_xvmPushLocalByRef( 5 );
	hb_xvmPushStringConst( "    <h3>Windows Dependencies</h3>", 33 );
	hb_xvmPushFuncSymbol( symbols + 16 );
	if( hb_xvmFunction( 0 ) ) break;
	if( hb_xvmPlus() ) break;
	if( hb_xvmPlusEqPop() ) break;
	hb_xvmSetLine( 797 );
	hb_xvmPushLocalByRef( 5 );
	hb_xvmPushFuncSymbol( symbols + 69 );
	hb_xvmPushLocal( 4 );
	hb_xvmPushStringConst( "DEPS_WIN", 8 );
	if( hb_xvmArrayPush() ) break;
	hb_xvmPushLocal( 2 );
	hb_xvmPushLocal( 4 );
	hb_xvmPushStringConst( "DEPS_LINUX", 10 );
	if( hb_xvmArrayPush() ) break;
	if( hb_xvmFunction( 3 ) ) break;
	if( hb_xvmPlusEqPop() ) break;
	hb_xvmSetLine( 798 );
	hb_xvmPushLocalByRef( 5 );
	hb_xvmPushStringConst( "  </div>", 8 );
	hb_xvmPushFuncSymbol( symbols + 16 );
	if( hb_xvmFunction( 0 ) ) break;
	if( hb_xvmPlus() ) break;
	if( hb_xvmPlusEqPop() ) break;
	hb_xvmSetLine( 799 );
	hb_xvmPushLocalByRef( 5 );
	hb_xvmPushStringConst( "</div>", 6 );
	hb_xvmPushFuncSymbol( symbols + 16 );
	if( hb_xvmFunction( 0 ) ) break;
	if( hb_xvmPlus() ) break;
	if( hb_xvmPlusEqPop() ) break;
lab00011: ;
	hb_xvmSetLine( 826 );
	hb_xvmPushLocalByRef( 5 );
	hb_xvmPushStringConst( "<details class=\"pkg-collapsible\" open>", 38 );
	hb_xvmPushFuncSymbol( symbols + 16 );
	if( hb_xvmFunction( 0 ) ) break;
	if( hb_xvmPlus() ) break;
	if( hb_xvmPlusEqPop() ) break;
	hb_xvmSetLine( 827 );
	hb_xvmPushLocalByRef( 5 );
	hb_xvmPushStringConst( "<summary><h2>Probed Makefile variables (Linux zig 64-bit)</h2></summary>", 72 );
	hb_xvmPushFuncSymbol( symbols + 16 );
	if( hb_xvmFunction( 0 ) ) break;
	if( hb_xvmPlus() ) break;
	if( hb_xvmPlusEqPop() ) break;
	hb_xvmSetLine( 828 );
	hb_xvmPushFuncSymbol( symbols + 31 );
	hb_xvmPushLocal( 4 );
	hb_xvmPushStringConst( "EVAL_LINUX", 10 );
	if( hb_xvmArrayPush() ) break;
	if( hb_xvmFunction( 1 ) ) break;
	if( hb_xvmGreaterThenIntIs( 0L, &fValue ) ) break;
	if( !fValue )
		goto lab00019;
	hb_xvmSetLine( 829 );
	hb_xvmPushLocalByRef( 5 );
	hb_xvmPushStringConst( "<table class=\"pkg-table\">", 25 );
	hb_xvmPushFuncSymbol( symbols + 16 );
	if( hb_xvmFunction( 0 ) ) break;
	if( hb_xvmPlus() ) break;
	if( hb_xvmPlusEqPop() ) break;
	hb_xvmSetLine( 830 );
	hb_xvmPushLocalByRef( 5 );
	hb_xvmPushStringConst( "<tr><th>Variable (in eval order)</th><th>Evaluated setting</th></tr>", 68 );
	hb_xvmPushFuncSymbol( symbols + 16 );
	if( hb_xvmFunction( 0 ) ) break;
	if( hb_xvmPlus() ) break;
	if( hb_xvmPlusEqPop() ) break;
	hb_xvmSetLine( 831 );
	hb_xvmPushLocal( 4 );
	hb_xvmPushStringConst( "EVAL_LINUX", 10 );
	if( hb_xvmArrayPush() ) break;
	hb_xvmPushLocalByRef( 8 );
	if( hb_xvmEnumStart( 1, 1 ) ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00018;
lab00012: ;
	hb_xvmSetLine( 832 );
	hb_xvmPushFuncSymbol( symbols + 38 );
	hb_xvmPushStringConst( " ", 1 );
	hb_xvmPushSymbol( symbols + 70 );
	hb_xvmPushLocalByRef( 8 );
	if( hb_xvmSend( 0 ) ) break;
	if( hb_xvmFunction( 2 ) ) break;
	if( hb_xvmGreaterThenIntIs( 0L, &fValue ) ) break;
	if( fValue )
		goto lab00013;
	hb_xvmPushFuncSymbol( symbols + 50 );
	hb_xvmPushLocal( 10 );
	hb_xvmPushSymbol( symbols + 70 );
	hb_xvmPushLocalByRef( 8 );
	if( hb_xvmSend( 0 ) ) break;
	if( hb_xvmFunction( 2 ) ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00014;
lab00013: ;
	hb_xvmSetLine( 833 );
	goto lab00017;
lab00014: ;
	hb_xvmSetLine( 835 );
	hb_xvmPushLocalByRef( 5 );
	hb_xvmPushStringConst( "<tr>", 4 );
	if( hb_xvmPlusEqPop() ) break;
	hb_xvmSetLine( 836 );
	hb_xvmPushLocalByRef( 5 );
	hb_xvmPushStringConst( "<td><code>", 10 );
	hb_xvmPushFuncSymbol( symbols + 63 );
	hb_xvmPushSymbol( symbols + 70 );
	hb_xvmPushLocalByRef( 8 );
	if( hb_xvmSend( 0 ) ) break;
	if( hb_xvmFunction( 1 ) ) break;
	if( hb_xvmPlus() ) break;
	hb_xvmPushStringConst( "</code></td>", 12 );
	if( hb_xvmPlus() ) break;
	if( hb_xvmPlusEqPop() ) break;
	hb_xvmSetLine( 837 );
	hb_xvmPushLocalByRef( 5 );
	hb_xvmPushStringConst( "<td>", 4 );
	if( hb_xvmPlusEqPop() ) break;
	hb_xvmSetLine( 838 );
	hb_xvmPushSymbol( symbols + 70 );
	hb_xvmPushLocalByRef( 8 );
	if( hb_xvmSend( 0 ) ) break;
	hb_xvmPushStringConst( "PACKAGE", 7 );
	if( hb_xvmExactlyEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00015;
	hb_xvmPushFuncSymbol( symbols + 71 );
	hb_xvmPushLocal( 8 );
	hb_xvmPushInteger( 4 );
	if( hb_xvmFunction( 2 ) ) break;
	hb_xvmPushStringConst( "hbpk", 4 );
	if( hb_xvmExactlyEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( fValue )
		goto lab00015;
	hb_xvmSetLine( 839 );
	hb_xvmPushLocalByRef( 5 );
	hb_xvmPushStringConst( "<em>", 4 );
	hb_xvmPushLocal( 8 );
	if( hb_xvmPlus() ) break;
	hb_xvmPushStringConst( "hbpk</em>", 9 );
	if( hb_xvmPlus() ) break;
	if( hb_xvmPlusEqPop() ) break;
	goto lab00016;
lab00015: ;
	hb_xvmSetLine( 841 );
	hb_xvmPushLocalByRef( 5 );
	hb_xvmPushStringConst( "<em>", 4 );
	hb_xvmPushLocal( 8 );
	if( hb_xvmPlus() ) break;
	hb_xvmPushStringConst( "</em>", 5 );
	if( hb_xvmPlus() ) break;
	if( hb_xvmPlusEqPop() ) break;
lab00016: ;
	hb_xvmSetLine( 843 );
	hb_xvmPushLocalByRef( 5 );
	hb_xvmPushStringConst( "</td></tr>", 10 );
	hb_xvmPushFuncSymbol( symbols + 16 );
	if( hb_xvmFunction( 0 ) ) break;
	if( hb_xvmPlus() ) break;
	if( hb_xvmPlusEqPop() ) break;
	hb_xvmSetLine( 844 );
lab00017: ;
	if( hb_xvmEnumNext() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( fValue )
		goto lab00012;
lab00018: ;
	hb_xvmEnumEnd();
	hb_xvmSetLine( 845 );
	hb_xvmPushLocalByRef( 5 );
	hb_xvmPushStringConst( "</table>", 8 );
	hb_xvmPushFuncSymbol( symbols + 16 );
	if( hb_xvmFunction( 0 ) ) break;
	if( hb_xvmPlus() ) break;
	if( hb_xvmPlusEqPop() ) break;
	goto lab00020;
lab00019: ;
	hb_xvmSetLine( 847 );
	hb_xvmPushLocalByRef( 5 );
	hb_xvmPushStringConst( "<p>No variables evaluated.</p>", 30 );
	hb_xvmPushFuncSymbol( symbols + 16 );
	if( hb_xvmFunction( 0 ) ) break;
	if( hb_xvmPlus() ) break;
	if( hb_xvmPlusEqPop() ) break;
lab00020: ;
	hb_xvmSetLine( 849 );
	hb_xvmPushLocalByRef( 5 );
	hb_xvmPushStringConst( "</details>", 10 );
	hb_xvmPushFuncSymbol( symbols + 16 );
	if( hb_xvmFunction( 0 ) ) break;
	if( hb_xvmPlus() ) break;
	if( hb_xvmPlusEqPop() ) break;
	hb_xvmSetLine( 851 );
	hb_xvmPushLocalByRef( 5 );
	hb_xvmPushStringConst( "<details class=\"pkg-collapsible\">", 33 );
	hb_xvmPushFuncSymbol( symbols + 16 );
	if( hb_xvmFunction( 0 ) ) break;
	if( hb_xvmPlus() ) break;
	if( hb_xvmPlusEqPop() ) break;
	hb_xvmSetLine( 852 );
	hb_xvmPushLocalByRef( 5 );
	hb_xvmPushStringConst( "<summary><h2>Probed Makefile variables (Windows zig 64-bit)</h2></summary>", 74 );
	hb_xvmPushFuncSymbol( symbols + 16 );
	if( hb_xvmFunction( 0 ) ) break;
	if( hb_xvmPlus() ) break;
	if( hb_xvmPlusEqPop() ) break;
	hb_xvmSetLine( 853 );
	hb_xvmPushFuncSymbol( symbols + 31 );
	hb_xvmPushLocal( 4 );
	hb_xvmPushStringConst( "EVAL_WIN", 8 );
	if( hb_xvmArrayPush() ) break;
	if( hb_xvmFunction( 1 ) ) break;
	if( hb_xvmGreaterThenIntIs( 0L, &fValue ) ) break;
	if( !fValue )
		goto lab00028;
	hb_xvmSetLine( 854 );
	hb_xvmPushLocalByRef( 5 );
	hb_xvmPushStringConst( "<table class=\"pkg-table\">", 25 );
	hb_xvmPushFuncSymbol( symbols + 16 );
	if( hb_xvmFunction( 0 ) ) break;
	if( hb_xvmPlus() ) break;
	if( hb_xvmPlusEqPop() ) break;
	hb_xvmSetLine( 855 );
	hb_xvmPushLocalByRef( 5 );
	hb_xvmPushStringConst( "<tr><th>Variable (in eval order)</th><th>Evaluated setting</th></tr>", 68 );
	hb_xvmPushFuncSymbol( symbols + 16 );
	if( hb_xvmFunction( 0 ) ) break;
	if( hb_xvmPlus() ) break;
	if( hb_xvmPlusEqPop() ) break;
	hb_xvmSetLine( 856 );
	hb_xvmPushLocal( 4 );
	hb_xvmPushStringConst( "EVAL_WIN", 8 );
	if( hb_xvmArrayPush() ) break;
	hb_xvmPushLocalByRef( 8 );
	if( hb_xvmEnumStart( 1, 1 ) ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00027;
lab00021: ;
	hb_xvmSetLine( 857 );
	hb_xvmPushFuncSymbol( symbols + 38 );
	hb_xvmPushStringConst( " ", 1 );
	hb_xvmPushSymbol( symbols + 70 );
	hb_xvmPushLocalByRef( 8 );
	if( hb_xvmSend( 0 ) ) break;
	if( hb_xvmFunction( 2 ) ) break;
	if( hb_xvmGreaterThenIntIs( 0L, &fValue ) ) break;
	if( fValue )
		goto lab00022;
	hb_xvmPushFuncSymbol( symbols + 50 );
	hb_xvmPushLocal( 10 );
	hb_xvmPushSymbol( symbols + 70 );
	hb_xvmPushLocalByRef( 8 );
	if( hb_xvmSend( 0 ) ) break;
	if( hb_xvmFunction( 2 ) ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00023;
lab00022: ;
	hb_xvmSetLine( 858 );
	goto lab00026;
lab00023: ;
	hb_xvmSetLine( 860 );
	hb_xvmPushLocalByRef( 5 );
	hb_xvmPushStringConst( "<tr>", 4 );
	if( hb_xvmPlusEqPop() ) break;
	hb_xvmSetLine( 861 );
	hb_xvmPushLocalByRef( 5 );
	hb_xvmPushStringConst( "<td><code>", 10 );
	hb_xvmPushFuncSymbol( symbols + 63 );
	hb_xvmPushSymbol( symbols + 70 );
	hb_xvmPushLocalByRef( 8 );
	if( hb_xvmSend( 0 ) ) break;
	if( hb_xvmFunction( 1 ) ) break;
	if( hb_xvmPlus() ) break;
	hb_xvmPushStringConst( "</code></td>", 12 );
	if( hb_xvmPlus() ) break;
	if( hb_xvmPlusEqPop() ) break;
	hb_xvmSetLine( 862 );
	hb_xvmPushLocalByRef( 5 );
	hb_xvmPushStringConst( "<td>", 4 );
	if( hb_xvmPlusEqPop() ) break;
	hb_xvmSetLine( 863 );
	hb_xvmPushSymbol( symbols + 70 );
	hb_xvmPushLocalByRef( 8 );
	if( hb_xvmSend( 0 ) ) break;
	hb_xvmPushStringConst( "PACKAGE", 7 );
	if( hb_xvmExactlyEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00024;
	hb_xvmPushFuncSymbol( symbols + 71 );
	hb_xvmPushLocal( 8 );
	hb_xvmPushInteger( 4 );
	if( hb_xvmFunction( 2 ) ) break;
	hb_xvmPushStringConst( "hbpk", 4 );
	if( hb_xvmExactlyEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( fValue )
		goto lab00024;
	hb_xvmSetLine( 864 );
	hb_xvmPushLocalByRef( 5 );
	hb_xvmPushStringConst( "<em>", 4 );
	hb_xvmPushLocal( 8 );
	if( hb_xvmPlus() ) break;
	hb_xvmPushStringConst( "hbpk</em>", 9 );
	if( hb_xvmPlus() ) break;
	if( hb_xvmPlusEqPop() ) break;
	goto lab00025;
lab00024: ;
	hb_xvmSetLine( 866 );
	hb_xvmPushLocalByRef( 5 );
	hb_xvmPushStringConst( "<em>", 4 );
	hb_xvmPushLocal( 8 );
	if( hb_xvmPlus() ) break;
	hb_xvmPushStringConst( "</em>", 5 );
	if( hb_xvmPlus() ) break;
	if( hb_xvmPlusEqPop() ) break;
lab00025: ;
	hb_xvmSetLine( 868 );
	hb_xvmPushLocalByRef( 5 );
	hb_xvmPushStringConst( "</td></tr>", 10 );
	hb_xvmPushFuncSymbol( symbols + 16 );
	if( hb_xvmFunction( 0 ) ) break;
	if( hb_xvmPlus() ) break;
	if( hb_xvmPlusEqPop() ) break;
	hb_xvmSetLine( 869 );
lab00026: ;
	if( hb_xvmEnumNext() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( fValue )
		goto lab00021;
lab00027: ;
	hb_xvmEnumEnd();
	hb_xvmSetLine( 870 );
	hb_xvmPushLocalByRef( 5 );
	hb_xvmPushStringConst( "</table>", 8 );
	hb_xvmPushFuncSymbol( symbols + 16 );
	if( hb_xvmFunction( 0 ) ) break;
	if( hb_xvmPlus() ) break;
	if( hb_xvmPlusEqPop() ) break;
	goto lab00029;
lab00028: ;
	hb_xvmSetLine( 872 );
	hb_xvmPushLocalByRef( 5 );
	hb_xvmPushStringConst( "<p>No variables evaluated.</p>", 30 );
	hb_xvmPushFuncSymbol( symbols + 16 );
	if( hb_xvmFunction( 0 ) ) break;
	if( hb_xvmPlus() ) break;
	if( hb_xvmPlusEqPop() ) break;
lab00029: ;
	hb_xvmSetLine( 874 );
	hb_xvmPushLocalByRef( 5 );
	hb_xvmPushStringConst( "</details>", 10 );
	hb_xvmPushFuncSymbol( symbols + 16 );
	if( hb_xvmFunction( 0 ) ) break;
	if( hb_xvmPlus() ) break;
	if( hb_xvmPlusEqPop() ) break;
	hb_xvmSetLine( 877 );
	hb_xvmPushFuncSymbol( symbols + 31 );
	hb_xvmPushLocal( 4 );
	hb_xvmPushStringConst( "CHILDREN", 8 );
	if( hb_xvmArrayPush() ) break;
	if( hb_xvmFunction( 1 ) ) break;
	if( hb_xvmGreaterThenIntIs( 0L, &fValue ) ) break;
	if( !fValue )
		goto lab00032;
	hb_xvmSetLine( 878 );
	hb_xvmPushLocalByRef( 5 );
	hb_xvmPushStringConst( "<h2>Sub-Packages / Children</h2>", 32 );
	hb_xvmPushFuncSymbol( symbols + 16 );
	if( hb_xvmFunction( 0 ) ) break;
	if( hb_xvmPlus() ) break;
	if( hb_xvmPlusEqPop() ) break;
	hb_xvmSetLine( 879 );
	hb_xvmPushLocalByRef( 5 );
	hb_xvmPushStringConst( "<div class=\"badge-group\">", 25 );
	hb_xvmPushFuncSymbol( symbols + 16 );
	if( hb_xvmFunction( 0 ) ) break;
	if( hb_xvmPlus() ) break;
	if( hb_xvmPlusEqPop() ) break;
	hb_xvmSetLine( 880 );
	hb_xvmPushLocal( 4 );
	hb_xvmPushStringConst( "CHILDREN", 8 );
	if( hb_xvmArrayPush() ) break;
	hb_xvmPushLocalByRef( 6 );
	if( hb_xvmEnumStart( 1, 1 ) ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00031;
lab00030: ;
	hb_xvmSetLine( 881 );
	hb_xvmPushLocalByRef( 5 );
	hb_xvmPushStringConst( "<a href=\"", 9 );
	hb_xvmPushLocal( 6 );
	if( hb_xvmPlus() ) break;
	hb_xvmPushStringConst( ".html\" class=\"badge child\">", 27 );
	if( hb_xvmPlus() ) break;
	hb_xvmPushFuncSymbol( symbols + 63 );
	hb_xvmPushLocal( 6 );
	if( hb_xvmFunction( 1 ) ) break;
	if( hb_xvmPlus() ) break;
	hb_xvmPushStringConst( "</a>", 4 );
	if( hb_xvmPlus() ) break;
	hb_xvmPushFuncSymbol( symbols + 16 );
	if( hb_xvmFunction( 0 ) ) break;
	if( hb_xvmPlus() ) break;
	if( hb_xvmPlusEqPop() ) break;
	hb_xvmSetLine( 882 );
	if( hb_xvmEnumNext() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( fValue )
		goto lab00030;
lab00031: ;
	hb_xvmEnumEnd();
	hb_xvmSetLine( 883 );
	hb_xvmPushLocalByRef( 5 );
	hb_xvmPushStringConst( "</div>", 6 );
	hb_xvmPushFuncSymbol( symbols + 16 );
	if( hb_xvmFunction( 0 ) ) break;
	if( hb_xvmPlus() ) break;
	if( hb_xvmPlusEqPop() ) break;
lab00032: ;
	hb_xvmSetLine( 887 );
	hb_xvmPushLocalByRef( 5 );
	hb_xvmPushStringConst( "<h2>Makefile Header Source</h2>", 31 );
	hb_xvmPushFuncSymbol( symbols + 16 );
	if( hb_xvmFunction( 0 ) ) break;
	if( hb_xvmPlus() ) break;
	if( hb_xvmPlusEqPop() ) break;
	hb_xvmSetLine( 888 );
	hb_xvmPushLocalByRef( 5 );
	hb_xvmPushStringConst( "<pre><code>", 11 );
	hb_xvmPushFuncSymbol( symbols + 63 );
	hb_xvmPushLocal( 4 );
	hb_xvmPushStringConst( "RAW_SRC", 7 );
	if( hb_xvmArrayPush() ) break;
	if( hb_xvmFunction( 1 ) ) break;
	if( hb_xvmPlus() ) break;
	hb_xvmPushStringConst( "</code></pre>", 13 );
	if( hb_xvmPlus() ) break;
	hb_xvmPushFuncSymbol( symbols + 16 );
	if( hb_xvmFunction( 0 ) ) break;
	if( hb_xvmPlus() ) break;
	if( hb_xvmPlusEqPop() ) break;
	hb_xvmSetLine( 890 );
	hb_xvmPushLocalByRef( 5 );
	hb_xvmPushFuncSymbol( symbols + 66 );
	if( hb_xvmFunction( 0 ) ) break;
	if( hb_xvmPlusEqPop() ) break;
	hb_xvmSetLine( 892 );
	hb_xvmPushFuncSymbol( symbols + 65 );
	hb_xvmPushLocal( 3 );
	hb_xvmPushFuncSymbol( symbols + 10 );
	if( hb_xvmFunction( 0 ) ) break;
	if( hb_xvmPlus() ) break;
	hb_xvmPushLocal( 4 );
	hb_xvmPushStringConst( "DIR_NAME", 8 );
	if( hb_xvmArrayPush() ) break;
	if( hb_xvmPlus() ) break;
	hb_xvmPushStringConst( ".html", 5 );
	if( hb_xvmPlus() ) break;
	hb_xvmPushLocal( 5 );
	if( hb_xvmDo( 2 ) ) break;
	hb_xvmSetLine( 893 );
	if( hb_xvmEnumNext() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( fValue )
		goto lab00001;
lab00033: ;
	hb_xvmEnumEnd();
	hb_xvmSetLine( 894 );
	/* *** END PROC *** */
   } while( 0 );
}

HB_FUNC_STATIC( EXTRACTPLATFORMDEPS )
{
   HB_BOOL fValue;
   do {
	hb_xvmFrame( 4, 1 );
	hb_xvmSetLine( 898 );
	hb_xvmPushFuncSymbol( symbols + 21 );
	hb_xvmPushLocal( 1 );
	hb_xvmPushStringConst( "DEPENDS", 7 );
	hb_xvmPushFuncSymbol( symbols + 21 );
	hb_xvmPushLocal( 1 );
	hb_xvmPushStringConst( "REQUIRES", 8 );
	hb_xvmPushStringConst( "", 0 );
	if( hb_xvmFunction( 3 ) ) break;
	if( hb_xvmFunction( 3 ) ) break;
	hb_xvmPopLocal( 2 );
	hb_xvmSetLine( 899 );
	hb_xvmPushFuncSymbol( symbols + 15 );
	hb_xvmPushLocal( 2 );
	hb_xvmPushStringConst( " ", 1 );
	if( hb_xvmFunction( 2 ) ) break;
	hb_xvmPopLocal( 3 );
	hb_xvmSetLine( 900 );
	hb_xvmArrayGen( 0 );
	hb_xvmPopLocal( 4 );
	hb_xvmSetLine( 902 );
	hb_xvmPushLocal( 3 );
	hb_xvmPushLocalByRef( 5 );
	if( hb_xvmEnumStart( 1, 1 ) ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00003;
lab00001: ;
	hb_xvmSetLine( 903 );
	hb_xvmPushFuncSymbol( symbols + 46 );
	hb_xvmPushFuncSymbol( symbols + 22 );
	hb_xvmPushLocal( 5 );
	if( hb_xvmFunction( 1 ) ) break;
	if( hb_xvmFunction( 1 ) ) break;
	hb_xvmPopLocal( 5 );
	hb_xvmSetLine( 904 );
	hb_xvmPushFuncSymbol( symbols + 23 );
	hb_xvmPushLocal( 5 );
	if( hb_xvmFunction( 1 ) ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( fValue )
		goto lab00002;
	hb_xvmPushFuncSymbol( symbols + 72 );
	hb_xvmPushLocal( 4 );
	hb_xvmPushLocal( 5 );
	if( hb_xvmFunction( 2 ) ) break;
	if( hb_xvmEqualIntIs( 0L, &fValue ) ) break;
	if( !fValue )
		goto lab00002;
	hb_xvmSetLine( 905 );
	hb_xvmPushFuncSymbol( symbols + 13 );
	hb_xvmPushLocal( 4 );
	hb_xvmPushLocal( 5 );
	if( hb_xvmDo( 2 ) ) break;
lab00002: ;
	hb_xvmSetLine( 907 );
	if( hb_xvmEnumNext() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( fValue )
		goto lab00001;
lab00003: ;
	hb_xvmEnumEnd();
	hb_xvmSetLine( 908 );
	hb_xvmPushLocal( 4 );
	hb_xvmRetValue();
	/* *** END PROC *** */
   } while( 0 );
}

HB_FUNC_STATIC( COMPAREDEPS )
{
   HB_BOOL fValue;
   do {
	hb_xvmFrame( 1, 2 );
	hb_xvmSetLine( 913 );
	hb_xvmPushFuncSymbol( symbols + 31 );
	hb_xvmPushLocal( 1 );
	if( hb_xvmFunction( 1 ) ) break;
	hb_xvmPushFuncSymbol( symbols + 31 );
	hb_xvmPushLocal( 2 );
	if( hb_xvmFunction( 1 ) ) break;
	if( hb_xvmNotEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00001;
	hb_xvmSetLine( 914 );
	hb_xvmPushLogical( HB_FALSE );
	hb_xvmRetValue();
	/* *** END PROC *** */
	break;
lab00001: ;
	hb_xvmSetLine( 917 );
	hb_xvmPushLocal( 1 );
	hb_xvmPushLocalByRef( 3 );
	if( hb_xvmEnumStart( 1, 1 ) ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00004;
lab00002: ;
	hb_xvmSetLine( 918 );
	hb_xvmPushFuncSymbol( symbols + 72 );
	hb_xvmPushLocal( 2 );
	hb_xvmPushLocal( 3 );
	if( hb_xvmFunction( 2 ) ) break;
	if( hb_xvmEqualIntIs( 0L, &fValue ) ) break;
	if( !fValue )
		goto lab00003;
	hb_xvmSetLine( 919 );
	hb_xvmPushLogical( HB_FALSE );
	hb_xvmRetValue();
	/* *** END PROC *** */
	break;
lab00003: ;
	hb_xvmSetLine( 921 );
	if( hb_xvmEnumNext() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( fValue )
		goto lab00002;
lab00004: ;
	hb_xvmEnumEnd();
	hb_xvmSetLine( 922 );
	hb_xvmPushLogical( HB_TRUE );
	hb_xvmRetValue();
	/* *** END PROC *** */
   } while( 0 );
}

HB_FUNC_STATIC( RENDERDEPENDENCYLIST )
{
   HB_BOOL fValue;
   do {
	hb_xvmFrame( 3, 3 );
	hb_xvmSetLine( 925 );
	hb_xvmPushStringConst( "", 0 );
	hb_xvmPopLocal( 4 );
	hb_xvmSetLine( 927 );
	hb_xvmPushFuncSymbol( symbols + 31 );
	hb_xvmPushLocal( 1 );
	if( hb_xvmFunction( 1 ) ) break;
	if( hb_xvmGreaterThenIntIs( 0L, &fValue ) ) break;
	if( !fValue )
		goto lab00008;
	hb_xvmSetLine( 928 );
	hb_xvmPushLocalByRef( 4 );
	hb_xvmPushStringConst( "<ul class=\"dep-list\">", 21 );
	hb_xvmPushFuncSymbol( symbols + 16 );
	if( hb_xvmFunction( 0 ) ) break;
	if( hb_xvmPlus() ) break;
	if( hb_xvmPlusEqPop() ) break;
	hb_xvmSetLine( 929 );
	hb_xvmPushLocal( 1 );
	hb_xvmPushLocalByRef( 5 );
	if( hb_xvmEnumStart( 1, 1 ) ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00007;
lab00001: ;
	hb_xvmSetLine( 930 );
	hb_xvmPushFuncSymbol( symbols + 23 );
	hb_xvmPushLocal( 5 );
	if( hb_xvmFunction( 1 ) ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( fValue )
		goto lab00006;
	hb_xvmSetLine( 934 );
	hb_xvmPushLocal( 3 );
	hb_xvmPushNil();
	if( hb_xvmNotEqual() ) break;
	hb_xvmDuplicate();
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00002;
	hb_stackPop();
	hb_xvmPushFuncSymbol( symbols + 72 );
	hb_xvmPushLocal( 3 );
	hb_xvmPushLocal( 5 );
	if( hb_xvmFunction( 2 ) ) break;
	if( hb_xvmEqualInt( 0L ) ) break;
lab00002: ;
	hb_xvmPopLocal( 6 );
	hb_xvmSetLine( 936 );
	hb_xvmPushLocalByRef( 4 );
	hb_xvmPushStringConst( "<li><strong>", 12 );
	hb_xvmPushFuncSymbol( symbols + 63 );
	hb_xvmPushLocal( 5 );
	if( hb_xvmFunction( 1 ) ) break;
	if( hb_xvmPlus() ) break;
	hb_xvmPushStringConst( "</strong> ", 10 );
	if( hb_xvmPlus() ) break;
	if( hb_xvmPlusEqPop() ) break;
	hb_xvmSetLine( 938 );
	hb_xvmPushLocal( 6 );
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00003;
	hb_xvmSetLine( 939 );
	hb_xvmPushLocalByRef( 4 );
	hb_xvmPushStringConst( "<span class=\"badge diff-only\">Platform Specific</span> ", 55 );
	if( hb_xvmPlusEqPop() ) break;
lab00003: ;
	hb_xvmSetLine( 942 );
	hb_xvmPushLocalByRef( 4 );
	hb_xvmPushStringConst( "&mdash; ", 8 );
	if( hb_xvmMacroText() ) break;
	if( hb_xvmPlusEqPop() ) break;
	hb_xvmSetLine( 943 );
	hb_xvmPushFuncSymbol( symbols + 50 );
	hb_xvmPushLocal( 2 );
	hb_xvmPushLocal( 5 );
	if( hb_xvmFunction( 2 ) ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00004;
	hb_xvmSetLine( 944 );
	hb_xvmPushLocalByRef( 4 );
	hb_xvmPushStringConst( "<span class=\"badge resolved\">Satisfied by: <a href=\"", 52 );
	hb_xvmPushLocal( 2 );
	hb_xvmPushLocal( 5 );
	if( hb_xvmArrayPush() ) break;
	if( hb_xvmArrayItemPush( 1L ) ) break;
	hb_xvmPushStringConst( "DIR_NAME", 8 );
	if( hb_xvmArrayPush() ) break;
	if( hb_xvmPlus() ) break;
	hb_xvmPushStringConst( ".html\">", 7 );
	if( hb_xvmPlus() ) break;
	hb_xvmPushFuncSymbol( symbols + 63 );
	hb_xvmPushLocal( 2 );
	hb_xvmPushLocal( 5 );
	if( hb_xvmArrayPush() ) break;
	if( hb_xvmArrayItemPush( 1L ) ) break;
	hb_xvmPushStringConst( "DIR_NAME", 8 );
	if( hb_xvmArrayPush() ) break;
	if( hb_xvmFunction( 1 ) ) break;
	if( hb_xvmPlus() ) break;
	hb_xvmPushStringConst( "</a></span>", 11 );
	if( hb_xvmPlus() ) break;
	if( hb_xvmPlusEqPop() ) break;
	goto lab00005;
lab00004: ;
	hb_xvmSetLine( 946 );
	hb_xvmPushLocalByRef( 4 );
	hb_xvmPushStringConst( "<span class=\"badge system\">System / External Dependency</span>", 62 );
	if( hb_xvmPlusEqPop() ) break;
lab00005: ;
	hb_xvmSetLine( 948 );
	hb_xvmPushLocalByRef( 4 );
	hb_xvmPushStringConst( "</li>", 5 );
	hb_xvmPushFuncSymbol( symbols + 16 );
	if( hb_xvmFunction( 0 ) ) break;
	if( hb_xvmPlus() ) break;
	if( hb_xvmPlusEqPop() ) break;
	hb_xvmSetLine( 949 );
lab00006: ;
	if( hb_xvmEnumNext() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( fValue )
		goto lab00001;
lab00007: ;
	hb_xvmEnumEnd();
	hb_xvmSetLine( 950 );
	hb_xvmPushLocalByRef( 4 );
	hb_xvmPushStringConst( "</ul>", 5 );
	hb_xvmPushFuncSymbol( symbols + 16 );
	if( hb_xvmFunction( 0 ) ) break;
	if( hb_xvmPlus() ) break;
	if( hb_xvmPlusEqPop() ) break;
	goto lab00009;
lab00008: ;
	hb_xvmSetLine( 952 );
	hb_xvmPushLocalByRef( 4 );
	hb_xvmPushStringConst( "<p>None</p>", 11 );
	hb_xvmPushFuncSymbol( symbols + 16 );
	if( hb_xvmFunction( 0 ) ) break;
	if( hb_xvmPlus() ) break;
	if( hb_xvmPlusEqPop() ) break;
lab00009: ;
	hb_xvmSetLine( 954 );
	hb_xvmPushLocal( 4 );
	hb_xvmRetValue();
	/* *** END PROC *** */
   } while( 0 );
}

HB_FUNC_STATIC( DETECTFETCH )
{
   HB_BOOL fValue;
   do {
	hb_xvmFrame( 5, 1 );
	hb_xvmSetLine( 957 );
	hb_xvmPushFuncSymbol( symbols + 46 );
	hb_xvmPushFuncSymbol( symbols + 21 );
	hb_xvmPushLocal( 1 );
	hb_xvmPushStringConst( "SRCURL", 6 );
	hb_xvmPushStringConst( "", 0 );
	if( hb_xvmFunction( 3 ) ) break;
	if( hb_xvmFunction( 1 ) ) break;
	hb_xvmPopLocal( 2 );
	hb_xvmSetLine( 958 );
	hb_xvmPushFuncSymbol( symbols + 46 );
	hb_xvmPushFuncSymbol( symbols + 21 );
	hb_xvmPushLocal( 1 );
	hb_xvmPushStringConst( "DIR_NAME", 8 );
	hb_xvmPushStringConst( "", 0 );
	if( hb_xvmFunction( 3 ) ) break;
	if( hb_xvmFunction( 1 ) ) break;
	hb_xvmPopLocal( 3 );
	hb_xvmSetLine( 959 );
	hb_xvmPushFuncSymbol( symbols + 46 );
	hb_xvmPushFuncSymbol( symbols + 21 );
	hb_xvmPushLocal( 1 );
	hb_xvmPushStringConst( "FETCH_METHOD", 12 );
	hb_xvmPushStringConst( "", 0 );
	if( hb_xvmFunction( 3 ) ) break;
	if( hb_xvmFunction( 1 ) ) break;
	hb_xvmPopLocal( 4 );
	hb_xvmSetLine( 960 );
	hb_xvmPushFuncSymbol( symbols + 46 );
	hb_xvmPushFuncSymbol( symbols + 21 );
	hb_xvmPushLocal( 1 );
	hb_xvmPushStringConst( "PKGBLD", 6 );
	hb_xvmPushStringConst( "", 0 );
	if( hb_xvmFunction( 3 ) ) break;
	if( hb_xvmFunction( 1 ) ) break;
	hb_xvmPopLocal( 5 );
	hb_xvmSetLine( 961 );
	hb_xvmPushFuncSymbol( symbols + 46 );
	hb_xvmPushFuncSymbol( symbols + 21 );
	hb_xvmPushLocal( 1 );
	hb_xvmPushStringConst( "PKGNAME", 7 );
	hb_xvmPushStringConst( "", 0 );
	if( hb_xvmFunction( 3 ) ) break;
	if( hb_xvmFunction( 1 ) ) break;
	hb_xvmPopLocal( 6 );
	hb_xvmSetLine( 963 );
	hb_xvmPushStringConst( "-INHERIT", 8 );
	hb_xvmPushLocal( 3 );
	if( hb_xvmInstring() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( fValue )
		goto lab00001;
	hb_xvmPushStringConst( "+INHERIT", 8 );
	hb_xvmPushLocal( 5 );
	if( hb_xvmInstring() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00002;
lab00001: ;
	hb_xvmSetLine( 964 );
	hb_xvmPushStringConst( "Host package manager", 20 );
	hb_xvmRetValue();
	/* *** END PROC *** */
	break;
lab00002: ;
	hb_xvmSetLine( 965 );
	hb_xvmPushStringConst( "BINARY", 6 );
	hb_xvmPushLocal( 4 );
	if( hb_xvmInstring() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( fValue )
		goto lab00003;
	hb_xvmPushStringConst( "BINARY", 6 );
	hb_xvmPushLocal( 5 );
	if( hb_xvmInstring() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( fValue )
		goto lab00003;
	hb_xvmPushStringConst( "BINARY", 6 );
	hb_xvmPushLocal( 6 );
	if( hb_xvmInstring() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00004;
lab00003: ;
	hb_xvmSetLine( 966 );
	hb_xvmPushStringConst( "Binary", 6 );
	hb_xvmRetValue();
	/* *** END PROC *** */
	break;
lab00004: ;
	hb_xvmSetLine( 967 );
	hb_xvmPushStringConst( ".GIT", 4 );
	hb_xvmPushLocal( 2 );
	if( hb_xvmInstring() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( fValue )
		goto lab00005;
	hb_xvmPushStringConst( "GITHUB.COM", 10 );
	hb_xvmPushLocal( 2 );
	if( hb_xvmInstring() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00006;
lab00005: ;
	hb_xvmSetLine( 968 );
	hb_xvmPushStringConst( "Git", 3 );
	hb_xvmRetValue();
	/* *** END PROC *** */
	break;
lab00006: ;
	hb_xvmSetLine( 971 );
	hb_xvmPushStringConst( "System", 6 );
	hb_xvmRetValue();
	/* *** END PROC *** */
   } while( 0 );
}

HB_FUNC_STATIC( GETHEADER )
{
   do {
	hb_xvmFrame( 0, 1 );
	hb_xvmSetLine( 979 );
	hb_xvmPushStringConst( "<!DOCTYPE html>", 15 );
	hb_xvmPushFuncSymbol( symbols + 16 );
	if( hb_xvmFunction( 0 ) ) break;
	if( hb_xvmPlus() ) break;
	hb_xvmPushStringConst( "<html><head><meta charset=\"utf-8\"><title>", 41 );
	if( hb_xvmPlus() ) break;
	hb_xvmPushFuncSymbol( symbols + 63 );
	hb_xvmPushLocal( 1 );
	if( hb_xvmFunction( 1 ) ) break;
	if( hb_xvmPlus() ) break;
	hb_xvmPushStringConst( "</title>", 8 );
	if( hb_xvmPlus() ) break;
	hb_xvmPushFuncSymbol( symbols + 16 );
	if( hb_xvmFunction( 0 ) ) break;
	if( hb_xvmPlus() ) break;
	hb_xvmPushStringConst( "<link rel=\"stylesheet\" type=\"text/css\" href=\"style.css\"></head><body>", 69 );
	if( hb_xvmPlus() ) break;
	hb_xvmPushFuncSymbol( symbols + 16 );
	if( hb_xvmFunction( 0 ) ) break;
	if( hb_xvmPlus() ) break;
	hb_xvmPushStringConst( "<div id=\"topbar\"><div class=\"container\"><div class=\"top-heading\">", 65 );
	if( hb_xvmPlus() ) break;
	hb_xvmPushStringConst( "<a href=\"index.html\">harbour.zip Package Catalog</a></div></div></div>", 70 );
	if( hb_xvmPlus() ) break;
	hb_xvmPushFuncSymbol( symbols + 16 );
	if( hb_xvmFunction( 0 ) ) break;
	if( hb_xvmPlus() ) break;
	hb_xvmPushStringConst( "<div id=\"page\"><div class=\"container\">", 38 );
	if( hb_xvmPlus() ) break;
	hb_xvmPushFuncSymbol( symbols + 16 );
	if( hb_xvmFunction( 0 ) ) break;
	if( hb_xvmPlus() ) break;
	hb_xvmRetValue();
	/* *** END PROC *** */
   } while( 0 );
}

HB_FUNC_STATIC( GETFOOTER )
{
   do {
	hb_xvmSetLine( 982 );
	hb_xvmPushStringConst( "</div></div><div id=\"footer\">Generated automatically by hbpk Makefile Catalog Generator.</div></body></html>", 108 );
	hb_xvmRetValue();
	/* *** END PROC *** */
   } while( 0 );
}

HB_FUNC_STATIC( HB_HTMLENCODE )
{
   do {
	hb_xvmFrame( 0, 1 );
	hb_xvmSetLine( 985 );
	hb_xvmPushLocal( 1 );
	hb_xvmRetValue();
	/* *** END PROC *** */
   } while( 0 );
}

HB_FUNC( ARRAYTOSPACELIST )
{
   HB_BOOL fValue;
   do {
	hb_xvmFrame( 2, 1 );
	hb_xvmSetLine( 989 );
	hb_xvmPushStringConst( "", 0 );
	hb_xvmPopLocal( 2 );
	hb_xvmSetLine( 991 );
	hb_xvmPushLocal( 1 );
	hb_xvmPushLocalByRef( 3 );
	if( hb_xvmEnumStart( 1, 1 ) ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00002;
lab00001: ;
	hb_xvmSetLine( 992 );
	hb_xvmPushLocalByRef( 2 );
	hb_xvmPushLocal( 3 );
	if( hb_xvmArrayItemPush( 1L ) ) break;
	hb_xvmPushStringConst( " ", 1 );
	if( hb_xvmPlus() ) break;
	if( hb_xvmPlusEqPop() ) break;
	hb_xvmSetLine( 993 );
	if( hb_xvmEnumNext() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( fValue )
		goto lab00001;
lab00002: ;
	hb_xvmEnumEnd();
	hb_xvmSetLine( 994 );
	hb_xvmPushFuncSymbol( symbols + 22 );
	hb_xvmPushLocal( 2 );
	if( hb_xvmDo( 1 ) ) break;
	/* *** END PROC *** */
   } while( 0 );
}

HB_FUNC( SHE )
{
   HB_BOOL fValue;
   do {
	hb_xvmFrame( 2, 1 );
	hb_xvmSetLine( 1001 );
	hb_xvmPushFuncSymbol( symbols + 75 );
	hb_xvmPushLocal( 1 );
	if( hb_xvmFunction( 1 ) ) break;
	hb_xvmPopLocal( 1 );
	hb_xvmSetLine( 1003 );
	hb_xvmPushLocal( 1 );
	hb_xvmPushStringConst( "hbpk-ls harbour-core | grep /hbmk2$(_EXT)$$", 43 );
	if( hb_xvmEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00001;
	hb_xvmSetLine( 1004 );
	hb_xvmPushStringConst( "hbmk2", 5 );
	hb_xvmRetValue();
	/* *** END PROC *** */
	break;
lab00001: ;
	hb_xvmSetLine( 1007 );
	hb_xvmPushFuncSymbol( symbols + 15 );
	hb_xvmPushLocal( 1 );
	hb_xvmPushStringConst( "|", 1 );
	if( hb_xvmFunction( 2 ) ) break;
	hb_xvmPopLocal( 2 );
	hb_xvmSetLine( 1008 );
	hb_xvmPushLocal( 2 );
	if( hb_xvmArrayItemPush( 1L ) ) break;
	hb_xvmPushStringConst( "uname", 5 );
	if( hb_xvmEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00002;
	hb_xvmSetLine( 1009 );
	hb_xvmPushFuncSymbol( symbols + 76 );
	hb_xvmPushLocal( 2 );
	if( hb_xvmArrayItemPush( 1L ) ) break;
	if( hb_xvmPushMemvar( symbols + 77 ) ) break;
	if( hb_xvmFunction( 2 ) ) break;
	hb_xvmPopLocal( 3 );
lab00002: ;
	hb_xvmSetLine( 1012 );
	hb_xvmPushFuncSymbol( symbols + 23 );
	hb_xvmPushLocal( 3 );
	if( hb_xvmFunction( 1 ) ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( fValue )
		goto lab00003;
	hb_xvmPushFuncSymbol( symbols + 31 );
	hb_xvmPushLocal( 2 );
	if( hb_xvmFunction( 1 ) ) break;
	if( hb_xvmGreaterThenIntIs( 1L, &fValue ) ) break;
	if( !fValue )
		goto lab00003;
	hb_xvmSetLine( 1013 );
	hb_xvmPushFuncSymbol( symbols + 75 );
	hb_xvmPushLocal( 2 );
	if( hb_xvmArrayItemPush( 2L ) ) break;
	if( hb_xvmFunction( 1 ) ) break;
	hb_xvmPushStringConst( "sed", 3 );
	if( hb_xvmEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00003;
	hb_xvmSetLine( 1014 );
	hb_xvmPushFuncSymbol( symbols + 78 );
	hb_xvmPushLocal( 3 );
	hb_xvmPushLocal( 1 );
	if( hb_xvmDo( 2 ) ) break;
	/* *** END PROC *** */
	break;
lab00003: ;
	hb_xvmSetLine( 1018 );
	hb_xvmPushStringConst( "", 0 );
	hb_xvmRetValue();
	/* *** END PROC *** */
   } while( 0 );
}

HB_FUNC( RUNSIMULATEDSHELL )
{
   HB_BOOL fValue;
   do {
	hb_xvmFrame( 2, 2 );
	hb_xvmSetLine( 1022 );
	hb_xvmPushStringConst( "", 0 );
	hb_xvmPopLocal( 3 );
	hb_xvmSetLine( 1023 );
	hb_xvmPushFuncSymbol( symbols + 4 );
	hb_xvmPushStringConst( "pseudoexecuting:", 16 );
	hb_xvmPushLocal( 1 );
	hb_xvmPushStringConst( "on", 2 );
	hb_xvmPushLocal( 2 );
	if( hb_xvmDo( 4 ) ) break;
	hb_xvmSetLine( 1025 );
	hb_xvmPushFuncSymbol( symbols + 15 );
	hb_xvmPushLocal( 1 );
	hb_xvmPushStringConst( " ", 1 );
	if( hb_xvmFunction( 2 ) ) break;
	hb_xvmPopLocal( 4 );
	hb_xvmSetLine( 1026 );
	hb_xvmPushFuncSymbol( symbols + 23 );
	hb_xvmPushLocal( 4 );
	if( hb_xvmArrayItemPush( 1L ) ) break;
	if( hb_xvmFunction( 1 ) ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( fValue )
		goto lab00016;
	hb_xvmSetLine( 1027 );
	goto lab00015;
lab00001: ;
	hb_xvmSetLine( 1029 );
	hb_xvmPushFuncSymbol( symbols + 38 );
	hb_xvmPushStringConst( "linux", 5 );
	hb_xvmPushLocal( 2 );
	if( hb_xvmFunction( 2 ) ) break;
	if( hb_xvmGreaterThenIntIs( 0L, &fValue ) ) break;
	if( !fValue )
		goto lab00006;
	hb_xvmSetLine( 1030 );
	hb_xvmPushFuncSymbol( symbols + 31 );
	hb_xvmPushLocal( 4 );
	if( hb_xvmFunction( 1 ) ) break;
	if( hb_xvmEqualIntIs( 1L, &fValue ) ) break;
	if( !fValue )
		goto lab00002;
	hb_xvmSetLine( 1031 );
	hb_xvmPushStringConst( "Linux", 5 );
	hb_xvmRetValue();
	/* *** END PROC *** */
	break;
lab00002: ;
	hb_xvmSetLine( 1032 );
	hb_xvmPushLocal( 4 );
	if( hb_xvmArrayItemPush( 2L ) ) break;
	hb_xvmPushStringConst( "-m", 2 );
	if( hb_xvmExactlyEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00005;
	hb_xvmSetLine( 1033 );
	hb_xvmPushFuncSymbol( symbols + 38 );
	hb_xvmPushStringConst( "x86_64", 6 );
	hb_xvmPushLocal( 2 );
	if( hb_xvmFunction( 2 ) ) break;
	if( hb_xvmGreaterThenIntIs( 0L, &fValue ) ) break;
	if( !fValue )
		goto lab00003;
	hb_xvmSetLine( 1034 );
	hb_xvmPushStringConst( "x86_64", 6 );
	hb_xvmRetValue();
	/* *** END PROC *** */
	break;
lab00003: ;
	hb_xvmSetLine( 1035 );
	hb_xvmPushFuncSymbol( symbols + 38 );
	hb_xvmPushStringConst( "aarch64", 7 );
	hb_xvmPushLocal( 2 );
	if( hb_xvmFunction( 2 ) ) break;
	if( hb_xvmGreaterThenIntIs( 0L, &fValue ) ) break;
	if( !fValue )
		goto lab00004;
	hb_xvmSetLine( 1036 );
	hb_xvmPushStringConst( "aarch64", 7 );
	hb_xvmRetValue();
	/* *** END PROC *** */
	break;
lab00004: ;
	hb_xvmSetLine( 1038 );
	hb_xvmPushStringConst( "x86", 3 );
	hb_xvmRetValue();
	/* *** END PROC *** */
	break;
lab00005: ;
	hb_xvmSetLine( 1040 );
	hb_xvmPushLocal( 4 );
	if( hb_xvmArrayItemPush( 2L ) ) break;
	hb_xvmPushStringConst( "-o", 2 );
	if( hb_xvmExactlyEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00012;
	hb_xvmSetLine( 1041 );
	hb_xvmPushStringConst( "GNU/Linux", 9 );
	hb_xvmRetValue();
	/* *** END PROC *** */
	break;
lab00006: ;
	hb_xvmSetLine( 1043 );
	hb_xvmPushFuncSymbol( symbols + 38 );
	hb_xvmPushStringConst( "windows", 7 );
	hb_xvmPushLocal( 2 );
	if( hb_xvmFunction( 2 ) ) break;
	if( hb_xvmGreaterThenIntIs( 0L, &fValue ) ) break;
	if( !fValue )
		goto lab00012;
	hb_xvmSetLine( 1044 );
	hb_xvmPushFuncSymbol( symbols + 31 );
	hb_xvmPushLocal( 4 );
	if( hb_xvmFunction( 1 ) ) break;
	if( hb_xvmEqualIntIs( 1L, &fValue ) ) break;
	if( !fValue )
		goto lab00008;
	hb_xvmSetLine( 1045 );
	hb_xvmPushFuncSymbol( symbols + 38 );
	hb_xvmPushStringConst( "x86_64", 6 );
	hb_xvmPushLocal( 2 );
	if( hb_xvmFunction( 2 ) ) break;
	if( hb_xvmGreaterThenIntIs( 0L, &fValue ) ) break;
	if( !fValue )
		goto lab00007;
	hb_xvmSetLine( 1046 );
	hb_xvmPushStringConst( "MINGW64", 7 );
	hb_xvmRetValue();
	/* *** END PROC *** */
	break;
lab00007: ;
	hb_xvmSetLine( 1048 );
	hb_xvmPushStringConst( "MINGW", 5 );
	hb_xvmRetValue();
	/* *** END PROC *** */
	break;
lab00008: ;
	hb_xvmSetLine( 1049 );
	hb_xvmPushLocal( 4 );
	if( hb_xvmArrayItemPush( 2L ) ) break;
	hb_xvmPushStringConst( "-m", 2 );
	if( hb_xvmExactlyEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00011;
	hb_xvmSetLine( 1050 );
	hb_xvmPushFuncSymbol( symbols + 38 );
	hb_xvmPushStringConst( "x86_64", 6 );
	hb_xvmPushLocal( 2 );
	if( hb_xvmFunction( 2 ) ) break;
	if( hb_xvmGreaterThenIntIs( 0L, &fValue ) ) break;
	if( !fValue )
		goto lab00009;
	hb_xvmSetLine( 1051 );
	hb_xvmPushStringConst( "x86_64", 6 );
	hb_xvmRetValue();
	/* *** END PROC *** */
	break;
lab00009: ;
	hb_xvmSetLine( 1052 );
	hb_xvmPushFuncSymbol( symbols + 38 );
	hb_xvmPushStringConst( "aarch64", 7 );
	hb_xvmPushLocal( 2 );
	if( hb_xvmFunction( 2 ) ) break;
	if( hb_xvmGreaterThenIntIs( 0L, &fValue ) ) break;
	if( !fValue )
		goto lab00010;
	hb_xvmSetLine( 1053 );
	hb_xvmPushStringConst( "aarch64", 7 );
	hb_xvmRetValue();
	/* *** END PROC *** */
	break;
lab00010: ;
	hb_xvmSetLine( 1055 );
	hb_xvmPushStringConst( "x86", 3 );
	hb_xvmRetValue();
	/* *** END PROC *** */
	break;
lab00011: ;
	hb_xvmSetLine( 1057 );
	hb_xvmPushLocal( 4 );
	if( hb_xvmArrayItemPush( 2L ) ) break;
	hb_xvmPushStringConst( "-o", 2 );
	if( hb_xvmExactlyEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00012;
	hb_xvmSetLine( 1058 );
	hb_xvmPushStringConst( "Msys", 4 );
	hb_xvmRetValue();
	/* *** END PROC *** */
	break;
lab00012: ;
	goto lab00016;
lab00013: ;
	hb_xvmSetLine( 1063 );
	hb_xvmPushLocal( 4 );
	hb_xvmPushFuncSymbol( symbols + 31 );
	hb_xvmPushLocal( 4 );
	if( hb_xvmFunction( 1 ) ) break;
	if( hb_xvmArrayPush() ) break;
	hb_xvmPushStringConst( "s/^libpq[[:space:]]\\+\\([0-9]\\+\\)\\..*/\\1/p", 41 );
	if( hb_xvmExactlyEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00014;
	hb_xvmSetLine( 1064 );
	hb_xvmPushStringConst( "18", 2 );
	hb_xvmRetValue();
	/* *** END PROC *** */
	break;
lab00014: ;
	goto lab00016;
lab00015: ;
	hb_xvmPushLocal( 4 );
	if( hb_xvmArrayItemPush( 1L ) ) break;
	{
		PHB_ITEM pSwitch;
		HB_TYPE type;
		const char * pszText;
		HB_SIZE nLen;
		if( hb_xvmSwitchGet( &pSwitch ) ) break;
		type = hb_itemType( pSwitch );
		pszText = ( type & HB_IT_STRING ) ? hb_itemGetCPtr( pSwitch ) : NULL;
		nLen = pszText ? hb_itemGetCLen( pSwitch ) : 0;
		if( pszText && nLen == 5 && ! memcmp( pszText, "uname", 5 ) )
		{
			hb_stackPop();
			goto lab00001;
		}
		if( pszText && nLen == 7 && ! memcmp( pszText, "hbpk-ls", 7 ) )
		{
			hb_stackPop();
			goto lab00013;
		}
		hb_stackPop();
	}
lab00016: ;
	hb_xvmSetLine( 1071 );
	hb_xvmPushFuncSymbol( symbols + 22 );
	hb_xvmPushLocal( 3 );
	if( hb_xvmDo( 1 ) ) break;
	/* *** END PROC *** */
   } while( 0 );
}

HB_FUNC( GETMAKEVAR )
{
   HB_BOOL fValue;
   do {
	hb_xvmFrame( 0, 2 );
	hb_xvmSetLine( 1075 );
	hb_xvmPushLocal( 2 );
	hb_xvmPushNil();
	if( hb_xvmNotEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00001;
	hb_xvmPushFuncSymbol( symbols + 50 );
	hb_xvmPushLocal( 2 );
	hb_xvmPushFuncSymbol( symbols + 46 );
	hb_xvmPushLocal( 1 );
	if( hb_xvmFunction( 1 ) ) break;
	if( hb_xvmFunction( 2 ) ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00001;
	hb_xvmSetLine( 1076 );
	hb_xvmPushLocal( 2 );
	hb_xvmPushFuncSymbol( symbols + 46 );
	hb_xvmPushLocal( 1 );
	if( hb_xvmFunction( 1 ) ) break;
	if( hb_xvmArrayPush() ) break;
	hb_xvmRetValue();
	/* *** END PROC *** */
	break;
lab00001: ;
	hb_xvmSetLine( 1078 );
	hb_xvmPushStringConst( "", 0 );
	hb_xvmRetValue();
	/* *** END PROC *** */
   } while( 0 );
}

HB_FUNC( PROCESSMACROS )
{
   HB_BOOL fValue;
   do {
	hb_xvmFrame( 12, 1 );
	hb_xvmSetLine( 1081 );
	hb_xvmCopyLocals( 1, 2 );
	hb_xvmSetLine( 1083 );
	hb_xvmLocalSetInt( 8, 1L );
	hb_xvmSetLine( 1086 );
	hb_xvmPushNil();
	hb_xvmPopLocal( 10 );
	hb_xvmSetLine( 1087 );
	hb_xvmPushNil();
	hb_xvmPopLocal( 11 );
lab00001: ;
	hb_xvmSetLine( 1093 );
	hb_xvmPushLogical( HB_FALSE );
	hb_xvmPopLocal( 13 );
	hb_xvmSetLine( 1094 );
	hb_xvmPushFuncSymbol( symbols + 53 );
	hb_xvmPushStringConst( "&(", 2 );
	hb_xvmPushLocal( 2 );
	hb_xvmPushLocal( 8 );
	if( hb_xvmFunction( 3 ) ) break;
	hb_xvmPopLocal( 3 );
	hb_xvmSetLine( 1095 );
	hb_xvmPushLocal( 3 );
	if( hb_xvmEqualIntIs( 0L, &fValue ) ) break;
	if( fValue )
		goto lab00023;
	hb_xvmSetLine( 1099 );
	hb_xvmPushFuncSymbol( symbols + 31 );
	hb_xvmPushLocal( 2 );
	if( hb_xvmFunction( 1 ) ) break;
	hb_xvmPopLocal( 6 );
	hb_xvmSetLine( 1100 );
	hb_xvmLocalSetInt( 5, 0L );
	hb_xvmSetLine( 1101 );
	hb_xvmLocalSetInt( 4, 0L );
	hb_xvmSetLine( 1103 );
	hb_xvmPushFuncSymbol( symbols + 30 );
	hb_xvmPushLocal( 2 );
	hb_xvmPushLocal( 3 );
	if( hb_xvmAddInt( 2L ) ) break;
	hb_xvmPushInteger( 5 );
	if( hb_xvmFunction( 3 ) ) break;
	hb_xvmPushStringConst( "shell", 5 );
	if( hb_xvmExactlyEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00002;
	hb_xvmSetLine( 1104 );
	hb_xvmPushFuncSymbol( symbols + 80 );
	hb_xvmPushLocal( 2 );
	hb_xvmPushLocal( 3 );
	if( hb_xvmAddInt( 2L ) ) break;
	hb_xvmPushInteger( 5 );
	hb_xvmPushStringConst( "she(\"", 5 );
	if( hb_xvmFunction( 4 ) ) break;
	hb_xvmPopLocal( 2 );
	hb_xvmSetLine( 1105 );
	hb_xvmPushFuncSymbol( symbols + 31 );
	hb_xvmPushLocal( 2 );
	if( hb_xvmFunction( 1 ) ) break;
	hb_xvmPopLocal( 6 );
	hb_xvmSetLine( 1106 );
	hb_xvmPushLogical( HB_TRUE );
	hb_xvmPopLocal( 13 );
	hb_xvmSetLine( 1107 );
	hb_xvmPushFuncSymbol( symbols + 4 );
	hb_xvmPushLocal( 2 );
	if( hb_xvmDo( 1 ) ) break;
lab00002: ;
	hb_xvmSetLine( 1111 );
	hb_xvmPushLocal( 3 );
	if( hb_xvmAddInt( 1L ) ) break;
	hb_xvmPushUnRef();
	hb_xvmPopLocal( 7 );
	goto lab00008;
lab00003: ;
	hb_xvmSetLine( 1112 );
	hb_xvmPushFuncSymbol( symbols + 30 );
	hb_xvmPushLocal( 2 );
	hb_xvmPushLocal( 7 );
	hb_xvmPushInteger( 1 );
	if( hb_xvmFunction( 3 ) ) break;
	hb_xvmPushStringConst( "(", 1 );
	if( hb_xvmExactlyEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00004;
	hb_xvmSetLine( 1113 );
	if( hb_xvmLocalInc( 5 ) ) break;
	goto lab00007;
lab00004: ;
	hb_xvmSetLine( 1114 );
	hb_xvmPushFuncSymbol( symbols + 30 );
	hb_xvmPushLocal( 2 );
	hb_xvmPushLocal( 7 );
	hb_xvmPushInteger( 1 );
	if( hb_xvmFunction( 3 ) ) break;
	hb_xvmPushStringConst( ")", 1 );
	if( hb_xvmExactlyEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00007;
	hb_xvmSetLine( 1115 );
	if( hb_xvmLocalDec( 5 ) ) break;
	hb_xvmSetLine( 1116 );
	hb_xvmPushLocal( 5 );
	hb_xvmPushLocal( 13 );
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00005;
	hb_xvmPushInteger( 1 );
	goto lab00006;
lab00005: ;
	hb_xvmPushInteger( 0 );
lab00006: ;
	if( hb_xvmMinus() ) break;
	if( hb_xvmEqualIntIs( 0L, &fValue ) ) break;
	if( !fValue )
		goto lab00007;
	hb_xvmSetLine( 1117 );
	hb_xvmCopyLocals( 7, 4 );
	goto lab00009;
lab00007: ;
	hb_xvmSetLine( 1111 );
	if( hb_xvmLocalIncPush( 7 ) ) break;
lab00008: ;
	hb_xvmPushLocal( 6 );
	if( hb_xvmGreater() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00003;
lab00009: ;
	hb_xvmSetLine( 1124 );
	hb_xvmPushLocal( 4 );
	if( hb_xvmEqualIntIs( 0L, &fValue ) ) break;
	if( fValue )
		goto lab00023;
	hb_xvmSetLine( 1130 );
	hb_xvmPushFuncSymbol( symbols + 30 );
	hb_xvmPushLocal( 2 );
	hb_xvmPushLocal( 3 );
	if( hb_xvmAddInt( 2L ) ) break;
	hb_xvmPushLocal( 4 );
	hb_xvmPushLocal( 3 );
	if( hb_xvmMinus() ) break;
	if( hb_xvmAddInt( -2L ) ) break;
	if( hb_xvmFunction( 3 ) ) break;
	hb_xvmPushLocal( 13 );
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00010;
	hb_xvmPushStringConst( ")", 1 );
	goto lab00011;
lab00010: ;
	hb_xvmPushStringConst( "", 0 );
lab00011: ;
	hb_xvmLocalAdd( 9 );
	hb_xvmSetLine( 1131 );
	hb_xvmPushLocal( 13 );
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00012;
	hb_xvmSetLine( 1132 );
	hb_xvmPushFuncSymbol( symbols + 44 );
	hb_xvmPushFuncSymbol( symbols + 49 );
	hb_xvmPushLocal( 9 );
	hb_xvmPushStringConst( "\"", 1 );
	hb_xvmPushStringConst( "\" + HB_BChar(34) + \"", 20 );
	hb_xvmPushInteger( 2 );
	if( hb_xvmFunction( 4 ) ) break;
	if( hb_xvmFunction( 1 ) ) break;
	hb_xvmPushStringConst( "\")", 2 );
	hb_xvmLocalAdd( 9 );
lab00012: ;
	hb_xvmSetLine( 1134 );
	if( hb_xvmPushMemvar( symbols + 24 ) ) break;
	hb_xvmPushStringConst( "LINUX", 5 );
	if( hb_xvmExactlyEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00013;
	hb_xvmSetLine( 1135 );
	hb_xvmPushStringConst( "x86_64-linux", 12 );
	hb_xvmPushFuncSymbol( symbols + 25 );
	hb_xvmPushSymbol( symbols + 77 );
	if( hb_xvmDo( 1 ) ) break;
	if( hb_xvmPopMemvar( symbols + 77 ) ) break;
	goto lab00014;
lab00013: ;
	hb_xvmSetLine( 1137 );
	hb_xvmPushStringConst( "x86_64-windows", 14 );
	hb_xvmPushFuncSymbol( symbols + 25 );
	hb_xvmPushSymbol( symbols + 77 );
	if( hb_xvmDo( 1 ) ) break;
	if( hb_xvmPopMemvar( symbols + 77 ) ) break;
lab00014: ;
	hb_xvmSetLine( 1141 );
	hb_xvmSeqBegin();
	for( ;; ) {
	hb_xvmPushFuncSymbol( symbols + 55 );
	if( hb_xvmFunction( 0 ) ) break;
	if( hb_xvmSeqBlock() ) break;
	hb_xvmSetLine( 1142 );
	hb_xvmPushFuncSymbol( symbols + 81 );
	hb_xvmPushLocal( 9 );
	if( hb_xvmFunction( 1 ) ) break;
	hb_xvmPopLocal( 10 );
	hb_xvmSetLine( 1143 );
	hb_xvmPushSymbol( symbols + 82 );
	hb_xvmPushLocal( 10 );
	if( hb_xvmSend( 0 ) ) break;
	hb_xvmPopLocal( 11 );
	hb_stackPop();
	if( hb_xvmSeqEndTest() ) break;
	goto lab00015;
	}
	hb_xvmSetLine( 1144 );
	if( hb_xvmSeqRecover() ) break;
	hb_stackPop();
	hb_xvmSetLine( 1145 );
	hb_xvmPushStringConst( "[ERROR: Invalid Macro]", 22 );
	hb_xvmPopLocal( 11 );
	hb_xvmSetLine( 1146 );
	hb_xvmPushFuncSymbol( symbols + 4 );
	hb_xvmPushStringConst( "[ERROR: Invalid Macro]", 22 );
	hb_xvmPushLocal( 9 );
	if( hb_xvmDo( 2 ) ) break;
lab00015: ;
	hb_xvmSetLine( 1151 );
	hb_xvmPushFuncSymbol( symbols + 83 );
	hb_xvmPushLocal( 11 );
	if( hb_xvmFunction( 1 ) ) break;
	hb_xvmPushStringConst( "C", 1 );
	if( hb_xvmExactlyEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00016;
	hb_xvmSetLine( 1152 );
	hb_xvmCopyLocals( 11, 12 );
	goto lab00022;
lab00016: ;
	hb_xvmSetLine( 1153 );
	hb_xvmPushFuncSymbol( symbols + 83 );
	hb_xvmPushLocal( 11 );
	if( hb_xvmFunction( 1 ) ) break;
	hb_xvmPushStringConst( "N", 1 );
	if( hb_xvmExactlyEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00017;
	hb_xvmSetLine( 1154 );
	hb_xvmPushFuncSymbol( symbols + 75 );
	hb_xvmPushFuncSymbol( symbols + 84 );
	hb_xvmPushLocal( 11 );
	if( hb_xvmFunction( 1 ) ) break;
	if( hb_xvmFunction( 1 ) ) break;
	hb_xvmPopLocal( 12 );
	goto lab00022;
lab00017: ;
	hb_xvmSetLine( 1155 );
	hb_xvmPushFuncSymbol( symbols + 83 );
	hb_xvmPushLocal( 11 );
	if( hb_xvmFunction( 1 ) ) break;
	hb_xvmPushStringConst( "D", 1 );
	if( hb_xvmExactlyEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00018;
	hb_xvmSetLine( 1156 );
	hb_xvmPushFuncSymbol( symbols + 85 );
	hb_xvmPushLocal( 11 );
	if( hb_xvmFunction( 1 ) ) break;
	hb_xvmPopLocal( 12 );
	goto lab00022;
lab00018: ;
	hb_xvmSetLine( 1157 );
	hb_xvmPushFuncSymbol( symbols + 83 );
	hb_xvmPushLocal( 11 );
	if( hb_xvmFunction( 1 ) ) break;
	hb_xvmPushStringConst( "L", 1 );
	if( hb_xvmExactlyEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00021;
	hb_xvmSetLine( 1158 );
	hb_xvmPushLocal( 11 );
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00019;
	hb_xvmPushStringConst( ".T.", 3 );
	goto lab00020;
lab00019: ;
	hb_xvmPushStringConst( ".F.", 3 );
lab00020: ;
	hb_xvmPopLocal( 12 );
	goto lab00022;
lab00021: ;
	hb_xvmSetLine( 1160 );
	hb_xvmPushStringConst( "", 0 );
	hb_xvmPopLocal( 12 );
lab00022: ;
	hb_xvmSetLine( 1164 );
	hb_xvmPushFuncSymbol( symbols + 30 );
	hb_xvmPushLocal( 2 );
	hb_xvmPushInteger( 1 );
	hb_xvmPushLocal( 3 );
	if( hb_xvmAddInt( -1L ) ) break;
	if( hb_xvmFunction( 3 ) ) break;
	hb_xvmPushLocal( 12 );
	if( hb_xvmPlus() ) break;
	hb_xvmPushFuncSymbol( symbols + 30 );
	hb_xvmPushLocal( 2 );
	hb_xvmPushLocal( 4 );
	if( hb_xvmAddInt( 1L ) ) break;
	if( hb_xvmFunction( 2 ) ) break;
	hb_xvmLocalAdd( 2 );
	hb_xvmSetLine( 1167 );
	hb_xvmPushLocal( 3 );
	hb_xvmPushFuncSymbol( symbols + 31 );
	hb_xvmPushLocal( 12 );
	if( hb_xvmFunction( 1 ) ) break;
	hb_xvmLocalAdd( 8 );
	goto lab00001;
lab00023: ;
	hb_xvmSetLine( 1170 );
	hb_xvmPushLocal( 2 );
	hb_xvmRetValue();
	/* *** END PROC *** */
   } while( 0 );
}

HB_FUNC_STATIC( VARSNOTSHOWN )
{
   HB_BOOL fValue;
   do {
	hb_xvmSFrame( symbols + 90 );
	hb_xvmSetLine( 1174 );
	hb_xvmPushFuncSymbol( symbols + 86 );
	hb_xvmPushStatic( 1 );
	if( hb_xvmFunction( 1 ) ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( fValue )
		goto lab00001;
	hb_xvmSetLine( 1175 );
	hb_xvmHashGen( 0 );
	hb_xvmPopStatic( 1 );
	hb_xvmSetLine( 1176 );
	hb_xvmPushNil();
	hb_xvmPushStatic( 1 );
	hb_xvmPushStringConst( "PKGFILE", 7 );
	if( hb_xvmArrayPop() ) break;
	hb_xvmSetLine( 1177 );
	hb_xvmPushNil();
	hb_xvmPushStatic( 1 );
	hb_xvmPushStringConst( "PKGVERF", 7 );
	if( hb_xvmArrayPop() ) break;
	hb_xvmSetLine( 1178 );
	hb_xvmPushNil();
	hb_xvmPushStatic( 1 );
	hb_xvmPushStringConst( "PKGDEPF", 7 );
	if( hb_xvmArrayPop() ) break;
	hb_xvmSetLine( 1179 );
	hb_xvmPushNil();
	hb_xvmPushStatic( 1 );
	hb_xvmPushStringConst( "HB_CPU", 6 );
	if( hb_xvmArrayPop() ) break;
	hb_xvmSetLine( 1180 );
	hb_xvmPushNil();
	hb_xvmPushStatic( 1 );
	hb_xvmPushStringConst( "HBPK_COMPILER", 13 );
	if( hb_xvmArrayPop() ) break;
	hb_xvmSetLine( 1181 );
	hb_xvmPushNil();
	hb_xvmPushStatic( 1 );
	hb_xvmPushStringConst( "HBPK_PLATFORM", 13 );
	if( hb_xvmArrayPop() ) break;
	hb_xvmSetLine( 1182 );
	hb_xvmPushNil();
	hb_xvmPushStatic( 1 );
	hb_xvmPushStringConst( "_JSON", 5 );
	if( hb_xvmArrayPop() ) break;
	hb_xvmSetLine( 1183 );
	hb_xvmPushNil();
	hb_xvmPushStatic( 1 );
	hb_xvmPushStringConst( "_STRIPPED", 9 );
	if( hb_xvmArrayPop() ) break;
	hb_xvmSetLine( 1184 );
	hb_xvmPushNil();
	hb_xvmPushStatic( 1 );
	hb_xvmPushStringConst( "_COMMA", 6 );
	if( hb_xvmArrayPop() ) break;
	hb_xvmSetLine( 1185 );
	hb_xvmPushNil();
	hb_xvmPushStatic( 1 );
	hb_xvmPushStringConst( "_CLEANED", 8 );
	if( hb_xvmArrayPop() ) break;
	hb_xvmSetLine( 1186 );
	hb_xvmPushNil();
	hb_xvmPushStatic( 1 );
	hb_xvmPushStringConst( "HBPK_CMAKE_G", 12 );
	if( hb_xvmArrayPop() ) break;
	hb_xvmSetLine( 1187 );
	hb_xvmPushNil();
	hb_xvmPushStatic( 1 );
	hb_xvmPushStringConst( "TOPDIR", 6 );
	if( hb_xvmArrayPop() ) break;
lab00001: ;
	hb_xvmSetLine( 1189 );
	hb_xvmPushStatic( 1 );
	hb_xvmRetValue();
	/* *** END PROC *** */
   } while( 0 );
}

HB_FUNC( SEDEMULATE )
{
   HB_BOOL fValue;
   do {
	hb_xvmFrame( 7, 2 );
	hb_xvmSetLine( 1192 );
	hb_xvmCopyLocals( 1, 3 );
	hb_xvmSetLine( 1193 );
	hb_xvmArrayGen( 0 );
	hb_xvmPopLocal( 4 );
	hb_xvmSetLine( 1194 );
	hb_xvmLocalSetInt( 5, 1L );
lab00001: ;
	hb_xvmSetLine( 1199 );
	hb_xvmPushFuncSymbol( symbols + 38 );
	hb_xvmPushStringConst( "\"", 1 );
	hb_xvmPushFuncSymbol( symbols + 30 );
	hb_xvmPushLocal( 2 );
	hb_xvmPushLocal( 5 );
	if( hb_xvmFunction( 2 ) ) break;
	if( hb_xvmFunction( 2 ) ) break;
	hb_xvmPopLocal( 6 );
	hb_xvmSetLine( 1200 );
	hb_xvmPushLocal( 6 );
	if( hb_xvmEqualIntIs( 0L, &fValue ) ) break;
	if( fValue )
		goto lab00003;
	hb_xvmSetLine( 1203 );
	hb_xvmPushLocalByRef( 6 );
	hb_xvmPushLocal( 5 );
	if( hb_xvmAddInt( -1L ) ) break;
	if( hb_xvmPlusEqPop() ) break;
	hb_xvmSetLine( 1204 );
	hb_xvmPushFuncSymbol( symbols + 38 );
	hb_xvmPushStringConst( "\"", 1 );
	hb_xvmPushFuncSymbol( symbols + 30 );
	hb_xvmPushLocal( 2 );
	hb_xvmPushLocal( 6 );
	if( hb_xvmAddInt( 1L ) ) break;
	if( hb_xvmFunction( 2 ) ) break;
	if( hb_xvmFunction( 2 ) ) break;
	hb_xvmPopLocal( 7 );
	hb_xvmSetLine( 1205 );
	hb_xvmPushLocal( 7 );
	if( hb_xvmEqualIntIs( 0L, &fValue ) ) break;
	if( fValue )
		goto lab00003;
	hb_xvmSetLine( 1208 );
	hb_xvmPushLocalByRef( 7 );
	hb_xvmPushLocal( 6 );
	if( hb_xvmPlusEqPop() ) break;
	hb_xvmSetLine( 1210 );
	hb_xvmPushFuncSymbol( symbols + 30 );
	hb_xvmPushLocal( 2 );
	hb_xvmPushLocal( 6 );
	if( hb_xvmAddInt( 1L ) ) break;
	hb_xvmPushLocal( 7 );
	hb_xvmPushLocal( 6 );
	if( hb_xvmMinus() ) break;
	if( hb_xvmAddInt( -1L ) ) break;
	if( hb_xvmFunction( 3 ) ) break;
	hb_xvmPopLocal( 8 );
	hb_xvmSetLine( 1211 );
	hb_xvmPushFuncSymbol( symbols + 28 );
	hb_xvmPushLocal( 8 );
	hb_xvmPushInteger( 1 );
	if( hb_xvmFunction( 2 ) ) break;
	hb_xvmPushStringConst( "s", 1 );
	if( hb_xvmExactlyEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00002;
	hb_xvmPushFuncSymbol( symbols + 31 );
	hb_xvmPushLocal( 8 );
	if( hb_xvmFunction( 1 ) ) break;
	if( hb_xvmGreaterThenIntIs( 1L, &fValue ) ) break;
	if( !fValue )
		goto lab00002;
	hb_xvmSetLine( 1212 );
	hb_xvmPushFuncSymbol( symbols + 13 );
	hb_xvmPushLocal( 4 );
	hb_xvmPushLocal( 8 );
	if( hb_xvmDo( 2 ) ) break;
lab00002: ;
	hb_xvmSetLine( 1215 );
	hb_xvmPushLocal( 7 );
	if( hb_xvmAddInt( 1L ) ) break;
	hb_xvmPopLocal( 5 );
	goto lab00001;
lab00003: ;
	hb_xvmSetLine( 1218 );
	hb_xvmPushInteger( 1 );
	hb_xvmPushUnRef();
	hb_xvmPopLocal( 9 );
	goto lab00005;
lab00004: ;
	hb_xvmSetLine( 1219 );
	hb_xvmPushFuncSymbol( symbols + 87 );
	hb_xvmPushLocal( 3 );
	hb_xvmPushLocal( 4 );
	hb_xvmPushLocal( 9 );
	if( hb_xvmArrayPush() ) break;
	if( hb_xvmFunction( 2 ) ) break;
	hb_xvmPopLocal( 3 );
	hb_xvmSetLine( 1218 );
	if( hb_xvmLocalIncPush( 9 ) ) break;
lab00005: ;
	hb_xvmPushFuncSymbol( symbols + 31 );
	hb_xvmPushLocal( 4 );
	if( hb_xvmFunction( 1 ) ) break;
	if( hb_xvmGreater() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00004;
	hb_xvmSetLine( 1222 );
	hb_xvmPushLocal( 3 );
	hb_xvmRetValue();
	/* *** END PROC *** */
   } while( 0 );
}

HB_FUNC_STATIC( SEDAPPLYONE )
{
   HB_BOOL fValue;
   do {
	hb_xvmFrame( 5, 2 );
	hb_xvmSetLine( 1226 );
	hb_xvmPushFuncSymbol( symbols + 30 );
	hb_xvmPushLocal( 2 );
	hb_xvmPushInteger( 2 );
	hb_xvmPushInteger( 1 );
	if( hb_xvmFunction( 3 ) ) break;
	hb_xvmPopLocal( 3 );
	hb_xvmSetLine( 1227 );
	hb_xvmLocalSetInt( 4, 3L );
	hb_xvmSetLine( 1230 );
	hb_xvmPushFuncSymbol( symbols + 88 );
	hb_xvmPushLocal( 2 );
	hb_xvmPushLocal( 4 );
	hb_xvmPushLocal( 3 );
	if( hb_xvmFunction( 3 ) ) break;
	hb_xvmPopLocal( 5 );
	hb_xvmSetLine( 1231 );
	hb_xvmPushLocal( 5 );
	if( hb_xvmEqualIntIs( 0L, &fValue ) ) break;
	if( !fValue )
		goto lab00001;
	hb_xvmSetLine( 1232 );
	hb_xvmPushLocal( 1 );
	hb_xvmRetValue();
	/* *** END PROC *** */
	break;
lab00001: ;
	hb_xvmSetLine( 1234 );
	hb_xvmPushFuncSymbol( symbols + 89 );
	hb_xvmPushFuncSymbol( symbols + 30 );
	hb_xvmPushLocal( 2 );
	hb_xvmPushLocal( 4 );
	hb_xvmPushLocal( 5 );
	hb_xvmPushLocal( 4 );
	if( hb_xvmMinus() ) break;
	if( hb_xvmFunction( 3 ) ) break;
	hb_xvmPushLocal( 3 );
	if( hb_xvmFunction( 2 ) ) break;
	hb_xvmPopLocal( 6 );
	hb_xvmSetLine( 1236 );
	hb_xvmPushLocal( 5 );
	if( hb_xvmAddInt( 1L ) ) break;
	hb_xvmPopLocal( 4 );
	hb_xvmSetLine( 1237 );
	hb_xvmPushFuncSymbol( symbols + 88 );
	hb_xvmPushLocal( 2 );
	hb_xvmPushLocal( 4 );
	hb_xvmPushLocal( 3 );
	if( hb_xvmFunction( 3 ) ) break;
	hb_xvmPopLocal( 5 );
	hb_xvmSetLine( 1238 );
	hb_xvmPushLocal( 5 );
	if( hb_xvmEqualIntIs( 0L, &fValue ) ) break;
	if( !fValue )
		goto lab00002;
	hb_xvmSetLine( 1239 );
	hb_xvmPushFuncSymbol( symbols + 89 );
	hb_xvmPushFuncSymbol( symbols + 30 );
	hb_xvmPushLocal( 2 );
	hb_xvmPushLocal( 4 );
	if( hb_xvmFunction( 2 ) ) break;
	hb_xvmPushLocal( 3 );
	if( hb_xvmFunction( 2 ) ) break;
	hb_xvmPopLocal( 7 );
	goto lab00003;
lab00002: ;
	hb_xvmSetLine( 1241 );
	hb_xvmPushFuncSymbol( symbols + 89 );
	hb_xvmPushFuncSymbol( symbols + 30 );
	hb_xvmPushLocal( 2 );
	hb_xvmPushLocal( 4 );
	hb_xvmPushLocal( 5 );
	hb_xvmPushLocal( 4 );
	if( hb_xvmMinus() ) break;
	if( hb_xvmFunction( 3 ) ) break;
	hb_xvmPushLocal( 3 );
	if( hb_xvmFunction( 2 ) ) break;
	hb_xvmPopLocal( 7 );
lab00003: ;
	hb_xvmSetLine( 1244 );
	hb_xvmPushFuncSymbol( symbols + 23 );
	hb_xvmPushLocal( 6 );
	if( hb_xvmFunction( 1 ) ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00004;
	hb_xvmSetLine( 1245 );
	hb_xvmPushLocal( 1 );
	hb_xvmRetValue();
	/* *** END PROC *** */
	break;
lab00004: ;
	hb_xvmSetLine( 1248 );
	hb_xvmPushFuncSymbol( symbols + 49 );
	hb_xvmPushLocal( 1 );
	hb_xvmPushLocal( 6 );
	hb_xvmPushLocal( 7 );
	if( hb_xvmDo( 3 ) ) break;
	/* *** END PROC *** */
   } while( 0 );
}

HB_FUNC_STATIC( SEDFINDDELIM )
{
   HB_BOOL fValue;
   do {
	hb_xvmFrame( 2, 3 );
	hb_xvmSetLine( 1253 );
	hb_xvmPushFuncSymbol( symbols + 31 );
	hb_xvmPushLocal( 1 );
	if( hb_xvmFunction( 1 ) ) break;
	hb_xvmPopLocal( 5 );
	hb_xvmSetLine( 1255 );
	hb_xvmPushLocal( 2 );
	hb_xvmPushUnRef();
	hb_xvmPopLocal( 4 );
	goto lab00004;
lab00001: ;
	hb_xvmSetLine( 1257 );
	hb_xvmPushFuncSymbol( symbols + 30 );
	hb_xvmPushLocal( 1 );
	hb_xvmPushLocal( 4 );
	hb_xvmPushInteger( 1 );
	if( hb_xvmFunction( 3 ) ) break;
	hb_xvmPushLocal( 3 );
	if( hb_xvmExactlyEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00003;
	hb_xvmPushLocal( 4 );
	hb_xvmPushLocal( 2 );
	if( hb_xvmGreater() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00002;
	hb_xvmPushFuncSymbol( symbols + 30 );
	hb_xvmPushLocal( 1 );
	hb_xvmPushLocal( 4 );
	if( hb_xvmAddInt( -1L ) ) break;
	hb_xvmPushInteger( 1 );
	if( hb_xvmFunction( 3 ) ) break;
	hb_xvmPushStringConst( "\\", 1 );
	if( hb_xvmExactlyEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( fValue )
		goto lab00003;
lab00002: ;
	hb_xvmSetLine( 1258 );
	hb_xvmPushLocal( 4 );
	hb_xvmRetValue();
	/* *** END PROC *** */
	break;
lab00003: ;
	hb_xvmSetLine( 1255 );
	if( hb_xvmLocalIncPush( 4 ) ) break;
lab00004: ;
	hb_xvmPushLocal( 5 );
	if( hb_xvmGreater() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00001;
	hb_xvmSetLine( 1262 );
	hb_xvmRetInt( 0L );
	/* *** END PROC *** */
   } while( 0 );
}

HB_FUNC_STATIC( SEDUNESCAPE )
{
   HB_BOOL fValue;
   do {
	hb_xvmFrame( 3, 2 );
	hb_xvmSetLine( 1266 );
	hb_xvmPushStringConst( "", 0 );
	hb_xvmPopLocal( 3 );
	hb_xvmSetLine( 1267 );
	hb_xvmLocalSetInt( 4, 1L );
	hb_xvmSetLine( 1268 );
	hb_xvmPushFuncSymbol( symbols + 31 );
	hb_xvmPushLocal( 1 );
	if( hb_xvmFunction( 1 ) ) break;
	hb_xvmPopLocal( 5 );
lab00001: ;
	hb_xvmSetLine( 1270 );
	hb_xvmPushLocal( 4 );
	hb_xvmPushLocal( 5 );
	if( hb_xvmLessEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00003;
	hb_xvmSetLine( 1271 );
	hb_xvmPushFuncSymbol( symbols + 30 );
	hb_xvmPushLocal( 1 );
	hb_xvmPushLocal( 4 );
	hb_xvmPushInteger( 1 );
	if( hb_xvmFunction( 3 ) ) break;
	hb_xvmPushStringConst( "\\", 1 );
	if( hb_xvmExactlyEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00002;
	hb_xvmPushLocal( 4 );
	hb_xvmPushLocal( 5 );
	if( hb_xvmLess() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00002;
	hb_xvmPushFuncSymbol( symbols + 30 );
	hb_xvmPushLocal( 1 );
	hb_xvmPushLocal( 4 );
	if( hb_xvmAddInt( 1L ) ) break;
	hb_xvmPushInteger( 1 );
	if( hb_xvmFunction( 3 ) ) break;
	hb_xvmPushLocal( 2 );
	if( hb_xvmExactlyEqual() ) break;
	if( hb_xvmPopLogical( &fValue ) ) break;
	if( ! fValue )
		goto lab00002;
	hb_xvmSetLine( 1272 );
	hb_xvmPushLocalByRef( 3 );
	hb_xvmPushLocal( 2 );
	if( hb_xvmPlusEqPop() ) break;
	hb_xvmSetLine( 1273 );
	if( hb_xvmLocalAddInt( 4, 2 ) ) break;
	goto lab00001;
lab00002: ;
	hb_xvmSetLine( 1275 );
	hb_xvmPushLocalByRef( 3 );
	hb_xvmPushFuncSymbol( symbols + 30 );
	hb_xvmPushLocal( 1 );
	hb_xvmPushLocal( 4 );
	hb_xvmPushInteger( 1 );
	if( hb_xvmFunction( 3 ) ) break;
	if( hb_xvmPlusEqPop() ) break;
	hb_xvmSetLine( 1276 );
	if( hb_xvmLocalInc( 4 ) ) break;
	goto lab00001;
lab00003: ;
	hb_xvmSetLine( 1280 );
	hb_xvmPushLocal( 3 );
	hb_xvmRetValue();
	/* *** END PROC *** */
   } while( 0 );
}

HB_FUNC_INITSTATICS()
{
   do {
	hb_xvmStatics( symbols + 90, 1 );
	/* *** END PROC *** */
   } while( 0 );
}

