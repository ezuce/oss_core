AC_PREREQ(2.57)
AC_INIT(oss_core, 2.0.0, info@ossapp.com)
AC_CONFIG_AUX_DIR(config)
m4_include([config/general.m4])
m4_include([config/oss_lib.m4])
AM_INIT_AUTOMAKE(foreign tar-ustar)
SFAC_AUTOMAKE_VERSION([1.6])
AC_CONFIG_SRCDIR([src/Core.cpp])
AM_CONFIG_HEADER([src/config.h])
AC_PROG_LIBTOOL
AC_LTDL_SHLIBEXT
AC_PATH_PROG([BASH], [bash])
AC_PROG_CXX
AX_COMPILER_VENDOR
AC_PROG_CC
CHECK_XARGS_REPLACE
CHECK_MSG_NOSIGNAL
CHECK_LIBRT
AC_SEARCH_LIBS([dlopen], [dl])
SFAC_LIB_CORE_FLAGS
AC_CHECK_FUNCS(setenv)
AC_CONFIG_FILES([
  Makefile
  include/Makefile
  src/Makefile
])

AC_OUTPUT
