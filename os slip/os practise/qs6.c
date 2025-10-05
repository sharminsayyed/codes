// sjf 
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int getrandombt(){
    return rand() % 10 + 1;
}
struct process{
    int pid, at, bt, st, ct, tat,wt;
};

int shortestbt(struct process p[] , int n , int ct){
    int minbt = 99999, shortestind = -1;
    for (int i = 0; i < n;i++){
        if(p[i].at <= ct && p[i].ct == 0){
            if(p[i].bt < minbt){
                minbt = p[i].bt;
                shortestind = i;
            }
        }
    }
    return shortestind;
}

void display(struct process p[] , int n){
    printf("\n pid\t at\t bt\t ct\t tat\t wt\t \n");
    float totaltat = 0, totalwt = 0;
    for (int i = 0; i < n;i++){
        printf("\n %d\t %d\t %d\t %d\t %d\t %d\t \n", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
        totaltat += p[i].tat;
        totalwt += p[i].wt;
    }
    printf("average tat : %f \n", (totaltat / n));
    printf("average wt : %f \n", (totalwt / n));
}
int main(){
    int n, i, j;
    printf("enter the no of processes  :");
    scanf("%d", &n);
    struct process p[n];
    for (i = 0; i < n;i++){
        p[i].pid = i + 1;
        printf("enter the arrival time and burst time for P%d :", p[i].pid);
        scanf("%d%d", &p[i].at, &p[i].bt);
        p[i].ct = 0;
    }

    int current_time = 0, np = 0;
    printf("gant chart : \n");
    for (i = 0; i < n; i++){
        np = shortestbt(p, n, current_time);
        if(np == -1){
            current_time++;
            i--;
            continue;
        }
        p[np].st = current_time;
        // p[np].ct = current_time + p[np].bt+2;
        p[np].ct = current_time + p[np].bt;
        p[np].tat = p[np].ct - p[np].at;
        p[np].wt = p[np].tat - p[np].bt;
        printf("P%d%s", p[np].pid, (i < n - 1) ? "->" : " ");
        current_time = p[np].ct;
    }
    display(p, n);

    for (i = 0; i < n;i++){
        p[i].bt = getrandombt();
    }
}