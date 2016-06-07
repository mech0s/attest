# attest
Autotools test project, using a variety of technologies
- C++
- ZMQ 
- Google ProtoBuf

After cloning, run 
```bash
autoreconf
```
Probably also run (if prompted to do so)
```bash
automake --add-missing
```

This should set up the autotools project on cygwin or any gnu/linux system

Run ./configure to get your Makefile prepared. 
Deal with any missing libraries and run ./configure again until this succeeds.
See note below about libraries.

All being well, run
```bash
make
```
It should incrementally re-build as required after any source edits.

Clean up the build with 
```bash
make clean
```

Really clean up with...
```bash
make distclean
```
...you will need to run ./configure again.

After "make distclean", running "git status" should show only your edits and any potentially meaningful new files.


###Cygwin library installation
Notes relate to Cygwin 32 on Windows 64bit. Probably applicable to other versions.

apt-cyg is a script that allows additional libraries to be installed
- https://github.com/transcode-open/apt-cyg

Place the script on your path e.g. /usr/bin/apt-cyg

This should make installation of protobuf and zmq easier:
```bash
apt-cyg install libprotobuf-devel
apt-cyg install libzmq-devel
```

The example code uses the cppzmq headers from here 
- https://github.com/zeromq/cppzmq

Copy zmq.hpp and zmq_addon.hpp to /usr/include


