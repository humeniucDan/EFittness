//
// Created by koath on 11/12/2024.
//

#include "login.h"

//std::string hashPassword(std::string password){
//    return password;
//}

std::string login(const std::string& givenUserAuthJson){
    UserAuth givenUserAuth(givenUserAuthJson);
    return login(givenUserAuth);
}

std::string login(UserAuth givenUserAuthData){
    UserAuth gotUserAuthData = getUserAuthByEmail(givenUserAuthData.getEmail());
    givenUserAuthData.setPassword(hashPassword(givenUserAuthData.getPassword()));

    std::string token = "";

    if (
            givenUserAuthData.getEmail() == gotUserAuthData.getEmail() &&
            givenUserAuthData.getPassword() == gotUserAuthData.getPassword()
       ) {
        token = genJwToken(gotUserAuthData);
    }

    return token;
}
