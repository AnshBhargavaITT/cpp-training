#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H

#include <string>
#include "userManager.h"
#include <vector>

class Authentication
{
    UserManager *userManager;
    IUser *currentUser = nullptr;

public:
    Authentication(UserManager *manager);

    IUser *login(const std::string &username, const std::string &password);

    bool logout();

    IUser *getCurrentUser() const;

    UserManager *getUserManager() const { return userManager; }
};

#endif