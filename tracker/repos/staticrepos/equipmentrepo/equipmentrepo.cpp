////
//// Created by koath on 12/24/2024.
////
//
//#include "equipmentrepo.h"
//#include "../../pqcred/pqcred.h"
//
//Equipment extractEquipmentById(pqxx::connection &, int id) {
//
//}
//
//Equipment extractCascadedEquipmentById(int id) {
//    /// TODO: FIX THE PQCRED CREATE_CONN FUNC
//
//    try {
//        pqxx::connection conn(
//                "dbname=" + DB_NAME +
//                " user=" + USER +
//                " password=" + PASSWORD +
//                " host=" + HOST +
//                " port=" + PORT
//        );
//        if (!conn.is_open()) {
//            std::cerr << "Failed to connect to database." << std::endl;
//            return {};
//        }
//
//        Equipment equipment = extractEquipmentById(conn, id);
//
//        pqxx::work txn(conn);
//
//        pqxx::result res = txn.exec(
//                "SELECT *\n"
//                "FROM efitness.utilizes u\n"
//                "join efitness.equipment e on u.equipment = e.id" + txn.quote(id) + ";"
//        );
//
//        std::cout << res.size() << std::endl;
//        std::vector<Muscle> muscles(res.size());
//        for (int i = 0; i < res.size(); i++) {
////            muscles.push_back(Muscle(row));
//            muscles[i] = Muscle(res[i]);
//        }
//        exercise.setSecondaryMuscles(muscles);
//
//        return exercise;
//
//    } catch (const std::exception &e) {
//        std::cerr << "Error: " << e.what() << std::endl;
//        return {};
//    }
//
//    return {};
//}
