/*
slip 7,9,15,19,20 - 10m - Write a program to create a child process using fork().The parent should goto sleep state and 
child process should begin its execution. In the child process, use execl() to execute the “ls” 
command.
*/
//  visit qs 3 for more details 

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
    pid_t pid = fork();
    if(pid <0 )
    {
        perror("process failed");
        exit(1);
    }
    if(pid == 0)
    {
        printf("child process \t process id :%d \n", getpid());

        execl("/bin/ls", "ls", NULL);

        perror("execl failed");
        exit(1);
        // This line will never be executed if execl() is successful
        printf("Child process execution completed \n");
    }
    else
    {
        printf("parent process \t process is: %d \n", getpid());
        printf("parent process sleeps for 5 seconds \n");
        sleep(5);
        printf("parent process woked up and terminated \n");
    }

    return 0;
}