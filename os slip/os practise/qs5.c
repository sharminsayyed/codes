// fcfs
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define max_process 5
struct process{
    int pid, at, bt, st, ct, tat, wt;
};

int arrtime(struct process p[] ,int n ,int current_time){
    int minarr = 99999, shortestind = -1;
    for (int i = 0; i < n;i++){
        if(p[i].at <= current_time && p[i].ct == 0){
            if(p[i].at < minarr){
                minarr = p[i].at;
                shortestind = i;
            }
        }
    }
    return shortestind;
}

int getrandombt(){
    return rand() % 10 + 1;
}

void display(struct process p[] , int n){
    printf("\n\t pid\t at\t bt\t ct\t tat\t wt\t \n");
    for (int i = 0; i < n; i++){
        printf("\t %d\t %d\t %d\t %d\t %d\t %d\t \n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }
    
}

void averagetime(struct process p[] ,int n)
{
    float totaltat = 0, totalwt = 0;
    for (int i = 0; i < n; i++)
    {
        totaltat += p[i].tat;
        totalwt += p[i].wt;
    }
    printf("average tat : %f \n", (totaltat / n));
    printf("average wt : %f \n", (totalwt / n));

}
int main()
{
    int n,i,j;
    printf("enter no of process :");
    scanf("%d", &n);
    struct process p[n];
    for (i = 0; i < n;i++)
    {
        p[i].pid = i + 1;
        printf("enter the arrival time and burst time for P%d : ", p[i].pid);
        scanf("%d%d", &p[i].at, &p[i].bt);
        p[i].ct = 0;
    }

    int current_time = 0;
    int np = 0;

    for (i = 0; i < n;i ++)
    {
        np = arrtime(p, n, current_time);
        if(np == -1){
            current_time++;
            i--;
            continue;
        }
        p[np].st = current_time;
        // adding the 2 units of waiting time for i/o 
        // p[np].ct = current_time + p[np].bt+2;
         p[np].ct = current_time + p[np].bt;
        p[np].tat = p[np].ct - p[np].at;
        p[np].wt = p[np].tat - p[np].bt;

        printf("P%d%s", p[np].pid, (i < n - 1) ? "->" : " ");

        current_time = p[np].ct;
        // current_time = p[np].ct+2;

    }
    display(p, n);
    averagetime(p, n);

    for (i = 0; i < n;i ++)
    {
        p[i].bt = getrandombt();
    }
}

/*
enter no of process :4
enter the arrival time and burst time for P1 : 1 5
enter the arrival time and burst time for P2 : 0 6
enter the arrival time and burst time for P3 : 1 2
enter the arrival time and burst time for P4 : 0 4
P2 ->P4 ->P1 ->P3 ->
         pid     at      bt      ct      tat     wt
:        1       1       5       21      20      15
         2       0       6       8       8       2
         3       1       2       25      24      22
         4       0       4       14      14      10
average tat : 16.500000
average wt : 12.250000 */