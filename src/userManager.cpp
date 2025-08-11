#include "userManager.h"
#include <iostream>

void UserManager::addUser(User *user)
{
    if (getUserByUsername(user->getUsername()) == nullptr && getUserById(user->getUserId()) == nullptr)
    {
        users.push_back(user);
    }
    else
    {
        std::cout << "User with username already exists " << std::endl;
    }
}

bool UserManager::removeUser(int userId)
{
    for (int iteratorI = 0; iteratorI < users.size(); iteratorI++)
    {
        if (users[iteratorI]->getUserId() == userId)
        {
            users.erase(users.begin() + iteratorI);
            return true;
        }
    }
    return false;
}

User *UserManager::getUserById(int userId) const
{
    for (int iteratorI = 0; iteratorI < users.size(); iteratorI++)
    {
        if (users[iteratorI]->getUserId() == userId)
        {
            return users[iteratorI];
        }
    }
    return nullptr;
}

User *UserManager::getUserByUsername(const std::string &username) const
{
    for (int iteratorI = 0; iteratorI < users.size(); iteratorI++)
    {
        if (users[iteratorI]->getUsername() == username)
        {
            return users[iteratorI];
        }
    }
    return nullptr;
}

const std::vector<User *> &UserManager::getAllUsers() const { return users; }
