#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_t thread_1;

pthread_t thread_2;

int value_thread_1;

int value_thread_2;

pthread_mutex_t lock_thread;

int value_lock_thread;

pthread_cond_t cond_thread;

int value_cond_wait;

int value_cond_signal;

int done = 1;

int value_sum_1;

int value_sum_2;

int total;

void *function_thread(void *data)
{
    value_lock_thread = pthread_mutex_lock(&lock_thread);
    if (value_lock_thread != 0)
    {
        printf("Cannot create mutex thread 1 !\n");
    }
    if (done == 1)
    {
        done = 2;
        printf("Waiting thread 1...... \n");
        value_cond_wait = pthread_cond_wait(&cond_thread, &lock_thread);
        if (value_cond_wait != 0)
        {
            printf("Cannot create condition wait thread 1 !\n");
        }
         printf("Running thread 1...... \n");
    }
    else
    {
        printf("Waiting thread 2...... \n");
        // done = 1;
        value_cond_signal = pthread_cond_signal(&cond_thread);
        if (value_cond_signal != 0)
        {
            printf("Cannot create condition signal thread 1 !\n");
        }
        printf("Running thread 2...... \n");
    }
    pthread_mutex_unlock(&lock_thread);
    return NULL;
}

int main(int agrv, const char *argc[])
{
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

    if (pthread_join(thread_2, NULL) != 0)
    {
        printf("cannot join thread 2 !\n");
    }
    return 0;
}