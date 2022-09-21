#ifndef CLOSE_ACCOUNT_COMMAND_
#define CLOSE_ACCOUNT_COMMAND_
#include "Account.h"
#include "Command.h"

struct closeAccount
{
    struct account account;
    struct command command;
};

void init_closeAccount(struct closeAccount *);

#endif