#ifndef TRACKER_MEALTIMESTAMP_H
#define TRACKER_MEALTIMESTAMP_H

#include <string>
#include "../abstracttimestamp/AbstractTimestamp.h"
#include <pqxx/pqxx>

class MealTimestamp: public AbstractTimestamp {
private:
    int carbs;
    int fats;
    int protein;
    int weight;
    int calories;

    static const std::string tableName;

public:
    int getCarbs() const;
    void setCarbs(int carbs);

    int getFats() const;
    void setFats(int fats);

    int getProtein() const;
    void setProtein(int protein);

    int getWeight() const;
    void setWeight(int weight);

    int getCalories() const;
    void setCalories(int calories);

    std::string toJson();

    MealTimestamp(const pqxx::row& row);
    MealTimestamp(int id, int userId, const std::string &description, const std::string& datetime, int carbs, int fats, int protein, int weight, int calories);
    MealTimestamp();

    static std::string_view getTablename();

    picojson::value toJsonValue();
};

#endif //TRACKER_MEALTIMESTAMP_H