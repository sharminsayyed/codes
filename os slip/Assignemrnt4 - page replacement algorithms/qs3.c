/*
Write the simulation program to implement demand paging and show the page scheduling 
and total number of page faults for the following given page reference string. Give input n as 
the number of memory frames. 
Reference String : 12,15,12,18,6,8,11,12,19,12,6,8,12,15,19,8 
Implement OPT
*/

#include<stdio.h>
#define max 10

/*This function find_farthest() finds the page in the frames that will not be used for the longest time in the future.

Check if the current frame's page is in future references: If a page in the frame is found in the future references, the code checks if its index is farther than farthest_index. If so, farthest_index and replace_index are updated.
If the current page (frames[i]) is found, the inner loop breaks because we don’t need to look further for that page.*/

int find_farthest(int currentindex, int frames[],int ref_page[] ,int np,int nf)
{
    int farthest = -1, replace_index = -1;
    for (int i = 0; i < nf; i++)
    {
        int j;
        for ( j = currentindex+1; j < np; j++)
        {
            if(frames[i] == ref_page[j])
            {
                if(j > farthest)
                {
                    farthest = j;
                    replace_index = i;
                }
                break;
            }
        }
        
        //// If a page is never referenced again, return its index
        if(j == np)
            return i;
    }

    // If no future references, return the farthest one
    return  (replace_index == -1) ? 0 : replace_index;
}

void print_frames(int page , int frames[] , int nf)
{
    printf("%4d", page);
    for (int i = 0; i < nf; i++)
    {
        if(frames[i] == -1)
        {
            printf("   -   ");
        }
        else
        {
            printf("   %d   ", frames[i]);
        }
    }
    printf("\n");
}
int main()
{
    int ref_page[] = {12, 15, 12, 18, 6, 8, 11, 12, 19, 12, 6, 8, 12, 15, 19, 8};
    int np = sizeof(ref_page) / sizeof(ref_page[0]);

    int nf;
    int frames[max];
    printf("enter the number of frames :");
    scanf("%d", &nf);

    int page_faults = 0;
    int i, j;

    int found = 0;

    for ( i = 0; i < nf; i++)
    {
        frames[i] = -1;
    }

    printf("page frame1 frame2 frame3 \n");
    printf("-------------------------------\n");
    for ( i = 0; i < np; i++)
    {
        found = 0;
        // if that page is already present in the frame
        for ( j = 0; j < nf; j++)
        {
            if(frames[j] == ref_page[i])
            {
                found = 1;
                break;
            }
        }

        if (found == 0)
        {
            // if frame is empty add the page and increase a fault
            for ( j = 0; j < nf; j++)
            {
                if(frames[j] == -1)
                {
                    frames[j] = ref_page[i];
                    page_faults++;
                    found = 1;
                    break;
                }
            }
            
            if(found == 0)
            {
            // replace the page using the optimal function
            int pos = find_farthest(i ,frames, ref_page, np, nf);
            frames[pos] = ref_page[i];
            page_faults++;
            }
        }

        

        print_frames(ref_page[i], frames, nf); 
    }

    printf("\nTotal Page Faults = %d\n", page_faults);
    
    return 0;
}

/*
enter the number of frames :3
page  frame1  frame2  frame3 
-------------------------------
  12 12  -  - 
  15 12  15  - 
  12 12  15  - 
  18 12  15  18 
   6 12  15  6 
   8 12  8  6 
  11 12  11  6 
  12 12  11  6 
  19 12  19  6 
  12 12  19  6 
   6 12  19  6 
   8 12  19  8 
  12 12  19  8 
  15 15  19  8 
  19 15  19  8 
   8 15  19  8 

Total Page Faults = 9
*/