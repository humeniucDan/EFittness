//
// Created by koath on 12/17/2024.
//

#ifndef TRACKER_WORKOUTTIMESTAMP_H
#define TRACKER_WORKOUTTIMESTAMP_H

#include <string>
#include "../abstracttimestamp/AbstractTimestamp.h"

class WorkoutTimestamp : public AbstractTimestamp {
private:
    int exerciseId;
    int reps;
    int weight;
    /// TODO: add exercise here
public:
    static const std::string tableName;

    int getExerciseId() const;
    void setExerciseId(int exerciseId);

    int getReps() const;
    void setReps(int reps);

    int getWeight() const;
    void setWeight(int weight);

    static std::string_view getTablename();

    WorkoutTimestamp(const pqxx::row& row);
    WorkoutTimestamp(int id, int userId, const std::string &description, const std::string& datetime, int exerciseId, int reps, int weight);
    WorkoutTimestamp();

    std::string toJson();
};

#endif //TRACKER_WORKOUTTIMESTAMP_H