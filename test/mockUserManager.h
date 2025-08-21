#include "userManager.h"
#include <gmock/gmock.h>

class MockUserManager : public UserManager 
{
public:
    MOCK_METHOD(bool, addUser, (User *user, const std::string &username, const std::string &password), (override));
    MOCK_METHOD(bool, removeUser, (int userId), (override));
    MOCK_METHOD(User *, getUserById, (int userId), (const, override));
    MOCK_METHOD(User *, getUserByUsername, (const std::string &username), (const, override));
    MOCK_METHOD(bool, verifyCredentials, (const std::string &username, const std::string &password), (const, override));
    MOCK_METHOD(const std::vector<User *> &, getAllUsers, (), (const, override));
    MOCK_METHOD(Credential, getCredentialByUserId, (int userId), (const, override));
};
