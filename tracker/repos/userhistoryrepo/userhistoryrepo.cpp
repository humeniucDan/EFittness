//
// Created by koath on 12/17/2024.
//

#include "userhistoryrepo.h"
#include "../timelinerepos/watertimelinerepo/watertimelinerepo.h"

UserHistory* extractUserHistoryByUserId(int id){
    return new UserHistory(
            {}, //extractWorkoutTimelineByUserId(id),
            {}, //extractMealsTimelineByUserId(id),
            {},  //extractCardioTimelineByUserId(id)
            extractWaterTimelineByUserId(id)
    );
}
