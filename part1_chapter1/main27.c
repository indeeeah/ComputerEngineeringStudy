#include <stdio.h>

int main(void){
    // int a[10] = { 6, 5, 4, 3, 9, 8, 0, 1, 2, 7};
    int a[10] = {0,};   // 0으로 채워짐
    int i;
    for (i = 0 ; i < 10 ; i++) {
        printf("%d\n", a[i]);
    }
    return 0;
}