#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/sem.h>
#include <sys/ipc.h>

#define NUMBER_OF_SEMAPHORES 5

#define SEMAPHORE 2

int semid;

key_t key;

union _semun
{
    int val;               /* Value for SETVAL */
    struct semid_ds *buf;  /* Buffer for IPC_STAT, IPC_SET */
    unsigned short *array; /* Array for GETALL, SETALL */
    struct seminfo *__buf; /* Buffer for IPC_INFO
                              (Linux-specific) */
} semun;

struct sembuf sops[NUMBER_OF_SEMAPHORES];

const char *pathname = ".";

int main(int argc, const char *argv[])
{

    key = ftok(pathname, 'x');
    if (key == -1)
    {
        printf("Cannot create key !\n");
    }
    // Creating or Opening a Semaphore Set
    semid = semget(key, NUMBER_OF_SEMAPHORES, 0644 | IPC_CREAT);
    printf("%d \n", semid);
    if (semid == -1)
    {
        printf("Cannot create semaphores !\n");
    }
    // Semaphore Control Operations
    for (int i = 0; i < NUMBER_OF_SEMAPHORES; i++)
    {
        if (semctl(semid, 0, IPC_STAT, &semun.buf) == -1)
        {
            printf("Cannot create semaphores control!\n");
        }
    }

    /* Subtract 10 from semaphore 0 */
    sops[0].sem_num = SEMAPHORE;
    sops[0].sem_op = -10;
    sops[0].sem_flg = 0;

    /* Wait for semaphore 0 to equal 0 */
    // sops[0].sem_num = SEMAPHORE;
    // sops[0].sem_op = 0;
    // sops[0].sem_flg = 0;

    /* Add 10 to semaphore 0 */
    sops[0].sem_num = SEMAPHORE;
    sops[0].sem_op = 10;
    sops[1].sem_flg = 0;

    if (semop(semid, sops, 1) == -1)
    {
        printf("Cannot create semaphores operations!\n");
    }

    if (semctl(semid, 0, IPC_RMID, NULL) == -1)
    {
        printf("Cannot remove semaphores control !\n");
    }
    return 0;
}