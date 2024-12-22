//
// Created by koath on 12/22/2024.
//

#ifndef TRACKER_EXERCISEREPO_H
#define TRACKER_EXERCISEREPO_H

#include "../../../models/static/exercise/Exercise.h"

#include "../../pqcred/pqcred.h"

Exercise getExerciseById(int id);

Exercise getCascadedExerciseById(int id);

#endif //TRACKER_EXERCISEREPO_H
