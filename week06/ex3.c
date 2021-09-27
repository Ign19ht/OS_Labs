#include <stdio.h>
#include <malloc.h>

typedef struct Process {
    int arrive;
    int burst;
    int CT;
    int TAT;
    int WT;
    int remaining;
} Process;

typedef struct Node {
    Process *process;
    struct Node *next;
}Node;

typedef struct Queue {
    int size;
    Node *next;
    Node *last;
}Queue;

void add_to_queue(Queue *queue, Process *process) {
    Node *node = malloc(sizeof(Node));
    node->process = process;
    node->next = NULL;
    if (queue->size == 0) {
        queue->next = node;
        queue->last = node;
    } else {
        queue->last->next = node;
        queue->last = node;
    }
    queue->size++;
}

Process* get_first(Queue *queue) {
    Node* node = queue->next;
    if (node == NULL) return NULL;
    queue->next = node->next;
    queue->size--;
    return node->process;
}

void scheduling(Process *processes[], int n, int quantum) {
    Queue queue = {0, NULL};
    int process_id = 0;
    int next_free_time = processes[0]->arrive;
    Process *executing_process = NULL;
    for (int time = next_free_time; 1; time++) {
        while (process_id < n && processes[process_id]->arrive == time) {
            add_to_queue(&queue, processes[process_id]);
            process_id++;
        }
        if (time >= next_free_time) {
            if (executing_process != NULL) {
                executing_process->remaining -= quantum;
                if (executing_process->remaining > 0) {
                    add_to_queue(&queue, executing_process);
                } else {
                    executing_process->CT = time;
                    executing_process->TAT = executing_process->CT - executing_process->arrive;
                    executing_process->WT = executing_process->TAT - executing_process->burst;
                }
            }
            executing_process = get_first(&queue);
            if (executing_process == NULL) {
                if (process_id == n) return;
            } else {
                if (executing_process->remaining > quantum) next_free_time += quantum;
                else next_free_time += executing_process->remaining;
            }
        }
    }
}

int main() {
    // input
    int quantum;
    printf("Enter the quantum:");
    scanf("%d", &quantum);
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
        processes[i].remaining = processes[i].burst;
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
    scheduling(sorted_processes, n, quantum);

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


