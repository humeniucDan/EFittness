// TODO: create Pseudo Object Model based on Inheritance (will be referred as POMI from now on)
//      - has to implement some kind of "std::string toJson()" method
//      - has to be to be usable in some sort of general repository that takes a POMI as a generic
//      - needs to be able to be cont constructed form a 'database row'

// TODO: create Repository class to abstract away postgres sql similar to an ORM
//      - will be able to take a POMI as a generic and generate specific queries and return single instances or vectors of the specified POMI type

// TODO: create Pseudo Object Model based on Inheritance
//      - has to implement some kind of "std::string toJson()" to be able to be sent to
//      - has to be to be usable in some sort of general repository that takes a POMI as a generic
//      - has to be able to be cont constructed form a 'database row' or a JSON string; thus need to implement either as a init func:
//          - "T formRow(dbRow row)" or as a overloaded constructor
//          - "T formJson(std::string json)" or as a overloaded constructor

// TODO: coming soon

#include "zeromq/zeromq.h"

int main() {
    startConsuming();

    for(int i = 0; i < 3; i++){
        produce();
    }

    return 0;
}
