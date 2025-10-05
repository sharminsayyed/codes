// fcfs 
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct process{
    int pid, at, bt,rt ,ct, tat, wt;
};



void display(struct process p[] , int n){
    float ttat = 0, twt = 0;
    printf("\n pid\t at\t bt\t ct\t tat\t wt\t \n");
    for (int i = 0; i < n;i++){
        printf("\n %d\t %d\t %d\t %d\t %d\t %d\t ", p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
        ttat += p[i].tat;
        twt += p[i].wt;
    }
    printf("a tat :%f \n", (ttat / n));
    printf("a wt :%f \n", (twt / n));
}
int main(){
    int n, i, j;
    printf("no of p:");
    scanf("%d", &n);
    struct process p[n];
    for (int i = 0; i < n;i++){
        p[i].pid = i + 1;
        printf("at and bt P%d:", p[i].pid);
        scanf("%d%d", &p[i].at, &p[i].bt);
        p[i].rt = p[i].bt;
        p[i].ct = 0;
    }

    int tq;
    printf("enter tq :");
    scanf("%d", &tq);

    int ct = 0;
    bool found;

    printf("gant chart \n");
    while(1){
        found = false;
        for (int i = 0; i < n;i++){
            if(p[i].rt > 0 && p[i].at <= ct){
                found = true;
                if(p[i].rt > tq){
                    ct += tq;
                    p[i].rt = p[i].rt - tq;
                    printf("P%d ->", p[i].pid);
                }
                else{
                    ct += p[i].rt;
                    p[i].ct = ct;
                    p[i].tat = p[i].ct - p[i].at;
                    p[i].wt = p[i].tat - p[i].bt;
                    p[i].rt = 0;
                    printf("P%d ->", p[i].pid);
                }
            }
        }
        if(found == false)
            break;
    }
    display(p, n);
}
