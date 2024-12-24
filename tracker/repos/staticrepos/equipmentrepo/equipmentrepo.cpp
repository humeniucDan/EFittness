////
//// Created by koath on 12/24/2024.
////
//
#include "equipmentrepo.h"
#include "../../pqcred/pqcred.h"

Equipment extractEquipmentById(pqxx::connection &conn, int id) {
    try {
        pqxx::work txn(conn);

        pqxx::result res = txn.exec(
                "SELECT * FROM efitness.equipment WHERE id = " + txn.quote(id) + ";"
        );
        txn.commit();

        if (res.size() == 0) {
            return {};
        }
        if (res.size() > 1) {
            std::cerr << "More than one equipment with the same id." << std::endl;
            return {};
        }

        return Equipment(res[0]["id"].as<int>(), res[0]["name"].as<std::string>(), {});

    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return {};
    }
}

Equipment extractCascadedEquipmentById(int id) {
    /// TODO: FIX THE PQCRED CREATE_CONN FUNC

    try {
        pqxx::connection conn(
                "dbname=" + DB_NAME +
                " user=" + USER +
                " password=" + PASSWORD +
                " host=" + HOST +
                " port=" + PORT
        );
        if (!conn.is_open()) {
            std::cerr << "Failed to connect to database." << std::endl;
            return {};
        }

        Equipment equipment = extractEquipmentById(conn, id);

        pqxx::work txn(conn);

        pqxx::result res = txn.exec(
                "SELECT e.*\n"
                "FROM efitness.utilizes u\n"
                "join efitness.exercises e on u.exercise = e.id\n"
                "where u.equipment = " + txn.quote(id) + "\n"
                ";"
        );

        std::vector<Exercise> exercises(res.size());
        for (int i = 0; i < res.size(); i++) {
            exercises[i] = Exercise(res[i]);
        }
        equipment.setUsedIn(exercises);

        return equipment;

    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return {};
    }

    return {};
}
