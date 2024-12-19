//
// Created by koath on 12/13/2024.
//

#ifndef TRACKER_CARDIOTIMESTAMP_H
#define TRACKER_CARDIOTIMESTAMP_H

#include <string>

class CardioTimestamp {
private:
    int exerciseId;
//    std::string time; // Using string for interval representation
    int intensity;

public:
    int getExerciseId() const;

    void setExerciseId(int exerciseId);

    int getIntensity() const;

    void setIntensity(int intensity);

    int getDistance() const;

    void setDistance(int distance);

    int distance;
};


#endif //TRACKER_CARDIOTIMESTAMP_H
