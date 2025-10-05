/*
Slip 18 -20m -Write the simulation program using SJF (non-preemptive). The arrival time and first CPU bursts of 
different jobs should be input to the system. The Assume the fixed I/O waiting time (2 units).The next 
CPU burst should be generated using random function. The output should give the Gantt chart, 
Turnaround Time and Waiting time for each process and average times. */

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define max_process 5
#define IOtime 2
struct process
{
    int pid;
    int at, bt, ct, tat, wt;
    int st;//start time 
};

int getbursttime(int cuurentbursttime)
{
    return cuurentbursttime + (rand() % 10) + 1;
}
int findshortestprocesS (struct process p[] , int n ,int currenttime)
{
    // minimum burstime
    int shortestind = -1, minbt = 99999;
    for ( int i = 0; i < n; i++)
    {
        if( p[i].at <= currenttime && p[i].ct == 0)
        {
            if(p[i].bt < minbt)
            {
                minbt = p[i].bt;
                shortestind = i;
            }
        }
    }

    return shortestind;
}
void display (struct process p[] , int n)
{
     printf("\n display all the times :");
    printf("\n pid\t at\t bt\t ct\t tat\t wt\t ");
    for ( int i = 0; i < n; i++)
    {
        printf("\n %d\t %d\t %d\t %d\t %d\t %d\t ", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
       
    }
   
}

void averagetime (struct process p[], int n)
{
     float totaltat = 0, totalwt;
     for ( int i = 0; i < n; i++)
    {
        totaltat += p[i].tat;
        totalwt += p[i].wt;
    }
     printf("\n average turaround time :%f ", totaltat / n);
      printf("\n average waiting  time :%f ", totalwt / n);
}
int main()
{
    // current time =0 nextprocess
    int ct = 0, np , n;
    int i, j;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct process p[max_process];
    printf("enter the arrival time and burst time for the processes :\n");

    for ( i = 0; i < n; i++)
    {
        p[i].pid = i + 1;
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &p[i].at);
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &p[i].bt);
        p[i].ct = 0;  
    }


    // calculate all the times  and dispaly gant chart
    printf("gant chart :\n");
    for ( i = 0; i < n; i++)
    {
        np = findshortestprocesS(p, n, ct);

        // if there is no process witth the shortes burst at the current time then increment the current time 
        if(np == -1)
        {
            // chatgpt
            ct++;
            i--; // Recheck the jobs in the next cycle
            continue;
        }

        p[np].st = ct;
        p[np].ct = ct + p[np].bt;
        p[np].tat = p[np].ct - p[np].at;
        p[np].wt = p[np].tat - p[np].bt;

        printf("p%d-> ", p[np].pid);
        // adding the complition time to current time to again check for the shortest bt
        ct = p[np].ct ;
        // ct =p[np].ct+2;
        p[np].bt = getbursttime(p[np].bt);
    }

    // printing all times
    display(p, n);

    // calculating averages
    averagetime(p, n);
}
