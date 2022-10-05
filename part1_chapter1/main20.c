#define _CRT_SECURE_NO_WARINGS
#include <stdio.h>

int main(void){
    int n;
    scanf("%d", &n);
    int i = 1;
    while (i <= 9){
        printf("%d * %d = %d\n", n, i, n * i);
        i++;
    }
    
    return 0;
}