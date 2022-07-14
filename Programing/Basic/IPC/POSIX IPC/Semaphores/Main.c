#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>
#include <unistd.h>
#include <pthread.h>

sem_t *sem;

const char *name = "/semaphore";

pthread_t thread_1;

pthread_t thread_2;

void *data;

int value_global = 0;

void *handle_thread_1(void *data)
{
    sem_wait(sem);
    for (int i = 0; i < 200; i++)
    {
        value_global++;
        printf("value global thread 1 = %d \n", value_global);
    }
    sem_post(sem);
    return data;
}

void *handle_thread_2(void *data)
{
    sem_wait(sem);
    for (int i = 0; i < 200; i++)
    {
        value_global++;
        printf("value global thread 2 = %d \n", value_global);
    }
    sem_post(sem);
    return data;
}
int main(int argc, const char *argv[])
{
    /* Unnamed Semaphores */
    // if (sem_init(sem, 0, 1) == -1)
    // {
    //     printf("Cannot init semaphore ! \n");
    // }
    /* Named Semaphores */
    sem = sem_open(name, O_CREAT, O_RDWR, 1);
    if (sem == SEM_FAILED)
    {
        printf("Cannot create semaphore !\n");
    }
    if (pthread_create(&thread_1, NULL, handle_thread_1, NULL) == -1)
    {
        printf("Cannot create thread 1 !\n");
    }
    if (pthread_create(&thread_2, NULL, handle_thread_2, NULL) == -1)
    {
        printf("Cannot create thread 2 !\n");
    }
    if (pthread_join(thread_1, &data) == -1)
    {
        printf("Cannot join thread 1 !\n");
    }
    if (pthread_join(thread_2, &data) == -1)
    {
        printf("Cannot join thread 2 !\n");
    }
    if (sem_unlink(name) == -1)
    {
        printf("Cannot remove semaphore ! \n");
    }
    return 0;
}