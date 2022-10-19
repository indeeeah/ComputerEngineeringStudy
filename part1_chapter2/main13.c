#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>
#define SIZE 1000

int a[SIZE];

int swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(void) {
    int n, min, index;  // min은 한번 검색 할때마다 가장 작은 값
    scanf("%d", &n);
    for (int i = 0 ; i < n ; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0 ; i < n ; i++) {
        min = INT_MAX;  // 작은값을 항상 선택하기 위해 일단 가장 큰 값을 넣어준다.

        // i부터 출발해서 n까지 가면서
        for (int j = i ; j < n ; j++) {
            // 현재 보고있는 원소가 min값보다 작다면
            if (min > a[j]) {
                min = a[j];
                // 가장 작은 값이 위치하는 곳이 index
                index = j;
            }
        }
        // 해당 i번째 값과 index의 값을 바꿔주면 됨
        swap(&a[i], &a[index]);
    }
    for (int i = 0 ; i < n ; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
