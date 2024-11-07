//
// Created by koath on 11/7/2024.
//

#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <bsoncxx/json.hpp>
#include <bsoncxx/builder/stream/document.hpp>

mongocxx::client getMongodbConnection(){
    try {
        // Create an instance.
        mongocxx::instance inst{};
        const auto uri = mongocxx::uri{
                "mongodb+srv://koathbaht:5h5GdgcDT6bPgvNI\@gocluster1.uttkkqw.mongodb.net/?retryWrites=true&w=majority&appName=GoCluster1"};
        // Set the version of the Stable API on the client
        mongocxx::options::client client_options;
        const auto api = mongocxx::options::server_api{mongocxx::options::server_api::version::k_version_1};
        client_options.server_api_opts(api);
        // Setup the connection and get a handle on the "admin" database.
        mongocxx::client conn{uri, client_options};
    } catch (const std::exception& e)
    {
        // Handle errors
    }
}