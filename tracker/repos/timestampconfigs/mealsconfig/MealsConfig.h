//
// Created by koath on 12/17/2024.
//

#ifndef TRACKER_MEALSCONFIG_H
#define TRACKER_MEALSCONFIG_H


#include "../abstractrepoconfig/AbstractRepoConfig.h"

#define TABLE_NAME "meals"

class MealsConfig: AbstractRepoConfig {
public:
    std::string getTableName();
};



#endif //TRACKER_MEALSCONFIG_H
