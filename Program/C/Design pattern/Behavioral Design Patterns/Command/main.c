#include <stdio.h>
#include <stdlib.h>
#include "Account.h"
#include "Command.h"
#include "CloseAccount.h"
#include "OpenAccount.h"

int main(int agrv, const char *argc[])
{
    struct openAccount *openAccount = (struct openAccount *)malloc(sizeof(struct openAccount));
    init_openAccount(openAccount);

    struct closeAccount *closeAccount = (struct closeAccount *)malloc(sizeof(struct closeAccount));
    init_closeAccount(closeAccount);

    open_account(&openAccount->account);
    close_account(&closeAccount->account);

    return 0;
}
