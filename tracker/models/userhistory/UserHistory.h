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
};


#endif //TRACKER_USERHISTORY_H
