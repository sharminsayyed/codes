#include<stdio.h>
int main(){
    int n, i, j, temp;
    int pid[10], bt[10], wt[10], tat[10];
    int twt=0, ttt=0;
    float awt = 0, atat = 0;

    printf("enter the no of proceses :");
    scanf("%d", &n);

    printf("enter the burst time for each process :");
    for (i = 0; i < n; i++){
        pid[i] = i + 1;
        printf("\np%d : ", i + 1);
        scanf("%d", &bt[i]);
    }

    // sort the burst time
    for (i = 0; i < n-1; i++){
        for (j = i + 1; j < n; j++){
            if(bt[i] > bt[j]){
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = pid[i];
                pid[i] = pid[j];
                pid[j] = temp;
            }
        }
    }

    //waiting time calculation
    wt[0] = 0;
    for (i = 1; i < n;i ++){
        wt[i] = wt[i - 1] + bt[i - 1];
        
       
    }

    // calculate the turn around time
    for (i = 0; i < n;i++){
        tat[i] = wt[i] + bt[i];
    }

        printf("Process\tBurst Time\tWaiting Time\tTurnAround Time\n ");
    for (i = 0; i < n;i++){
        printf("P%d\t\t", pid[i]);
        printf("%d\t\t", bt[i]);
        printf("%d\t\t", wt[i]);
        printf("%d\n", tat[i]);
        ttt += tat[i];
        twt += wt[i];
    }

    awt = (float)twt / (float)n;
    atat = (float)ttt / (float)n;

    printf("Average waiting time :%f \n Average Turn around time : %f \n", awt, atat);

    // print gant chart
    printf("Gant Chart :\n");
    for (i = 0; i < n; i++)
    {
        printf("P%d", pid[i]);
        if(i != n-1)
            printf("->");
    }

        return 0;


}