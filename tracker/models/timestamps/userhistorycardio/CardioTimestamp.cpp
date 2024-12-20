//
// Created by koath on 12/13/2024.
//

#include "CardioTimestamp.h"

int CardioTimestamp::getExerciseId() const {
    return exerciseId;
}

void CardioTimestamp::setExerciseId(int exerciseId) {
    CardioTimestamp::exerciseId = exerciseId;
}

int CardioTimestamp::getIntensity() const {
    return intensity;
}

void CardioTimestamp::setIntensity(int intensity) {
    CardioTimestamp::intensity = intensity;
}

int CardioTimestamp::getDistance() const {
    return distance;
}

void CardioTimestamp::setDistance(int distance) {
    CardioTimestamp::distance = distance;
}

std::string_view CardioTimestamp::getTablename() {
    return CardioTimestamp::tableName;
}

CardioTimestamp::CardioTimestamp(const pqxx::row& row)
    : AbstractTimestamp(row), exerciseId(row["exerciseId"].as<int>()), intensity(row["intensity"].as<int>()), distance(row["distance"].as<int>()) {}

CardioTimestamp::CardioTimestamp(int id, int userId, const std::string &description, int exerciseId, int intensity, int distance)
    : AbstractTimestamp(id, userId, description), exerciseId(exerciseId), intensity(intensity), distance(distance) {}

CardioTimestamp::CardioTimestamp() {}

std::string CardioTimestamp::toJson() {
    picojson::object jsonObject;
    this->addToJson(jsonObject);
    jsonObject["exerciseId"] = picojson::value(static_cast<double>(exerciseId));
    jsonObject["intensity"] = picojson::value(static_cast<double>(intensity));
    jsonObject["distance"] = picojson::value(static_cast<double>(distance));
    return picojson::value(jsonObject).serialize();
}

