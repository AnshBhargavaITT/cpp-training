#ifndef MOCKBANKSERVER_H
#define MOCKBANKSERVER_H
#include<gmock/gmock.h>
#include <bankServer.h>

class MockBankServer : public IBankServer 
{
public:
    MOCK_METHOD(void , connect , () , (override));
    MOCK_METHOD(void , disconnect , (), (override));
    MOCK_METHOD(void , credit , (int, int) , (override));
    MOCK_METHOD(void , debit , (int, int) , (override));
    MOCK_METHOD(int , getBalance , (int) , (override));
};

#endif