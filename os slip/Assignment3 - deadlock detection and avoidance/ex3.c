#include <stdio.h>
#include <stdbool.h>

#define P 5 // Number of processes
#define R 4 // Number of resource types

// Function to calculate the need matrix
void calculateNeed(int need[P][R], int max[P][R], int alloc[P][R]) {
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < R; j++) {
            need[i][j] = max[i][j] - alloc[i][j];  // Need = Max - Allocation
        }
    }
}

// Function to print the current state of the system
void printState(int alloc[P][R], int max[P][R], int avail[R], int need[P][R]) {
    printf("Allocation Matrix:\n");
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < R; j++) {
            printf("%d ", alloc[i][j]);
        }
        printf("\n");
    }

    printf("\nMaximum Matrix:\n");
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < R; j++) {
            printf("%d ", max[i][j]);
        }
        printf("\n");
    }

    printf("\nAvailable Resources:\n");
    for (int i = 0; i < R; i++) {
        printf("%d ", avail[i]);
    }

    printf("\n\nNeed Matrix:\n");
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < R; j++) {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to check if the system is in a safe state
bool isSafe(int alloc[P][R], int max[P][R], int avail[R], int safeSeq[P]) {
    int need[P][R];
    bool finish[P] = {false};  // Indicates if each process is finished
    int work[R];               // Work array to track available resources during execution

    calculateNeed(need, max, alloc);  // Calculate the need matrix

    // Copy available resources to the work array
    for (int i = 0; i < R; i++) {
        work[i] = avail[i];
    }

    int count = 0;  // Number of processes in the safe sequence

    // While not all processes are finished
    while (count < P) {
        bool found = false;

        // Check each process to see if it can be allocated resources
        for (int i = 0; i < P; i++) {
            if (finish[i] == false) {  // If the process is not finished
                bool canAllocate = true;  // Assume we can allocate resources

                // Check if all needed resources can be allocated
                for (int j = 0; j < R; j++) {  
                    if (need[i][j] > work[j]) {  // If the process needs more than available
                        canAllocate = false;  // Cannot allocate resources
                        break;  // Exit the loop
                    }
                }

                // If resources can be allocated to process i
                if (canAllocate) {
                    // Process i can safely finish, so release its resources
                    for (int k = 0; k < R; k++) {
                        work[k] += alloc[i][k];  // Add allocated resources to the available pool
                    }

                    // Mark the process as finished
                    safeSeq[count] = i;  // Store process i in the safe sequence
                    count++;             // Move to the next position in the sequence

                    finish[i] = true;     // Mark this process as finished
                    found = true;         // Indicate that we found a process that can safely finish
                }
            }
        }

        // If no process could be found to safely execute, the system is not safe
        if (!found) {
            printf("System is not in a safe state.\n");
            return false;
        }
    }

    // If all processes can finish, the system is in a safe state
    printf("System is in a safe state.\nSafe sequence is: ");
    for (int i = 0; i < P; i++) {
        printf("P%d%s", safeSeq[i], (i < P - 1) ? " -> " : "");  // Print the safe sequence
    }
    printf("\n");
    return true;
}

// Function to request resources for a process
bool requestResources(int process, int request[R], int alloc[P][R], int max[P][R], int avail[R]) {
    int need[P][R];
    calculateNeed(need, max, alloc);  // Calculate the need matrix

    // Check if the process is requesting more resources than it needs
    for (int i = 0; i < R; i++) {
        if (request[i] > need[process][i]) {
            printf("Error: Process has exceeded its maximum claim.\n");
            return false;
        }
    }

    // Check if resources are available
    for (int i = 0; i < R; i++) {
        if (request[i] > avail[i]) {
            printf("Resources not available for Process P%d.\n", process);
            return false;
        }
    }

    // Temporarily allocate the requested resources
    for (int i = 0; i < R; i++) {
        avail[i] -= request[i];
        alloc[process][i] += request[i];
        need[process][i] -= request[i];
    }

    // Check if the system is still in a safe state after the request
    int safeSeq[P]; // Array to hold the safe sequence
    if (isSafe(alloc, max, avail, safeSeq)) {
        printf("Request can be granted safely for Process P%d.\n", process);
        return true;
    } else {
        // Rollback the allocation if the system is not safe
        for (int i = 0; i < R; i++) {
            avail[i] += request[i];
            alloc[process][i] -= request[i];
            need[process][i] += request[i];
        }
        printf("Request cannot be granted, system will be unsafe.\n");
        return false;
    }
}

// Function to check for deadlock
void checkDeadlock(bool finish[P], int n, int ans[P]) {
    bool flag = true;
    for (int i = 0; i < n; i++) {
        if (finish[i] == false) { 
            flag = false; 
            printf("System is in deadlock !!\n"); 
            break; 
        }
    }

    if (flag == true) {
        printf("System is in safe state and following is the safe sequence: ");
        for (int i = 0; i < n - 1; i++) {
            printf("P%d -> ", ans[i]); 
        }
        printf("P%d\n", ans[n - 1]);
    }
}

int main() {
    // Example data for testing (processes, allocation, maximum, and available resources)
    int alloc[P][R] = { {0, 1, 0, 3}, {2, 0, 0, 0}, {3, 0, 2, 1}, {2, 1, 1, 0}, {0, 0, 2, 2} };
    int max[P][R] = { {7, 5, 3, 4}, {3, 2, 2, 2}, {9, 0, 2, 2}, {4, 2, 2, 3}, {5, 3, 3, 4} };
    int avail[R] = {3, 3, 2, 2};  // Available resources
    int need[P][R];

    // Calculate and print the current state
    calculateNeed(need, max, alloc);
    printState(alloc, max, avail, need);

    // Check if the system is in a safe state
    int safeSeq[P];
    isSafe(alloc, max, avail, safeSeq);

    // Example request from Process 1 (P1)
    int request[R] = { 0, 4, 2, 0 };
    requestResources(1, request, alloc, max, avail);

    // Example finish array for deadlock check
    bool finish[P] = {false}; // Initialize finish array
    // Assuming some processes have finished (for demonstration)
    finish[0] = true;
    finish[1] = true;

    // Check for deadlock based on the finish array
    checkDeadlock(finish, P, safeSeq);

    return 0;
}
