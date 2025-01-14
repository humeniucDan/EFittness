//
// Created by koath on 12/20/2024.
//

#ifndef TRACKER_ABSTRACTTIMELINEREPO_H
#define TRACKER_ABSTRACTTIMELINEREPO_H

#include <vector>
#include "pqxx/pqxx"
#include <iostream>
#include "../../pqcred/pqcred.h"
#include "../../../models/timestamps/abstracttimestamp/AbstractTimestamp.h"

template <typename T>
std::vector<T> extractTimelineByUserId(int userId) {
    // maybe only fetch a limited amount of time like 30 days

    /// TODO: FIX THE PQCRED CREATE_CONN FUNC

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
            return {};
        }
        pqxx::work txn(conn);

        pqxx::result res = txn.exec("SELECT * FROM efitness." + std::string(T::getTablename()) + " WHERE userId = " + txn.quote(userId) + "order by datetime asc;");

        std::vector<T> Timeline(res.size());
        for (int i = 0; i < res.size(); i++) {
            Timeline[i] = T(res[i]);
        }

        return Timeline;

    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return {};
    }
}

template <typename T>
std::vector<T> extractTimelineByUserId(pqxx::connection &conn, int userId) {
    // maybe only fetch a limited amount of time like 30 days

    /// TODO: FIX THE PQCRED CREATE_CONN FUNC

    try {
        pqxx::work txn(conn);

        pqxx::result res = txn.exec("SELECT * FROM efitness." + std::string(T::getTablename()) + " WHERE userId = " + txn.quote(userId) + "order by datetime asc;");

        std::vector<T> Timeline(res.size());
        for (int i = 0; i < res.size(); i++) {
            Timeline[i] = T(res[i]);
        }

        return Timeline;

    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return {};
    }
}

void insertAbstractTimestamp(int userId, AbstractTimestamp& abstractTimestamp);

#endif //TRACKER_ABSTRACTTIMELINEREPO_H
