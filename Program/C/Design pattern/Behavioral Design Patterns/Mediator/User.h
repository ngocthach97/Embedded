#ifndef USER_
#define USER_

struct user
{
    char *name;
    struct user_operations *ops;
};

struct user_operations
{
    void (*setName)(struct user *, char *name);
    void (*sendMessage)(struct user *, char *message);
};

#endif