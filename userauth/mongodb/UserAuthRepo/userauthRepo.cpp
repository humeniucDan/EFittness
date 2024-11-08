//
// Created by koath on 11/7/2024.
//

#include "../../models/UserAuth/UserAuth.h"
#include "../connectionlogic/connectionlogic.h"

UserAuth getUserAuthByEmail(const std::string& email){

    auto* comps = const_cast<MongodbComponents *>(getMongodbComponents());

    bsoncxx::builder::stream::document filter_builder;
    filter_builder << "email" << email;
    bsoncxx::document::value filter = filter_builder << bsoncxx::builder::stream::finalize;

    // Execute the find query with the filter
    auto cursor = comps->col.find(filter.view());

    std::string json;
    std::cout << '[';
    for(auto&& doc: cursor) {
        json = bsoncxx::to_json(doc);
        std::cout << "\n" << json << ",";
    }
    std::cout << "\b\n]\n";

    delete comps;

    UserAuth usr(json);

    return usr;
}
