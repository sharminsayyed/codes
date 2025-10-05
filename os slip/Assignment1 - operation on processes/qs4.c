/*
slip 4 ,10,12 - 10m -Write a program to illustrate the concept of orphan process ( Using fork() and sleep())
*/

/*
The parent process sleeps for 5 seconds and terminates. During this time, the child process will still be running and will become an orphan.
The child process sleeps for 10 seconds, so by the time it wakes up and finishes, the parent process has already terminated.
As a result, the child process becomes an orphan and is adopted by the init process.

In this case, when the parent process terminates, the child process becomes an orphan and is adopted by init.
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
    pid_t pid = fork();
    if(pid < 0)
    {
        perror("process failed ");
        exit(1);
    }
    if(pid == 0)
    {
        printf("child process pid :%d \n", getpid());
        sleep(10);
        printf(" \n child process is terminated\n");
    }
    else
    {
        printf("parent proces pid :%d \n", getpid());
        sleep(5);
        printf("parent process is terminated \n");
    }
    return 0;
}

/*
parent proces pid :302400 
child process pid :302401 
parent process is terminated 
child process is terminated
*/