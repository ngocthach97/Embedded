#ifndef OPEN_ACCOUNT_COMMAND_
#define OPEN_ACCOUNT_COMMAND_
#include "Command.h"
#include "Account.h"

struct openAccount
{
    struct account account;
    struct command command;
};

void init_openAccount(struct openAccount *);

#endif