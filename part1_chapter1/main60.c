#include <stdio.h>
#include <stdlib.h>

int main(void){
    int *a = (int*) malloc(sizeof(int));
    printf("%d\n", a);
    free(a);
    a = (int*) malloc(sizeof(int));
    free(a);
    printf("%d\n", a);
    return 0;
}