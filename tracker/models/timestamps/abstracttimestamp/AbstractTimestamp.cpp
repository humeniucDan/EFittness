//
// Created by koath on 12/17/2024.
//

#include "AbstractTimestamp.h"

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

AbstractTimestamp::AbstractTimestamp(int id, int userId, const std::string &description) : id(id), userId(userId),
                                                                                           description(description) {}

AbstractTimestamp::AbstractTimestamp() {}
