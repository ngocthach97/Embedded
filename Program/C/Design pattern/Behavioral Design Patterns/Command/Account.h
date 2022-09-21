#ifndef ACCOUNT_COMMAND_
#define ACCOUNT_COMMAND_

struct account
{
    char *name;
    struct account_operations *ops;
};

struct account_operations
{
    void (*open)(struct account *);
    void (*close)(struct account *);
};

void init_account(struct account *);

static inline void open_account(struct account *account)
{
    account->ops->open(account);
}

static inline void close_account(struct account *account)
{
    account->ops->close(account);
}

#endif