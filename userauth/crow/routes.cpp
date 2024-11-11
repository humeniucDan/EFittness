//
// Created by koath on 11/6/2024.
//

#include "routes.h"
#include "../login/login.h"
#include "../mongodb/UserAuthRepo/userauthRepo.h"
#include "../jsonwebtoken/jwtlogic/jwtlogic.h"

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
//                    token = login();
//                } catch (int e) {
//                    switch (e) {
//                        case 1:
//                            return crow::response(400, "Email not found");
//                        case 2:
//                            return crow::response(400, "Password incorect");
//                    }
//                }
                crow::response rsp(200, "jwtToken");
                rsp.add_header("Set-Cookie", "generatedToken="+genToken(req.body));

                return rsp;
            });

    CROW_ROUTE(app, "/signup").methods("POST"_method)
            ([](const crow::request& req){
                try {
                    std::cout << req.body << std::endl;
                    UserAuth curUser = getUserAuthByEmail(req.body);
                    std::cout <<
                        curUser.getId() << " " <<
                        curUser.getEmail() << " " <<
                        curUser.getPassword() <<
                        "\n";
                } catch (nlohmann::json::parse_error &e) {
                    std::cout << "JSON parsing error: " << e.what() << std::endl;
                }
                return crow::response(200, "Hello!");
            });
}