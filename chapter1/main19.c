#define _CRT_SECURE_NO_WARINGS
#include <stdio.h>

int main(void){
    int n;
    char a;
    scanf("%d %c", &n, &a);
    while (n--)
    {
        printf("%c ", a);
    }
    return 0;
}