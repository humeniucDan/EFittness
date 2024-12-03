#include <thread>
#include "zeromq/zeromq.h"

int main() {

    std::thread t{consume};

    while(true){}

    return 0;
}
