#include <stdio.h>

int add(int a, int b){
    return a+b;
}

int main(void){
    printf("%d\n", add(10, 20));
    return 0;
}