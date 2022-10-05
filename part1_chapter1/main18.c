#define _CRT_SECURE_NO_WARINGS
#include <stdio.h>

int main(void){
    int sum = 0;
    for (; 1;){ // 1이 없어도 됨. for(;;) 동일하게 무한루프
        int x;
        scanf("%d", &x);
        if(x == -1){
            break;
        }
        sum += x;
    }
    printf("%d\n", sum);
    return 0;
}