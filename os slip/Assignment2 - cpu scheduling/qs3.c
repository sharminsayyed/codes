/*
slip 19 -20m - Write the program to simulate Non-preemptive Priority scheduling. The arrival time and 
first CPU burst and priority for different n number of processes should be input to the algorithm. 
Assume the fixed IO waiting time (2 units). The next CPU-burst should be generated randomly. 
The output should give Gantt chart, turnaround time and waiting time for each process. Also find 
the average waiting time and turnaround time. */

// arrival time and prioority

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define max_process 5
struct process
{
    int pid, at, bt, p, st, ct, tat, wt;
};

int findshortestpriority(struct process p[], int n, int currenttime)
{
    int minpriority = 999999;
    int shortestind = -1;
    for (int i = 0; i < n; i++)
    {
        if(p[i].at <= currenttime && p[i].ct == 0)
        {
            if(p[i].p < minpriority)
            {
                minpriority = p[i].p;
                shortestind = i;
            }

        }
    }
    return shortestind;
}

void averagetimes(struct process p[], int n)
{
    float totalwt = 0, totaltat = 0;
    for (int i = 0; i < n;i++)
    {
        totaltat += p[i].tat;
        totalwt += p[i].wt;
    }
    printf("\n average waiting time : %f ", totalwt / n);
    printf("\n average turnaround time : %f ", totaltat / n);
}

void display(struct process p[] ,int n)
{
    printf("\n pid\t at\t bt\t ct\t tat\t wt\t ");
    for ( int i = 0; i < n; i++)
    {
        printf("\n %d\t %d\t %d\t %d\t %d\t %d\t ", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
       
    }
}
int generaterandombt ()
{
    return rand() % 10 + 1;
}
int main()
{
    int n, i, j;
    int ct = 0, np;

    struct process p[max_process];
    printf("enter the number of processes :");
    scanf("%d", &n);
    for (i = 0; i<n ; i++)
    {
        p[i].pid = i + 1;
        printf("emter the arrival time , burst time, priority of the process %d:",p[i].pid);
        scanf("%d%d%d", &p[i].at, &p[i].bt, &p[i].p);
        p[i].ct = 0;
    }

    // display gant chart calculate al the times
    for (i = 0; i < n;i++)
    {
        np = findshortestpriority(p, n, ct);
        if(np ==-1)
        {
            printf("idle->");
            ct++;
            continue;
        }

        p[np].st = ct;
        p[np].ct = ct +p[np].bt;
        p[np].tat = p[np].ct - p[np].at;
        p[np].wt = p[np].tat - p[np].bt;

        printf("P%d->", p[np].pid);

        ct = p[np].ct;
        // ct = p[i].ct +2;

        p[np].bt = generaterandombt();
    }


    //display all the times
    display(p,n);
    // generate the avergae time
    averagetimes(p, n);
}