//
// Created by koath on 11/5/2024.
//

#include "zeromq.h"

// TODO: add a constants file for:
//      -protocol
//      -host
//      -port

// TODO: create assignable callback functionality

// TODO: create dynamic object sender/receiver based on POMI

int consume(){
    using namespace std::chrono_literals;

    // initialize the zmq context with a single IO thread
    zmq::context_t context{1};
    // construct a REP (reply) socket and bind to interface
    zmq::socket_t socket{context, zmq::socket_type::pull};
    socket.bind("tcp://*:5556");

    std::cout << "Started consuming.\n";
    while(true)
    {
        zmq::message_t request;
        socket.recv(request, zmq::recv_flags::none);
        std::this_thread::sleep_for(1s);
        std::cout << "Consumer received: " << request.to_string() << std::endl;
    }

    return 0;
}

//TODO: debug or deprecate
void startConsuming(){
    std::thread consumer{consume};
}

int produce(std::string packet)
{
    zmq::context_t context{1};

    zmq::socket_t socket{context, zmq::socket_type::push};
    socket.connect("tcp://localhost:5555");

//    const std::string data{packet};

    socket.send(zmq::buffer(packet), zmq::send_flags::none);
    std::cout << "Producer sent: " << packet << "\n";

    return 0;
}