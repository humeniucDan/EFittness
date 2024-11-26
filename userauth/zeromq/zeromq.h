//
// Created by koath on 11/5/2024.
//

#ifndef USERAUTH_ZEROMQ_H
#define USERAUTH_ZEROMQ_H

#include <string>
#include <chrono>
#include <thread>
#include <iostream>

#include <zmq.hpp>

//void startConsuming();
int consume();
int produce(std::string string);

#endif //USERAUTH_ZEROMQ_H
