#ifndef USERMANAGER_H
#define USERMANAGER_H

#include "users.h"
#include <vector>
#include <string>

struct Credential
{
    std::string username;
    std::string password;
    User *user;
};

class UserManager
{
    std::vector<User *> users;
    std::vector<Credential> credentials; 

public:
    bool addUser(User *user, const std::string &username, const std::string &password);

    bool removeUser(int userId);

    User *getUserById(int userId) const;

    User *getUserByUsername(const std::string &username) const;

    bool verifyCredentials(const std::string &username, const std::string &password) const;

    const std::vector<User *> &getAllUsers() const;

    Credential getCredentialByUserId(int userId) const;
};

#endif
