#include<stdio.h>
int main(){
    int i;
    int n;
    int pid[5],bt[5],wt[5];
    int ttt, twt;
    float awt = 0, atat = 0;
    printf("enter the no of procsses :"); // 3
    scanf("%d", &n);
    printf("enter the process id of each process :"); // 1 2  3 
    for(i = 0; i<n; i++){
        scanf("%d", &pid[i]);
    }
    printf("enter the burst time for each process :"); // 5 11 11 
    for(i = 0; i < n;i++){
        scanf("%d", &bt[i]);
    }
    wt[0] = 0;
    for(i = 1; i < n; i++){
        wt[i] = bt[i - 1] + wt[i - 1];
    }
    printf("process id\tburst time\twaiting time\tturnaaround time\n");
    for(i = 0; i < n; i++){
        printf("P%d \t\t", pid[i]);
        printf("%d \t\t", bt[i]);
        printf("%d \t\t", wt[i]);
        printf("%d \n", (bt[i] +wt[i]));
        ttt += (bt[i] + wt[i]);
        twt += wt[i];
    }
    awt = (float)twt / (float)n;
    atat = (float)ttt / (float)n;
    printf("Average waiting time : %f \n Average Turn Around Time : %f \n", awt, atat);

    // print gantt chart
    printf("Gantt chart  :\n");
    for (i = 0; i < n;i++){
        printf("P%d ", pid[i]);
        if(i != n-1)
            printf("->");
    }
        return 0;
}