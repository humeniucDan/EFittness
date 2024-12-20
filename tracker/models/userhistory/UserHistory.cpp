//
// Created by koath on 12/13/2024.
//

#include "UserHistory.h"
#include <picojson/picojson.h>

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

//std::string UserHistory::toJson() {
//    picojson::object jsonObject;
//    picojson::array workoutsArray;
//    picojson::array mealsArray;
//    picojson::array cardiosArray;
//    picojson::array watersArray;
//
//    for (auto& workout : workouts) {
//        picojson::value workoutJson;
//        picojson::parse(workoutJson, workout.toJson());
//        workoutsArray.push_back(workoutJson);
//    }
//
//    for (auto& meal : meals) {
//        picojson::value mealJson;
//        picojson::parse(mealJson, meal.toJson());
//        mealsArray.push_back(mealJson);
//    }
//
//    for (auto& cardio : cardios) {
//        picojson::value cardioJson;
//        picojson::parse(cardioJson, cardio.toJson());
//        cardiosArray.push_back(cardioJson);
//    }
//
//    for (auto& water : waters) {
//        picojson::value waterJson;
//        picojson::parse(waterJson, water.toJson());
//        watersArray.push_back(waterJson);
//    }
//
//    jsonObject["workouts"] = picojson::value(workoutsArray);
//    jsonObject["meals"] = picojson::value(mealsArray);
//    jsonObject["cardios"] = picojson::value(cardiosArray);
//    jsonObject["waters"] = picojson::value(watersArray);
//
//    return picojson::value(jsonObject).serialize();
//}
