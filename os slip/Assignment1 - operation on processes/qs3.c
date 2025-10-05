/*
Slip3 - 10m -  Creating a child process using the command exec(). Note down process ids of the parent 
and the child processes, check whether the control is given back to the parent after the child 
process terminates. 
*/

/*
In the context of the exec() family of system calls, there are several variations, such as execl(), execp(), execv(), execvp(), etc.
Each of these functions serves a similar purpose (replacing the current process image with a new program),but they differ in how they
accept arguments.
The reason we don't just use exec() directly is that exec() is not a complete function by itself. Instead, it is a family of functions
(like execl(), execp(), execlp(), etc.) that offer different ways to execute a new program.

The <sys/wait.h> header and related functions like fork(), wait(), and execl() are part of the POSIX standard,
which is typically available on Unix-like systems (Linux, macOS). However,Windows does not natively support these POSIX APIs.*/

#include <stdio.h>    // Includes the standard input-output library
#include<stdlib.h> // for exit(1)
#include <unistd.h>   // Includes POSIX API declarations like fork() and execl()
#include <sys/types.h> // For defining data types like pid_t
// #include <sys\wait.h> // For wait() to make the parent process wait for child termination

int main()
{
    pid_t pid = fork();
    if(pid < 0)
    {
        perror("failed process");
        exit(1);  
    }
    if(pid ==0 )
    {
        printf("child process id :%d\n ", getpid());
        // execl() replaces the current process image with a new process image, in this case, the 'ls' command.
        // "/bin/ls" is the path to the `ls` command, used to list directory contents.
        execl("/bin/ls", "ls", NULL);
        perror("execl failed");
        return 1;
        // exit(1);
    }
    else
    {
        printf("parent process id :%d \n", getpid());
        // wait() makes the parent process wait until the child process finishes.
         // The parent waits for the child process to terminate, preventing the parent from terminating first.
        wait(NULL);
        printf("child process has been terminated or completed and control bakk to parent process\n");
    }
    return 0;
}
/*
parent process id :260410 
child process id :260411
main  main.c
child process has been terminated or completed and control bakk to parent process

*/
