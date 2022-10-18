#include <stdio.h>
#include <stdlib.h>

#define INF 99999999

typedef struct Node {
    int data;
    struct Node *next;  // 다음 노드와 연결될 수 있게 next를 만들어줘야 함
} Node;

typedef struct Stack {
    Node *top;  // 모든 스택은 top이라는 node를 가지고 있으면 된다.
} Stack;

void push(Stack *stack, int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->next = stack->top;
    stack->top = node;  // 항상 처음 들어온 노드가 탑이기 때문에 탑으로 해줌
}

int pop(Stack *stack) {
    if (stack->top == NULL) {
        printf("스택 언더플로우가 발생했습니다.\n");
        return -INF;
    }
    Node *node = stack->top;    // 최상단 노드에 잠시 넣으둠
    int data = node->data;  // 최상단 노드의 데이터 추출
    stack->top = node->next;    // 스택의 탑은 최상단 노드의 next
    free(node); // node 메모리 할당 해제
    return data;
}

void show(Stack *stack) {
    Node *cur = stack->top;
    printf("--- 스택의 최상단 --- \n");
    while (cur != NULL) {
        printf("%d\n", cur->data);
        cur = cur->next;
    }
    printf("--- 스택의 최하단 --- \n");
}

int main(void) {
    Stack stack;
    stack.top = NULL;   // 반드시 NULL값을 넣어주어야 한다.
    show(&stack);
    push(&stack, 7);
    push(&stack, 5);
    push(&stack, 4);
    pop(&stack);
    push(&stack, 6);
    pop(&stack);
    show(&stack);
    return 0;
}