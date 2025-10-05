/*
slip 20,17,12,10,7,3, - 20m -Write the simulation program using FCFS. The arrival time and first CPU bursts of different jobs 
should be input to the system. Assume the fixed I/O waiting time (2 units). The next CPU burst 
should be generated using random function. The output should give the Gantt chart, Turnaround 
Time and Waiting time for each process and average times. 
*/

// fcfs algorithm the process are executed according to the burst time 

#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#define max_process 5
#define IOTime 2
struct process
{
    int pid;
   int at, bt, ct, wt, tat;
};

int getnextbursttime()
{
    // rand() function generates the pseudo random number 
    // rand() % 10 produces a random number between 0 and 9, because the result of rand() % 10 is the remainder when the random number is divided by 10.
    // rand()%10 + 1 gives range 1-10
    return rand() % 10 + 1;
}

void completiontime (struct process p[],int n)
{
    // for the first process beacuse it is sorted so the process with least arrival time is at index 0
    p[0].ct = p[0].at + p[0].bt;
    for (int i = 1; i < n;i++)
    {
        // ct = ct time of previous proceess + burstime of cuurent process
        p[i].ct = p[i - 1].ct + p[i].bt +IOTime;
    }
}

void waitingtime(struct process p[] , int n)
{
    for (int i = 0; i < n;i ++)
    {
        p[i].wt = p[i].tat - p[i].bt;
    }
}

void turnaroundtime(struct process p[], int n)
{
    for (int i = 0; i < n; i++)
    {
        p[i].tat = p[i].ct - p[i].at;
    }
}

void display(struct process p[] ,int n)
{
    printf("\n");
    printf("\npid\tat\tbt\tct\ttat\twt");
    for (int i = 0; i < n;i++)
    {
        printf("\nP%d \t %d \t%d \t%d \t%d \t%d ", p[i].pid, p[i].at, p[i].bt,p[i].ct,p[i].tat,p[i].wt);
    }
}

void average(struct process p[], int n)
{   float totaltat = 0;
    float totalwt = 0;
    for (int i = 0; i < n;i++)
    {
        totaltat += p[i].tat;
        totalwt += p[i].wt;
    }
    printf("\naverage turnaround time : %f \n", totaltat/n);
    printf("average waiting time : %f \n", totalwt/n);
}

void ganttchart(struct process p[] , int n)
{
    printf("\n gantt charrt :\n");
    for (int i = 0; i < n;i++)
    {
        printf("|\tP%d\t", p[i].pid);
    }
    printf("|\n");
    printf("0");
    for (int i = 0; i < n;i++)
    {
        printf("\t\t%d", p[i].ct);
    }
}
int main()
{
    int n, i,j;
    printf("enter the no of process :");
    scanf("%d", &n);

    struct process p[max_process];

    printf("enter the arrival time for the processes :\n");
    for (i = 0; i < n ;i++)
    {
        p[i].pid = i + 1;
        printf("\n Arrival time for P%d: ", p[i].pid);
        scanf("%d", &p[i].at);
        printf("Burst Time for P%d:", p[i].pid);
        scanf("%d", &p[i].bt);
    }

    // sort the process according to the arrival time
    for ( i = 0; i < n - 1;i++)
    {
        for (j = i + 1; j < n;j++)
        {
            if(p[i].at > p[j].at)
            {
                struct process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
            else if(p[i].at == p[j].at && p[j].pid < p[i].pid)
            {
                struct process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    

    // calculate all the completion time
    completiontime(p, n);

    // claculate turnaround timee
    turnaroundtime(p, n);

    // calculate waiting time
    waitingtime(p, n);

    //display gantt chart
    ganttchart(p, n);

    // display all the times
    display(p, n);
    
    // claculating average tat and wt
    average(p, n);

    for (i = 0; i < n;i++)
    {
        p[i].bt = getnextbursttime();
    }
}
