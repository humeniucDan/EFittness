//
// Created by koath on 12/21/2024.
//

#include "timelinefolds.h"

//template <typename T>
//std::vector<T> foldTimelineWith(bool (*isSame)(const std::chrono::system_clock::time_point& t1, const std::chrono::system_clock::time_point& t2),
//                                std::vector<T> timeline) {
//    /// TODO: maybe inity with size or (size/2)
//    std::vector<T> foldedTimeline;
//
//    if (timeline.empty()) return foldedTimeline;
//
//    T currentFold = timeline[0];
//    for (int i = 1; i < timeline.size(); i++) {
//        if (isSame(currentFold.getDatetime(), timeline[i].getDatetime())) {
//            currentFold = currentFold + timeline[i];
//        } else {
//            foldedTimeline.push_back(currentFold);
//            currentFold = timeline[i];
//        }
//    }
//    foldedTimeline.push_back(currentFold);
//
//    return foldedTimeline;
//}
