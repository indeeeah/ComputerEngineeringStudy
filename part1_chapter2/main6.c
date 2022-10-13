#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *head;

void addFront(Node *root, int data) {
    Node *node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->next = root->next;
    root->next = node;
}

void removeFront(Node *root) {
    Node *front = root->next;
    root->next = front->next;
    free(front);
}

void freeAll(Node *root) {
    Node *cur = head->next;
    while (cur != NULL) {
        Node *next = cur->next;
        free(cur);
        cur = next;
    }
}

void showAll(Node *root) {
    printf("%d ", 11111);
    Node *cur = head->next;
    printf("%d ", 22222);
    while (cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
}

int main(void) {
    Node *head = (Node*) malloc(sizeof(Node));
    head->next = NULL;
    addFront(head, 2);
    addFront(head, 1);
    addFront(head, 7);
    addFront(head, 9);
    addFront(head, 8);
    removeFront(head);

    // showAll(head); Segmentation fault
    Node *cur = head->next;
    while (cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->next;
    }
    
    // freeAll(head); Segmentation fault
    while (cur != NULL) {
        Node *next = cur->next;
        free(cur);
        cur = next;
    }

    /* showAll 함수와 freeAll 함수를 호출해서 사용하려니 Segmentation fault가 났다.
     * 왜인지 찾지를 못해서 나중에 찾아보기로 한다..
     */

    return 0;
}