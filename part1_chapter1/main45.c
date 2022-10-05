#include <stdio.h>
#include <string.h>

int main(){
    char a[30] = "Soomini";
    char b[20] = "hihihihihihi";
    strcat(a, b);
    printf("합쳐진 결과 문자열: %s\n", a);
    return 0;
}