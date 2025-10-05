// fifo
#include<stdio.h>
#include<stdbool.h>
#define max_frame 5
bool page_present_in_frame(int page , int nf , int frames[]){
    for (int i = 0; i<nf; i++){
        if(frames[i] == page )
            return true;
    }
    return false;
}
void print_frame(int ref, int nf,int frames[]){
    printf("%4d   ", ref);
    for (int i = 0; i < nf; i++){
        if(frames[i] == -1)
            printf("   -   ");
        else
            printf("   %d   ", frames[i]);
    }
    printf("\n");
}
int main()
{
    //  reference string an frame set up
    int ref_str[] = {0, 2, 1, 6, 4, 0, 1, 0, 3, 1, 2, 1};
    int rl = sizeof(ref_str) / sizeof(ref_str[0]);
    int nf = 3, i, j;
    int frames[max_frame];
    for (i = 0; i < 3; i++){
        frames[i] = -1;
    }

    // putting the number in the frame and printing it 
    int pagefaults = 0;
    int ind = 0;
    printf("page  frame1  frame2  frame3  \n");
    printf("--------------------------------\n");
    for (i = 0; i < rl; i++)
    {
        int current_page = ref_str[i];
        if(!page_present_in_frame(current_page , nf, frames)){
            frames[ind] = current_page;
            ind = (ind + 1) % nf;
            pagefaults++;
        }
        //printing the frames
        print_frame(current_page, nf, frames);
    }
    // page fualts 
    printf("\n total no of page faults  : %d \n", pagefaults);
}