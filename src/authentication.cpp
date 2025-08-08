#include "authentication.h"

Authentication::Authentication(UserManager* manager) {userManager = manager;}

User* Authentication::login(const std::string& username, const std::string& password) 
{
    User* user = userManager->getUserByUsername(username);
    if (user && user->verifyPassword(password)) 
    {
        if(isLoggedIn(user)){return user;}
        loggedInUsers.push_back(user);
        return user;
    }
    return nullptr;
}

bool Authentication::logout(User* user) 
{
    for (int iteratorI = 0; iteratorI < loggedInUsers.size(); iteratorI++) 
    {
        if (loggedInUsers[iteratorI]->getUserId() == user->getUserId()) 
        {
            loggedInUsers.erase(loggedInUsers.begin() + iteratorI);
            return true;
        }
    }
    return false;
}

bool Authentication::isLoggedIn(User* user) const 
{
    for (int iteratorI = 0; iteratorI < loggedInUsers.size(); iteratorI++) 
    {
        if (loggedInUsers[iteratorI]->getUserId() == user->getUserId()) {return true;}
    }
    return false;
}

