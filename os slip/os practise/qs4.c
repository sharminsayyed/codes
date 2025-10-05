// bankers algorithm 
#include<stdio.h>
#include<stdbool.h>
#define np 5 
#define nr 4
void calculate_need(int alloc[np][nr] , int max[np][nr] ,int need[np][nr]){
    for (int i = 0; i < np; i++){
        for (int j = 0; j < nr; j++){
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
}

void print_need(int need[np][nr]){
    printf("need matrix :\n");
    for (int i = 0; i < np; i++){
        for (int j = 0; j < nr; j++){
            printf("%d \t", need[i][j]);
        }
        printf("\n");
    }
}

bool isSafe(int alloc[np][nr] ,int max[np][nr], int avail[nr]){
    int need[np][nr];
    int work[nr];
    int safeseq[np];
    bool finish[np] = {false};
    int i, j;

    calculate_need(alloc, max, need);

    for (i = 0; i < nr; i++)
        work[i] = avail[i];

    int count = 0;
    while(count < np){
        bool found = false;
        for (i = 0; i < np;i++){
            if(finish[i] == false){
                bool canallocate = true;
                for (j = 0; j < nr; j++){
                    if(need[i][j] > work[j]){
                        canallocate = false;
                        break;
                    }
                }
                if(canallocate){
                    for (int k = 0; k < nr; k++){
                        work[k] += alloc[i][k];
                    }
                    safeseq[count] = i;
                    count++;
                    finish[i] = true;
                    found = true;
                }
            }
        }
        if(found == false){
            printf("System is not in safe state \n");
            return false;
        }
    }

    printf("\nsystem is in a safe state \nsafe sequence :\n");
    for (i = 0; i < np; i++){
        printf("P%d%s", safeseq[i], (i < np - 1) ? "->" : " ");
    }

    return true;
}


bool reqResources(int process , int req[nr] , int alloc[np][nr], int max[np][nr], int avail[nr]){
    int need[np][nr];
    int i;
    calculate_need(alloc, max, need);

    //req > need
    for (i = 0; i < nr; i++){
        if(req[i] > need[process][i]){
            printf("error : process has exceeded its maximum limit ");
            return false;
        }
    }

    // req > avail
    for (i = 0; i < nr; i++){
        if(req[i] > avail[i]){
            printf("\nerror :resources are not available yet have to wait");
            return false;
        }
    }

    // assume if the req granted
    for (i = 0; i < nr; i++){
        avail[i] -= req[i];
        need[process][i] -= req[i];
        alloc[process][i] += req[i];
    }

    if(isSafe(alloc,max,avail)){
        printf("request are granted to the process immmediately");
        return true;
    }
    else{
        for (i = 0; i < nr; i++){
            avail[i] += req[i];
            need[process][i] += req[i];
            alloc[process][i] -= req[i];
        }
        printf("\nRequest cannot be granted  for the process %d", process);
        return false;
    }
}

int main()
{
    int alloc[np][nr] = { {0, 0, 1, 2}, {1, 0, 0, 0}, {1, 3, 5, 4}, {0, 6, 3, 2}, {0, 0, 1, 4} };
    int max[np][nr] = {{0, 0, 1, 2}, {1, 7, 5, 0}, {2, 3, 5, 6}, {0, 6, 5, 2}, {0, 6, 5, 6}};
    int avail[nr] = {1, 5, 2, 0};
    int need[np][nr];

    calculate_need(alloc, max, need);
    print_need(need);

    isSafe(alloc, max, avail);

    int req[nr] = {0, 4, 2, 0};
    reqResources(0, req, alloc, max, avail);

    return 0;
}