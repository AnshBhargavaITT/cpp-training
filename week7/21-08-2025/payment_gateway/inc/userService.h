#ifndef USER_SERVICE
#define USER_SERVICE
#include<iostream>
#include "IUserInterface.h"
#include "IEmailService.h"

class UserService
{
public:
    UserService(IUserInterface* user, IEmailService* emailService);
    bool RegisterUser(const std::string& username);

private:
    IUserInterface* user;
    IEmailService* emailService;
};

#endif