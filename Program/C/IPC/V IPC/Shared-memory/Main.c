#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h> /* For portability */
#include <sys/shm.h>

int shmid;

key_t key;

char *pathname = '.';
int main(int argc, const char *argv[])
{
    key = ftok(pathname, 'x');
    if (key == -1)
    {
        printf("Cannot generating a unique key \n");
    }

    shmid = shmget(key, size_t size, 0644 | IPC_CREAT |);
    printf("Check \n");
    return 0;
}