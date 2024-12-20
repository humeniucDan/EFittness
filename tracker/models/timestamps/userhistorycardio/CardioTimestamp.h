//
// Created by koath on 12/13/2024.
//

#ifndef TRACKER_CARDIOTIMESTAMP_H
#define TRACKER_CARDIOTIMESTAMP_H

#include <string>
#include "../abstracttimestamp/AbstractTimestamp.h"
#include <pqxx/pqxx>

class CardioTimestamp: public AbstractTimestamp{
private:
    int exerciseId;
//    std::string time; // Using string for interval representation
    int intensity;
    int distance;

    constexpr static std::string_view tableName = "cardio_timeline";

public:
    int getExerciseId() const;

    void setExerciseId(int exerciseId);

    int getIntensity() const;

    void setIntensity(int intensity);

    int getDistance() const;

    void setDistance(int distance);

    std::string toJson();

    CardioTimestamp(const pqxx::row& row);

    CardioTimestamp(int id, int userId, const std::string &description, const std::string& datetime, int exerciseId, int intensity, int distance);

    CardioTimestamp();

    static std::string_view getTablename();
};


#endif //TRACKER_CARDIOTIMESTAMP_H
