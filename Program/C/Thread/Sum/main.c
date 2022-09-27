#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_t thread_1;

pthread_t thread_2;

pthread_t thread_3;

int value_thread_1;

int value_thread_2;

int value_thread_3;

pthread_mutex_t lock_thread;

int value_lock_thread;

pthread_cond_t cond_thread_1;

pthread_cond_t cond_thread_2;

pthread_cond_t cond_thread_3;

int value_cond_wait;

int value_cond_signal;

int done = 1;

int value_1, value_2, total;

void *function_thread_1(void *data)
{
    if (done == 1)
    {
        done = 2;

        for (int i = 0; i < 100; i++)
        {
            value_1 = i;
            printf("Value 1 = %d\n", value_1);
            value_cond_signal = pthread_cond_signal(&cond_thread_2);
            if (value_cond_signal != 0)
            {
                printf("Cannot create condition signal thread 2 !\n");
            }
            value_cond_wait = pthread_cond_wait(&cond_thread_1, &lock_thread);
            if (value_cond_wait != 0)
            {
                printf("Cannot create condition wait thread 1 !\n");
            }
        }
    }
    return NULL;
}

void *function_thread_2(void *data)
{
    if (done == 2)
    {
        done = 3;

        for (int i = 0; i < 100; i++)
        {
            value_2 = i;
            printf("Value 2 = %d\n", value_2);

            value_cond_signal = pthread_cond_signal(&cond_thread_3);
            if (value_cond_signal != 0)
            {
                printf("Cannot create condition signal thread 3 !\n");
            }

            value_cond_wait = pthread_cond_wait(&cond_thread_2, &lock_thread);
            if (value_cond_wait != 0)
            {
                printf("Cannot create condition wait thread 2 !\n");
            }
        }
    }
    return NULL;
}

void *function_thread_3(void *data)
{
    if (done == 3)
    {
        done = 1;

        for (int i = 0; i < 100; i++)
        {
            total = value_1 + value_2;
            printf("Total = %d\n", total);
            value_cond_signal = pthread_cond_signal(&cond_thread_1);
            if (value_cond_signal != 0)
            {
                printf("Cannot create condition signal thread 1 !\n");
            }
            value_cond_wait = pthread_cond_wait(&cond_thread_3, &lock_thread);
            if (value_cond_wait != 0)
            {
                printf("Cannot create condition wait thread 3 !\n");
            }
        }
    }
    return NULL;
}

int main(int agrv, const char *argc[])
{
    value_thread_1 = pthread_create(&thread_1, NULL, function_thread_1, NULL);
    if (value_thread_1 != 0)
    {
        printf("Cannot create thread 1 !\n");
    }

    value_thread_2 = pthread_create(&thread_2, NULL, function_thread_2, NULL);
    if (value_thread_2 != 0)
    {
        printf("Cannot create thread 2 !\n");
    }

    value_thread_3 = pthread_create(&thread_3, NULL, function_thread_3, NULL);
    if (value_thread_3 != 0)
    {
        printf("Cannot create thread 3 !\n");
    }

    if (pthread_join(thread_1, NULL) != 0)
    {
        printf("cannot join thread 1 !\n");
    }

    if (pthread_join(thread_2, NULL) != 0)
    {
        printf("cannot join thread 2 !\n");
    }

    if (pthread_join(thread_3, NULL) != 0)
    {
        printf("cannot join thread 3 !\n");
    }

    return 0;
}