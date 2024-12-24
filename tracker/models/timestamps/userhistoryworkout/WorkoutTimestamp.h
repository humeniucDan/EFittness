//
// Created by koath on 12/17/2024.
//

#ifndef TRACKER_WORKOUTTIMESTAMP_H
#define TRACKER_WORKOUTTIMESTAMP_H

#include <string>
#include "../abstracttimestamp/AbstractTimestamp.h"
#include "../../static/exercise/Exercise.h"

class WorkoutTimestamp : public AbstractTimestamp {
private:
    int exerciseId;
    int reps;
    int weight;
    Exercise exercise;

    constexpr static std::string_view tableName = "workout_timeline";
public:

    int getExerciseId() const;
    void setExerciseId(int exerciseId);

    int getReps() const;
    void setReps(int reps);

    int getWeight() const;
    void setWeight(int weight);

    const std::string &getExerciseName() const;

    const Exercise &getExercise() const;

    void setExercise(const Exercise &exercise);

    WorkoutTimestamp(const pqxx::row& row);
    WorkoutTimestamp(int id, int userId, const std::string &description, const std::string& datetime, int exerciseId, int reps, int weight);
    WorkoutTimestamp();

    std::string toJson();

    static std::string_view getTablename();
};

#endif //TRACKER_WORKOUTTIMESTAMP_H