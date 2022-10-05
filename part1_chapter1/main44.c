#include <stdio.h>
#include <string.h>

int main(){
    char a[20] = "Soomini";
    char b[20] = "hihihihihihi";
    strcpy(a, b);   // a = b
    printf("복사된 문자열: %s\n", a);
    return 0;
}