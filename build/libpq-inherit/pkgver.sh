#/bin/sh
awk '/#define PACKAGE_VERSION/ { split($3, v, "."); gsub(/"/, "", v[1]); print v[1] }' $1/pg_config.h
