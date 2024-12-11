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

int consume(void (*callback)(std::string)){
    using namespace std::chrono_literals;

    zmq::context_t context{1};
    zmq::socket_t socket{context, zmq::socket_type::pull};
    socket.bind("tcp://*:5556");

    std::cout << "Started consuming.\n";
    while(true)
    {
        zmq::message_t request;
        socket.recv(request, zmq::recv_flags::none);

        std::cout << "Consumer received: " << request.to_string() << std::endl;

        callback(request.to_string());
    }
    return 0;
}

// TODO: add callback function as a parameter
// might prefer function pointer as opposed to std::function<> for the performance gain
int produce(std::string packet)
{
    zmq::context_t context{1};

    zmq::socket_t socket{context, zmq::socket_type::push};
    socket.connect("tcp://*:5555");

    socket.send(zmq::buffer(packet), zmq::send_flags::none);
    std::cout << "Producer sent: " << packet << "\n";

    return 0;
}