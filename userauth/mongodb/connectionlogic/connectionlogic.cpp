//
// Created by koath on 11/7/2024.
//

#include "connectionlogic.h"

mongocxx::client getMongodbConnection(){
    // TODO: refactor connection uri in a env variables file

    try {
        // TODO: create a MongoInstance singleton instead of a global variable
        const auto uri = mongocxx::uri{ "mongodb+srv://koathbaht:changeme@cluster0.acsi7.mongodb.net/?retryWrites=true&w=majority&appName=Cluster0"};

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
}