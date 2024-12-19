//
// Created by koath on 12/13/2024.
//

#include "UserHistory.h"

UserHistory::UserHistory(const std::vector<WorkoutTimestamp> workouts,
                         const std::vector<MealTimestamp> meals,
                         const std::vector<CardioTimestamp> cardios,
                         const std::vector<WaterTimestamp> waters)
        : workouts(workouts), meals(meals), cardios(cardios), waters(waters) {}

const std::vector<WorkoutTimestamp> &UserHistory::getWorkouts() const {
    return workouts;
}

void UserHistory::setWorkouts(const std::vector<WorkoutTimestamp> &workouts) {
    UserHistory::workouts = workouts;
}

const std::vector<MealTimestamp> &UserHistory::getMeals() const {
    return meals;
}

void UserHistory::setMeals(const std::vector<MealTimestamp> &meals) {
    UserHistory::meals = meals;
}

const std::vector<CardioTimestamp> &UserHistory::getCardios() const {
    return cardios;
}

void UserHistory::setCardios(const std::vector<CardioTimestamp> &cardios) {
    UserHistory::cardios = cardios;
}

const std::vector<WaterTimestamp> &UserHistory::getWaters() const {
    return waters;
}

void UserHistory::setWaters(const std::vector<WaterTimestamp> &waters) {
    UserHistory::waters = waters;
}
