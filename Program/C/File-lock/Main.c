#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/file.h>
#include <string.h>
#include <unistd.h>

const char *pathname = "/home/nguyen/Embedded/Programing/Basic/File-lock/File_lock.txt";

char buffer_write[1024] = "Check !";

char buffer_read[1024] ;

int fd, lock;

void *arg;

pthread_t thread_1;

void *function_handle_read(void *data)
{
    if (flock(*(int *)data, LOCK_SH) != -1)
    {
        if (read(*(int *)data, buffer_read, sizeof(buffer_write)) != -1)
        {
            printf("Read file success !\n");
            printf("%s \n",buffer_read);
        }
    }
    if (flock(*(int *)data, LOCK_UN) != -1)
    {
        printf("Thread read unlock file success!\n");
    }
    return data;
}

pthread_t thread_2;

void *function_handle_write(void *data)
{
    if (flock(*(int *)data, LOCK_SH) != -1)
    {
        if (write(*(int *)data, buffer_write, sizeof(buffer_write)) != -1)
        {
            printf("Write file success !\n");
        }
    }
    if (flock(*(int *)data, LOCK_UN) != -1)
    {
        printf("Thread write unlock file success!\n");
    }
    return data;
}

int main(int argc, const char *argv[])
{
    fd = open(pathname, O_RDWR);
    
    if (pthread_create(&thread_1, NULL, function_handle_read, &fd) == -1)
    {
        printf("Cannot create thread 1 !\n");
    }
    if (pthread_create(&thread_2, NULL, function_handle_write, &fd) == -1)
    {
        printf("Cannot create thread 2 !\n");
    }
    if (pthread_join(thread_1, &arg) == -1)
    {
        printf("Cannot join thread 1 !\n");
    }
    if (pthread_join(thread_2, &arg) == -1)
    {
        printf("Cannot join thread 2 !\n");
    }
    return 0;
}