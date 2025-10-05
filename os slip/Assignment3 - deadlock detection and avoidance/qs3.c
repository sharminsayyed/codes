/*
Slip 19 ,1,4,13  -20m -
Write a C program to simulate Banker’s algorithm for the purpose of deadlock 
avoidance. Consider the following snapshot of system, A, B, C and D are the resource type.
a) Calculate and display the content of need matrix? 
b) Is the system in safe state? If display the safe sequence. 
c) If a request from process P arrives for (0, 4, 2, 0) can it be granted immediately by keeping the 
system in safe state. Print a message 
*/
// avail[r] max[p][r] alloc[p][r] need[p][r] 

#include<stdio.h>
#include<stdbool.h>
#define np 5
#define nr 4

void calculateneedmatrix (int need[np][nr] ,int max[np][nr], int alloc[np][nr])
{
    for (int i = 0; i < np;i++)
    {
        for (int j = 0; j < nr;j++)
        {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

}

void printneed(int need[np][nr])
{
    printf("display need matrix :\n");
    for (int i = 0; i < np; i++)
    {
        for (int j = 0; j < nr; j++)
        {
            printf("%d \t", need[i][j]);
        }
        printf("\n");
    }
}



bool isSafe(int max[np][nr], int alloc[np][nr] ,int avail[nr])
{
    int need[np][nr];
    bool finish[np] = {false};
    int work[nr];
    int safeseq[np];

    calculateneedmatrix(need, max, alloc);

    for (int i = 0; i < nr; i++)
    {
        work[i] = avail[i];
    }

    int count = 0;
    // this count is used to save the process execution order -- safeseq 
    // run until count =  no of process -1
    while(count < np)
    {
        // means a process has not been executed
        bool found = false;
        // checking for each process
        for (int i = 0; i < np; i++)
        {
            // if the process has not been finished 
            if(finish[i] == false)
            {
                // it can be allocated the rsources it needs 
                bool canallocate = true;

                // checking if the resources can be allocated to a particular process 
                for (int j = 0;j< nr; j++)
                {
                    // if need of the process > than the availabe  
                    if(need[i][j] > work[j])
                    {
                        // it cannot be allocated and has to wait until the resouces are available 
                        canallocate = false;
                        break;
                    }
                }

                // if the need < available then process is allocated the resources
                if(canallocate)
                {
                    // here the allocated resources of the process are given back to the available resources 
                    // after the process completes its execution 
                    for (int k = 0; k < nr; k++)
                    {
                        work[k] += alloc[i][k];
                    }

                    // the process is added to the safe sequence 
                    safeseq[count] = i;
                    // the count is increased showing that 1 process has been executed 
                    count++;

                    // finish = true means that particular process has been executed 
                    finish[i] = true;

                    // this ensures that the process is safely allocated resources and executed properly 
                    found = true;
                }
            }
        }

        if(found == false)
        {
            printf("\n System is not in the safe state");
            return false;
        }
        
    } // while loop ends

    printf("\n System is in a safe State \n Safe Sequences is :");
    for (int i = 0; i < np; i++)
    {
        printf("P%d%s", safeseq[i], (i < np - 1) ? "->" : " ");
        // it display  arrow if there is another process inn front if no process in front is display empty string 
    }
    return true;
}


 // for requesting resources 
bool reqResources(int process , int req[nr] , int max[np][nr] , int alloc[np][nr], int avail[nr])
{
    int need[np][nr];
    calculateneedmatrix(need, max, alloc);

    // request > need
    for (int i = 0; i < nr; i++)
    {
        if(req[i] > need[process][i])
        {
            printf("\nError : process has exceeded ist maximum claim");
            return false;
        }
    }

    // request > avail
    for (int i = 0; i < nr; i++)
    {
        if(req[i] > avail[i])
        {
            printf("\nresources are not available for Process %d ", process);
            return false;
        }
    }
    
    // assume as if the request is granted and resources are allocated 
    for (int i = 0; i < nr; i++)
    {
        avail[i] -= req[i];
        need[process][i] -= req[i];
        alloc[process][i] += req[i];
    }

    // check if the system is still in the safe state after the request has been granted 
    if(isSafe(max,alloc,avail))
    {
        printf("\nRequest can be granted safely for the process %d", process);
        return true;
    }
    else
    {
        for (int i = 0; i < nr; i++)
        {
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
    int alloc[np][nr] =
    {
        {0, 0, 1, 2}, {1, 0, 0, 0}, {1,3,5,4,}, {0, 6, 3, 2}, {0, 0, 1, 4}
    };
    int max[np][nr] =
    {
        {0, 0, 1, 2}, {1, 7, 5, 0}, {2, 3, 5, 6}, {0, 6, 5, 2}, {0, 6, 5, 6}
    };
    int avail[nr] = {1, 5, 2, 0};
    int i, j;
    int need[np][nr];

    // calulate need amrtix
    calculateneedmatrix(need, max, alloc);
    printneed(need);

    // check is the state is safe and print safe sequence
    isSafe(max, alloc, avail);

    //If a request from process P arrives for (0, 4, 2, 0) can it be granted immediately by keeping the system in safe state. Print a message
    int req[nr] = {0, 4, 2, 0};
    reqResources(1, req, max, alloc, avail);
    return 0;

}