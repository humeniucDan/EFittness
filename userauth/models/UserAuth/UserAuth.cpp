//
// Created by koath on 11/7/2024.
//

#include "UserAuth.h"

#include <utility>
#include <iostream>

UserAuth::UserAuth(int id, std::string email, std::string password)
    : id(id),
    email(std::move(email)),
    password(std::move(password)) {}

UserAuth::UserAuth(const std::string& json) {
    try {
        nlohmann::json jsonData = nlohmann::json::parse(json);
        this->id = jsonData["_id"];
        this->email = jsonData["email"];
        this->password = jsonData["password"];
    } catch (nlohmann::json::type_error &e) {
        std::cout << "JSON parsing error: " << e.what() << std::endl;
    }
}

int UserAuth::getId() const{
    return this->id;
}
std::string UserAuth::getEmail(){
    return this->email;
}
std::string UserAuth::getPassword(){
    return this->password;
}

std::string UserAuth::toJson() {
    nlohmann::json json;
    json["_id"] = this->id;
    json["email"] = this->email;
    // should not return password as well

    return json.dump();
}
