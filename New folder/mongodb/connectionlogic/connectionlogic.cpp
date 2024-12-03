//
// Created by koath on 11/7/2024.
//

#include "connectionlogic.h"

mongocxx::client getMongodbConnection(const std::string& dbUrl){
//     TODO: refactor connection uri in a env variables file
    try {
//         TODO: create a MongoInstance singleton instead of a global variable
        const auto uri = mongocxx::uri{dbUrl};

        mongocxx::options::client client_options;
        const auto api = mongocxx::options::server_api{mongocxx::options::server_api::version::k_version_1};
        client_options.server_api_opts(api);

        mongocxx::client conn{uri, client_options};

        return conn;
    } catch (const std::exception& e)
    {
//         TODO: Handle errors
        std::cout << e.what() << "\n";
    }

//    return conn
}

const MongodbComponents* getMongodbComponents(){
    return new MongodbComponents(CONN_URL, DB_NAME, COLLECTION_NAME);
}