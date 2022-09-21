#include "CloseAccount.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Command.h"
#include "Account.h"
#define offsetof(TYPE, MEMBER) ((size_t) & ((TYPE *)0)->MEMBER)
#define container_of(ptr, type, member) ({         \
    const typeof( ((type *)0)->member ) *__mptr = (ptr); \
    (type *)( (char *)__mptr - offsetof(type,member) ); })

void execute_closeAccount(struct command *command)
{
    struct closeAccount *_close = container_of(command, struct closeAccount, command);
    close_account(&_close->account);
}

struct command_operations closeAccount_ops = {
    .execute = execute_closeAccount,
};

void init_closeAccount(struct closeAccount *closeAccount)
{
    init_command(&closeAccount->command);
    closeAccount->command.ops = &closeAccount_ops;
    init_account(&closeAccount->account);
}