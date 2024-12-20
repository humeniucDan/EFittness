//
// Created by koath on 12/17/2024.
//

#include "WaterTimestamp.h"

WaterTimestamp::WaterTimestamp() {}


int WaterTimestamp::getQuantity() const {
    return quantity;
}

void WaterTimestamp::setQuantity(int quantity) {
    WaterTimestamp::quantity = quantity;
}

int WaterTimestamp::getCaffeine() const {
    return caffeine;
}

void WaterTimestamp::setCaffeine(int caffeine) {
    WaterTimestamp::caffeine = caffeine;
}

int WaterTimestamp::getSugar() const {
    return sugar;
}

void WaterTimestamp::setSugar(int sugar) {
    WaterTimestamp::sugar = sugar;
}

std::string WaterTimestamp::toJson(){
    picojson::object jsonObject;
    this->addToJson(jsonObject);
    jsonObject["quantity"] = picojson::value(static_cast<double>(quantity));
    jsonObject["caffeine"] = picojson::value(static_cast<double>(caffeine));
    jsonObject["sugar"] = picojson::value(static_cast<double>(sugar));
    return picojson::value(jsonObject).serialize();
}

std::string_view WaterTimestamp::getTablename(){
    return WaterTimestamp::tableName;
}

WaterTimestamp::WaterTimestamp(int id, int userId, const std::string &description, int quantity, int caffeine, int sugar)
    : AbstractTimestamp(id, userId, description), quantity(quantity), caffeine(caffeine), sugar(sugar) {}
WaterTimestamp::WaterTimestamp(const pqxx::row& row)
        : AbstractTimestamp(row), quantity(row["quantity"].as<int>()), caffeine(row["caffeine"].as<int>()), sugar(row["sugar"].as<int>()) {}


