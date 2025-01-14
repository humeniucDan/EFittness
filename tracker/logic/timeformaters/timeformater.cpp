//
// Created by koath on 1/15/2025.
//

#include "timeformater.h"

std::string formatTime(const std::chrono::system_clock::time_point &time) {
    std::time_t time_t_format = std::chrono::system_clock::to_time_t(time);
    std::tm tm = *std::localtime(&time_t_format);
    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y/%m/%d %H:%M:%S");
    return oss.str();
}
