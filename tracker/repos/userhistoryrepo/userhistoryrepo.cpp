//
// Created by koath on 12/17/2024.
//

#include "userhistoryrepo.h"
#include "../timelinerepos/abstracttimelinerepo/abstracttimelinerepo.h"
#include "pqxx/pqxx"

UserHistory* extractUserHistoryByUserId(int id){
    /// TODO: initialize just one connection and pass it around

    return new UserHistory(
            extractTimelineByUserId<WorkoutTimestamp>(id), //extractWorkoutTimelineByUserId(id),
            extractTimelineByUserId<MealTimestamp>(id), //extractMealsTimelineByUserId(id),
            extractTimelineByUserId<CardioTimestamp>(id),  //extractCardioTimelineByUserId(id)
            extractTimelineByUserId<WaterTimestamp>(id) //extractWaterTimelineByUserId(id)
    );
}