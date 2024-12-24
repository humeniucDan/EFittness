#include "WorkoutTimestamp.h"
#include <picojson/picojson.h>


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

std::string_view WorkoutTimestamp::getTablename() {
    return tableName;
}

WorkoutTimestamp::WorkoutTimestamp(const pqxx::row& row)
        : AbstractTimestamp(row), exerciseId(row["exerciseId"].as<int>()), reps(row["reps"].as<int>()), weight(row["weight"].as<int>()) {}

WorkoutTimestamp::WorkoutTimestamp(int id, int userId, const std::string &description, const std::string& datetime, int exerciseId, int reps, int weight)
        : AbstractTimestamp(id, userId, description, datetime), exerciseId(exerciseId), reps(reps), weight(weight) {}

WorkoutTimestamp::WorkoutTimestamp() {}

std::string WorkoutTimestamp::toJson() {
    picojson::object jsonObject;
    this->addToJson(jsonObject);
    jsonObject["exerciseId"] = picojson::value(static_cast<double>(exerciseId));
    jsonObject["reps"] = picojson::value(static_cast<double>(reps));
    jsonObject["weight"] = picojson::value(static_cast<double>(weight));
    picojson::object exerciseJsonObj;
    exercise.addToJson(exerciseJsonObj);
    jsonObject["exercise"] = picojson::value(exerciseJsonObj);
    return picojson::value(jsonObject).serialize();
}

const Exercise &WorkoutTimestamp::getExercise() const {
    return exercise;
}

void WorkoutTimestamp::setExercise(const Exercise &exercise) {
    WorkoutTimestamp::exercise = exercise;
}
