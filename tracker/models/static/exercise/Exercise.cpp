//
// Created by koath on 12/22/2024.
//

#include "Exercise.h"
#include "../muscle/Muscle.h"

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

const std::vector<Muscle> &Exercise::getSecondaryMuscles() const {
    return secondaryMuscles;
}

void Exercise::setSecondaryMuscles(const std::vector<Muscle> &workedMuscles) {
    Exercise::secondaryMuscles = workedMuscles;
}

const std::vector<Equipment> &Exercise::getNeededEquipment() const {
    return neededEquipment;
}

void Exercise::setNeededEquipment(const std::vector<Equipment> &neededEquipment) {
    Exercise::neededEquipment = neededEquipment;
}

const std::string &Exercise::getType() const {
    return type;
}

void Exercise::setType(const std::string &type) {
    Exercise::type = type;
}

const std::string &Exercise::getSteps() const {
    return steps;
}

void Exercise::setSteps(const std::string &steps) {
    Exercise::steps = steps;
}

Exercise::Exercise() {}

Exercise::Exercise(int id, const std::string &name, const std::string &primer, const std::string &type,
                   Muscle *primaryMuscle, const std::string &steps, const std::vector<Muscle> &secondaryMuscles,
                   const std::vector<Equipment> &neededEquipment) : id(id), name(name), primer(primer), type(type),
                                                                    primaryMuscle(primaryMuscle), steps(steps),
                                                                    secondaryMuscles(secondaryMuscles),
                                                                    neededEquipment(neededEquipment) {}

void Exercise::setPrimaryMuscle1(Muscle *primaryMuscle) {
    Exercise::primaryMuscle = primaryMuscle;
}
