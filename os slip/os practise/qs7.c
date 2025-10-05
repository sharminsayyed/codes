// round robin 
#include<stdio.h>
#include<stdbool.h>
struct process{
    int pid, at, bt, rt, ct, tat, wt;
};

int getrandombt(){
    return rand() % 10 + 1;
}
void display(struct process p[] , int n){
    float totaltat = 0, totatlwt = 0;
    printf("\n pid\t at\t bt\t ct\t tat\t wt\t \n");
    for (int i = 0; i < n;i++){
        printf("\n %d\t %d\t %d\t %d\t %d\t %d\t",p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
        totaltat += p[i].tat;
        totatlwt += p[i].wt;
    }
    printf("average tat : %f\n", (totaltat / n));
    printf("average wt : %f\n", (totatlwt / n));
}
int main(){
    int n ,i,j;
    printf("enter the no of processes  :");
    scanf("%d", &n);
    struct process p[n];
    for (i = 0; i < n; i++){
        p[i].pid = i + 1;
        printf("enter the arrival and burst time for P%d :", p[i].pid);
        scanf("%d%d", &p[i].at, &p[i].bt);
        p[i].ct = 0;
        p[i].rt = p[i].bt;
    }
    int tq;
    printf(" \nenter the time quantum :");
    scanf("%d", &tq);

    bool done;
    int ct = 0;

    printf("gant chart :\n");
    while(1){
        done = true;
        for (i = 0; i < n; i++){
            if(p[i].rt > 0 && p[i].at <= ct){
            done = false;
                if(p[i].rt > tq ){
                    ct += tq;
                    p[i].rt = p[i].rt - tq;
                    printf("P%d ->", p[i].pid);
                }
                else{
                    ct += p[i].rt;
                    p[i].ct = ct;
                    // p[i].ct = ct+2;
                    p[i].tat = p[i].ct - p[i].at;
                    p[i].wt = p[i].tat - p[i].bt;
                    p[i].rt = 0;
                    printf("P%d ->", p[i].pid);
                }
            }
        }
        if(done == true)
            break;
    }
    display(p,n);

    // generate the cpu bt
    for (i = 0; i < n;i++){
        p[i].bt = getrandombt();
        p[i].rt = p[i].bt;
    }

        return 0;
}
