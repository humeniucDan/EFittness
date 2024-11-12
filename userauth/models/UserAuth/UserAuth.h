//
// Created by koath on 11/7/2024.
//

#ifndef USERAUTH_USERAUTH_H
#define USERAUTH_USERAUTH_H

#include <string>
#include <nlohmann/json.hpp>

class UserAuth {
private:
    int id;
    std::string email;
    std::string password;

public:
    explicit UserAuth(const std::string& json);
    UserAuth(int id, std::string email, std::string password);
    UserAuth(std::string email, std::string password);

    int getId() const;
    std::string getEmail() const;
    std::string getPassword() const;
    void setPassword(std::string newPassword);

    std::string toJson();
};


#endif //USERAUTH_USERAUTH_H
