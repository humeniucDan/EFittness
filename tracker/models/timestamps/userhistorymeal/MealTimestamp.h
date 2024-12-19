//
// Created by koath on 12/17/2024.
//

#ifndef TRACKER_MEALTIMESTAMP_H
#define TRACKER_MEALTIMESTAMP_H


#include <string>

class MealTimestamp {
private:
    int carbs;
    int fats;
    int protein;
public:
    int getCarbs() const;

    void setCarbs(int carbs);

    int getFats() const;

    void setFats(int fats);

    int getProtein() const;

    void setProtein(int protein);
};


#endif //TRACKER_MEALTIMESTAMP_H
