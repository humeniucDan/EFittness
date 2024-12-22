//
// Created by koath on 12/21/2024.
//

#ifndef TRACKER_TIMECHECKERS_H
#define TRACKER_TIMECHECKERS_H

#include <ctime>
#include <chrono>

bool isSameDay(const std::chrono::system_clock::time_point& t1, const std::chrono::system_clock::time_point& t2);

bool isSameWeek(const std::chrono::system_clock::time_point& t1, const std::chrono::system_clock::time_point& t2) ;

bool isSameMonth(const std::chrono::system_clock::time_point& t1, const std::chrono::system_clock::time_point& t2) ;

#endif //TRACKER_TIMECHECKERS_H
