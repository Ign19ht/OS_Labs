#include <stdio.h>
#include <malloc.h>

typedef struct node {
    int value;
    struct node *next;
}Node;

void print_list(Node *head) {
    Node* current = head->next;
    while (current) {
        printf("%d ", current->value);
        current = current->next;
    }
}

void insert_node(Node *head, Node *new_node, Node *prev_node) {
    Node *current = head;
    while (current != prev_node && current->next) current = current->next;
    if (current == prev_node) {
        new_node->next = current->next;
        current->next = new_node;
    }
}

void delete_node(Node *head, Node *deleted_node) {
    Node *current = head;
    while (current->next != deleted_node && current->next) current = current->next;
    if (current->next == deleted_node) {
        current->next = deleted_node->next;
    }
}

Node* create_node(int value) {
    Node* node = malloc(sizeof(Node));
    node->next = NULL;
    node->value = value;
    return node;
}

Node* create_list() {
    Node* node = malloc(sizeof(Node));
    node->next = NULL;
    return node;
}

int main(){
    Node* list = create_list();
    Node* node1 = create_node(6);
    Node* node2 = create_node(5);
    insert_node(list, node1, list);
    print_list(list);
    printf("\n");
    insert_node(list, node2, node1);
    print_list(list);
    printf("\n");
    delete_node(list, node1);
    print_list(list);
    return 0;
}

