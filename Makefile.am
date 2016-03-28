AM_LDFLAGS = -lzmq -lpthread

bin_PROGRAMS = helloClient helloServer
helloClient_SOURCES = \
	src/component1/comp1.cpp \
	src/clientMain.cpp

helloServer_SOURCES = \
	src/component2/comp2.cpp \
	src/serverMain.cpp

%.pb.cc %.pb.h: %.proto
	$(PROTOC) --proto_path=$(srcdir) --cpp_out=@builddir@ $^

dist_noinst_DATA = whatever.proto

nodist_helloServer_SOURCES = @builddir@/whatever.pb.cc @builddir@/whatever.pb.h

MOSTLYCLEANFILES = whatever.pb.cc whatever.pb.h

BUILT_SOURCES = whatever.pb.h

AM_CPPFLAGS = -I@builddir@
#+=
