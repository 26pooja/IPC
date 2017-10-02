#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

#define SHMSZ     27

int main()
{
    char c;
    int shmid;
    key_t key;
    char *shm, *s;

    key = 5678;

    shmid = shmget(key, SHMSZ, IPC_CREAT | 0666);
       

    shm = shmat(shmid, NULL, 0);
       
    s = shm;

    for (c = 'a'; c <= 'z'; c++)
        *s++ = c;
    *s = (char *)NULL;

    while (*shm != '*')
        sleep(1);

    return 0;
}


