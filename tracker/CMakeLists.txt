cmake_minimum_required(VERSION 3.26)
project(tracker)

set(CMAKE_CXX_STANDARD 20)
add_definitions(-D_WIN32_WINNT=0x0A00)

include_directories("${CMAKE_SOURCE_DIR}/vcpkg_installed/x64-windows/include")
include_directories("${CMAKE_SOURCE_DIR}/vcpkg_installed/x64-linux/include")

link_directories("${CMAKE_SOURCE_DIR}/vcpkg_installed/x64-windows")
link_directories("${CMAKE_SOURCE_DIR}/vcpkg_installed/x64-linux")

find_package(libpqxx CONFIG REQUIRED)
find_package(Crow CONFIG REQUIRED)
find_package(jwt-cpp CONFIG REQUIRED)

add_executable(tracker
        main.cpp
        crow/routes.cpp
        jsonwebtoken/jwtvalidation/jwtvalidation.cpp
        models/userhistory/UserHistory.cpp
        models/timestamps/userhistorywater/WaterTimestamp.cpp
        models/timestamps/userhistorymeal/MealTimestamp.cpp
        models/timestamps/userhistoryworkout/WorkoutTimestamp.cpp
        models/timestamps/abstracttimestamp/AbstractTimestamp.cpp
        models/timestamps/userhistorycardio/CardioTimestamp.cpp
        repos/userhistoryrepo/userhistoryrepo.cpp
        repos/pqcred/pqcred.cpp
        repos/timelinerepos/abstracttimelinerepo/abstracttimelinerepo.cpp
        repos/timelinerepos/abstracttimelinerepo/abstracttimelinerepo.h
        logic/timelinefolds/timelinefolds.cpp
        logic/timecheckers/timecheckers.cpp
        models/static/muscle/Muscle.cpp
        models/static/equipment/Equipment.cpp
        models/static/exercise/Exercise.cpp
        repos/staticrepos/exereciserepo/exerciserepo.cpp
        repos/staticrepos/abstractstaticrepo/abstractstaticrepo.cpp
        repos/staticrepos/equipmentrepo/equipmentrepo.cpp
        repos/staticrepos/msuclesrepo/musclesrepo.cpp
)

target_link_libraries(tracker PRIVATE Crow::Crow asio::asio)
target_link_libraries(tracker PRIVATE libpqxx::pqxx)
target_link_libraries(tracker PRIVATE jwt-cpp::jwt-cpp)

