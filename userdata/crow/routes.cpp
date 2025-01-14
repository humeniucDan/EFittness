//
// Created by koath on 11/6/2024.
//

#include "routes.h"
#include "../jsonwebtoken/jwtvalidation/jwtvalidation.h"
#include "../mongodb/UserDataRepo/userdataRepo.h"

#include <crow/middlewares/cors.h>

//using Session = crow::SessionMiddleware<crow::FileStore>;
void startRoutes(crow::App<crow::CookieParser, crow::SessionMiddleware<crow::FileStore>, crow::CORSHandler> &app){
    CROW_ROUTE(app, "/").methods("GET"_method)
            ([&app](const crow::request& req){
                auto& ctx = app.get_context<crow::CookieParser>(req);
                std::string jwToken = ctx.get_cookie("jwToken");

                if(!validateJwToken(jwToken)){
                    std::cout << "Invalid\n";
                    return crow::response(401, "Invalid token");
                }

                std::string retStr = "";

                auto decoded_token = jwt::decode(jwToken);

                std::string email = "";
                // Extract the "email" claim
                if (decoded_token.has_payload_claim("email")) {
                    email = decoded_token.get_payload_claim("email").as_string();
                }

                retStr = extractUserDataJsonByEmail(email);

                return crow::response(200, retStr);
            });
}