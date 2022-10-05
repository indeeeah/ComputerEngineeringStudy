#include <stdio.h>


int main(void){
    int a[5] = {1, 2, 3, 4, 5};
    int *b = a;
    printf("%d\n", b[2]);
    return 0;
}