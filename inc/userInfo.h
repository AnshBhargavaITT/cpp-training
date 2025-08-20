#ifndef USERINFO_H
#define USERINFO_H

#include <string>
#include "enums.h"  

struct UserInfo 
{
    int id;
    std::string name;
    Role role;
};

struct AccountHolderInfo : public UserInfo 
{
    std::string email;
    std::string phoneNumber;
};

#endif
