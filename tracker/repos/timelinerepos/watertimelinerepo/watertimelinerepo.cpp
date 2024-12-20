//
// Created by koath on 12/17/2024.
//
#include "watertimelinerepo.h"

std::vector<WaterTimestamp> extractWaterTimelineByUserId(int userId) {
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

        pqxx::result res = txn.exec("SELECT * FROM efitness.water_timeline WHERE userId = " + txn.quote(userId));

        std::vector<WaterTimestamp> waterTimeline(res.size());
        for (int i = 0; i < res.size(); i++) {
            waterTimeline[i] = WaterTimestamp(res[i]);
        }

        return waterTimeline;

    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return {};
    }
}
