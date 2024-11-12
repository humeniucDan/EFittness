//
// Created by koath on 11/8/2024.
//

#include "jwtgeneration.h"
#include <jwt-cpp/jwt.h>

std::string genJwToken(const UserAuth& userAuth) {
    auto token = jwt::create()
            .set_type("JWS")
            .set_payload_claim("_id", jwt::claim(std::to_string(userAuth.getId())))
            .set_payload_claim("email", jwt::claim(userAuth.getEmail()))
            .sign(jwt::algorithm::hs256{"secret"});
    return token;
}

