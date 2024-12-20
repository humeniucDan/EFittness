#include "MealTimestamp.h"
#include <picojson/picojson.h>

const std::string MealTimestamp::tableName = "meal_timeline";

int MealTimestamp::getCarbs() const {
    return carbs;
}

void MealTimestamp::setCarbs(int carbs) {
    MealTimestamp::carbs = carbs;
}

int MealTimestamp::getFats() const {
    return fats;
}

void MealTimestamp::setFats(int fats) {
    MealTimestamp::fats = fats;
}

int MealTimestamp::getProtein() const {
    return protein;
}

void MealTimestamp::setProtein(int protein) {
    MealTimestamp::protein = protein;
}

int MealTimestamp::getWeight() const {
    return weight;
}

void MealTimestamp::setWeight(int weight) {
    MealTimestamp::weight = weight;
}

int MealTimestamp::getCalories() const {
    return calories;
}

void MealTimestamp::setCalories(int calories) {
    MealTimestamp::calories = calories;
}

std::string_view MealTimestamp::getTablename() {
    return MealTimestamp::tableName;
}

MealTimestamp::MealTimestamp(const pqxx::row& row)
        : AbstractTimestamp(row), carbs(row["carbs"].as<int>()), fats(row["fats"].as<int>()), protein(row["protein"].as<int>()), weight(row["weight"].as<int>()), calories(row["calories"].as<int>()) {}

MealTimestamp::MealTimestamp(int id, int userId, const std::string &description, const std::string& datetime, int carbs, int fats, int protein, int weight, int calories)
        : AbstractTimestamp(id, userId, description , datetime), carbs(carbs), fats(fats), protein(protein), weight(weight), calories(calories) {}

MealTimestamp::MealTimestamp() {}

picojson::value MealTimestamp::toJsonValue() {
    picojson::object jsonObject;
    this->addToJson(jsonObject);
    jsonObject["carbs"] = picojson::value(static_cast<double>(carbs));
    jsonObject["fats"] = picojson::value(static_cast<double>(fats));
    jsonObject["protein"] = picojson::value(static_cast<double>(protein));
    jsonObject["weight"] = picojson::value(static_cast<double>(weight));
    jsonObject["calories"] = picojson::value(static_cast<double>(calories));
    return picojson::value(jsonObject);
}

std::string MealTimestamp::toJson()  {
    return toJsonValue().serialize();
}