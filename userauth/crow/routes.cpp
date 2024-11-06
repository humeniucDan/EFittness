//
// Created by koath on 11/6/2024.
//

#include "routes.h"

void startRoutes(crow::App<crow::CookieParser, crow::SessionMiddleware<crow::FileStore>> &app){
    CROW_ROUTE(app, "/").methods("GET"_method)
            ([](const crow::request& req){
                produce();
                return crow::response(200, "Hello!");
            });
}