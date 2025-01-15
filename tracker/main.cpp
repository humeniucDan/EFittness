#include <thread>

#include <crow.h>
#include <crow/middlewares/cookie_parser.h>
#include <crow/middlewares/session.h>

#include "crow/routes.h"
#include <crow/middlewares/cors.h>

int main() {

//    using Session = crow::SessionMiddleware<crow::FileStore>;
    crow::App<crow::CookieParser, crow::SessionMiddleware<crow::FileStore>, crow::CORSHandler> app{crow::SessionMiddleware<crow::FileStore>{
            crow::FileStore{"/tmp/sessiondata"}
    }};

auto& cors = app.get_middleware<crow::CORSHandler>();
cors
    .global()
    .headers("X-Custom-Header", "Upgrade-Insecure-Requests")
    .methods("POST"_method, "GET"_method, "PUT"_method, "DELETE"_method, "OPTIONS"_method)
    .origin("*");



    startRoutes(app);

    //set the port, set the app to run on multiple threads, and run the app
    app.port(18082).multithreaded().run();

    return 0;
}
