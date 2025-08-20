#ifndef USERS_H
#define USERS_H

#include <string>
#include "enums.h"
#include "userInfo.h"

class User
{
protected:
    int userId;
    std::string name;
    Role role;

public:
    User(const UserInfo &info)
        : userId(info.id),
          name(info.name),
          role(info.role) {}

    virtual ~User() {}

    virtual int getUserId() const = 0;

    virtual std::string getName() const = 0;
    
    virtual Role getRole() const = 0;
};

#endif
