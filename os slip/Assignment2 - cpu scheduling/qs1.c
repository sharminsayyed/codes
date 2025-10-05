/*
slip 20,17,12,10,7,3, - 20m -Write the simulation program using FCFS. The arrival time and first CPU bursts of different jobs 
should be input to the system. Assume the fixed I/O waiting time (2 units). The next CPU burst 
should be generated using random function. The output should give the Gantt chart, Turnaround 
Time and Waiting time for each process and average times. 
*/

// fcfs algorithm the process are executed according to the burst time ss

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define maxprocess 5

struct process
{
    int pid, at, bt, st, ct, tat, wt;
};

int findshortestarrival(struct process p[], int n , int currenttime)
{
    int  minarrival =99999 ,shortestind = -1;
    for (int i = 0; i < n; i++)
    {
        if(p[i].at <= currenttime && p[i].ct == 0)
        {
           if(p[i].at < minarrival)
           {
               minarrival = p[i].at;
               shortestind = i;
           }
        }
    }
    return shortestind;
}

int getrandombt()
{
    return rand() % 10 + 1;
}

void display(struct process p[] ,int n)
{
    printf("\n pid\t at\t bt\t ct\t tat\t wt\t ");
    for ( int i = 0; i < n; i++)
    {
        printf("\n %d\t %d\t %d\t %d\t %d\t %d\t ", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
       
    }
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

int main()
{
    int n, i, j;
    int currenttime = 0, np = 0;

    printf("enter the number of processes :");
    scanf("%d", &n);
    struct process p[maxprocess];

    printf("enter the arrival time and burstt time for the process :\n");
    for (i = 0; i < n;i++)
    {
        p[i].pid = i + 1;
        printf("\n enter the arrival time  and burst time of P%d :", p[i].pid);
        scanf("%d%d", &p[i].at, &p[i].bt);
        p[i].ct = 0;
    }

    printf("\n gant chart : \n ");
    for (i = 0; i < n;i++)
    {
        np = findshortestarrival(p, n, currenttime);
        if(np == -1)
        {
            printf("idle->");
            currenttime++;
            i--;
            continue;
        }

        p[np].st = currenttime;
        p[np].ct = currenttime + p[np].bt;
        p[np].tat = p[np].ct - p[np].at;
        p[np].wt = p[np].tat - p[np].bt;

        printf("P%d->", p[np].pid);

        currenttime = p[np].ct;
        //   currenttime = p[np].ct +2;

        p[np].bt = getrandombt();
    }

    // display all the times
    display(p, n);

    // average times
    averagetimes(p, n);
}