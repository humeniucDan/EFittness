//
// Created by koath on 11/6/2024.
//

#include "routes.h"
#include "../jsonwebtoken/jwtvalidation/jwtvalidation.h"
#include "../repos/timelinerepos/abstracttimelinerepo/abstracttimelinerepo.h"
#include "../models/timestamps/userhistorywater/WaterTimestamp.h"
#include "../models/timestamps/userhistorycardio/CardioTimestamp.h"
#include "../models/timestamps/userhistorymeal/MealTimestamp.h"
#include "../models/timestamps/userhistoryworkout/WorkoutTimestamp.h"
#include "../repos/userhistoryrepo/userhistoryrepo.h"
#include "../models/userhistory/UserHistory.h"
#include "../logic/timecheckers/timecheckers.h"
#include "../logic/timelinefolds/timelinefolds.h"

//#include "../repos/timelinerepos/watertimelinerepo/watertimelinerepo.h"

//using Session = crow::SessionMiddleware<crow::FileStore>;
void startRoutes(crow::App<crow::CookieParser, crow::SessionMiddleware<crow::FileStore>> &app){
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

                int id;
                // Extract the "email" claim
                if (decoded_token.has_payload_claim("_id")) {
                    id = std::stoi(decoded_token.get_payload_claim("_id").as_string());
                }

                UserHistory* userHistory = extractUserHistoryByUserId(id);

                userHistory->setMeals(
                        foldTimelineWith<MealTimestamp>(isSameDay, userHistory->getMeals())
                        );

                std::string jsonStr = userHistory->toJson();
                delete userHistory;

                return crow::response(200, jsonStr);
            });
}