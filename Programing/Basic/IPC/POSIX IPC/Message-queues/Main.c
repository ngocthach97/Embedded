#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 1024

#define QUEUE_NAME "/queue_demo"

const char MESSAGE_SEND[MAX_SIZE] = "Hello world";

mqd_t mpd;

struct mq_attr attr;

char MESSAGE_RECEIVE[MAX_SIZE];

struct timespec timeout;

int main(int argc, const char *argv[])
{
    // Message queue description flags
    attr.mq_flags = 0;
    // Maximum number of messages on queue
    attr.mq_maxmsg = 10;
    //  Maximum message size (in bytes)
    attr.mq_msgsize = MAX_SIZE;
    // Number of messages currently in queue
    attr.mq_curmsgs = 0;

    mpd = mq_open(QUEUE_NAME, O_CREAT | O_RDWR, 0644, &attr);

    if (mpd == -1)
    {
        printf("Cannot create message queue ! \n");
    }

    if (mq_send(mpd, MESSAGE_SEND, MAX_SIZE, 0) == -1)
    {
        printf("Cannot send message ! \n");
    }

    if (mq_receive(mpd, MESSAGE_RECEIVE, MAX_SIZE, 0) == -1)
    {
        printf("Cannot receive message ! \n");
    }

    printf("Value receive message = %s ! \n", MESSAGE_RECEIVE);

    // Sending and Receiving Messages with a Timeout

    if (clock_gettime(CLOCK_REALTIME, &timeout) == -1)
    {
        printf("Cannot get time ! \n");
    }

    timeout.tv_nsec += 0;
    timeout.tv_sec += 100000;

    if (mq_timedsend(mpd, MESSAGE_SEND, MAX_SIZE, 0, &timeout) == -1)
    {
        printf("Cannot send message ! \n");
    }
    if (mq_timedreceive(mpd, MESSAGE_RECEIVE, MAX_SIZE, 0, &timeout) == -1)
    {
        printf("Cannot receive message ! \n");
    }
    printf("Value receive message with timeout = %s ! \n", MESSAGE_RECEIVE);

    if (mq_close(mpd) == -1)
    {
        printf("Cannot close message ! \n");
    }

    if (mq_unlink(QUEUE_NAME) == -1)
    {
        printf("Cannot remove message ! \n");
    }

    return 0;
}