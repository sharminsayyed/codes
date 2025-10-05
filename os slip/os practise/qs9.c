// deadlock 
#include<stdio.h>
#include<stdlib.h>
int main(){
    int np, nr;
    int sum_max[10], max[10][10], total_minr = 0;
    printf("enter the no of processes and resources :");
    scanf("%d %d", &np, &nr);

    printf("enter the max matrix (%d * %d):",np,nr);
    for (int i = 0; i < np;i ++){
        sum_max[i] = 0;
        for (int j = 0; j < nr; j++){
            scanf("%d", &max[i][j]);
            sum_max[i] += max[i][j];
        }
    }

    for (int j = 0; j < nr; j++){
        int max_demand = 0;
        for (int i = 0; i < np;i++){
            if(max[i][j] > max_demand){
                max_demand = max[i][j];
            }
        }
        total_minr += max_demand;
    }

    total_minr = total_minr - (np - 1);
    printf("the minimum no of resources required to avoid deadlock is : %d", total_minr);
}