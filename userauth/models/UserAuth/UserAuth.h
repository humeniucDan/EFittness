//
// Created by koath on 11/7/2024.
//

#ifndef USERAUTH_USERAUTH_H
#define USERAUTH_USERAUTH_H


#include <string>

class UserAuth {
private:
    std::string email;
    std::string password;

public:
    std::string getEmail();
    std::string getPassword();
};


#endif //USERAUTH_USERAUTH_H
