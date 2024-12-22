//
// Created by koath on 12/19/2024.
//

#ifndef TRACKER_PQCRED_H
#define TRACKER_PQCRED_H

#include "pqxx/pqxx"

#define DB_NAME std::string("postgres")
#define USER "postgres"
#define PASSWORD "changeme"
#define HOST "localhost"
#define PORT "5432"

pqxx::connection* createPGConn();

#endif //TRACKER_PQCRED_H
