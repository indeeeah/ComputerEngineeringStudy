#define _CRT_SECURE_NO_WARINGS
#include <stdio.h>

int main(void){
    double a;
    scanf("%lf", &a);
    printf("%.2f\n", a); // 소숫점 2번째까지 출력하겠다.
    return 0;
}