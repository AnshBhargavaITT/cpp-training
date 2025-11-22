#ifndef USER_INTERFACE
#define USER_INTERFACE
#include<string>

class IUserInterface 
{
public:
    virtual ~IUserInterface()=default;

    virtual bool saveUser(const std::string& username)=0;
};

#endif