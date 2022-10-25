#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_SIZE 10000

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

typedef struct priorityQueue {
    int heap[MAX_SIZE];
    int count;
} priorityQueue;

void push(priorityQueue *pq, int data) {
    if (pq->count >= MAX_SIZE) {
        return ;
    }
    pq->heap[pq->count] = data; // 항상 완전이진트리의 마지막 원소로 들어가게 됨
    int now = pq->count;    // now = 삽입된 위 데이터에 대한 인덱스
    int parent = (pq->count - 1) / 2;   // now에 1을 빼고 2로 나눈 값

    // 새 원소를 삽입한 이후에 상향식으로 힙을 구성합니다.
    // 자신의 위치가 부모보다 크다면 스왑으로 바꿔준다.
    while (now > 0 && pq->heap[now] > pq->heap[parent]) {
        swap(&pq->heap[now], &pq->heap[parent]);
        now = parent;
        parent = (parent - 1) / 2;
    }
    pq->count++;
}

int pop(priorityQueue *pq) {
    if (pq->count <= 0) {
        return -9999;
    }
    int res = pq->heap[0];  // 추출할 원소, 즉 루트 노드
    pq->count--;
    pq->heap[0] = pq->heap[pq->count];  // 해당 루트노드에 가장 마지막 원소를 넣음
    int now = 0;
    int leftChild = 1;
    int rightChild = 2;
    int target = now;   // 자기 자신

    // 새 원소를 추출한 이후에 하향식으로 힙을 구성합니다.
    while (leftChild < pq->count) {
        if (pq->heap[target] < pq->heap[leftChild]) {
            target = leftChild;
        }
        if (pq->heap[target] < pq->heap[rightChild] && rightChild < pq->count) {
            target = rightChild;
        }
        // 더 이상 내려가지 않아도 될 떄 종료
        if (target == now) {
            break;
        }
        else {
            swap(&pq->heap[now], &pq->heap[target]);
            now = target;
            leftChild = now * 2 + 1;
            rightChild = now * 2 + 2;
        }
    }
    return res;
}

int main(void) {
    int n, data;
    scanf("%d", &n);
    priorityQueue pq;
    pq.count = 0;
    for (int i = 0 ; i < n ; i++) {
        scanf("%d", &data);
        push(&pq, data);
    }
    for (int i = 0 ; i < n ; i++) {
        int data = pop(&pq);
        printf("%d ", data);
    }

    return 0;
}