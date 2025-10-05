#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

typedef struct {
    int id;             // Process ID
    int arrivalTime;    // Arrival Time
    int burstTime;      // CPU Burst Time
    int startTime;      // Start Time
    int endTime;        // End Time
    int turnaroundTime; // Turnaround Time
    int waitingTime;    // Waiting Time
} Process;

// Function to generate the next burst time randomly
int generateNextBurstTime(int currentBurstTime) {
    return currentBurstTime + (rand() % 10) + 1; // Random burst time between 1 and 10
}

// Function to find the process with the shortest burst time
int findShortestJob(Process processes[], int n, int currentTime) {
    int minBurstTime = 999999, shortestIndex = -1;
    
    for (int i = 0; i < n; i++) {
        if (processes[i].arrivalTime <= currentTime && processes[i].endTime == 0) {
            if (processes[i].burstTime < minBurstTime) {
                minBurstTime = processes[i].burstTime;
                shortestIndex = i;
            }
        }
    }
    
    return shortestIndex;
}

// Function to calculate and print average times
void calculateAverageTimes(Process processes[], int n) {
    int totalTurnaroundTime = 0, totalWaitingTime = 0;
    
    for (int i = 0; i < n; i++) {
        totalTurnaroundTime += processes[i].turnaroundTime;
        totalWaitingTime += processes[i].waitingTime;
    }
    
    printf("\nAverage Turnaround Time: %.2f\n", (float)totalTurnaroundTime / n);
    printf("Average Waiting Time: %.2f\n", (float)totalWaitingTime / n);
}

int main() {
    int n, currentTime = 0, nextJobIndex;
    
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    
    Process processes[MAX];
    
    // Input for arrival time and burst time
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter arrival time for process %d: ", i + 1);
        scanf("%d", &processes[i].arrivalTime);
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &processes[i].burstTime);
        processes[i].endTime = 0;  // Initialize endTime to 0
    }
    
    srand(time(NULL));  // Seed for random number generation
    
    // SJF Scheduling
    printf("\nGantt Chart:\n");
    for (int i = 0; i < n; i++) {
        nextJobIndex = findShortestJob(processes, n, currentTime);
        
        if (nextJobIndex == -1) {
            currentTime++;
            i--; // Recheck the jobs in the next cycle
            continue;
        }
        
        processes[nextJobIndex].startTime = currentTime;
        processes[nextJobIndex].endTime = currentTime + processes[nextJobIndex].burstTime;
        processes[nextJobIndex].turnaroundTime = processes[nextJobIndex].endTime - processes[nextJobIndex].arrivalTime;
        processes[nextJobIndex].waitingTime = processes[nextJobIndex].turnaroundTime - processes[nextJobIndex].burstTime;
        
        printf("P%d ", processes[nextJobIndex].id);  // Display Gantt Chart
        currentTime = processes[nextJobIndex].endTime;
        
        // Add fixed I/O wait time (2 units)
        // new 
        currentTime += 2;
        
        // Generate the next CPU burst time
        processes[nextJobIndex].burstTime = generateNextBurstTime(processes[nextJobIndex].burstTime);
    }
    
    printf("\n\nProcess Summary:\n");
    printf("ID\tArrival Time\tBurst Time\tStart Time\tEnd Time\tTurnaround Time\tWaiting Time\n");
    
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", 
                processes[i].id, processes[i].arrivalTime, processes[i].burstTime,
                processes[i].startTime, processes[i].endTime, processes[i].turnaroundTime, 
                processes[i].waitingTime);
    }
    
    // Calculate and print average turnaround and waiting time
    calculateAverageTimes(processes, n);
    
    return 0;
}
