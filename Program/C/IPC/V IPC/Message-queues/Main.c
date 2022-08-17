#include <sys/types.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <sys/shm.h>
#define MAX_SIZE 1024
struct tm *tm_msg_stime, *tm_msg_rtime, *tm_msg_ctime;
char send_messages[MAX_SIZE] = "Hello world";
char receive_messages[MAX_SIZE];
key_t key;
int msqid;
struct msqid_ds buf;
struct ipc_perm perm;
int main(int agrv, const char *argc[])
{
    msqid = msgget(key, 0644 | IPC_CREAT);
    if (msqid == -1)
    {
        printf("Cannot create message queue !\n");
    }

    if (msgctl(msqid, IPC_STAT, &buf) == -1)
    {
        printf("Cannot message queue control operations ! \n");
    }

    if (msgsnd(msqid, &send_messages, sizeof(send_messages), 0) == -1)
    {
        printf("Cannot sending messages ! \n");
    }
    if (msgrcv(msqid, &receive_messages, sizeof(receive_messages), 0, 0) == -1)
    {
        printf("Cannot receiving_messages ! \n");
    }
    printf("%s\n", receive_messages);
    
    perm = buf.msg_perm;

    printf("Ownership and permissions \n");
    printf("Creator user ID = %d \n",perm.cuid);
    printf("Creator group ID =%d \n",perm.cgid);
    printf("Owner user ID = %d\n",perm.uid);
    printf("Owner group ID = %d\n",perm.gid);
    printf("R/w permissions = %d \n",perm.mode);
   
    tm_msg_stime = gmtime(&buf.msg_stime);
    printf("Time of last msgsnd() = %s", asctime(tm_msg_stime));

    tm_msg_rtime = gmtime(&buf.msg_rtime);
    printf("Time of last msgrcv() = %s", asctime(tm_msg_rtime));

    tm_msg_ctime = gmtime(&buf.msg_ctime);
    printf("Time of last change = %s", asctime(tm_msg_ctime));

    printf("Number of bytes in queue = %ld \n", buf.__msg_cbytes);

    printf("Number of messages in queue = %ld\n", buf.msg_qnum);

    printf("Maximum bytes in queue = %ld\n", buf.msg_qbytes);

    printf("PID of last msgsnd() = %d \n", buf.msg_lspid);

    printf("PID of last msgrcv() = %d \n", buf.msg_lrpid);

    return 0;
}