//
// Created by koath on 11/26/2024.
//

#ifndef USERAUTH_USERDATAREPO_H
#define USERAUTH_USERDATAREPO_H

//#include "../../models/UserData/UserData.h"
//#include "../connectionlogic/connectionlogic.h"
//
//bool insertUserDataIntoDB(const UserData& userData){
//    auto* comps = const_cast<MongodbComponents *>(getMongodbComponents());
//
//    bsoncxx::builder::stream::document document_builder;
//    document_builder << "_id" <<
//                     << "email" << userAuth.getEmail()
//                     << "password" << userAuth.getPassword();
//
//    // Finalize the document
//    bsoncxx::document::value document = document_builder << bsoncxx::builder::stream::finalize;
//
//    // Insert the document into the collection
//    auto result = comps->col.insert_one(document.view());
//}

#endif //USERAUTH_USERDATAREPO_H
