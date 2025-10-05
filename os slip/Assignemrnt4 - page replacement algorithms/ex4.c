#include<stdio.h>
int find_farthest(int reference[], int frames[], int current, int total_refs, int frame_size) {
    int farthest_index = -1, replace_index = -1;

    // Check each page in the frames
    for (int i = 0; i < frame_size; i++) {
        int j;
        for (j = current + 1; j < total_refs; j++) {
            if (frames[i] == reference[j]) {
                if (j > farthest_index) {
                    farthest_index = j;
                    replace_index = i;
                }
                break;
            }
        }

        // If a page is never referenced again, return its index
        if (j == total_refs) {
            return i;
        }
    }

    // If no future references, return the farthest one
    return replace_index == -1 ? 0 : replace_index;
}

int main() {
    int reference[] = {8,0,1,2,0,3,0,4,2,3,0,3,2,1,2};
    int total_refs = sizeof(reference) / sizeof(reference[0]);
    int frames[10], frame_size, page_faults = 0;
    int found, frame_index = 0;

    // Initialize frames to -1
    for (int i = 0; i < 10; i++) {
        frames[i] = -1;
    }

    // Input the number of frames
    printf("Enter the number of memory frames: ");
    scanf("%d", &frame_size);

    printf("\nPage Reference String: ");
    for (int i = 0; i < total_refs; i++) {
        printf("%d ", reference[i]);
    }
    printf("\n\n");

    // Iterate through each page in the reference string
    for (int i = 0; i < total_refs; i++) {
        found = 0;

        // Check if the current page is already in memory
        for (int j = 0; j < frame_size; j++) {
            if (frames[j] == reference[i]) {
                found = 1;
                break;
            }
        }

        // If not found, page fault occurs
        if (!found) {
            // Check for empty frames first
            for (int j = 0; j < frame_size; j++) {
                if (frames[j] == -1) {
                    frames[j] = reference[i]; // Fixed from `frames[i] == reference[i]` to `frames[j] = reference[i]`
                    page_faults++;
                    found = 1; // A frame was filled
                    break; // No need to check further
                }
            }
            
        }
        if (!found) {
                // Replace the page using the optimal algorithm
                int replace_index = find_farthest(reference, frames, i, total_refs, frame_size);
                frames[replace_index] = reference[i];
                page_faults++;
            }

        // Display the current state of frames
        printf("Step %d: ", i + 1);
        for (int j = 0; j < frame_size; j++) {
            if (frames[j] == -1) {
                printf("- ");
            } else {
                printf("%d ", frames[j]);
            }
        }
        printf("\n");
    }

    // Output total page faults
    printf("\nTotal Page Faults: %d\n", page_faults);

    return 0;
}
