//
// Created by koath on 12/22/2024.
//

#include <iostream>
#include "exerciserepo.h"

//Exercise getCascadedExerciseById(int id) {
//    try {
//        // Establish a connection to the database
//        pqxx::connection conn(
//                "dbname=" + DB_NAME +
//                " user=" + USER +
//                " password=" + PASSWORD +
//                " host=" + HOST +
//                " port=" + PORT
//        );
//        /// TODO: IF CONNECTION FAILS, RETURN SOMETHING
////        if (!conn.is_open()) {
////            std::cerr << "Failed to connect to database." << std::endl;
////            // maybe return an empty vector
////            return ;
////        }
//        pqxx::work txn(conn);
//
//        pqxx::result res = txn.exec("SELECT * FROM efitness." + std::string(T::getTablename()) + " WHERE userId = " + txn.quote(userId) + "order by datetime asc;");
//
//        try {
//            // Establish a connection to the database
//            pqxx::connection conn(
//                    "dbname=" + DB_NAME +
//                    " user=" + USER +
//                    " password=" + PASSWORD +
//                    " host=" + HOST +
//                    " port=" + PORT
//            );
//            if (!conn.is_open()) {
//                std::cerr << "Failed to connect to database." << std::endl;
//                // maybe return an empty vector
//                return {};
//            }
//            pqxx::work txn(conn);
//
//            pqxx::result res = txn.exec("SELECT * FROM efitness. WHERE userId = " + txn.quote(userId) + "order by datetime asc;");
//
//            std::vector<T> Timeline(res.size());
//            for (int i = 0; i < res.size(); i++) {
//                Timeline[i] = T(res[i]);
//            }
//
//            return Timeline;
//
//        } catch (const std::exception &e) {
//            std::cerr << "Error: " << e.what() << std::endl;
//            /// todo: return something
////            return {};
//        }}
//
//        return Timeline;
//
//    } catch (const std::exception &e) {
//        std::cerr << "Error: " << e.what() << std::endl;
//        return {};
//    }
//}
