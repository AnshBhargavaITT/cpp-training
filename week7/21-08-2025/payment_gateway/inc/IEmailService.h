#ifndef EMAIL_SERVICE
#define EMAIL_SERVICE
#include<string>

class IEmailService 
{
public:
    virtual~IEmailService()=default;

    virtual bool sendMail(const std::string& username)=0;
};

#endif