//
// Created by koath on 12/17/2024.
//

#include "AbstractTimestamp.h"
#include <format>
#include <utility>
#define DATE_FMT "%Y-%m-%d %H:%M:%S"

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

AbstractTimestamp::AbstractTimestamp(int id, int userId, std::string description, const std::string& datetime)
        : id(id), userId(userId), description(std::move(description)) {
    // what is even going on here ??
    std::tm tm = {};
    std::istringstream ss(datetime);
    ss >> std::get_time(&tm, "%Y-%m-%d %H:%M:%S");
    this->datetime = std::chrono::system_clock::from_time_t(std::mktime(&tm));
}

AbstractTimestamp::AbstractTimestamp(const pqxx::row& row)
    : AbstractTimestamp(
            row["id"].as<int>(),
            row["userId"].as<int>(),
            row["description"].as<std::string>(),
            row["datetime"].as<std::string>()
            ) {}

AbstractTimestamp::AbstractTimestamp() {}

void AbstractTimestamp::addToJson(picojson::object& jsonObject) {
    jsonObject["id"] = picojson::value(static_cast<double>(id));
    jsonObject["userId"] = picojson::value(static_cast<double>(userId));
    jsonObject["description"] = picojson::value(description);

    std::time_t date_time_t = std::chrono::system_clock::to_time_t(datetime);
    std::ostringstream oss;
    oss << std::put_time(std::localtime(&date_time_t), DATE_FMT);
    jsonObject["datetime"] = picojson::value(oss.str());
}

const std::chrono::system_clock::time_point &AbstractTimestamp::getDatetime() const {
    return datetime;
}

void AbstractTimestamp::setDatetime(const std::chrono::system_clock::time_point &datetime) {
    AbstractTimestamp::datetime = datetime;
}

AbstractTimestamp::AbstractTimestamp(int id, int userId, std::string description,
                                     const std::chrono::system_clock::time_point datetime)
                                     : id(id), userId(userId), description(std::move(description)), datetime(datetime) {}

std::string AbstractTimestamp::getSQLInsertQuery(int userId){
    return ");";
}
