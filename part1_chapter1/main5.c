#define _CRT_SECURE_NO_WARINGS
#include <stdio.h>

int main(void){
    int a, b, c;
    scanf("%1d%1d%1d", &a, &b, &c); // 한자리씩 끊어서 입력받기
    printf("%d %d %d\n", a, b, c);
    return 0;
}