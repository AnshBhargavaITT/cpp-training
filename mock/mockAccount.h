#ifndef MOCK_ACCOUNT_H
#define MOCK_ACCOUNT_H
#include <gmock/gmock.h>
#include "account.h"

class MockAccount : public Account
{
public:
    MockAccount()
    {
        this->balance = 0.0;
        this->accountNumber = 0;
    }

    ~MockAccount() override = default;

    MOCK_METHOD(bool, deposit, (double), (override));

    MOCK_METHOD(bool, withdraw, (double), (override));

    MOCK_METHOD(std::vector<Transaction *>, bankStatement, (), (override));

    MOCK_METHOD(AccountType, getAccountType, (), (const, override));

    MOCK_METHOD(int, getAccountNumber, (), (const, override));

    MOCK_METHOD(double, getBalance, (), (const, override));

    MOCK_METHOD(void, setAccountNumber, (int), (override));
};

#endif
