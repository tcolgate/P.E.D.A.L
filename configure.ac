AC_INIT(src/parsepdl.c)
AC_CONFIG_AUX_DIR(./config)
AM_INIT_AUTOMAKE(pedal, 0.2)
AM_CONFIG_HEADER(include/config.h )

dnl Checks for programs.
AC_PROG_MAKE_SET
AC_PROG_CC
AM_PROG_LEX
AC_PROG_YACC

AC_LIBTOOL_DLOPEN
AM_PROG_LIBTOOL

dnl Checks for header files.
AC_STDC_HEADERS

dnl Checks for library functions.

AC_OUTPUT([Makefile  src/Makefile include/Makefile export-plugins/Makefile export-plugins/RIB-exporter/Makefile export-plugins/POV-exporter/Makefile export-plugins/GL-exporter/Makefile])

