#ifndef TRACKER_EQUIPMENT_H
#define TRACKER_EQUIPMENT_H

#include <string>
#include <vector>
#include "../exercise/Exercise.h"
#include <picojson/picojson.h>

class Exercise;

class Equipment {
private:
    int id;
    std::string name;
    std::vector<Exercise> usedIn;

public:
    int getId() const;

    void setId(int id);

    const std::string &getName() const;

    void setName(const std::string &name);

    const std::vector<Exercise> &getUsedIn() const;

    void setUsedIn(const std::vector<Exercise> &usedIn);

    Equipment(int id, const std::string &name, const std::vector<Exercise> &usedIn);

    Equipment();

    std::string toJson();
    void addToJson(picojson::object& j);
};


#endif //TRACKER_EQUIPMENT_H
