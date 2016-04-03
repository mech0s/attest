#include "comp1.hpp"
#include <zmq.hpp>
#include <string>
#include <iostream>

#include "src/pb2/phase2.pb.h"

int Comp1::c1method( int input){
    //  Prepare our context and socket
    zmq::context_t context (1);
    zmq::socket_t socket (context, ZMQ_REQ);

    std::cout << "Connecting to hello world server." << std::endl;
    socket.connect ("ipc:///tmp/zmqipc");

    Person p = Person();
    p.set_name("Mr. Sender");
    p.set_id(999);
    std::string str;
    p.SerializeToString(&str);
    int sz = str.length();
    zmq::message_t *query = new zmq::message_t(sz);
    memcpy(query->data (), str.c_str(), sz);
//    query->size = sz;
    //socket->send (*query);

    //  Do 10 requests, waiting each time for a response
    for (int request_nbr = 0; request_nbr != 10; request_nbr++) {
        //zmq::message_t request (5);
        //memcpy (request.data (), "Hello", 5);
        std::cout << "Sending Hello " << request_nbr << "." << std::endl;
	//socket.send (request, ZMQ_SNDMORE || ZMQ_NOBLOCK);
        socket.send (*query);
        //  Get the reply.
        zmq::message_t reply;
        socket.recv (&reply);
        std::cout << "Received World " << request_nbr << std::endl;
    }

  return input * 2;

}
