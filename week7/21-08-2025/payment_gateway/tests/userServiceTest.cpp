#include <gtest/gtest.h>
#include "userService.h"
#include "emailMock.h"
#include "userMock.h"

using ::testing::Return;
using ::testing::_;

TEST(UserServiceTest, FailsWhenUsernameIsEmpty) 
{
    MockUserInterface mockRepo;
    MockEmailService mockEmail;

    UserService service(&mockRepo, &mockEmail);

    EXPECT_FALSE(service.RegisterUser(""));
}

TEST(UserServiceTest, FailsIfUserSaveFails) 
{
    MockUserInterface mockRepo;
    MockEmailService mockEmail;

    EXPECT_CALL(mockRepo, saveUser("john")).WillOnce(Return(false));
    EXPECT_CALL(mockEmail, sendMail(_)).Times(0);

    UserService service(&mockRepo, &mockEmail);
    EXPECT_FALSE(service.RegisterUser("john"));
}

TEST(UserServiceTest, WelcomeMailOnRegisteration) 
{
    MockUserInterface mockRepo;
    MockEmailService mockEmail;

    EXPECT_CALL(mockRepo, saveUser("john")).WillOnce(Return(true));
    EXPECT_CALL(mockEmail, sendMail("john")).WillOnce(Return(true));

    UserService service(&mockRepo, &mockEmail);
    EXPECT_TRUE(service.RegisterUser("john"));
}
