//
// Created by koath on 12/17/2024.
//

#include <iostream>
#include "watertimelinerepo.h"
#include "../pqcred.h"
#include "../timestamprepos/watertimestamprepo/watertimestamprepo.h"

std::vector<WaterTimestamp> extractWaterTimelineByUserId(int userId) {
    //maybe here preallocate some memory and only fetch a limited amount of time like 30 days

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

        // Query the table
        pqxx::result res = txn.exec("SELECT * FROM waterTimeline WHERE user_id = " + txn.quote(userId));

        std::vector<WaterTimestamp> waterTimeline(res.size());
        // Process and display results
        for (int i = 0; i < res.size(); i++) {
            waterTimeline[i] = parseWaterTimestampRow(res[i]);
        }

        return waterTimeline;

    } catch (const std::exception &e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return {};
    }
}
