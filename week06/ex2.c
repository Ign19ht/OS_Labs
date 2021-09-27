#include <stdio.h>
#include <malloc.h>

typedef struct Process {
    int arrive;
    int burst;
    int CT;
    int TAT;
    int WT;
} Process;

typedef struct Node {
    Process *process;
    struct Node *next;
}Node;

typedef struct LinkedList {
    int size;
    Node *next;
}LinkedList;

void add_to_queue(LinkedList *queue, Process *process) {
    Node *node = malloc(sizeof(Node));
    node->process = process;
    if (queue->size == 0) {
        node->next = NULL;
        queue->next = node;
    } else {
        Node *current = queue->next;
        if (current->process->burst > process->burst) {
            node->next = queue->next;
            queue->next = node;
        } else {
            while (current->next && current->next->process->burst <= process->burst) current = current->next;
            node->next = current->next;
            current->next = node;
        }
    }
    queue->size++;
}

Process* get_first(LinkedList *linkedList) {
    Node* node = linkedList->next;
    if (node == NULL) return NULL;
    linkedList->next = node->next;
    linkedList->size--;
    return node->process;
}

void scheduling(Process *processes[], int n) {
    LinkedList queue = {0, NULL};
    int current_process_id = 0;
    int next_free_time = processes[0]->arrive;
    for (int time = next_free_time; 1; time++) {
        while (current_process_id < n && processes[current_process_id]->arrive == time) {
            add_to_queue(&queue, processes[current_process_id]);
            current_process_id++;
        }
        if (time >= next_free_time) {
            Process *process = get_first(&queue);
            if (process == NULL) {
                if (current_process_id == n) return;
            } else {
                process->CT = time + process->burst;
                process->WT = time - process->arrive;
                process->TAT = process->CT - process->arrive;
                next_free_time = process->CT;
            }
        }
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


