// need matrix
#include<stdio.h>
#include<stdlib.h>
int main(){
    int alloc[5][4] = {
        {1, 2, 0, 2}, {2, 3, 0, 0}, {2, 1, 3, 0}, {1, 2, 1, 0}, {2, 3, 1, 0}};
    int max[5][4] = {
        {2, 2, 0, 2}, {2, 3, 1, 1}, {2, 1, 3, 1}, {1, 2, 3, 4}, {2, 3, 1, 4}};
    

    int need[5][4];
    for (int i = 0; i < 5;i++)
    {
        for (int j = 0; j < 4; j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
            printf("%d \t", need[i][j]);
        }
        printf("\n");
    }
}
