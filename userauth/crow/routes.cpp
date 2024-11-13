//
// Created by koath on 11/6/2024.
//

#include "routes.h"
#include "../login/login.h"
#include "../mongodb/UserAuthRepo/userauthRepo.h"
#include "../jsonwebtoken/jwtgeneration/jwtgeneration.h"
#include "../jsonwebtoken/jwtvalidation/jwtvalidation.h"

//using Session = crow::SessionMiddleware<crow::FileStore>;
void startRoutes(crow::App<crow::CookieParser, crow::SessionMiddleware<crow::FileStore>> &app){
    CROW_ROUTE(app, "/").methods("GET"_method)
            ([&app](const crow::request& req){
                auto& ctx = app.get_context<crow::CookieParser>(req);
                std::string jwToken = ctx.get_cookie("jwToken");

                std::string retStr = validateJwToken(jwToken) ? "Valid" : "Invalid";

                produce();
                return crow::response(200, retStr);
            });

    CROW_ROUTE(app, "/logout").methods("GET"_method)
            ([](const crow::request& req){
                crow::response rsp(200, "Logged out!");
                rsp.add_header("Set-Cookie", "jwToken=");
                return rsp;
            });

    CROW_ROUTE(app, "/login").methods("GET"_method)
            ([](const crow::request& req){
                std::string token;
                try {
                    token = login(req.body);
                } catch (int e) {
                    switch (e) {
                        // TODO: handle exceptions
                    }
                }

                crow::response rsp(200, token);
                rsp.add_header("Set-Cookie", "jwToken="+token);

                return rsp;
            });

    CROW_ROUTE(app, "/signup").methods("POST"_method)
            ([](const crow::request& req){
                try {
                    //  TODO: fix issues :
                    //  - mongodb should be an auto incrementing int without collisions
                    //  - remove password from object before sending through queue

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
    CROW_ROUTE(app, "/checkHighestId").methods("GET"_method)
            ([](const crow::request& req){
                  getNextUserAuthId();

                return crow::response(200, "Hello!");
            });
}