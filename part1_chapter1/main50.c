#include <stdio.h>

int main(void){
    register int a = 10, i;
    for(i = 0 ; i < a ; i++){
        printf("%d ", i);
    }
    return 0;
}