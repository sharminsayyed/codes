#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_PROCESSES 10

struct Process {
    int pid;          // Process ID
    int arrivalTime;  // Arrival Time
    int burstTime;    // Initial CPU Burst Time
    int remainingTime; // Remaining CPU Burst Time
    int completionTime; // Completion Time
    int turnaroundTime; // Turnaround Time
    int waitingTime;    // Waiting Time
};

void calculateTimes(struct Process processes[], int n) {
    float totalWT = 0, totalTAT = 0;

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        processes[i].turnaroundTime = processes[i].completionTime - processes[i].arrivalTime;
        processes[i].waitingTime = processes[i].turnaroundTime - processes[i].burstTime;

        totalTAT += processes[i].turnaroundTime;
        totalWT += processes[i].waitingTime;

        printf("%d\t%d\t%d\t%d\t%d\t%d\n", 
               processes[i].pid, processes[i].arrivalTime, 
               processes[i].burstTime, processes[i].completionTime,
               processes[i].turnaroundTime, processes[i].waitingTime);
    }

    printf("\nAverage Turnaround Time: %.2f", totalTAT / n);
    printf("\nAverage Waiting Time: %.2f\n", totalWT / n);
}

int main() {
    struct Process processes[MAX_PROCESSES];
    int n, quantum;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input processes
    for (int i = 0; i < n; i++) {
        processes[i].pid = i + 1; // Assign PID
        printf("Enter arrival time and burst time for process %d: ", processes[i].pid);
        scanf("%d %d", &processes[i].arrivalTime, &processes[i].burstTime);
        processes[i].remainingTime = processes[i].burstTime; // Initialize remaining time
        processes[i].completionTime = 0; // Initialize completion time
    }

    printf("Enter time quantum: ");
    scanf("%d", &quantum);

    int currentTime = 0;
    bool done;

    // Gantt Chart
    printf("\nGantt Chart:\n");
    printf("0 "); // Start time

    while (1) {
        done = true; // Flag to check if all processes are finished

        for (int i = 0; i < n; i++) {
            if (processes[i].remainingTime > 0 && processes[i].arrivalTime <= currentTime) {
                done = false; // Found a process that is not finished

                if (processes[i].remainingTime > quantum) {
                    // Process can run for a full quantum
                    currentTime += quantum;
                    processes[i].remainingTime -= quantum;
                    printf(" -> P%d ", processes[i].pid);
                } else {
                    // Process finishes in this time slice
                    currentTime += processes[i].remainingTime;
                    processes[i].completionTime = currentTime;
                    processes[i].remainingTime = 0;
                    printf(" -> P%d ", processes[i].pid);
                }
            }
            
        }


        // If all processes are done
        if (done) break;
    }

    printf(" -> %d\n", currentTime); // End time

    // Calculate and display turnaround time and waiting time
    calculateTimes(processes, n);

    return 0;
}
