//
// Created by koath on 12/17/2024.
//

#include "MealTimestamp.h"

int MealTimestamp::getCarbs() const {
    return carbs;
}

void MealTimestamp::setCarbs(int carbs) {
    MealTimestamp::carbs = carbs;
}

int MealTimestamp::getFats() const {
    return fats;
}

void MealTimestamp::setFats(int fats) {
    MealTimestamp::fats = fats;
}

int MealTimestamp::getProtein() const {
    return protein;
}

void MealTimestamp::setProtein(int protein) {
    MealTimestamp::protein = protein;
}
