#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

FILE *file;

pthread_t thread[5];

pthread_cond_t cond_thread[5];

int count;

pthread_mutex_t p_clock;

void *function_write_thread(void *data)
{
    pthread_mutex_lock(&p_clock);
    for (int i = 0; i < 10; i++)
    {
        count++;
        fprintf(file, "%d \n", count);
    }
    pthread_mutex_unlock(&p_clock);
    return NULL;
}

int main(int agrv, const char *argc[])
{
    int value_clock = pthread_mutex_init(&p_clock, NULL);
    if (value_clock != 0)
    {
        printf("Cannot create clock thread !\n");
    }
    for (int i = 0; i < 5; i++)
    {
        int value_cond_thread = pthread_cond_init(&cond_thread[i], NULL);
        if (value_cond_thread != 0)
        {
            printf("Cannot create condition thread !\n");
        }
    }

    if ((file = fopen("data.txt", "w")) == NULL)
    {
        printf("Error! opening file");
        exit(1);
    }

    for (int i = 0; i < 5; i++)
    {
        int value_thread = pthread_create(&thread[i], NULL, function_write_thread, NULL);
        if (value_thread != 0)
        {
            printf("Cannot create thread !\n");
        }
    }

    for (int i = 0; i < 5; i++)
    {
        int value_thread_join = pthread_join(thread[i], NULL);
        if (value_thread_join != 0)
        {
            printf("Cannot create thread join !\n");
        }
    }
    fclose(file);
    printf("%d \n", count);
    return 0;
}
