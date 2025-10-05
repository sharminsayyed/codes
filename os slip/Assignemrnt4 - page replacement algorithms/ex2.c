#include <stdio.h>

#define MAX 100

// Function to find the Least Recently Used (LRU) page
int findLRU(int time[], int n) {
    int i, minimum = time[0], pos = 0;

    for (i = 1; i < n; ++i) {
        if (time[i] < minimum) {
            minimum = time[i];
            pos = i;
        }
    }
    return pos;
}

void print_frames(int ref, int frames[], int n) {
    printf("%4d    ", ref);  // Print the current page reference
    for (int i = 0; i < n; i++) {
        if (frames[i] == -1) {
            printf("  -   ");  // Print "-" for empty frames
        } else {
            printf("  %d   ", frames[i]);  // Print the page number in the frame
        }
    }
    printf("\n");
}

int main() {
    int no_of_frames, no_of_pages, frames[MAX], pages[MAX], counter = 0, time[MAX];
    int flag1, flag2, i, j, pos, page_faults = 0;

    // Input number of memory frames
    printf("Enter the number of memory frames: ");
    scanf("%d", &no_of_frames);

    // Input the reference string (pages)
    printf("Enter the number of pages in reference string: ");
    scanf("%d", &no_of_pages);

    printf("Enter the page reference string: ");
    for (i = 0; i < no_of_pages; ++i) {
        scanf("%d", &pages[i]);
    }

    // Initialize all frames as empty
    for (i = 0; i < no_of_frames; ++i) {
        frames[i] = -1;
    }

    printf("Page   Frame1  Frame2  Frame3  ...  \n");
    printf("-----------------------------------\n");

    // Process each page in the reference string
    for (i = 0; i < no_of_pages; ++i) {
        flag1 = flag2 = 0;

        // Check if the page is already in any frame
        for (j = 0; j < no_of_frames; ++j) {
            if (frames[j] == pages[i]) {
                counter++;
                time[j] = counter;  // Update the time when the page is accessed
                flag1 = flag2 = 1;
                break;
            }
        }

        // If page is not in any frame
        if (flag1 == 0) {
            for (j = 0; j < no_of_frames; ++j) {
                if (frames[j] == -1) {
                    counter++;
                    page_faults++;
                    frames[j] = pages[i];
                    time[j] = counter;  // Track the time the page was added
                    flag2 = 1;
                    break;
                }
            }
        }

        // If no empty frame is found, replace the least recently used page
        if (flag2 == 0) {
            pos = findLRU(time, no_of_frames);  // Find LRU page position
            counter++;
            page_faults++;
            frames[pos] = pages[i];  // Replace with the new page
            time[pos] = counter;  // Update time for the new page
        }

        // Print the current status of memory frames
        print_frames(pages[i], frames, no_of_frames);
    }

    // Output the total number of page faults
    printf("\nTotal Page Faults = %d\n", page_faults);

    return 0;
}
