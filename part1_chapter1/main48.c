#include <stdio.h>

int main(void){
    int a = 7;
    if(1){
        int a = 5;
    }
    printf("%d", a);
    return 0;
}