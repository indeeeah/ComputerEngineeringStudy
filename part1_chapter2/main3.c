#include <stdio.h>
#include <stdlib.h>

// 동적할당을 이용하겠다.
typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *head;

int main(void) {
    head = (Node*) malloc(sizeof(Node));    // 연결리스트의 시작 노드 필요한 만큼만 메모리 할당
    Node *node1 = (Node*) malloc(sizeof(Node)); // 필요한 만큼만 메모리 할당
    node1->data = 1;
    Node *node2 = (Node*) malloc(sizeof(Node)); // 필요한 만큼만 메모리 할당
    node2->data = 2;

    head->next = node1;
    node1->next = node2;
    node2->next = NULL; // 무조건 마지막은 NULL값으로 해야 함

    Node *cur = head->next;
    
    while (cur != NULL) {
        printf("%d ", cur->data);
        cur = cur->next;
    }

    return 0;
}