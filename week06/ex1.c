#include <stdio.h>]

typedef struct Process {
    int arrive;
    int burst;
    int CT;
    int TAT;
    int WT;
} Process;

void scheduling(Process *processes[], int n) {
    int current_time = 0;
    for (int i = 0; i < n; i++) {
        if (processes[i]->arrive > current_time) current_time = processes[i]->arrive;
        processes[i]->WT = current_time - processes[i]->arrive;
        current_time += processes[i]->burst;
        processes[i]->CT = current_time;
        processes[i]->TAT = current_time - processes[i]->arrive;
    }
}

int main() {
    // input
    int n;
    printf("Enter number of processes:");
    scanf("%d", &n);
    Process processes[n];
    Process *sorted_processes[n];
    for (int i = 0; i < n; i++) {
        sorted_processes[i] = &processes[i];
        printf("Arrival time of process[%d]:", i + 1);
        scanf("%d", &processes[i].arrive);
        printf("Burst time of process[%d]:", i + 1);
        scanf("%d", &processes[i].burst);
    }

    // Sorting by arrival time
    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (sorted_processes[j]->arrive > sorted_processes[j + 1]->arrive) {
                Process *temp = sorted_processes[j];
                sorted_processes[j] = sorted_processes[j + 1];
                sorted_processes[j + 1] = temp;
            }
        }
    }

    // Scheduling
    scheduling(sorted_processes, n);

    // Print result
    printf("P#     AT    BT    CT    TAT   WT\n\n");
    int total_wt = 0;
    int total_tat = 0;
    for (int i = 0; i < n; i++) {
        printf("P%-6d%-6d%-6d%-6d%-6d%-6d\n", i + 1, processes[i].arrive, processes[i].burst,
               processes[i].CT, processes[i].TAT, processes[i].WT);
        total_wt += processes[i].WT;
        total_tat += processes[i].TAT;
    }
    printf("\nAverage TAT = %f\n", ((float)total_tat / (float)n));
    printf("Average WT = %f", ((float)total_wt / (float)n));
    return 0;
}


