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
    virtual bool addUser(User *user, const std::string &username, const std::string &password);

    virtual bool removeUser(int userId);

    virtual User *getUserById(int userId) const;

    virtual User *getUserByUsername(const std::string &username) const;

    virtual bool verifyCredentials(const std::string &username, const std::string &password) const;

    virtual const std::vector<User *> &getAllUsers() const;

    virtual Credential getCredentialByUserId(int userId) const;
};

#endif
