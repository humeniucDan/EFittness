//
// Created by koath on 11/12/2024.
//

#ifndef USERAUTH_SIGNUP_H
#define USERAUTH_SIGNUP_H

#include <string>
#include "../models/UserAuth/UserAuth.h"
#include "../models/UserData/UserData.h"
#include "../mongodb/UserAuthRepo/userauthRepo.h"
#include "../zeromq/zeromq.h"

std::string signup(const std::string&);
void setCurrentHighestId();
std::string signup(UserAuth);

#endif //USERAUTH_SIGNUP_H
