#ifndef BANKSERVER_H
#define BANKSERVER_H

class IBankServer
{
public:
    virtual ~IBankServer(){};
    virtual void connect()=0;
    virtual void disconnect()=0;
    virtual void credit(int accountNumber , int amount)=0;
    virtual void debit(int accountNumber , int amount)=0;
    virtual int getBalance(int accountNumber)=0;
};

#endif
