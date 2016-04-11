AC_INIT([ATTEST], 1.0)
AM_INIT_AUTOMAKE([subdir-objects])
AC_PROG_CXX
AC_CONFIG_FILES([
  Makefile
])


AC_ARG_WITH([protobuf-libdir],
    [AS_HELP_STRING([--with-protobuf-libdir=LIB_DIR],
        [location of the protocol buffers libraries, defaults to /usr/lib])],
    [PROTOBUF_LIBDIR="$withval"],
    [PROTOBUF_LIBDIR='/usr/lib'])
AC_SUBST([PROTOBUF_LIBDIR])

LDFLAGS="$LDFLAGS -L$PROTOBUF_LIBDIR"

AC_CHECK_LIB([protobuf], [main], [], [AC_MSG_ERROR([cannot find protobuf library])])

AC_ARG_WITH([protoc],
    [AS_HELP_STRING([--with-protoc=PATH],
        [location of the protoc protocol buffer compiler binary, defaults to protoc])],
    [PROTOC="$withval"],
    [PROTOC='protoc'])
AC_SUBST([PROTOC])

PKG_CHECK_MODULES(libzmq, libzmq >= 3.0)

#PKG_CHECK_MODULES(PROTOBUF, protobuf >= 2.4.0)
#
#AC_CHECK_PROG([PROTOC], [protoc], [protoc])
#AS_IF([test "x${PROTOC}" == "x"],
#    [AC_MSG_ERROR([ProtoBuf compiler "protoc" not found.])])

AC_OUTPUT
