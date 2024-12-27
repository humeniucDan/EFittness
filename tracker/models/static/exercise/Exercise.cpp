//
// Created by koath on 12/22/2024.
//

#include "Exercise.h"
#include "../muscle/Muscle.h"
#include "picojson/picojson.h"

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

void Exercise::setPrimaryMuscle(Muscle *primaryMuscle) {
    std::cout << "Setting primary muscle\n";
    Exercise::primaryMuscle = primaryMuscle;
}

Exercise::Exercise(const pqxx::row& row) {
    id = row["id"].as<int>();
    name = row["name"].as<std::string>();
    primer = row["primer"].as<std::string>();
    type = row["type"].as<std::string>();
    steps = row["steps"].as<std::string>();
    try {
        primaryMuscle = new Muscle(row["m_id"].as<int>(), row["m_name"].as<std::string>(), {});
        std::cout << "Primary muscle assigned here\n" << std::endl;
    } catch (const std::exception& e) {}
    // Assuming primaryMuscle, secondaryMuscles, and neededEquipment are populated elsewhere
}
std::string Exercise::toJson() {
    picojson::object obj;
    addToJson(obj);
    return picojson::value(obj).serialize();
}

void Exercise::addToJson(picojson::object& jsonObj) {
    jsonObj["id"] = picojson::value(static_cast<double>(id));
    jsonObj["name"] = picojson::value(name);
    jsonObj["primer"] = picojson::value(primer);
    jsonObj["type"] = picojson::value(type);
    jsonObj["steps"] = picojson::value(steps);
    jsonObj["primaryMuscle"] = picojson::value(primaryMuscle->toJson());

    picojson::array musclesArray;
    for (auto& muscle : secondaryMuscles) {
        picojson::object muscleObj;
        muscle.addToJson(muscleObj);
        musclesArray.push_back(picojson::value(muscleObj));
    }
    jsonObj["secondaryMuscles"] = picojson::value(musclesArray);

    picojson::array equipmentArray;
    for (auto& equipment : neededEquipment) {
        picojson::object equipmentObj;
        equipment.addToJson(equipmentObj);
        equipmentArray.push_back(picojson::value(equipmentObj));
    }
    jsonObj["equipmentNeeded"] = picojson::value(equipmentArray);
}

void Exercise::setSecondaryMuscles(const std::vector<Muscle> &workedMuscles) {
    this->secondaryMuscles = workedMuscles;
}

const Muscle* Exercise::getPrimaryMuscle() const {
    return primaryMuscle;
}

//Exercise::~Exercise() {
//    std::cout << "Deleting primary muscle\n";
//    delete primaryMuscle;
//}
