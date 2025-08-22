#include "authentication.h"

Authentication::Authentication(UserManager *manager)
{
    userManager = manager;
    currentUser = nullptr;
}

IUser *Authentication::login(const std::string &username, const std::string &password)
{
    if (userManager->verifyCredentials(username, password))
    {
        currentUser = userManager->getUserByUsername(username);
        return currentUser;
    }
    return nullptr;
}

bool Authentication::logout()
{
    if (currentUser != nullptr)
    {
        currentUser = nullptr;
        return true;
    }
    return false;
}

IUser *Authentication::getCurrentUser() const { return currentUser; }
