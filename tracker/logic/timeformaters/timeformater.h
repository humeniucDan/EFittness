//
// Created by koath on 1/15/2025.
//

#ifndef TRACKER_TIMEFORMATER_H
#define TRACKER_TIMEFORMATER_H

#include "string"
#include <sstream>
#include <iomanip>
#include <chrono>

std::string formatTime(const std::chrono::system_clock::time_point &time);

#endif //TRACKER_TIMEFORMATER_H
