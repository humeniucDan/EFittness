//
// Created by koath on 11/7/2024.
//

#ifndef USERAUTH_CONNECTIONLOGIC_H
#define USERAUTH_CONNECTIONLOGIC_H

#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <bsoncxx/json.hpp>
#include <bsoncxx/builder/stream/document.hpp>

mongocxx::client getMongodbConnection();
mongocxx::client getMongodbCollection();

#endif //USERAUTH_CONNECTIONLOGIC_H
