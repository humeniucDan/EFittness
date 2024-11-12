//
// Created by koath on 11/8/2024.
//

#ifndef USERAUTH_JWTGENERATION_H
#define USERAUTH_JWTGENERATION_H

#include <string>
#include "../../models/UserAuth/UserAuth.h"

std::string genJwToken(const UserAuth& userAuth);

#endif //USERAUTH_JWTGENERATION_H
