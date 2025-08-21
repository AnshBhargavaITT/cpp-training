#include "userService.h"

UserService::UserService(IUserInterface* repo, IEmailService* emailService)
    : user(repo), emailService(emailService) {}

bool UserService::RegisterUser(const std::string& username) 
{
    if (username.empty()) return false;

    bool saved = user->saveUser(username);
    if (!saved) return false;

    return emailService->sendMail(username);
}
