#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>
#include<sys/stat.h>
#include<fcntl.h>
int main()
{
     int ret,fd;
     char buff[256]="Hello_world";
     ret= mkfifo("demo",0666);
     fd=open("demo",O_WRONLY);
     write(fd,buff,11);
     close(fd);
     return 0;
        
}

