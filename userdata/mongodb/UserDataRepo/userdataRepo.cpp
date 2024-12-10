//
// Created by koath on 11/26/2024.
//

#include "userdataRepo.h"

void insertUserDataIntoDB(std::string userDataJson){
    auto* comps = const_cast<MongodbComponents *>(getMongodbComponents());

    bsoncxx::builder::stream::document document_builder;
    auto bson = bsoncxx::from_json(userDataJson);

    // Insert the BSON document into the MongoDB collection.
    try {
        comps->col.insert_one(bson.view());
        std::cout << "User inserted successfully!" << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Error inserting user: " << e.what() << std::endl;
    }
}

void insertUserDataIntoDB(UserData userData){
    insertUserDataIntoDB(userData.toJson());
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
