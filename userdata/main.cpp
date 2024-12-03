#include <thread>
#include "zeromq/zeromq.h"

int main() {

    std::thread t{consume};

    return 0;
}
