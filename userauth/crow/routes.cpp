//
// Created by koath on 11/6/2024.
//

#include "routes.h"
#include "../login/login.h"
#include "../mongodb/UserAuthRepo/userauthRepo.h"

void startRoutes(crow::App<crow::CookieParser, crow::SessionMiddleware<crow::FileStore>> &app){
    CROW_ROUTE(app, "/").methods("GET"_method)
            ([](const crow::request& req){
                produce();
                return crow::response(200, "Hello!");
            });

    CROW_ROUTE(app, "/login").methods("GET"_method)
            ([](const crow::request& req){
//                std::string token;
//                try {
////                    token = login();
//                } catch (int e) {
//                    switch (e) {
//                        case 1:
//                            return crow::response(400, "Email not found");
//                        case 2:
//                            return crow::response(400, "Password incorect");
//                    }
//                }

                return crow::response(200, "token");
            });

    CROW_ROUTE(app, "/signup").methods("POST"_method)
            ([](const crow::request& req){
                getUserAuthByEmail("email");
                return crow::response(200, "Hello!");
            });
}