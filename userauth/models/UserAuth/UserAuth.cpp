//
// Created by koath on 11/7/2024.
//

// TODO: Refactor JSON parsing using PICOJSON
// TODO: Use argon2 for password hashing: https://vcpkg.io/en/package/argon2

#include "UserAuth.h"

#include <utility>
#include <iostream>

UserAuth::UserAuth(int id, std::string email, std::string password)
    : id(id),
    email(std::move(email)),
    password(std::move(password)) {}
UserAuth::UserAuth(std::string email, std::string password)
    : id(-1),
    email(std::move(email)),
    password(std::move(password)) {}

UserAuth::UserAuth(const std::string& json) {
    try {
        nlohmann::json jsonData = nlohmann::json::parse(json);

        if(jsonData.contains("_id"))
            this->id = jsonData["_id"];

        if(jsonData.contains("email") && jsonData.contains("password")) {
            this->email = jsonData["email"];
            this->password = jsonData["password"];
        }
    } catch (nlohmann::json::type_error &e) {
        std::cout << "JSON parsing error: " << e.what() << std::endl;
    }
}

int UserAuth::getId() const{
    return this->id;
}
std::string UserAuth::getEmail() const{
    return this->email;
}
std::string UserAuth::getPassword() const{
    return this->password;
}

void UserAuth::setId(const int &id) {
    this->id = id;
}

void UserAuth::setPassword(std::string newPassword){
    this->password = std::move(newPassword);
}

std::string UserAuth::toJson() {
    nlohmann::json json;
    json["_id"] = this->id;
    json["email"] = this->email;
    // should not return password as well

    return json.dump();
}
