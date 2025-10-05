/*
slip 2 ,11- 10m -Create a child process using fork(), display parent and child process id. Child process will 
display the message “Hello World” and the parent process should display “Hi”. 
[10 marks] */

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>

int main()
{
    pid_t pid = fork();
    if(pid < 0)
    {
        perror("\nfailed process");
        exit(1);
    }
    if(pid == 0)
    {
        printf(" child process pid :%d \n Hello  worldd", getpid());
    }
    else
    {
        printf(" parent process pid = %d \n Hii \n ", getpid());
    }
    return 0;
}
/*
parent process pid = 120056 
 Hii 
 child process pid :120057 
 Hello  worldd
 */