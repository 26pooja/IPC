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
     char buff[256];
     ret= mkfifo("demo",0666);
     fd=open("demo",O_RDONLY);
     read(fd,buff,11);
     
      printf("\n%s",buff);
      
     close(fd);
     return 0;
        
}

