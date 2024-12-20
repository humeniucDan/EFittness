//
// Created by koath on 12/17/2024.
//

#include "AbstractTimestamp.h"

#include <utility>

int AbstractTimestamp::getId() const {
    return id;
}

void AbstractTimestamp::setId(int id) {
    AbstractTimestamp::id = id;
}

int AbstractTimestamp::getUserId() const {
    return userId;
}

void AbstractTimestamp::setUserId(int userId) {
    AbstractTimestamp::userId = userId;
}

const std::string &AbstractTimestamp::getDescription() const {
    return description;
}

void AbstractTimestamp::setDescription(const std::string &description) {
    AbstractTimestamp::description = description;
}

AbstractTimestamp::AbstractTimestamp(int id, int userId, std::string description) : id(id), userId(userId),
                                                                                           description(std::move(description)) {}

AbstractTimestamp::AbstractTimestamp(const pqxx::row& row)
    : AbstractTimestamp(
            row["id"].as<int>(),
            row["userId"].as<int>(),
            row["description"].as<std::string>()
            ) {}

AbstractTimestamp::AbstractTimestamp() {}

void AbstractTimestamp::addToJson(picojson::object& jsonObject) {
    jsonObject["id"] = picojson::value(static_cast<double>(id));
    jsonObject["userId"] = picojson::value(static_cast<double>(userId));
    jsonObject["description"] = picojson::value(description);
}
