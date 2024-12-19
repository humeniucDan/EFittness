//
// Created by koath on 12/17/2024.
//

#ifndef TRACKER_WORKOUTTIMESTAMP_H
#define TRACKER_WORKOUTTIMESTAMP_H


#include <string>
#include "../abstracttimestamp/AbstractTimestamp.h"

class WorkoutTimestamp : public AbstractTimestamp{
private:
    int exerciseId;
    int reps;
    int weight;
public:
    int getExerciseId() const;

    void setExerciseId(int exerciseId);

    int getReps() const;

    void setReps(int reps);

    int getWeight() const;

    void setWeight(int weight);
};


#endif //TRACKER_WORKOUTTIMESTAMP_H
