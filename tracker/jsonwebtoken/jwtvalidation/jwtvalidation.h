//
// Created by koath on 11/12/2024.
//

#ifndef USERAUTH_JWTVALIDATION_H
#define USERAUTH_JWTVALIDATION_H

#include <string>
#include "jwt-cpp/jwt.h"

bool validateJwToken(const std::string& jwToken);

#endif //USERAUTH_JWTVALIDATION_H
