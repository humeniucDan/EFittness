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

WaterTimestamp::WaterTimestamp(int id, int userId, const std::string &description, int quantity, int caffeine, int sugar)
    : AbstractTimestamp(id, userId, description), quantity(quantity), caffeine(caffeine), sugar(sugar) {}


