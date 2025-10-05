/*
Slip9 - 20m
Write the program to simulate Round Robin (RR) scheduling. The arrival time and first CPU- 
burst for different n number of processes should be input to the algorithm. Also give the time 
quantum as input. Assume the fixed IO waiting time (2 units). The next CPU-burst should be 
generated randomly. The output should give Gantt chart, turnaround time and waiting time for each 
process. Also find the average waiting time and turnaround time.
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#define max_process 5

struct process
{
    int pid, at, bt, rt, ct, tat, wt;
};

int getrandombt()
{
    return rand() % 10 + 1;
}
int main()
{
    int n, i, j;
    printf("enter the no of process :");
    scanf("%d", &n);

    struct process p[max_process];
    printf("enter the arrival time nd burst time for the process :");
    for ( i = 0; i < n; i++)
    {
        p[i].pid = i + 1;
        printf("Arrival time and Burst time for P%d :" ,p[i].pid);
        scanf("%d%d", &p[i].at, &p[i].bt);
        p[i].rt = p[i].bt;
        p[i].ct = 0;
    }

    // include the time qunatum 
    int timequantum;
    printf("enter the time quantum:");
    scanf("%d", &timequantum);


// gant chart and calculate times 
    int ct = 0;
    bool done;

    printf("gant chart :\n ");
    while(1){
        done = true;
        for ( i = 0; i < n; i++){
            if(p[i].rt > 0 && p[i].at <= ct){
                done = false;
                if(p[i].rt > timequantum){
                    ct += timequantum;
                    p[i].rt = p[i].rt - timequantum;
                    printf("->P%d", p[i].pid);
                }
                else{
                    ct += p[i].rt;
                    p[i].ct = ct;
                    // p[i].ct = ct +2;
                    p[i].tat = p[i].ct - p[i].at;
                    p[i].wt = p[i].tat - p[i].bt;
                    p[i].rt = 0;
                    printf("- >P%d", p[i].pid);
                }
            }
        }
        if(done == true)
            break;
    }

    // display the times 
    float totaltat = 0, totalwt = 0;

    printf("display all the times : \n");
    printf("Pid \tat \tbt \tct \ttat \twt \n");
    for ( i = 0; i < n; i++)
    {
        printf("%d \t%d \t%d \t%d \t%d \t%d \n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
        totaltat += p[i].tat;
        totalwt += p[i].wt;
    }

    printf("average tat :%.2f \n", totaltat / n);
     printf("average wt :%.2f \n", totalwt / n);


    // generate the next cpu burst randomly 
    for ( i = 0; i < n; i++)
    {
        p[i].bt = getrandombt();
        p[i].rt = p[i].rt;
    }
    return 0;
}