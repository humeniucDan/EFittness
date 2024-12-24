//
// Created by koath on 12/22/2024.
//

#include <iostream>
#include "exerciserepo.h"


[[maybe_unused]] std::string getExerciseNameById(pqxx::connection conn, int id) {
    try {
        pqxx::work txn(conn);

        pqxx::result res = txn.exec(
                "SELECT * FROM efitness.exercises WHERE id = " + txn.quote(id) + ";");

        if( res.empty() ) return "";
        if( res.size() > 1 ) {
            std::cerr << "Error: Multiple exercises with the same id" << std::endl;
            return "";
        }

        return res[0]["name"].as<std::string>();
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return {};
    }
}

Exercise extractExerciseById(pqxx::connection& conn, int id) {
    try {
        pqxx::work txn(conn);

        pqxx::result res = txn.exec(
                "SELECT * FROM efitness.exercises WHERE id = " + txn.quote(id) + ";");

        if( res.empty() ) return {};
        if( res.size() > 1 ) {
            std::cerr << "Error: Multiple exercises with the same id" << std::endl;
            return {};
        }

        txn.commit();

        return Exercise(res[0]);
    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return {};
    }
}

Exercise extractCascadedExerciseById(int id) {
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

        Exercise exercise = extractExerciseById(conn, id);

        pqxx::work* txn;
        txn = new pqxx::work(conn);

        pqxx::result res = txn->exec(
                "SELECT m.* FROM efitness.secondary s join efitness.muscles m on s.muscle = m.id where s.exercise = " + txn->quote(id) + ";"
                        );
        txn->commit();
        delete txn;

        std::cout << res.size() << std::endl;
        std::vector<Muscle> muscles(res.size());
        for (int i = 0; i < res.size(); i++) {
//            muscles.push_back(Muscle(row));
            muscles[i] = Muscle(res[i]);
        }
        exercise.setSecondaryMuscles(muscles);

        txn = new pqxx::work(conn);

        res = txn->exec(
            "SELECT e.*\n"
            "FROM efitness.utilizes u\n"
            "join efitness.equipment e on u.equipment = e.id\n"
            "where u.exercise = " + txn->quote(id) + ";");

        std::cout << res.size() << std::endl;
        std::vector<Equipment> equipment(res.size());
        for (int i = 0; i < res.size(); i++) {
//            muscles.push_back(Muscle(row));
            equipment[i] = Equipment(res[i]["id"].as<int>(), res[i]["name"].as<std::string>(), {});
        }
        exercise.setNeededEquipment(equipment);

        return exercise;

    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return {};
    }

    return {};
}
