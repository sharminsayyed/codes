/*
Slip8 ,18 - 20m - Write a C program to accept the number of process and resources and find the need matrix 
content and display it.
*/

#include<stdio.h>

int main()
{
    int np, nr ,i,j;
    int max[10][10], alloc[10][10], need[10][10];

    printf("enter no of processes : ");
    scanf("%d", &np);
    printf("enter no of resources : ");
    scanf("%d", &nr);

    printf("enter the max matrix : \n");
    for (int i = 0; i < np; i++)
    {
        for (j = 0; j < nr;j++)
        {
            printf("Max[%d][%d] : ", i + 1, j + 1);
            scanf("%d", &max[i][j]);
        }
    }

    printf("enter the allocation matrix : \n");
    for (int i = 0; i < np; i++)
    {
        for (j = 0; j < nr;j++)
        {
            printf("Allocation[%d][%d] : ", i + 1, j + 1);
            scanf("%d", &alloc[i][j]);
        }
    }

    // calculation for neeed matrix 
    for (int i = 0; i < np; i++)
    {
        for (j = 0; j < nr;j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    // neeed matrix
    printf("\n Need Matrix: \n");
    for (i = 0; i < np;i++)
    {
        for (j = 0; j < nr;j++)
        {
            printf("%d \t", need[i][j]);
        }
        printf("\n");
    }
}