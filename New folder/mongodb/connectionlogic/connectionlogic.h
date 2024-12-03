//
// Created by koath on 11/7/2024.
//

#ifndef USERAUTH_CONNECTIONLOGIC_H
#define USERAUTH_CONNECTIONLOGIC_H

#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <bsoncxx/json.hpp>
#include <bsoncxx/builder/stream/document.hpp>

#include "dbvariables.h"

mongocxx::client getMongodbConnection(const std::string&);

struct MongodbComponents {
    mongocxx::client client;
    mongocxx::database db;
    mongocxx::collection col;

    // Constructor for easy initialization
    MongodbComponents(const std::string& uri_string, const std::string& db_name, const std::string& collection_name){
        client = getMongodbConnection(uri_string);
        db = client[db_name];
        col = db[collection_name];
    }
};

const MongodbComponents* getMongodbComponents();

#endif //USERAUTH_CONNECTIONLOGIC_H
