/*
*/

/*
Type Mismatch: The clock() function returns a value of type clock_t (usually defined as long), not int. 
To avoid issues with type mismatch and to handle large clock values correctly, you should declare clock1 and clock2 as clock_t rather than int.

Time Units: The clock() function returns the processor time in clock ticks, and to get the time in seconds, you should divide 
the difference by CLOCKS_PER_SEC.*/

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<time.h>
int main()
{
    pid_t pid =fork();
    clock_t clock1 = clock();
    if(pid == 0)
    {
        printf("child process \n");
    }
    else
    {
        printf("parent process\n ");
    }
    clock_t clock2 = clock();
    double time  = (double) (clock2 - clock1) / CLOCKS_PER_SEC;
    printf("time taken for execution in seconds :%F \n",time);
    return 0;
}
/*
parent process
time taken for execution in seconds :0.000028 
child process 
time taken for execution in seconds :0.000032 
*/

// or
#include<stdio.h>
#include<time.h>

int main()
{
    clock_t clock1 = clock();
    int sum =0;
    for(int i =1 ;i<100000 ; i++)
    {
        sum += i;
    }
    clock_t clock2 = clock();
    double time = (double)(clock2 - clock1)/CLOCKS_PER_SEC;
    
    printf("time for execution in seconds :%f",time);
    return 0;
}
// time for execution in seconds :0.000208