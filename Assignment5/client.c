#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>

#define MSG     128


typedef struct msgbuf 
{
    long    mtype;
    char    mtext[MSG];
} message_buf;


int main()
{
    int msqid;
    key_t key=1234;
    message_buf  rbuf;

     msqid = msgget(key, 0666);

     msgrcv(msqid, &rbuf, MSG, 1, 0);

    printf("%s\n", rbuf.mtext);
     return 0;
}


