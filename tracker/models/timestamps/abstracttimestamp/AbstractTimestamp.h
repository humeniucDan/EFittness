//
// Created by koath on 12/17/2024.
//

#ifndef TRACKER_ABSTRACTTIMESTAMP_H
#define TRACKER_ABSTRACTTIMESTAMP_H


#include <string>

class AbstractTimestamp {
private:
    int id;
    int userId;
    std::string description;

public:
    AbstractTimestamp(int id, int userId, const std::string &description);

    AbstractTimestamp();

    int getId() const;
    void setId(int id);
    int getUserId() const;
    void setUserId(int userId);
    const std::string &getDescription() const;
    void setDescription(const std::string &description);
};


#endif //TRACKER_ABSTRACTTIMESTAMP_H
