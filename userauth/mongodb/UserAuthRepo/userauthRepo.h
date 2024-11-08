//
// Created by koath on 11/7/2024.
//

#ifndef USERAUTH_USERAUTHREPO_H
#define USERAUTH_USERAUTHREPO_H

#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <bsoncxx/json.hpp>
#include <bsoncxx/builder/stream/document.hpp>
#include "../../models/UserAuth/UserAuth.h"

UserAuth getUserAuthByEmail(const std::string& email);

#endif //USERAUTH_USERAUTHREPO_H
