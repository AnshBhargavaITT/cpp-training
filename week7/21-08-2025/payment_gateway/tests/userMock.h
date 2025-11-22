#include <gmock/gmock.h>
#include "IUserInterface.h"

class MockUserInterface : public IUserInterface {
public:
    MOCK_METHOD(bool, saveUser, (const std::string& username), (override));
};
