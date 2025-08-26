#ifndef USERMANAGER_H
#define USERMANAGER_H

#include "users.h"
#include <vector>
#include <string>

struct Credential
{
    std::string username;
    std::string password;
    IUser *user;
};

class UserManager
{
    std::vector<IUser *> users;
    std::vector<Credential> credentials;

public:
    virtual bool addUser(IUser *user, const std::string &username, const std::string &password);

    virtual bool removeUser(int userId);

    virtual IUser *getUserById(int userId) const;

    virtual IUser *getUserByUsername(const std::string &username) const;

    virtual bool verifyCredentials(const std::string &username, const std::string &password) const;

    virtual const std::vector<IUser *> &getAllUsers() const;

    virtual Credential getCredentialByUserId(int userId) const;
};

#endif
