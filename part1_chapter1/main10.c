#include <stdio.h>

int main(void){
    int a = 7;
    printf("%d\n", ++a);    // 8이 출력되고 종료 -> 8
    printf("%d\n", a++);    // 출력이 이루어진 다음에 더해짐 -> 8
    printf("%d\n", ++a);    // 8이 출력되고 종료 -> 10
    return 0;
}