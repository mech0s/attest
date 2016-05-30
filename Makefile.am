AM_LDFLAGS= -pthread

bin_PROGRAMS = helloClient helloServer
helloClient_SOURCES = \
	src/component1/comp1.cpp \
	src/clientMain.cpp 

helloClient_CPPFLAGS = $(libzmq_CFLAGS) 
helloClient_LDADD = $(libzmq_LIBS) $(PTHREAD_LIBS)

helloServer_SOURCES = \
	src/component2/comp2.cpp \
	src/serverMain.cpp

helloServer_CPPFLAGS = $(libzmq_CFLAGS) 
helloServer_LDADD = $(libzmq_LIBS) $(PTHREAD_LIBS)

%.pb.cc %.pb.h: %.proto
	$(PROTOC) --proto_path=$(srcdir)/$(@D) --cpp_out=@builddir@/$(@D) $^

dist_noinst_DATA = \
	src/pb2/phase2.proto

nodist_helloClient_SOURCES = \
	@builddir@/src/pb2/phase2.pb.cc \
	@builddir@/src/pb2/phase2.pb.h \
	@builddir@/src/pb2/sentMessage.pb.h\
	@builddir@/src/pb2/sentMessage.pb.cc
nodist_helloServer_SOURCES = \
	@builddir@/src/pb2/phase2.pb.cc \
	@builddir@/src/pb2/phase2.pb.h

MOSTLYCLEANFILES = $(nodist_helloServer_SOURCES)

BUILT_SOURCES = @builddir@/src/pb2/phase2.pb.h \
				@builddir@/src/pb2/sentMessage.pb.h


AM_CPPFLAGS = -I@builddir@ 
#+=
