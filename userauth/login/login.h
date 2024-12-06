//
// Created by koath on 11/7/2024.
//

#ifndef USERAUTH_LOIGN_H
#define USERAUTH_LOIGN_H

#include <string>
#include "../models/UserAuth/UserAuth.h"
#include "../mongodb/UserAuthRepo/userauthRepo.h"
#include "../jsonwebtoken/jwtgeneration/jwtgeneration.h"
#include "../argon2/argonhelper.h"

std::string login(const std::string&);
std::string login(UserAuth);

#endif //USERAUTH_LOIGN_H
