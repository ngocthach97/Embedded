#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

int value_global;

sem_t semaphore;

void *function_thread(void *data)
{
    sem_wait(&semaphore);
    for (int i = 0; i < 50000; i++)
    {
        value_global++;
    }
    sem_post(&semaphore);
    return data;
}

int main(int agrv, const char *argc[])
{
    sem_init(&semaphore, 0, 1);
    
    pthread_t thread_1, thread_2;

    int value_thread_1, value_thread_2;

    value_thread_1 = pthread_create(&thread_1, NULL, function_thread, NULL);
    if (value_thread_1 != 0)
    {
        printf("Cannot create thread 1 !\n");
    }

    value_thread_2 = pthread_create(&thread_2, NULL, function_thread, NULL);
    if (value_thread_2 != 0)
    {
        printf("Cannot create thread 2 !\n");
    }

    if (pthread_join(thread_1, NULL) != 0)
    {
        printf("cannot join thread 2 !\n");
    }

    if (pthread_join(thread_2, NULL) != 0)
    {
        printf("cannot join thread 2 !\n");
    }

    printf("Value = %d\n", value_global);
    return 0;
}
