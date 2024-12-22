//
// Created by koath on 12/22/2024.
//

#ifndef TRACKER_MUSCLE_H
#define TRACKER_MUSCLE_H

#include <string>
#include <vector>
#include "../exercise/Exercise.h"

class Exercise;

class Muscle {
private:
    int id;
    std::string name;
    std::vector<Exercise> workedBy;
public:
    int getId() const;

    void setId(int id);

    const std::string &getName() const;

    void setName(const std::string &name);

    const std::vector<Exercise> &getWorkedBy() const;

    void setWorkedBy(const std::vector<Exercise> &workedBy);

    Muscle(int id, const std::string &name, const std::vector<Exercise> &workedBy);

    Muscle();
};


#endif //TRACKER_MUSCLE_H
