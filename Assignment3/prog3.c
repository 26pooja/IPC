#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<fcntl.h>
int main(int argc,char *argv[])
{
int status;
pid_t pid;
int pipe_id[2];
char buff[256];
if(pipe(pipe_id)==-1)
   printf("pipe not created");


if(fork() == 0)
{	
	printf("Child process running\n");
      write(pipe_id[1],"hello",5);
	
        
	
	return 1;
}
else
{
printf("Parent process running\n");
read(pipe_id[0],buff,5);
printf("\n%s\n",buff);
}
pid = wait(&status);


return 0;
}
