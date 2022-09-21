#include "Account.h"
#include <stdio.h>

void _open_account(struct account *account)
{
    printf("Account [%s] Opened\n", account->name);
}

void _close_account(struct account *account)
{
    printf("Account [%s] Closed\n", account->name);
}

struct account_operations account_ops = {
    .open = _open_account,
    .close = _close_account,
};

void init_account(struct account *account)
{
    account->ops = &account_ops;
    account->name = "Nguyen";
}