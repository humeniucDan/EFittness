//
// Created by koath on 12/22/2024.
//

#include "Exercise.h"

int Exercise::getId() const {
    return id;
}

void Exercise::setId(int id) {
    Exercise::id = id;
}

const std::string &Exercise::getName() const {
    return name;
}

void Exercise::setName(const std::string &name) {
    Exercise::name = name;
}

const std::string &Exercise::getPrimer() const {
    return primer;
}

void Exercise::setPrimer(const std::string &primer) {
    Exercise::primer = primer;
}

const std::vector<Muscle> &Exercise::getWorkedMuscles() const {
    return workedMuscles;
}

void Exercise::setWorkedMuscles(const std::vector<Muscle> &workedMuscles) {
    Exercise::workedMuscles = workedMuscles;
}

const std::vector<Equipment> &Exercise::getNeededEquipment() const {
    return neededEquipment;
}

void Exercise::setNeededEquipment(const std::vector<Equipment> &neededEquipment) {
    Exercise::neededEquipment = neededEquipment;
}

Exercise::Exercise(int id, const std::string &name, const std::string &primer, const std::vector<Muscle> &workedMuscles, const std::vector<Equipment> &neededEquipment)
    : id(id), name(name), primer(primer), workedMuscles(workedMuscles), neededEquipment(neededEquipment) {}
