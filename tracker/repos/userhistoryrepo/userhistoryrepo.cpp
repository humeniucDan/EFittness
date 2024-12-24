//
// Created by koath on 12/17/2024.
//

#include "userhistoryrepo.h"
#include "../timelinerepos/abstracttimelinerepo/abstracttimelinerepo.h"
#include "../staticrepos/exereciserepo/exerciserepo.h"
#include "pqxx/pqxx"

UserHistory* extractUserHistoryByUserId(int id){
    /// TODO: maybe use a connection pool
    /// TODO: extract the workout timeline and add exercise names to the timeline
    /// or redo the timeline to include the exercise name

    pqxx::connection conn(
            "dbname=" + DB_NAME +
            " user=" + USER +
            " password=" + PASSWORD +
            " host=" + HOST +
            " port=" + PORT
    );
    if (!conn.is_open()) {
        std::cerr << "Failed to connect to database." << std::endl;
        // maybe return an empty vector
        return {};
    }

    std::vector<WorkoutTimestamp> workoutTimeline = extractTimelineByUserId<WorkoutTimestamp>(conn, id);
    for(auto& workout: workoutTimeline){
        Exercise e = workout.getExercise();
        e.setId(workout.getExerciseId());
        workout.setExercise(e);
    }

    return new UserHistory(
            workoutTimeline, //extractWorkoutTimelineByUserId(id),
            extractTimelineByUserId<MealTimestamp>(conn, id), //extractMealsTimelineByUserId(id),
            extractTimelineByUserId<CardioTimestamp>(conn, id),  //extractCardioTimelineByUserId(id)
            extractTimelineByUserId<WaterTimestamp>(conn, id) //extractWaterTimelineByUserId(id)
    );
}