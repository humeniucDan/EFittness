//
// Created by koath on 12/21/2024.
//
/// TODO REFACTOR WITH CTEST
#include <iostream>
#include "../logic/timecheckers/timecheckers.h"
using namespace std;
int main() {
    auto now = std::chrono::system_clock::now();
    auto a_week_ago = now - std::chrono::hours(24 * 5);
    cout << isSameWeek(std::chrono::system_clock::now(), std::chrono::system_clock::now()) << endl;
    cout << isSameWeek(std::chrono::system_clock::now(), a_week_ago) << endl;
    return 0;
}