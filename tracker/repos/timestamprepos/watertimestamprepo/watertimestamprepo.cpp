//
// Created by koath on 12/19/2024.
//

#include "watertimestamprepo.h"

WaterTimestamp parseWaterTimestampRow(const pqxx::row& row) {
    WaterTimestamp waterTimestamp(
            row["id"].as<int>(),
            row["userId"].as<int>(),
            row["description"].as<std::string>(),
            row["quantity"].as<int>(),
            row["caffeine"].as<int>(),
            row["sugar"].as<int>()
    );

    return waterTimestamp;
}