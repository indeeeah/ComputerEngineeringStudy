#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 1000

int a [SIZE];

int swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quickSort(int start, int end) {
    if (start >= end) {
        return;
    }
    int key = start;    // 피벗값을 부분배열의 첫번째 원소가 되도록 만들어줌
    int i = start + 1;  // 왼쪽에서 출발
    int j = end;    // 오른쪽에서 출발
    int temp;
    while (i <= j) { // 엇갈릴 떄까지 반복합니다. i가 j보다 커졌을 때는 엇갈린 순간이기 때문
        while (i <= end && a[i] <= a[key]) {
            i++;
        }
        while (j > start && a[j] >= a[key]) {
            j--;
        }
        // i와 j가 엇갈린 상태라면 스왑
        if (i > j) {
            swap(&a[key], &a[j]);
        } else {
            swap(&a[i], &a[j]);
        }
    }

    // 재귀적으로 두번 호출하게 만듦
    quickSort(start, j - i);
    quickSort(j + 1, end);
}

int main(void) {
    int n;
    scanf("%d", &n);    // 원소의 개수가 다섯개인 것을 알려주는 것
    for (int i = 0 ; i < n ; i++) {
        scanf("%d", &a[i]);
    }
    quickSort(0, n - 1);
    for (int i = 0 ; i < n ; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}