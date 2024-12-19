//
// Created by koath on 12/13/2024.
//

#include "CardioTimestamp.h"

int CardioTimestamp::getExerciseId() const {
    return exerciseId;
}

void CardioTimestamp::setExerciseId(int exerciseId) {
    CardioTimestamp::exerciseId = exerciseId;
}

int CardioTimestamp::getIntensity() const {
    return intensity;
}

void CardioTimestamp::setIntensity(int intensity) {
    CardioTimestamp::intensity = intensity;
}

int CardioTimestamp::getDistance() const {
    return distance;
}

void CardioTimestamp::setDistance(int distance) {
    CardioTimestamp::distance = distance;
}
