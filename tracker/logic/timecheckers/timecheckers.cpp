//
// Created by koath on 12/21/2024.
//

#include "timecheckers.h"

bool isSameDay(const std::chrono::system_clock::time_point& t1, const std::chrono::system_clock::time_point& t2) {
    std::time_t time1 = std::chrono::system_clock::to_time_t(t1);
    std::time_t time2 = std::chrono::system_clock::to_time_t(t2);

    std::tm tm1 = *std::localtime(&time1);
    std::tm tm2 = *std::localtime(&time2);

    return tm1.tm_year == tm2.tm_year && tm1.tm_yday == tm2.tm_yday;
}

bool isSameWeek(const std::chrono::system_clock::time_point& t1, const std::chrono::system_clock::time_point& t2) {
    std::time_t time1 = std::chrono::system_clock::to_time_t(t1);
    std::time_t time2 = std::chrono::system_clock::to_time_t(t2);

    std::tm tm1 = *std::localtime(&time1);
    std::tm tm2 = *std::localtime(&time2);

    return tm1.tm_year == tm2.tm_year && tm1.tm_yday / 7 == tm2.tm_yday / 7;
}

bool isSameMonth(const std::chrono::system_clock::time_point& t1, const std::chrono::system_clock::time_point& t2) {
    std::time_t time1 = std::chrono::system_clock::to_time_t(t1);
    std::time_t time2 = std::chrono::system_clock::to_time_t(t2);

    std::tm tm1 = *std::localtime(&time1);
    std::tm tm2 = *std::localtime(&time2);

    return tm1.tm_year == tm2.tm_year && tm1.tm_mon == tm2.tm_mon;
}