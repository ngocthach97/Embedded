#ifndef CHATROOM_
#define CHATROOM_
#include "User.h"
struct chatRoom
{
    struct chatRoom_operations *ops;
};

struct chatRoom_operations
{
    void (*showMessage)(struct chatRoom *, struct user *, char *message);
};

void _showMessage(struct chatRoom *chatRoom, struct user *user, char *message){
    chatRoom->ops->showMessage(chatRoom, user,message);
}
#endif