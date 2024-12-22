//
// Created by koath on 12/22/2024.
//

#ifndef TRACKER_EXERCISE_H
#define TRACKER_EXERCISE_H


#include <string>
#include <vector>
#include "../muscle/Muscle.h"
#include "../equipment/Equipment.h"

class Muscle;
class Equipment;

class Exercise {
private:
    int id;
    std::string name;
    std::string primer;
    std::vector<Muscle> workedMuscles;
    std::vector<Equipment> neededEquipment;
public:
    int getId() const;

    void setId(int id);

    const std::string &getName() const;

    void setName(const std::string &name);

    const std::string &getPrimer() const;

    void setPrimer(const std::string &primer);

    const std::vector<Muscle> &getWorkedMuscles() const;

    void setWorkedMuscles(const std::vector<Muscle> &workedMuscles);

    const std::vector<Equipment> &getNeededEquipment() const;

    void setNeededEquipment(const std::vector<Equipment> &neededEquipment);

    Exercise(int id, const std::string &name, const std::string &primer, const std::vector<Muscle> &workedMuscles,
             const std::vector<Equipment> &neededEquipment);
};


#endif //TRACKER_EXERCISE_H
