#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 10000

void radixSort(int *a, int n) {
    int res[MAX];   // 결과 배열
    int maxValue = 0;
    int exp = 1;

    for (int i = 0 ; i < n ; i++) {
        if (a[i] > maxValue) {
            maxValue = a[i];
        }
    }

    while (maxValue / exp > 0) {    // 1의 자립무터 계산
        int bucket[10] = { 0 }; // 자릿수
        for (int i = 0 ; i < n ; i++) { // 자릿수 배열 처리
            bucket[a[i] / exp % 10]++;
        }

        for (int i = 1 ; i < 10 ; i++) {    // 누적 계산
            bucket[i] += bucket[i - 1];
        }

        for (int i = n - 1 ; i >= 0 ; i--) {    // 같은 자릿수 끼리는 순서를 유지
            res[--bucket[a[i] / exp % 10]] = a[i];
        }

        for (int i = 0 ; i < n; i++) {  // 기본 배열 갱신
            a[i] = res[i];
        }

        exp *=10;   // 10이 곱해지기 때문에 while문을 돌때마다 다음 자릿수를 계산하게 됨
    }
}

int main(void) {
    int a[MAX];
    int i, n;
    scanf("%d", &n);
    for (i = 0 ; i < n ; i++) {
        scanf("%d", &a[i]);
    }
    radixSort(a, n);
    for(i = 0 ; i < n ; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}