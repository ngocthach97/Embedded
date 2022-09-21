#include "OpenAccount.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Command.h"
#include "Account.h"
#define offsetof(TYPE, MEMBER) ((size_t) & ((TYPE *)0)->MEMBER)
#define container_of(ptr, type, member) ({         \
    const typeof( ((type *)0)->member ) *__mptr = (ptr); \
    (type *)( (char *)__mptr - offsetof(type,member) ); })

void execute_openAccount(struct command *command)
{
    struct openAccount *_open = container_of(command, struct openAccount, command);
    open_account(&_open->account);
}

struct command_operations openAccount_ops = {
    .execute = execute_openAccount,
};

void init_openAccount(struct openAccount *openAccount)
{
    init_command(&openAccount->command);
    openAccount->command.ops = &openAccount_ops;
    init_account(&openAccount->account);
}