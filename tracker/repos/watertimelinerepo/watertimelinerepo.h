//
// Created by koath on 12/17/2024.
//

#ifndef TRACKER_WATERTIMELINEREPO_H
#define TRACKER_WATERTIMELINEREPO_H


#include <vector>
#include "../../models/timestamps/userhistorywater/WaterTimestamp.h"
#include <pqxx/pqxx>

//#define

std::vector<WaterTimestamp> extractWaterTimelineByUserId(int);
// insert also needed

#endif //TRACKER_WATERTIMELINEREPO_H
