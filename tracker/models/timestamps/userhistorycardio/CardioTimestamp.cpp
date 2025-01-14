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

CardioTimestamp::CardioTimestamp(int id, int userId, const std::string &description, const std::string &datetime, int exerciseId, int intensity, int distance)
    : AbstractTimestamp(id, userId, description, datetime), exerciseId(exerciseId), intensity(intensity), distance(distance) {}

CardioTimestamp::CardioTimestamp() {}

CardioTimestamp::CardioTimestamp(std::string json) {
    picojson::value v;
    std::string err = picojson::parse(v, json);
    if (!err.empty()) {
        throw std::runtime_error("JSON parse error: " + err);
    }
    picojson::object& obj = v.get<picojson::object>();
//    if (obj.find("id") != obj.end()) {
//        this->setId(static_cast<int>(obj["id"].get<double>()));
//    }
//    if (obj.find("userId") != obj.end()) {
//        this->setUserId(static_cast<int>(obj["userId"].get<double>()));
//    }
    this->setDescription(obj["description"].get<std::string>());
    this->setDatetime(std::chrono::system_clock::from_time_t(static_cast<time_t>(obj["datetime"].get<double>())));
    this->setExerciseId(static_cast<int>(obj["exerciseId"].get<double>()));
    this->setIntensity(static_cast<int>(obj["intensity"].get<double>()));
    this->setDistance(static_cast<int>(obj["distance"].get<double>()));
}

std::string CardioTimestamp::toJson() {
    picojson::object jsonObject;
    this->addToJson(jsonObject);
    jsonObject["exerciseId"] = picojson::value(static_cast<double>(exerciseId));
    jsonObject["intensity"] = picojson::value(static_cast<double>(intensity));
    jsonObject["distance"] = picojson::value(static_cast<double>(distance));
    return picojson::value(jsonObject).serialize();
}

std::string CardioTimestamp::getSQLInsertQuery(int userId) {
    return "INSERT INTO efitness.cardio_timeline (userId, description, exercise_id, intensity, distance, datetime) VALUES (" +
           std::to_string(userId) + "," +
           "'" + this->getDescription() + "', " +
           std::to_string(this->exerciseId) + "," +
           std::to_string(this->intensity) + "," +
           std::to_string(this->distance) + "," +
            "'" + std::to_string(std::chrono::system_clock::to_time_t(this->getDatetime())) + "')";
}
