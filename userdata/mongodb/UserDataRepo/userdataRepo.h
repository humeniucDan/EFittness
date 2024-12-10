//
// Created by koath on 11/26/2024.
//

#ifndef USERAUTH_USERDATAREPO_H
#define USERAUTH_USERDATAREPO_H

#include "../../models/UserData/UserData.h"
#include "../connectionlogic/connectionlogic.h"

void insertUserDataIntoDB(std::string userDataJson);
void insertUserDataIntoDB(UserData userData);

std::string extractUserDataJsonByEmail(std::string email);

#endif //USERAUTH_USERDATAREPO_H
