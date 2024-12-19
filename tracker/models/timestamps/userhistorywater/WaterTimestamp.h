//
// Created by koath on 12/17/2024.
//

#ifndef TRACKER_WATERTIMESTAMP_H
#define TRACKER_WATERTIMESTAMP_H

#include <string>
#include "../abstracttimestamp/AbstractTimestamp.h"

class WaterTimestamp:AbstractTimestamp{
private:
    int quantity{};
    int caffeine{};
    int sugar{};

public:
    WaterTimestamp();

    WaterTimestamp(int id, int userId, const std::string &description, int quantity, int caffeine, int sugar);

    int getQuantity() const;

    void setQuantity(int quantity);

    int getCaffeine() const;

    void setCaffeine(int caffeine);

    int getSugar() const;

    void setSugar(int sugar);
};


#endif //TRACKER_WATERTIMESTAMP_H
