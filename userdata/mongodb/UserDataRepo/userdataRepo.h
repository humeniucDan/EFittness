//
// Created by koath on 11/26/2024.
//

#ifndef USERAUTH_USERDATAREPO_H
#define USERAUTH_USERDATAREPO_H

#include "../../models/UserData/UserData.h"
#include "../connectionlogic/connectionlogic.h"

bool insertUserDataIntoDB(std::string userDataJson);

std::string extractUserDataJsonByEmail(std::string email);

#endif //USERAUTH_USERDATAREPO_H
