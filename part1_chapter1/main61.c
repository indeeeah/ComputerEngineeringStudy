#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    char *a = (char*) malloc(100);
    memset(a, 'A', 100);
    for (int i = 0 ; i<100 ; i++){
        printf("%c ", a[i]);
    }
    return 0;
}