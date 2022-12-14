#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 1000

int a [SIZE];

int swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void) {
    int n;
    scanf("%d", &n);
    for (int i = 0 ; i < n ; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0 ; i < n - 1 ; i++) {
        int j = i;  // 어디에 들어갈지 정하는 대상우너소
        while (j >=0 && a[j] > a[j + 1]) {  // 현재 왼쪽에 있는 값이 크다면 오름차순으로 이동
            swap(&a[j], &a[j + 1]);
            j--;
        }
    }
    for (int i = 0 ; i < n ; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}