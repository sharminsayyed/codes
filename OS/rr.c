#include<stdio.h>
int main(){
    int n, i;
    int p[10], bt[10], tat[10], wt[10], rt[10] ,ct[10];
    int time = 0, completed = 0 ,quant =0;
    int ttt = 0, twt = 0;
    float awt = 0, atat = 0;
    printf("enter the no of processes :");
    scanf("%d", &n);

    printf("enter burst time for each process :");
    for (i = 0; i < n;i++){
        p[i] = i + 1;
        printf("\n P%d :", p[i]);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
        wt[i] = 0;
        tat[i] = 0;
        ct[i] = 0;
    }

    printf("\n enter th qunatum time :");
    scanf("%d", &quant);

    printf("gantt chart :\n");

    while(completed < n){
        for (i = 0; i < n; i++){
            if(rt[i] > 0){
                if(rt[i] > quant){
                    printf("P%d ->", p[i]);
                    rt[i] -= quant;
                    time += quant;
                }
                else{
                    printf("P%d ->", p[i]);
                    time += rt[i];
                    ct[i] = time;
                    tat[i] = ct[i] - 0;// tat = completion time -arrival time;
                    wt[i] = tat[i] - bt[i];// wt = tat -bt
                    rt[i] = 0;
                    completed++;
                     
                }
            }
        }
    }

    printf("\nProcess\tBurst Time\tCompletion Time\t Waiting Time\tTurnaroundTime\n");
    for (i = 0; i < n;i++){
        printf("P%d\t\t", p[i]);
        printf("%d\t\t",bt[i]);
        printf("%d\t\t", ct[i]);
        printf("%d\t\t", wt[i]);
        printf("%d\n", tat[i]);

        ttt += tat[i];
        twt += wt[i];
    }

    awt = (float)twt / (float)n;
    atat = (float)ttt / (float)n;

    printf("Average waiting Time : %f \n Average TurnAround Time :%f \n", awt, atat);

    //bt = 5 7 3 , q =3

    return 0;
}