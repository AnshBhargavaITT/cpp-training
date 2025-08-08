#ifndef AUTHENTICATION_H
#define AUTHENTICATION_H

#include <string>
#include "userManager.h"
#include <vector>

class Authentication 
{
    UserManager* userManager;
    std::vector<User*> loggedInUsers; 

public:
    Authentication(UserManager* manager);
    
    User* login(const std::string& username, const std::string& password);

    bool logout(User* user);

    bool isLoggedIn(User* user) const;
};

#endif