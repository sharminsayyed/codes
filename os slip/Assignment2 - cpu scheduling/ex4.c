#include <stdio.h>
#include <stdbool.h>

struct Process {
    int pid;            // Process ID
    int arrival_time;    // Arrival Time
    int burst_time;      // Burst Time
    int priority;        // Priority (lower number means higher priority)
    int waiting_time;    // Waiting Time
    int turnaround_time; // Turnaround Time
    int completion_time; // Completion Time
    int start_time;      // Start Time
    bool is_completed;   // Flag to check if process is completed
};

// Function to find the next process to be executed based on arrival time and priority
int findNextProcess(struct Process p[], int n, int current_time) {
    int min_priority = 10000;
    int index = -1;

    for (int i = 0; i < n; i++) {
        if (p[i].arrival_time <= current_time && !p[i].is_completed) {
            if (p[i].priority < min_priority) {
                min_priority = p[i].priority;
                index = i;
            }
        }
    }
    return index;
}

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];
    int total_waiting_time = 0, total_turnaround_time = 0;
    int current_time = 0, completed_processes = 0;

    // Input process details
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter arrival time, burst time and priority for process %d: ", p[i].pid);
        scanf("%d%d%d", &p[i].arrival_time, &p[i].burst_time, &p[i].priority);
        p[i].is_completed = false;
    }

    printf("\nGantt Chart:\n");

    // Simulation loop
    while (completed_processes < n) {
        int index = findNextProcess(p, n, current_time);
        
        // If no process is available, increment time and display idle
        if (index == -1) {
            printf("| Idle (1 unit) ");
            current_time++;
            continue;
        }

        // Process selected
        p[index].start_time = current_time;
        p[index].completion_time = current_time + p[index].burst_time;
        p[index].turnaround_time = p[index].completion_time - p[index].arrival_time;
        p[index].waiting_time = p[index].turnaround_time - p[index].burst_time;
        p[index].is_completed = true;

        total_turnaround_time += p[index].turnaround_time;
        total_waiting_time += p[index].waiting_time;

        // Display in Gantt chart
        printf("| P%d (%d units, completes at %d) ", p[index].pid, p[index].burst_time, p[index].completion_time);
        
        // Move current time forward by burst time plus 2 units for IO wait time
        current_time = p[index].completion_time ;
        completed_processes++;
    }

    printf("|\n");

    // Output turnaround and waiting times for each process
    printf("\npid\tat\tbt\tP\tct\ttat\twt\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n", p[i].pid, p[i].arrival_time, p[i].burst_time, p[i].priority, p[i].completion_time, p[i].turnaround_time, p[i].waiting_time);
    }

    // Calculate and print average waiting and turnaround times
    float avg_waiting_time = (float)total_waiting_time / n;
    float avg_turnaround_time = (float)total_turnaround_time / n;
    printf("\nAverage Waiting Time: %.2f\n", avg_waiting_time);
    printf("Average Turnaround Time: %.2f\n", avg_turnaround_time);

    return 0;
}
