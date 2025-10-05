/*
 slip 1,5,6
 Write the simulation program to implement demand paging and show the page scheduling 
and total number of page faults for the following given page reference string. Give input n=3 as 
the number of memory frames. 
Reference String :3, 4, 5, 6, 3, 4, 7, 3, 4, 5, 6, 7, 2, 4, 6 
Implement FIFO 

Slip 11,14
Write the simulation program to implement demand paging and show the page scheduling 
and total number of page faults for the following given page reference string. Give input n as the 
number of memory frames. 
Reference String: 0, 2, 1, 6, 4, 0, 1, 0, 3, 1, 2, 1 
 
Implement FIFO
*/

#include<stdio.h>
#include<stdbool.h>
#define max_ref_str 100
#define max_frame 10

bool page_present_in_frame(int frame[] ,int nf , int page)
{
    for (int i = 0; i < nf; i++)
    {// id page is present in the frame 
        if(frame[i] == page)
            return true;
    }
    return false;
}

void print_frames(int ref, int frames[], int n) {
    // print 4 character spaces of reference string
    printf("%4d    ", ref);  
    for (int i = 0; i < n; i++) {
        if (frames[i] == -1) {
            // no page is present 
            printf("  -   ");  
        } else {
            printf("  %d   ", frames[i]);  
        }
    }
    printf("\n");
}
int main()
{
    // int ref_page[] = {3, 4, 5, 6, 3, 4, 7, 3, 4, 5, 6, 7, 2, 4, 6};
    int ref_page[] = {0, 2, 1, 6, 4, 0, 1, 0, 3, 1, 2, 1};
    // len = 4(15) = 60 / 4 = 15 
    int ref_len = sizeof(ref_page) / sizeof(ref_page[0]);

    int nf = 3;
    int frame[max_frame];

    // intialize all the frame position to -1
    for (int i = 0; i < nf; i++)
    {
        frame[i] = -1;
    }

    int page_fault = 0;
    int ind = 0;

    // checking if page is present int the frame 
    // or we have to replace a particular page to place a new page 
    printf("page  frame1  frame2  frame3  \n");
    printf("-------------------------------\n");
    for (int i = 0; i < ref_len; i++)
    {
        // assigning 
        int current_page = ref_page[i];
        // is page preesent in frame == false 
        if(!page_present_in_frame(frame ,nf,current_page))
        {
            // replacing the page with new page using index 
            frame[ind] = current_page;

            /*
            index + 1 moves to the next frame.
            % n makes sure that when index reaches the maximum number of frames (n), it wraps back around to 0.
            This circular updating ensures the correct order of replacement in a FIFO manner.*/
            ind = (ind + 1) % nf;

            // increase page fault 
            page_fault++;
        }
        print_frames(current_page, frame, nf);
    }

    printf("total page faults : %d\n", page_fault);
}