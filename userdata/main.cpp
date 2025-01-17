#include <thread>
#include "zeromq/zeromq.h"

#include "mongocxx/instance.hpp"

#include <crow.h>
#include <crow/middlewares/cookie_parser.h>
#include <crow/middlewares/session.h>

#include "crow/routes.h"
#include "mongodb/UserDataRepo/userdataRepo.h"

int main() {
    std::thread t([](){
        consume(insertUserDataIntoDB);
    });

//    while(true){}
    mongocxx::instance inst{};

//    using Session = crow::SessionMiddleware<crow::FileStore>;
    crow::App<crow::CookieParser, crow::SessionMiddleware<crow::FileStore>, crow::CORSHandler> app{crow::SessionMiddleware<crow::FileStore>{
            crow::FileStore{"/tmp/sessiondata"}
    }};
    startRoutes(app);

    //set the port, set the app to run on multiple threads, and run the app
    app.port(18081).multithreaded().run();

    return 0;
}
