//
// Created by koath on 11/8/2024.
//

#include "jwtlogic.h"
#include <jwt-cpp/jwt.h>

std::string genToken(const std::string& json) {
    auto token = jwt::create()
            .set_type("JWS")
            .set_issuer("auth0")
            .set_payload_claim("sample", jwt::claim(std::string("test")))
            .sign(jwt::algorithm::hs256{"secret"});
    return token;
}
bool validateToken(const std::string& jwToken) {
    std::string token = "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXUyJ9.eyJpc3MiOiJhdXRoMCIsInNhbXBsZSI6InRlc3QifQ.lQm3N2bVlqt2-1L-FsOjtR6uE-L4E9zJutMWKIe1v1M";
    auto decoded = jwt::decode(token);

    for(auto& e : decoded.get_payload_json())
        std::cout << e.first << " = " << e.second << std::endl;
    return true;
}

