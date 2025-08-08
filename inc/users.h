#ifndef USERS_H
#define USERS_H

#include <string>
#include "enums.h"

class User
{
protected:
    int userId;
    std::string name;
    std::string username;
    std::string password;
    Role role;

public:
    virtual ~User() {}

    virtual int getUserId() const = 0;

    virtual std::string getName() const = 0;

    virtual std::string getUsername() const = 0;

    virtual std::string getPassword() const = 0;

    virtual Role getRole() const = 0;

    virtual bool verifyPassword(const std::string &inputPassword) const;
};

#endif
