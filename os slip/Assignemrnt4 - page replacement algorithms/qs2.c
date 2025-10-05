/*
Write the simulation program to implement demand paging and show the page scheduling 
and total number of page faults for the following given page reference string. Give input n as the 
number of memory frames. 
Reference String: 7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2 
i. Implement LRU*/

/*
no_of_frames: Number of memory frames.
no_of_pages: Number of pages in the reference string.
frames[]: Array to store the pages currently loaded into memory.
pages[]: Array containing the reference string (pages to be loaded).
counter: Keeps track of the time for the LRU algorithm.
time[]: Array that stores the last access time of each page in memory.
flag1 and flag2: Flags used to check conditions during page replacement.
page_faults: Keeps count of the total page faults.
*/
#include<stdio.h>
#define max 20

int findlru(int time[] , int nf)
{
    int mini = time[0], pos = 0;
    for (int i = 0; i < nf; i++)
    {
        if(time[i] < mini)
        {
            mini = time[i];
            pos = i;
        }
    }
    return pos;
}


void print_frames(int ref, int frames[],  int nf)
{
    printf("%4d", ref);
    for (int i = 0; i < nf; i++)
    {
        if(frames[i] == -1){
            printf("   -   ");
        }
        else{
            printf("   %d   ", frames[i]);
        }
    }
    printf("\n");
}
int main()
{
    int ref_page[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int page_len = sizeof(ref_page) / sizeof(ref_page[0]);

    int frames[max], nf;
    printf("enter the number of frames :");
    scanf("%d", &nf);

    int counter, time[max];
    int flag1, flag2;

    int page_fault = 0;
    
    int i, j;

    for ( i = 0; i < nf; i++)
    {
        frames[i] = -1;
    }

    printf("pages frame1 frame2 frame3\n");
    printf("-----------------------------------\n");
    for ( i = 0; i < page_len; i++)
    {
        flag1 = flag2 = 0;

        // if the page is present in one of the frames
        for ( j = 0; j < nf; j++)
        {
            if(frames[j] == ref_page[i])
            {
                counter++;
                time[j] = counter;
                flag1 = flag2 = 1;
                break;
            }
        }

        // if the frames is empty
        if(flag1 == 0)
        {
            for ( j = 0; j < nf; j++)
            {
                if(frames[j] == -1)
                {
                    frames[j] = ref_page[i];
                    counter++;
                    time[j] = counter;
                    page_fault++;
                    flag2 = 1;
                    break;
                }
            }
            
        }

        // appplying lru here replacing the pages 
        if(flag2 == 0)
        {
            int pos = findlru(time, nf);
            frames[pos] = ref_page[i];
            counter++;
            time[pos] = counter;
            page_fault++;
        }
        print_frames(ref_page[i], frames, nf );
    }
    printf("\nTotal Page Faults = %d\n", page_fault);
    
}