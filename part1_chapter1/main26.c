#define _CRT_SECURE_NO_WARINGS
#include <stdio.h>

int factorial(int a){
    if (a==1){
        return 1;
    }else{
        return a * factorial(a-1);
    }
}

int main(void){
    int n;
    printf("n 팩토리얼을 시작합니다. ");
    scanf("%d", &n);
    printf("%d\n", factorial(n));
    return 0;
}