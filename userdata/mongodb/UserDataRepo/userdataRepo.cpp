//
// Created by koath on 11/26/2024.
//

#include "userdataRepo.h"

bool insertUserDataIntoDB(const UserData& userData){
    auto* comps = const_cast<MongodbComponents *>(getMongodbComponents());

    bsoncxx::builder::stream::document document_builder;
    document_builder << "_id";

    // Finalize the document
    bsoncxx::document::value document = document_builder << bsoncxx::builder::stream::finalize;

    // Insert the document into the collection
    auto result = comps->col.insert_one(document.view());

    return true;
}

std::string extractUserDataJsonByEmail(std::string email){
    auto* comps = const_cast<MongodbComponents *>(getMongodbComponents());

    auto filter = bsoncxx::builder::stream::document{} << "email" << email << bsoncxx::builder::stream::finalize;
    auto result = comps->col.find_one(filter.view());

    std::string retStr =  "";

    if (result) {
        retStr = bsoncxx::to_json(result->view());
    } else {
        std::cerr << "No user found with email: " << email << std::endl;
        //TODO: Throw error
    }

    return retStr;
}
