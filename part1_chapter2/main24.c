#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1001

typedef struct Node {
    int index;
    struct Node *next;
} Node;

Node** a;   // 정점이 여러개라고 가정하기 때문에 이차원 포인터로 할당
int n, m, c[MAX_SIZE];  // c는 방문을 했는지 확인하는 변수, n은 정점, m은 간선

// 스택 연결리스트처럼 만들었음
void addFront(Node *root, int index) {
    Node *node = (Node*) malloc(sizeof(Node));
    node->index = index;
    node->next = root->next;
    root->next = node;
}

void dfs(int x) {

    // 현재 노드를 방문했다고 하면 return; 해줌
    if (c[x]) {
        return ;
    }
    // 방문 처리
    c[x] = 1;
    printf("%d", x);

    Node *cur = a[x]->next;

    while (cur != NULL) {
        int next = cur->index;
        dfs(next);
        cur = cur->next;
    }
}

int main(void) {
    scanf("%d %d", &n, &m);
    a = (Node**)malloc(sizeof(Node*) * (MAX_SIZE));
    for (int i = 1 ; i <= n ; i++) {
        a[i] = (Node*)malloc(sizeof(Node));
        a[i]->next = NULL;
    }
    for (int i = 0 ; i < m ; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        addFront(a[x], y);  // x라는 정점에서 y로 갈수있다
        addFront(a[y], x);  // y라는 정점에서 x로 갈수있다
    }
    dfs(1);

    return 0;
}