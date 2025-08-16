#include "userManager.h"
#include <iostream>
#include <unordered_map>

bool UserManager::addUser(User *user, const std::string &username, const std::string &password)
{
    std::unordered_map<std::string, Credential>::iterator iteratorI = credentials.find(username);

    if (iteratorI != credentials.end())
    {
        if (iteratorI->second.user->getUserId() != user->getUserId())
        {
            std::cout << "User with username '" << username << "' already exists" << std::endl;
            return false;
        }
        else
        {
            credentials[username] = Credential{username, password, user};
            return true;
        }
    }

    for (int iteratorI = 0; iteratorI < users.size(); iteratorI++)
    {
        if (users[iteratorI]->getUserId() == user->getUserId())
        {
            std::cout << "User with ID " << user->getUserId() << " already exists" << std::endl;
            return false;
        }
    }

    users.push_back(user);
    credentials[username] = Credential{username, password, user};
    return true;
}

bool UserManager::removeUser(int userId)
{
    for (int iteratorI = 0; iteratorI < users.size(); iteratorI++)
    {
        if (users[iteratorI]->getUserId() == userId)
        {
            for (std::unordered_map<std::string, Credential>::iterator iteratorI = credentials.begin(); iteratorI != credentials.end(); iteratorI++)
            {
                if (iteratorI->second.user->getUserId() == userId)
                {
                    credentials.erase(iteratorI);
                    break;
                }
            }

            delete users[iteratorI];
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
    if (credentials.count(username) > 0)
    {
        return credentials.at(username).user;
    }
    return nullptr;
}

bool UserManager::verifyCredentials(const std::string &username, const std::string &password) const
{
    if (credentials.count(username) > 0)
    {
        return credentials.at(username).password == password;
    }
    return false;
}

const std::vector<User *> &UserManager::getAllUsers() const { return users; }

Credential UserManager::getCredentialByUserId(int userId) const
{
    for (const std::pair<const std::string, Credential> &pair : credentials)
    {
        if (pair.second.user->getUserId() == userId)
        {
            return pair.second;
        }
    }
    return {"", "", nullptr};
}
