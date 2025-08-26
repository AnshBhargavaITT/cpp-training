#ifndef MOCK_USER_H
#define MOCK_USER_H
#include <gmock/gmock.h>
#include "users.h"

class MockUser : public IUser
{
public:
    MockUser() : IUser() {}
    
    MOCK_METHOD(int, getUserId, (), (const, override));

    MOCK_METHOD(std::string, getName, (), (const, override));

    MOCK_METHOD(Role, getRole, (), (const, override));
};

#endif