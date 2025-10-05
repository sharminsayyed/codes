// lru 
#include<stdio.h>
#include<stdlib.h>

int find_lru(int time[] , int nf){
    int mini = time[0], pos = 0;
    for (int j = 0; j < nf;j++){
        if(time[j] < mini){
            mini = time[j];
            pos = j;
        }
    }
    return pos;
}

void print_frame(int ref , int nf ,int frames[]){
    printf("%4d   ", ref);
    for (int i = 0; i < nf; i++){
        if(frames[i] == -1)
            printf("   -   ");
        else
            printf("   %d   ", frames[i]);
    }
    printf("\n");
}
int main(){
    // setting reference string and frames 
    int ref_str[] =  {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int rl = sizeof(ref_str) / sizeof(ref_str[0]);
    int nf;
    int frames[5];
    printf("enter the no of frames :");
    scanf("%d", &nf);
    for (int i = 0; i < nf; i++)
        frames[i] = -1;
    
    // variables for lru
    int flag1, flag2, counter = 0, i, j,pagefaults=0;
    int time[nf];

    printf("page  ");
    for (i = 0; i < nf;i++)
        printf("frame%d  ", i + 1);
    printf("\n---------------------------------------\n");

    // main logic
    for (i = 0; i < rl;i++)
    {
        flag1 = flag2 = 0;

        // check if the page is present in the frame
        for (j = 0; j < nf; j++){
            if(frames[j] == ref_str[i]){
                counter++;
                time[j] = counter;
                flag1 = flag2 = 1;
                break;
            }
        }

        // or check if the frame is empty 
        if(flag1 == 0){
            for (j = 0; j < nf;j++){
                if(frames[j] == -1){
                    frames[j] = ref_str[i];
                    counter++;
                    time[j] = counter;
                    pagefaults++;
                    flag2 = 1;
                    break;
                }
            }
        }

        // or replace using the lru 
        if(flag2 == 0){
            int pos = find_lru(time, nf);
            frames[pos] = ref_str[i];
            counter++;
            time[pos] = counter;
            pagefaults++;
        }

        // print the frame in the chart
        print_frame(ref_str[i], nf, frames);
    }
    printf("total page faults : %d ", pagefaults);
}