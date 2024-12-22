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
