cmake_minimum_required(VERSION 3.26)
project(userauth)

set(CMAKE_CXX_STANDARD 20)

include_directories("${CMAKE_SOURCE_DIR}/vcpkg_installed/x64-windows/include")
include_directories("${CMAKE_SOURCE_DIR}/vcpkg_installed/x64-linux/include")

link_directories("${CMAKE_SOURCE_DIR}/vcpkg_installed/x64-windows")
link_directories("${CMAKE_SOURCE_DIR}/vcpkg_installed/x64-linux")

find_package(Crow CONFIG REQUIRED)
find_package(bsoncxx CONFIG REQUIRED)
find_package(mongocxx CONFIG REQUIRED)
find_package(cppzmq CONFIG REQUIRED)
find_package(nlohmann_json CONFIG REQUIRED)
find_package(jwt-cpp CONFIG REQUIRED)

add_executable(userauth
        main.cpp
        zeromq/zeromq.cpp
        zeromq/zeromq.cpp
        crow/routes.cpp
        models/UserAuth/UserAuth.cpp
        mongodb/UserAuthRepo/userauthRepo.cpp
        mongodb/connectionlogic/connectionlogic.cpp
        mongodb/mongodbInstance/MongodbInstance.cpp
        jsonwebtoken/jwtgeneration/jwtgeneration.cpp
        login/login.cpp
        login/login.cpp
        signup/signup.cpp
        signup/signup.h
        jsonwebtoken/jwtvalidation/jwtvalidation.cpp
        jsonwebtoken/jwtvalidation/jwtvalidation.h
        jsonwebtoken/jwtvalidation/jwtvalidation.cpp
)

target_link_libraries(userauth PRIVATE Crow::Crow asio::asio)
target_link_libraries(userauth PRIVATE $<IF:$<TARGET_EXISTS:mongo::bsoncxx_static>,mongo::bsoncxx_static,mongo::bsoncxx_shared>)
target_link_libraries(userauth PRIVATE $<IF:$<TARGET_EXISTS:mongo::mongocxx_static>,mongo::mongocxx_static,mongo::mongocxx_shared>)
target_link_libraries(userauth PRIVATE cppzmq cppzmq-static)
target_link_libraries(userauth PRIVATE nlohmann_json::nlohmann_json)
target_link_libraries(userauth PRIVATE jwt-cpp::jwt-cpp)
