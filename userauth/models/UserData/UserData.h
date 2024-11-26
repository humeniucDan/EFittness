//
// Created by koath on 11/25/2024.
//

#ifndef USERAUTH_USERDATA_H
#define USERAUTH_USERDATA_H


#include <string>
#include <picojson/picojson.h>
#include "../Location/Location.h"

class UserData {
private:
    int _id;
    std::string firstName;
    std::string lastName;
    std::string email;
    char gender;
//    Time birthday
//    Location location;
    std::string profilePicture;
    std::string phone;

public:
    UserData(const std::string &firstName, const std::string &lastName, const std::string &email, char gender,
             const std::string &profilePicture, const std::string &phone);
    UserData(const std::string &json);

    std::string toJson();

    int getId() const;

    void setId(int id);

    const std::string &getFirstName() const;

    void setFirstName(const std::string &firstName);

    const std::string &getLastName() const;

    void setLastName(const std::string &lastName);

    const std::string &getEmail() const;

    void setEmail(const std::string &email);

    char getGender() const;

    void setGender(char gender);

    const std::string &getProfilePicture() const;

    void setProfilePicture(const std::string &profilePicture);

    const std::string &getPhone() const;

    void setPhone(const std::string &phone);
};




#endif //USERAUTH_USERDATA_H
