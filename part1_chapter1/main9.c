#define _CRT_SECURE_NO_WARINGS
#include <stdio.h>

int main(void){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    printf("%d\n", !a); // 0이 아니면 참
    printf("%d\n", a && b);
    printf("%d\n", (a > b) && (b > c));
    return 0;
}