#define _CRT_SECURE_NO_WARINGS
#include <stdio.h>

int main(void){
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", a > b);  // 첫번째 값이 더 크면 1, 작으면 0 출력
    return 0;
}