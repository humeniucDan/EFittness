//
// Created by koath on 12/24/2024.
//

#include "musclesrepo.h"
#include "../../pqcred/pqcred.h"

Muscle extractMuscleById(pqxx::connection &conn, int id) {
    try {
        pqxx::work txn(conn);

        pqxx::result res = txn.exec(
                "SELECT * FROM efitness.muscles WHERE id = " + txn.quote(id) + ";"
        );
        txn.commit();

        if (res.size() == 0) {
            return {};
        }
        if (res.size() > 1) {
            std::cerr << "More than one muscle with the same id." << std::endl;
            return {};
        }

        return Muscle(res[0]["id"].as<int>(), res[0]["name"].as<std::string>(), {});

    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return {};
    }
}

Muscle extractCascadedMuscleById(int id) {
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

        Muscle muscle = extractMuscleById(conn, id);

        pqxx::work txn(conn);

        pqxx::result res = txn.exec(
                "SELECT distinct e.*\n"
                "FROM efitness.muscles m \n"
                "join efitness.secondary s on s.muscle = m.id\n"
                "join efitness.exercises e on (e.primary_muscle = m.id or e.id = s.exercise) \n"
                "where m.id = " + txn.quote(id) + ";"
        );


        std::vector<Exercise> exercises(res.size());
        for (int i = 0; i < res.size(); i++) {
            exercises[i] = Exercise(res[i]);
        }
        muscle.setWorkedBy(exercises);

        return muscle;

    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return {};
    }

    return {};
}