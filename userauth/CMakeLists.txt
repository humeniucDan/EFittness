cmake_minimum_required(VERSION 3.26)
project(userauth)

set(CMAKE_CXX_STANDARD 20)

include_directories("${CMAKE_SOURCE_DIR}/vcpkg_installed/x64-windows/include")
include_directories("${CMAKE_SOURCE_DIR}/vcpkg_installed/x64-linux/include")

link_directories("${CMAKE_SOURCE_DIR}/vcpkg_installed/x64-windows")
link_directories("${CMAKE_SOURCE_DIR}/vcpkg_installed/x64-linux")

find_package(libpqxx CONFIG REQUIRED)
find_package(Crow CONFIG REQUIRED)
find_package(bsoncxx CONFIG REQUIRED)
find_package(mongocxx CONFIG REQUIRED)
find_package(cppzmq CONFIG REQUIRED)

add_executable(userauth
        main.cpp
        zeromq/zeromq.cpp
        zeromq/zeromq.cpp
        zeromq/zeromq.h
        zeromq/zeromq.h
        crow/routes.h
        crow/routes.cpp
        login/login.h
        models/UserAuth/UserAuth.cpp
        models/UserAuth/UserAuth.h
        mongodb/UserAuthRepo/userauthRepo.h
        mongodb/UserAuthRepo/userauthRepo.h
        mongodb/UserAuthRepo/userauthRepo.cpp
        mongodb/connectionlogic/connectionlogic.h
        mongodb/connectionlogic/connectionlogic.cpp
)

target_link_libraries(userauth PRIVATE Crow::Crow asio::asio)
target_link_libraries(userauth PRIVATE libpqxx::pqxx)
target_link_libraries(userauth PRIVATE $<IF:$<TARGET_EXISTS:mongo::bsoncxx_static>,mongo::bsoncxx_static,mongo::bsoncxx_shared>)
target_link_libraries(userauth PRIVATE $<IF:$<TARGET_EXISTS:mongo::mongocxx_static>,mongo::mongocxx_static,mongo::mongocxx_shared>)
target_link_libraries(userauth PRIVATE cppzmq cppzmq-static)
