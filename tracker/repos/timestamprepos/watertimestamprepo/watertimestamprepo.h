//
// Created by koath on 12/19/2024.
//

#ifndef TRACKER_WATERTIMESTAMPREPO_H
#define TRACKER_WATERTIMESTAMPREPO_H

#include <pqxx/pqxx>
#include "../../../models/timestamps/userhistorywater/WaterTimestamp.h"

WaterTimestamp parseWaterTimestampRow(const pqxx::row&);

#endif //TRACKER_WATERTIMESTAMPREPO_H
