//
// Created by koath on 11/25/2024.
//

#include "UserData.h"

UserData::UserData(const std::string &firstName, const std::string &lastName, const std::string &email, char gender, const std::string &profilePicture, const std::string &phone)
    : firstName(firstName),
    lastName(lastName), email(email),
    gender(gender),
    profilePicture(profilePicture),
    phone(phone) {}

UserData::UserData(const std::string &json) {
    try {
        picojson::value v;
        std::string err = picojson::parse(v, json);
        if (!err.empty()) {
            throw std::runtime_error(err);
        }
        if (!v.is<picojson::object>()) {
            throw std::runtime_error("JSON is not an object");
        }
        picojson::object &obj = v.get<picojson::object>();
        this->firstName = obj["firstName"].get<std::string>();
        this->lastName = obj["lastName"].get<std::string>();
        this->email = obj["email"].get<std::string>();
        this->gender = obj["gender"].get<std::string>()[0];
        this->profilePicture = obj["profilePicture"].get<std::string>();
        this->phone = obj["phone"].get<std::string>();
    } catch (const std::exception &e) {
        std::cout << "JSON parsing error: " << e.what() << std::endl;
    }
}

std::string UserData::toJson() {
    picojson::object obj;
    obj["_id"] = picojson::value(static_cast<double>(this->_id));
    obj["firstName"] = picojson::value(this->firstName);
    obj["lastName"] = picojson::value(this->lastName);
    obj["email"] = picojson::value(this->email);
    obj["gender"] = picojson::value(std::string(1, this->gender));
    obj["profilePicture"] = picojson::value(this->profilePicture);
    obj["phone"] = picojson::value(this->phone);

    return picojson::value(obj).serialize();
}

int UserData::getId() const {
    return _id;
}

void UserData::setId(int id) {
    _id = id;
}

const std::string &UserData::getFirstName() const {
    return firstName;
}

void UserData::setFirstName(const std::string &firstName) {
    UserData::firstName = firstName;
}

const std::string &UserData::getLastName() const {
    return lastName;
}

void UserData::setLastName(const std::string &lastName) {
    UserData::lastName = lastName;
}

const std::string &UserData::getEmail() const {
    return email;
}

void UserData::setEmail(const std::string &email) {
    UserData::email = email;
}

char UserData::getGender() const {
    return gender;
}

void UserData::setGender(char gender) {
    UserData::gender = gender;
}

const std::string &UserData::getProfilePicture() const {
    return profilePicture;
}

void UserData::setProfilePicture(const std::string &profilePicture) {
    UserData::profilePicture = profilePicture;
}

const std::string &UserData::getPhone() const {
    return phone;
}

void UserData::setPhone(const std::string &phone) {
    UserData::phone = phone;
}
