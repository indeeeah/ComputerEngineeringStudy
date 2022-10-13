#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *head;

void removeFront(Node *root) {
    Node *front = root->next;
    root->next = front->next;
    free(front);
}

int main(void) {
    head = (Node*) malloc(sizeof(Node));
    Node *node1 = (Node*) malloc(sizeof(Node));
    node1->data = 1;
    Node *node2 = (Node*) malloc(sizeof(Node));
    node2->data = 2;

    head->next = node1;
    node1->next = node2;
    node2->next = NULL;

    removeFront(head);

    Node *cur = head->next;
    
    while (cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->next;
    }

    return 0;
}