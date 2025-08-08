#include "users.h"

bool User::verifyPassword(const std::string& inputPassword) const
{
    return password==inputPassword;
}