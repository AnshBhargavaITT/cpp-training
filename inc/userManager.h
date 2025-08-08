#ifndef USERMANAGER_H
#define USERMANAGER_H

#include "users.h"
#include <vector>
#include <string>

class UserManager 
{
    std::vector<User*> users;

public:
    void addUser(User* user);

    bool removeUser(int userId);

    User* getUserById(int userId) const;

    User* getUserByUsername(const std::string& username) const;
    
    const std::vector<User*>& getAllUsers() const;
};

#endif
