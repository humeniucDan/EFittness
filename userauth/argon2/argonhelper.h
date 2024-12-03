//
// Created by koath on 12/3/2024.
//

#ifndef USERAUTH_ARGONHELPER_H
#define USERAUTH_ARGONHELPER_H

#include <string>
#include <argon2.h>

std::string hashPassword(const std::string &password);

#endif //USERAUTH_ARGONHELPER_H
