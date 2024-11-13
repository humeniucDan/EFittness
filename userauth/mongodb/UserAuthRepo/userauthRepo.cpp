//
// Created by koath on 11/7/2024.
//

#include "../../models/UserAuth/UserAuth.h"
#include "../connectionlogic/connectionlogic.h"

int getNextUserAuthId(){
    auto* comps = const_cast<MongodbComponents *>(getMongodbComponents());

    // Build the sort document to sort by `_id` in descending order.
    auto sort_order = static_cast<bsoncxx::view_or_value<bsoncxx::document::view, bsoncxx::document::value>>(
            bsoncxx::builder::stream::document{} << "_id" << -1 << bsoncxx::builder::stream::finalize
    );

    // Use find_one with the sort option to get the document with the highest `_id`.
    auto result = comps->col.find_one({}, mongocxx::options::find{}.sort(sort_order));

    // Check if a result was found and display it.
    if (result) {
        std::cout << "User with highest _id: " << bsoncxx::to_json(result->view()) << std::endl;
    } else {
        std::cout << "No documents found in the collection." << std::endl;
    }

    return 1;
}

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
