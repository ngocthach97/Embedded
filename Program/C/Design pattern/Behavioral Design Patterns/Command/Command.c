#include "Command.h"
#include <stdio.h>
#include <stdlib.h>
void init_command(struct command *command)
{
    command->ops = NULL;
}