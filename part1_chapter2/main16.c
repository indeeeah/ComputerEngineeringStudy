#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_VALUE 10001

int n, m;
int a[MAX_VALUE];   // 상당히 많은 메모리 소비가 있기 때문에 MAX_VALUE를 지정해줘야 함

int main() {
    scanf("%d", &n);
    for (int i = 0 ; i < n ; i++) {
        scanf("%d", &m);
        a[m]++;
    }
    for (int i = 0 ; i < MAX_VALUE ; i++) {
        while (a[i] != 0 ) {
            printf("%d ", i);
            a[i]--;
        }
    }

    return 0;
}