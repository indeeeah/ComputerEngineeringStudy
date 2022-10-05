#include <stdio.h>

int main(void){
    char a[20] = "Hello World";
    a[4] = ',';
    printf("%s\n", a);
    return 0;
}