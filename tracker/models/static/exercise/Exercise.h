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
    std::string type;
    Muscle* primaryMuscle;
    std::string steps;
    std::vector<Muscle> secondaryMuscles;
    std::vector<Equipment> neededEquipment;
public:
    int getId() const;

    void setId(int id);

    const std::string &getName() const;

    void setName(const std::string &name);

    const std::string &getPrimer() const;

    void setPrimer(const std::string &primer);

    const std::vector<Muscle> &getSecondaryMuscles() const;

    void setSecondaryMuscles(const std::vector<Muscle> &workedMuscles);

    const std::vector<Equipment> &getNeededEquipment() const;

    void setNeededEquipment(const std::vector<Equipment> &neededEquipment);

    const std::string &getType() const;

    void setType(const std::string &type);

    const Muscle* &getPrimaryMuscle() const;

    void setPrimaryMuscle(const Muscle* &primaryMuscle);

    const std::string &getSteps() const;

    void setSteps(const std::string &steps);

    void setPrimaryMuscle1(Muscle *primaryMuscle);

    Exercise(int id, const std::string &name, const std::string &primer, const std::string &type, Muscle *primaryMuscle,
             const std::string &steps, const std::vector<Muscle> &secondaryMuscles,
             const std::vector<Equipment> &neededEquipment);

    Exercise();
};


#endif //TRACKER_EXERCISE_H
