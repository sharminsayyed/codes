/*
slip 17 -10 -Write the program to calculate minimum number of resources needed to avoid 
deadlock. */

/*
Here’s the program to calculate the minimum number of resources needed to avoid deadlock based on the formula:
R≥(sum of maximum demands of all processes)−(number of processes−1)*/
#include<stdio.h>
int main()
{
    int np, nr;
    int i, j;
    printf("enter no of processes : ");
    scanf("%d", &np);
    printf("enter the no of resorces :");
    scanf("%d", &nr);

    int max[10][10];
    int sumofmax = 0;

    printf("enter the max matrix : \n");
    for (int i = 0; i < np; i++)
    {
        for (j = 0; j < nr;j++)
        {
            printf("Max[%d][%d] : ", i + 1, j + 1);
            scanf("%d", &max[i][j]);
            sumofmax += max[i][j];
        }
    }

    int min_resources = sumofmax - (np - 1);
    printf("\nMinimum number of resources needed to avoid deadlock: %d\n", min_resources);
}