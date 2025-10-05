/*
Slip 1,5,13 - 10m - Write a program that demonstrates the use of nice() system call. After a child process is started 
using fork(), assign higher priority to the child using nice() system call. 
*/

// pid_t = datatype  to store the processid  present in #include<sys/types.h>
// nice() = in nice system call a new priority number is added to the already existing one 
// +19 lowest priority  -20 highest priority
//to change the priority of the child to a higher priority (nice(-7)) and the parent to a lower priority (nice(15)).

#include <unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>

int main() {
    pid_t pid;
    pid = fork();
    if(pid <0 )
    {
        perror("failed process");
        exit(1);
    }
    if(pid == 0)
    {
        printf("\ni am child process \t process id :%d", getpid());
        printf("\npriority of child process :%d", nice(4));
    }
    else
    {
        printf("\n i am parent process \t process id :%d", getpid());
        printf("\npriority of parent process :%d", nice(15));
    }
    return 0;
}

/*
i am parent process 	 process id :81927
priority of parent process :15
i am child process 	 process id :81928
priority of child process :4
*/