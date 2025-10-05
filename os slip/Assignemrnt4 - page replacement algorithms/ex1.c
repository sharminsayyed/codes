#include <stdio.h>
#include <stdbool.h>

#define MAX_FRAMES 10
#define MAX_REFERENCES 100

// Function to check if a page is present in the memory frames
bool is_present(int frames[], int n, int page) {
    for (int i = 0; i < n; i++) {
        if (frames[i] == page) {
            return true;
        }
    }
    return false;
}

// Function to print the current status of memory frames
void print_frames(int ref, int frames[], int n) {
    printf("%4d    ", ref);  // Print the current page reference (String)
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
    int n = 3;  // Number of memory frames
    //int ref_string[] = {3, 4, 5, 6, 3, 4, 7, 3, 4, 5, 6, 7, 2, 4, 6}; // Reference string
    int ref_string[] = {0, 2, 1, 6, 4, 0, 1, 0, 3, 1, 2, 1};

    int ref_len = sizeof(ref_string) / sizeof(ref_string[0]);  // Length of the reference string

    int frames[MAX_FRAMES];  // Memory frames
    int page_faults = 0;     // Count of page faults
    int index = 0;           // To track the position in the frame (FIFO order)

    // Initialize all frames as empty
    for (int i = 0; i < n; i++) {
        frames[i] = -1;
    }

    printf("Page  Frame1  Frame2  Frame3\n");
    printf("---------------------------\n");

    // FIFO page replacement algorithm
    for (int i = 0; i < ref_len; i++) {
        int current_page = ref_string[i];

        // Check if the current page is already present in the memory frames
        if (!is_present(frames, n, current_page)) {
            // Page fault occurs, replace the oldest page in FIFO manner
            frames[index] = current_page;
            index = (index + 1) % n;  // Update the index to the next frame position (circular queue)
            page_faults++;
        }

        // Print the current status of frames along with the page reference
        print_frames(current_page, frames, n);
    }

    // Output the total number of page faults
    printf("\nTotal Page Faults: %d\n", page_faults);

    return 0;
}
