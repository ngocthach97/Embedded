#include <stdio.h>
#include <stdlib.h>
#include <sys/inotify.h>
#include <unistd.h>

#define BUF_LEN 1024

char *pathname = "/home/nguyen/Embedded/Basic/Monitoring/File.txt";

char buf[BUF_LEN];

int check_inotify_init;

int check_inotify_add_watch;

int check_read;

struct inotify_event *event;

int main(int agrv, const char *argc[])
{

    check_inotify_init = inotify_init();
    if (check_inotify_init == -1)
    {
        printf("Connot creates a new inotify instance \n");
    }
    check_inotify_add_watch = inotify_add_watch(check_inotify_init, pathname, IN_ALL_EVENTS);
    if (check_inotify_add_watch == -1)
    {
        printf("Cannot adds a new item to list! \n");
    }
    check_read = read(check_inotify_init, buf, BUF_LEN);
    if(check_read < 0 ){
        printf("Cannot read file");
    }
    event = (struct inotify_event *) buf;

    if (event->mask & IN_ACCESS){
        printf("IN_ACCESS \n");
    }
    return 0;
}