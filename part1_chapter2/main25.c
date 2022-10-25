#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define INF 99999999
#define MAX_SIZE 1001

typedef struct Node {
    int index;
    struct Node *next;
} Node;

typedef struct Queue {
    Node *front;
    Node *rear;
    int count;
} Queue;

Node** a;
int n, m, c[MAX_SIZE];

void addFront(Node *root, int index) {
    Node *node = (Node*) malloc(sizeof(Node));
    node->index = index;    // 넣고자하는 값
    node->next = root->next;
    root->next = node;
}

void queuePush(Queue *queue, int index) {
    Node *node = (Node*) malloc(sizeof(Node));
    node->index = index;
    node->next = NULL;

    // 현재 큐가 비어있다면
    if (queue->count == 0) {
        queue->front = node;
    } else {
        queue->rear->next = node;   // 큐가 비어있지않다면 큐의 꼬리부분에 노드 추가
    }

    // 큐에 꼬리에는 항상 노드가 있음
    queue->rear = node;
    queue->count++;
}

int queuePop(Queue *queue) {
    if (queue->count == 0) {
        printf("큐 언더플로우가 발생했습니다.\n");
        return -INF;
    }

    Node *node = queue->front;
    int index = node->index;
    queue->front = node->next;
    free(node);
    queue->count--;
    return index;
}

void bfs(int start) {
    Queue q;
    q.front = q.rear = NULL;
    q.count = 0;

    queuePush(&q, start);   // 시작 인덱스
    c[start] = 1;   // 방문처리

    while (q.count != 0) {
        int x = queuePop(&q);
        printf("%d ", x);

        Node *cur = a[x]->next;
        while (cur != NULL) {
            int next = cur->index;

            if (!c[next]) {
                queuePush(&q, next);
                c[next] = 1;
            }
            cur = cur->next;
        }
    }
}

int main(void) {
    scanf("%d %d", &n, &m);
    a = (Node**) malloc(sizeof(Node*) * (MAX_SIZE));
    for (int i = 1 ; i <= n ; i++) {
        a[i] = (Node*) malloc(sizeof(Node));
        a[i]->next = NULL;
    }
    for (int i = 0 ; i < m ; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        addFront(a[x], y);
        addFront(a[y], x);
    }
    bfs(1);

    return 0;
}