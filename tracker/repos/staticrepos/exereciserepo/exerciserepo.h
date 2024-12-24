//
// Created by koath on 12/22/2024.
//

#ifndef TRACKER_EXERCISEREPO_H
#define TRACKER_EXERCISEREPO_H

#include "../../../models/static/exercise/Exercise.h"
#include "../../../models/static/muscle/Muscle.h"
#include "../../pqcred/pqcred.h"

Exercise extractExerciseById(int id);
Exercise extractExerciseById(pqxx::connection&, int id);

std::string extractExerciseNameById(int id);

[[maybe_unused]] std::string extractExerciseNameById(pqxx::connection conn, int id);

Exercise extractCascadedExerciseById(int id);

#endif //TRACKER_EXERCISEREPO_H
