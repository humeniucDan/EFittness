//
// Created by koath on 11/7/2024.
//

#include "../../models/UserAuth/UserAuth.h"
#include "../connectionlogic/connectionlogic.h"



UserAuth getUserAuthByEmail(std::string email){
    mongocxx::client conn = getMongodbConnection();

    mongocxx::database db = conn["eFitness"];

    mongocxx::collection col = db["userauth"];
    bsoncxx::builder::stream::document filter_builder;
    filter_builder << "email" << email;
    bsoncxx::document::value filter = filter_builder << bsoncxx::builder::stream::finalize;

    // Execute the find query with the filter
    auto cursor = col.find(filter.view());

    std::cout << '[';
    for(auto&& doc: cursor) std::cout << "\n" << bsoncxx::to_json(doc) << ",";
    std::cout << "\b\n]\n";

    return {};
}
