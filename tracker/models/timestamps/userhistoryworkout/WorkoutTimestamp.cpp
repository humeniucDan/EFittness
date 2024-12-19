//
// Created by koath on 12/17/2024.
//

#include "WorkoutTimestamp.h"

int WorkoutTimestamp::getExerciseId() const {
    return exerciseId;
}

void WorkoutTimestamp::setExerciseId(int exerciseId) {
    WorkoutTimestamp::exerciseId = exerciseId;
}

int WorkoutTimestamp::getReps() const {
    return reps;
}

void WorkoutTimestamp::setReps(int reps) {
    WorkoutTimestamp::reps = reps;
}

int WorkoutTimestamp::getWeight() const {
    return weight;
}

void WorkoutTimestamp::setWeight(int weight) {
    WorkoutTimestamp::weight = weight;
}
