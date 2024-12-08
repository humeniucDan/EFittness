cmake_minimum_required(VERSION 3.26)
project(userdata)

set(CMAKE_CXX_STANDARD 20)

include_directories("${CMAKE_SOURCE_DIR}/vcpkg_installed/x64-windows/include")
include_directories("${CMAKE_SOURCE_DIR}/vcpkg_installed/x64-linux/include")

link_directories("${CMAKE_SOURCE_DIR}/vcpkg_installed/x64-windows")
link_directories("${CMAKE_SOURCE_DIR}/vcpkg_installed/x64-linux")

find_package(Crow CONFIG REQUIRED)
find_package(bsoncxx CONFIG REQUIRED)
find_package(mongocxx CONFIG REQUIRED)
find_package(cppzmq CONFIG REQUIRED)
find_package(jwt-cpp CONFIG REQUIRED)

#find_path(PICOJSON_INCLUDE_DIRS "picojson/picojson.h")

add_executable(userdata
        main.cpp
        zeromq/zeromq.cpp
        crow/routes.cpp
        jsonwebtoken/jwtvalidation/jwtvalidation.cpp
        mongodb/connectionlogic/connectionlogic.cpp
        mongodb/UserDataRepo/userdataRepo.cpp
        models/UserData/UserData.cpp
)

target_link_libraries(userdata PRIVATE Crow::Crow asio::asio)
target_link_libraries(userdata PRIVATE $<IF:$<TARGET_EXISTS:mongo::bsoncxx_static>,mongo::bsoncxx_static,mongo::bsoncxx_shared>)
target_link_libraries(userdata PRIVATE $<IF:$<TARGET_EXISTS:mongo::mongocxx_static>,mongo::mongocxx_static,mongo::mongocxx_shared>)
target_link_libraries(userdata PRIVATE cppzmq cppzmq-static)
target_link_libraries(userdata PRIVATE jwt-cpp::jwt-cpp)

#target_include_directories(main PRIVATE ${PICOJSON_INCLUDE_DIRS})
