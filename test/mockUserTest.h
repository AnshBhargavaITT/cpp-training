#include <gmock/gmock.h>
#include "users.h"

class MockUser : public User 
{
public:
    MockUser(const UserInfo& info) : User(info) {}
    MOCK_METHOD(int, getUserId, (), (const, override));
    MOCK_METHOD(std::string, getName, (), (const, override));
    MOCK_METHOD(Role, getRole, (), (const, override));
};
