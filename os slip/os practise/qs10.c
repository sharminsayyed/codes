// priority scheduling non preemptive 
#include<stdio.h>
#include<stdlib.h>
struct process {
    int pid, at, bt ,p,st, ct, tat, wt;
};

int priority(struct process p[] , int n , int ct){
    int minp = 99999, ind = -1;
    for (int i = 0; i < n;i++){
        if(p[i].at <= ct && p[i].ct == 0){
            if(p[i].p < minp){
                minp = p[i].p;
                ind = i;
            }
        }
    }
    return ind;
}


int main(){
    int n, i;
    printf("enter the no of processes : ");
    scanf("%d", &n);
    struct process p[n];
    for (i = 0; i < n; i++){
        p[i].pid = i + 1;
        printf("enter the arrival time , burst time  and priority of P%d :", p[i].pid);
        scanf("%d%d%d", &p[i].at, &p[i].bt, &p[i].p);
        p[i].ct = 0;
    }

    int ct = 0 ,np;
    printf("gant chart : \n");
    for (int i = 0; i < n; i++){
        int np = priority(p, n, ct);
        if(np == -1){
            printf("idle ->");
            ct++;
            continue;
        }
        p[np].st = ct;
        p[np].ct = ct + p[np].bt;
        p[np].tat = p[np].ct - p[np].at;
        p[np].wt = p[np].tat - p[np].bt;

        printf("P%d%s", p[np].pid, (i < n - 1) ? "->" : " ");
        ct = p[np].ct;
    }

    // display(p, n);
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