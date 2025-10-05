// opt
#include<stdio.h>
#include<stdbool.h>
int find_farthest(int currentind , int ref_str[] , int rl ,int frames[] , int nf)
{
    // farthest for( j in ref_str) and replace_ind is for(i in frames)
    int farthest = -1, replace_ind = -1;
    for (int i = 0; i < nf;i++){
        int j;
        for (j = currentind + 1; j < rl; j++){
            if(frames[i] == ref_str[j]){
                if(j>farthest){
                    farthest = j;
                    replace_ind = i;
                }
                break; // to stop beacuse we already know where we will find the page again nexttime
            }
        }
        if(j == rl)
            return i;
    }

    return (replace_ind == -1) ? 0 : replace_ind;
}

void print_frame(int ref , int frames[] , int nf){
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
    // setting the reference string anf frames
    int ref_str[] = {12, 15, 12, 18, 6, 8, 11, 12, 19, 12, 6, 8, 12, 15, 19, 8};
    int rl = sizeof(ref_str) / sizeof(ref_str[0]);
    int nf;
    int frames[5];
    printf("enter the no of frames:");
    scanf("%d", &nf);
    for (int i = 0; i < nf; i++)
        frames[i] = -1;

    int i, j, pagefaults = 0;
    int found;

    printf("page  ");
    for (i = 0; i < nf; i++)
        printf("frames%d  ", i + 1);
    printf("\n -------------------------------------- \n");

    for (i = 0; i < rl; i++){
        found = 0;

        //check if the ref_str present in the frames
        for (j = 0; j < nf; j++){
            if(frames[j] == ref_str[i]){
                found = 1;
                break;
            }
        }
    

        if(found == 0){
            // check if any one frame is empty
            for (j = 0; j < nf; j++){
                if(frames[j] == -1){
                    frames[j] = ref_str[i];
                    pagefaults++;
                    found = 1;
                    break;
                }
            }

            // if found still is 0 then we nee to replace usinf the opt 
            if(found == 0){
                int pos = find_farthest(i, ref_str, rl, frames, nf);
                frames[pos] = ref_str[i];
                pagefaults++;
            }
        }
        print_frame(ref_str[i], frames, nf);
    }
    printf("total no of page faults : %d ", pagefaults);
    return 0;
}

