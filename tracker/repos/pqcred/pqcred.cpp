//
// Created by koath on 12/19/2024.
//

#include "pqcred.h"

pqxx::connection* createPGConn(){
    auto conn = new pqxx::connection(
            "dbname=" + DB_NAME +
            " user=" + USER +
            " password=" + PASSWORD +
            " host=" + HOST +
            " port=" + PORT
    );

    return conn;
}
