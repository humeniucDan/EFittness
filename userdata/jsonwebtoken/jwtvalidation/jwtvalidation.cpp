//
// Created by koath on 11/12/2024.
//

#include "jwtvalidation.h"

bool validateJwToken(const std::string& jwToken) {
    auto decoded = jwt::decode(jwToken);

    auto verifier = jwt::verify()
            .allow_algorithm(jwt::algorithm::hs256{"secret"});

    try {
        verifier.verify(decoded);
        return true;
    } catch(jwt::error::token_verification_exception& e){
        std::cout << e.what() << "\n";
        return false;
    }
}