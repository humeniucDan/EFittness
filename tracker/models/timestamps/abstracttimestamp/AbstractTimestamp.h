//
// Created by koath on 12/17/2024.
//

#ifndef TRACKER_ABSTRACTTIMESTAMP_H
#define TRACKER_ABSTRACTTIMESTAMP_H


#include <string>
#include <pqxx/pqxx>
#include "picojson/picojson.h"
#include <chrono>

class AbstractTimestamp {
private:
    int id;
    int userId;
    std::chrono::system_clock::time_point datetime;
    std::string description;

public:
    AbstractTimestamp(int id, int userId, std::string description, const std::string& datetime);
    AbstractTimestamp(const pqxx::row&);
    AbstractTimestamp();

    int getId() const;
    void setId(int id);
    int getUserId() const;
    void setUserId(int userId);
    const std::string &getDescription() const;
    void setDescription(const std::string &description);

    const std::chrono::system_clock::time_point &getDatetime() const;
    void setDatetime(const std::chrono::system_clock::time_point &datetime);

    void addToJson(picojson::object&);

    static std::string_view getTablename();
};


#endif //TRACKER_ABSTRACTTIMESTAMP_H
