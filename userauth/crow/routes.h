//
// Created by koath on 11/6/2024.
//

#ifndef USERAUTH_ROUTES_H
#define USERAUTH_ROUTES_H

#include <crow.h>
#include "crow/middlewares/cookie_parser.h"
#include "crow/middlewares/session.h"

#include "../zeromq/zeromq.h"

//using Session = crow::SessionMiddleware<crow::FileStore>;

void startRoutes(crow::App<crow::CookieParser, crow::SessionMiddleware<crow::FileStore>> &app);

#endif //USERAUTH_ROUTES_H