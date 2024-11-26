//
// Created by koath on 11/12/2024.
//

#include "signup.h"

std::string signup(const std::string &json) {
    // TODO: check weather the email already exists

    int userId = getNextUserAuthId();

    UserAuth userAuth(json);
    userAuth.setId(userId);

    UserData userData(json);
    userData.setId(userId);

    insertUserAuthIntoDB(userAuth);

    produce(userData.toJson());

    // TODO: send UserData through ZeroMQ to the relevant MicroServ
    // TODO: maybe also return JWT on signup

    return "Inserted user";
}

std::string signup(UserAuth) {
    return "";
}

