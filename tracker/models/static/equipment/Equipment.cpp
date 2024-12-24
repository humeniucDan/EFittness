//
// Created by koath on 12/22/2024.
//

#include "Equipment.h"


int Equipment::getId() const {
    return id;
}

void Equipment::setId(int id) {
    Equipment::id = id;
}

const std::string &Equipment::getName() const {
    return name;
}

void Equipment::setName(const std::string &name) {
    Equipment::name = name;
}

const std::vector<Exercise> &Equipment::getUsedIn() const {
    return usedIn;
}

void Equipment::setUsedIn(const std::vector<Exercise> &usedIn) {
    Equipment::usedIn = usedIn;
}

Equipment::Equipment(int id, const std::string &name, const std::vector<Exercise> &usedIn)
    : id(id), name(name), usedIn(usedIn) {}

Equipment::Equipment() {}

//picojson::object Equipment::toJson() const {
//    picojson::object obj;
//    obj["id"] = picojson::value(static_cast<double>(id));
//    obj["name"] = picojson::value(name);
//
//    picojson::array exercisesArray;
//    for (const auto& exercise : usedIn) {
//        exercisesArray.push_back(picojson::value(exercise.toJson()));
//    }
//    obj["usedIn"] = picojson::value(exercisesArray);
//
//    return obj;
//}

void Equipment::addToJson(picojson::object &j) {
    j["id"] = picojson::value(static_cast<double>(id));
    j["name"] = picojson::value(name);

    picojson::array exercisesArray;
    for (auto& exercise : usedIn) {
        picojson::object exerciseJson;
        exercise.addToJson(exerciseJson);
        exercisesArray.push_back(picojson::value(exerciseJson));
    }
    j["usedIn"] = picojson::value(exercisesArray);
}
