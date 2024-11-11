//
// Created by koath on 11/8/2024.
//

#ifndef USERAUTH_JWTLOGIC_H
#define USERAUTH_JWTLOGIC_H

#include <string>

bool validateToken(const std::string& token);
std::string genToken(const std::string& json);

#endif //USERAUTH_JWTLOGIC_H
