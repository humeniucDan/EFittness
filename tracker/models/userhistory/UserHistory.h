//
// Created by koath on 12/13/2024.
//

#ifndef TRACKER_USERHISTORY_H
#define TRACKER_USERHISTORY_H


#include <vector>
#include "../timestamps/userhistoryworkout/WorkoutTimestamp.h"
#include "../timestamps/userhistorymeal/MealTimestamp.h"
#include "../timestamps/userhistorycardio/CardioTimestamp.h"
#include "../timestamps/userhistorywater/WaterTimestamp.h"

#include <chrono>

class UserHistory {
private:
    std::vector<WorkoutTimestamp> workouts;
    std::vector<MealTimestamp> meals;
    std::vector<CardioTimestamp> cardios;
    std::vector<WaterTimestamp> waters;

public:
    UserHistory(const std::vector<WorkoutTimestamp> workouts, const std::vector<MealTimestamp> meals,
                const std::vector<CardioTimestamp> cardios, const std::vector<WaterTimestamp> waters);

    const std::vector<WorkoutTimestamp> &getWorkouts() const;

//    virtual ~UserHistory();

    void setWorkouts(const std::vector<WorkoutTimestamp> &workouts);

    const std::vector<MealTimestamp> &getMeals() const;
    void setMeals(const std::vector<MealTimestamp> &meals);

    const std::vector<CardioTimestamp> &getCardios() const;
    void setCardios(const std::vector<CardioTimestamp> &cardios);

    const std::vector<WaterTimestamp> &getWaters() const;
    void setWaters(const std::vector<WaterTimestamp> &waters);

    /// TODO: Implement toJsonValue for all classes

    std::string toJson() {
        picojson::object jsonObject;
        picojson::array workoutsArray;
        picojson::array mealsArray;
        picojson::array cardiosArray;
        picojson::array watersArray;

        for (auto& workout : workouts) {
            picojson::value workoutJson;
            picojson::parse(workoutJson, workout.toJson());
            workoutsArray.push_back(workoutJson);
        }

        for (auto& meal : meals) {
            mealsArray.push_back(meal.toJsonValue());
        }

        for (auto& cardio : cardios) {
            picojson::value cardioJson;
            picojson::parse(cardioJson, cardio.toJson());
            cardiosArray.push_back(cardioJson);
        }

        for (auto& water : waters) {
            picojson::value waterJson;
            picojson::parse(waterJson, water.toJson());
            watersArray.push_back(waterJson);
        }

        jsonObject["workouts"] = picojson::value(workoutsArray);
        jsonObject["meals"] = picojson::value(mealsArray);
        jsonObject["cardios"] = picojson::value(cardiosArray);
        jsonObject["waters"] = picojson::value(watersArray);

        return picojson::value(jsonObject).serialize();
    }
};

#endif //TRACKER_USERHISTORY_H
