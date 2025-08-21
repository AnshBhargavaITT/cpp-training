#include <gmock/gmock.h>
#include "IEmailService.h"

class MockEmailService : public IEmailService 
{
public:
    MOCK_METHOD(bool, sendMail, (const std::string& username), (override));
};
