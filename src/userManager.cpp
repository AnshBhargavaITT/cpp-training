#include "userManager.h"
#include <iostream>
#include <unordered_map>

bool UserManager::addUser(IUser *user, const std::string &username, const std::string &password)
{
    for (Credential &cred : credentials)
    {
        if (cred.username == username)
        {
            if (cred.user->getUserId() == user->getUserId())
            {
                return true;
            }
        }
    }

    for (IUser *existingUser : users)
    {
        if (existingUser->getUserId() == user->getUserId())
        {
            std::cout << "User with ID " << user->getUserId() << " already exists" << std::endl;
            return false;
        }
    }

    users.push_back(user);

    Credential newCred;
    newCred.username = username;
    newCred.password = password;
    newCred.user = user;

    credentials.push_back(newCred);

    return true;
}

bool UserManager::removeUser(int userId)
{
    bool removed = false;

    for (int iteratorI = 0; iteratorI < users.size(); iteratorI++)
    {
        if (users[iteratorI] && users[iteratorI]->getUserId() == userId)
        {
            users.erase(users.begin() + iteratorI);
            break;
        }
    }

    for (int iteratorI = 0; iteratorI < credentials.size(); iteratorI++)
    {
        if (credentials[iteratorI].user && credentials[iteratorI].user->getUserId() == userId)
        {
            credentials.erase(credentials.begin() + iteratorI);
            removed = true;
            break;
        }
    }

    return removed;
}

IUser *UserManager::getUserById(int userId) const
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

IUser *UserManager::getUserByUsername(const std::string &username) const
{
    for (int iteratorI = 0; iteratorI < credentials.size(); iteratorI++)
    {
        if (credentials[iteratorI].username == username)
        {
            return credentials[iteratorI].user;
        }
    }
    return nullptr;
}

bool UserManager::verifyCredentials(const std::string &username, const std::string &password) const
{
    for (int iteratorI = 0; iteratorI < credentials.size(); iteratorI++)
    {
        if (credentials[iteratorI].username == username && credentials[iteratorI].password == password)
        {
            return true;
        }
    }
    return false;
}

const std::vector<IUser *> &UserManager::getAllUsers() const { return users; }

Credential UserManager::getCredentialByUserId(int userId) const
{
    for (int iteratorI = 0; iteratorI < credentials.size(); iteratorI++)
    {
        if (credentials[iteratorI].user && credentials[iteratorI].user->getUserId() == userId)
        {
            return credentials[iteratorI];
        }
    }

    Credential emptyCred;
    emptyCred.username = "";
    emptyCred.password = "";
    emptyCred.user = nullptr;
    return emptyCred;
}
