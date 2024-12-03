//
// Created by koath on 11/12/2024.
//

#include "signup.h"
#include <argon2.h>
#include "../argon2/argonhelper.h"

//const int ARGON2_HASH_LEN = 32;
#define ARGON2_HASH_LEN 32
#define ARGON2_SALT_LEN 9

int nextUserId = 1;

void setCurrentHighestId(){
    nextUserId = getNextUserAuthId();
}

std::string signup(const std::string &json) {
    // TODO: check weather the email already exists

    // TODO: remake highest id func to not make requests to mongo every time
//    int nextUserId = getNextUserAuthId();

    UserAuth userAuth(json);
    userAuth.setId(nextUserId);
    userAuth.setPassword(
            hashPassword(userAuth.getPassword())
            );

    UserData userData(json);
    userData.setId(nextUserId);

    nextUserId++;

    insertUserAuthIntoDB(userAuth);

    produce(userData.toJson());

    // TODO: send UserData through ZeroMQ to the relevant MicroServ
    // TODO: maybe also return JWT on signup

    return R"({"msg": "Inserted user"})";
}

std::string signup(UserAuth) {
    return "";
}

