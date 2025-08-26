#ifndef MOCK_USER_MANAGER_H
#define MOCK_USER_MANAGER_H

#include "userManager.h"
#include <gmock/gmock.h>

class MockUserManager : public UserManager
{
public:
    MOCK_METHOD(bool, addUser, (IUser *, const std::string &, const std::string &), (override));

    MOCK_METHOD(bool, removeUser, (int), (override));

    MOCK_METHOD(IUser *, getUserById, (int), (const, override));

    MOCK_METHOD(IUser *, getUserByUsername, (const std::string &), (const, override));

    MOCK_METHOD(bool, verifyCredentials, (const std::string &, const std::string &), (const, override));

    MOCK_METHOD(const std::vector<IUser *> &, getAllUsers, (), (const, override));

    MOCK_METHOD(Credential, getCredentialByUserId, (int), (const, override));
};

#endif
