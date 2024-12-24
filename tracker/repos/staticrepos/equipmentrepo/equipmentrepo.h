//
// Created by koath on 12/24/2024.
//

#ifndef TRACKER_EQUIPMENTREPO_H
#define TRACKER_EQUIPMENTREPO_H

#include "../../../models/static/Equipment/Equipment.h"

Equipment extractEquipmentById(int id);
Equipment extractEquipmentById(pqxx::connection&, int id);

Equipment extractCascadedEquipmentById(int id);

#endif //TRACKER_EQUIPMENTREPO_H
