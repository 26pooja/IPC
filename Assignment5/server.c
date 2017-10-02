#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>

#define MSG     128



typedef struct msgbuf 
{
    long    mtype;
    char    mtext[MSG];
} message_buf;

int main()
{
    int msgid;
    key_t key=1234;
    message_buf sbuf;
    int buf_length;

   

     msgid = msgget(key, IPC_CREAT | 0666);
    
     sbuf.mtype = 1;
    
     strcpy(sbuf.mtext, "Hello World!!!");
    
     buf_length = strlen(sbuf.mtext) + 1 ;
    
     msgsnd(msgid, &sbuf, buf_length, IPC_NOWAIT);
     
     return 0;
        
}

