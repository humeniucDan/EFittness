//
// Created by koath on 11/5/2024.
//

#include "zeromq.h"

// TODO: add variables for:
//      -protocol
//      -host
//      -port

// TODO: create assignable callback functionality

// TODO: create dynamic object sender/receiver based on POMI

void consume(){
    using namespace std::chrono_literals;

    // initialize the zmq context with a single IO thread
    zmq::context_t context{1};
    // construct a REP (reply) socket and bind to interface
    zmq::socket_t socket{context, zmq::socket_type::rep};
    socket.bind("tcp://*:5555");
    // prepare some static data for responses
    const std::string data{"World"};

    std::cout << "Started consuming.\n";
    while(true)
    {
        zmq::message_t request;
        socket.recv(request, zmq::recv_flags::none);

        std::cout << "Consumer received: " << request.to_string() << std::endl;
    }
}
void startConsuming(){
    std::thread consumer{consume};
}

int produce()
{
    zmq::context_t context{1};

    zmq::socket_t socket{context, zmq::socket_type::req};
    socket.connect("tcp://localhost:5555");

    const std::string data{"Hello"};

    socket.send(zmq::buffer(data), zmq::send_flags::none);
    std::cout << "Producer sent: " << data << "\n";

    return 0;
}