//
// Created by koath on 12/22/2024.
//

#include "Muscle.h"


int Muscle::getId() const {
    return id;
}

void Muscle::setId(int id) {
    Muscle::id = id;
}

const std::string &Muscle::getName() const {
    return name;
}

void Muscle::setName(const std::string &name) {
    Muscle::name = name;
}

const std::vector<Exercise> &Muscle::getWorkedBy() const {
    return workedBy;
}

void Muscle::setWorkedBy(const std::vector<Exercise> &workedBy) {
    Muscle::workedBy = workedBy;
}

Muscle::Muscle(int id, const std::string &name, const std::vector<Exercise> &workedBy)
    : id(id), name(name), workedBy(workedBy) {}

Muscle::Muscle() {}

Muscle::Muscle(const pqxx::row& row) {
    this->id = row["id"].as<int>();
    this->name = row["name"].as<std::string>();
}

std::string Muscle::toJson() {
    picojson::object obj;
    addToJson(obj);
    return picojson::value(obj).serialize();
}

void Muscle::addToJson(picojson::object &obj) {
    obj["id"] = picojson::value(static_cast<double>(this->id));
    obj["name"] = picojson::value(this->name);
}
