#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H

#include <string>
#include "userManager.h"
#include <vector>

class Authentication
{
    UserManager *userManager;
    User *currentUser = nullptr;

public:
    Authentication(UserManager *manager);

    User *login(const std::string &username, const std::string &password);

    bool logout();

    User *getCurrentUser() const;

    UserManager *getUserManager() const { return userManager; }
};

#endif