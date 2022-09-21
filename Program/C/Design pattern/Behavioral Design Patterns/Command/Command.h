#ifndef COMMAND_
#define COMMAND_

struct command
{
    struct command_operations *ops;
};

struct command_operations
{
    void (*execute)(struct command *);
};

void init_command(struct command *);

static inline void _execute(struct command *command)
{
    command->ops->execute(command);
}
#endif