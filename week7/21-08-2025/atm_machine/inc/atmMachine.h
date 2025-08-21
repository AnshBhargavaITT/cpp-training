#ifndef ATMMACHINE_H
#define ATMMACHINE_H
#include "bankServer.h"

class ATMMachine
{
    IBankServer* bank;

public:

    ATMMachine(IBankServer* server):bank(server){};
    bool withdraw(int accountNumber , int amount);
    bool deposit(int accountNumber , int amount);
};

#endif