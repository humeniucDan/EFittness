//
// Created by koath on 12/20/2024.
//

#include "abstracttimelinerepo.h"

//template <typename T>
//std::vector<T> extractTimelineByUserId(int userId) {
//    // maybe only fetch a limited amount of time like 30 days
//
//    /// TODO: FIX THE PQCRED CREATE_CONN FUNC
//
//    try {
//        // Establish a connection to the database
//        pqxx::connection conn(
//                "dbname=" + DB_NAME +
//                " user=" + USER +
//                " password=" + PASSWORD +
//                " host=" + HOST +
//                " port=" + PORT
//        );
//        if (!conn.is_open()) {
//            std::cerr << "Failed to connect to database." << std::endl;
//            // maybe return an empty vector
//            return {};
//        }
//        pqxx::work txn(conn);
//
//        pqxx::result res = txn.exec("SELECT * FROM efitness." + txn.quote(T::getTablename()) + " WHERE userId = " + txn.quote(userId));
//
//        std::vector<T> Timeline(res.size());
//        for (int i = 0; i < res.size(); i++) {
//            Timeline[i] = T(res[i]);
//        }
//
//        return Timeline;
//
//    } catch (const std::exception &e) {
//        std::cerr << "Error: " << e.what() << std::endl;
//        return {};
//    }
//}

void insertAbstractTimestamp(int userId, AbstractTimestamp &abstractTimestamp) {
    try {
        // Establish a connection to the database
        pqxx::connection conn(
                "dbname=" + DB_NAME +
                " user=" + USER +
                " password=" + PASSWORD +
                " host=" + HOST +
                " port=" + PORT
        );
        if (!conn.is_open()) {
            std::cerr << "Failed to connect to database." << std::endl;
            // maybe return an empty vector
        }
        pqxx::work txn(conn);

        pqxx::result res = txn.exec(abstractTimestamp.getSQLInsertQuery(userId));

        txn.commit();

    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
