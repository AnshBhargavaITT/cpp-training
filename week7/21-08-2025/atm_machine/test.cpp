#include <iostream>
#include "mockBankServer.h"
#include "atmMachine.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
using ::testing::AtLeast;
using ::testing::AtMost;
using ::testing::AnyNumber;
using ::testing::Return;

class DefaultTest : public ::testing::Test 
{
protected:
    void SetUp() override 
    {
        //ON_CALL(bankServer, getBalance).WillByDefault(Return(1000));
        //EXPECT_CALL(bankServer,getBalance).Times(AnyNumber()).WillRepeatedly(Return(1000));
        //EXPECT_CALL(bankServer,getBalance).Times(AtLeast(1)).WillRepeatedly(Return(1000));
        //EXPECT_CALL(bankServer,getBalance).Times(AnyNumber()).WillOnce(Return(1000));
        EXPECT_CALL(bankServer,getBalance).Times(AnyNumber()).WillOnce(Return(1000)).WillOnce(Return(2000));
    }

    MockBankServer bankServer;
    ATMMachine* atm;

    void SetUpATM() 
    {
        atm = new ATMMachine(&bankServer);
    }

    void TearDown() override 
    {
        delete atm;
    }
};

TEST_F(DefaultTest, CanDeposit) 
{
    SetUpATM();
    EXPECT_TRUE(atm->deposit(123456789, 2000));
}

TEST_F(DefaultTest, CanWithdraw) 
{
    SetUpATM();
    EXPECT_TRUE(atm->withdraw(123456789, 1000));
    EXPECT_TRUE(atm->withdraw(123456789, 2000));
}
