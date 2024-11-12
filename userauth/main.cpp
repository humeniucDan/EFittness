// TODO: create Pseudo Object Model based on Inheritance (will be referred as POMI from now on)
//      - has to implement some kind of "std::string toJson()" method
//      - needs to be able to be cont constructed form a 'database row'

// TODO: create Repository class to abstract away postgres sql similar to an ORM
//      - will be derived a POMI as a generic and generate specific queries and return single instances or vectors of the specified POMI type

// TODO: create Pseudo Object Model based on Inheritance
//      - has to implement some kind of "std::string toJson()" to be able to be sent to
//      - has to be to be usable in some sort of general repository that takes a POMI as a generic
//      - has to be able to be cont constructed form a 'database row' or a JSON string; thus need to implement either as a init func:
//          - "T fromRow(dbRow row)" or as a overloaded constructor
//          - "T fromJson(std::string json)" or as a overloaded constructor

// TODO: coming soon

#include "zeromq/zeromq.h"
#include "crow/routes.h"

#include <thread>

#include <crow.h>
#include <crow/middlewares/cookie_parser.h>
#include <crow/middlewares/session.h>

#include "mongocxx/instance.hpp"

int main() {
//    startConsuming();

    // TODO: REFACTOR IN A SINGLETON PATTERN
    mongocxx::instance inst{};

//    using Session = crow::SessionMiddleware<crow::FileStore>;
    crow::App<crow::CookieParser, crow::SessionMiddleware<crow::FileStore>> app{crow::SessionMiddleware<crow::FileStore>{
            crow::FileStore{"/tmp/sessiondata"}
    }};

    std::thread t{consume};

    startRoutes(app);

    //set the port, set the app to run on multiple threads, and run the app
    app.port(18080).multithreaded().run();

    return 0;
}
