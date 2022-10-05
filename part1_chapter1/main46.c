#include <stdio.h>
#include <string.h>

int main(){
    char a[40] = "Soomini hihihihihihi";
    char b[40] = "hihihihihihi";
    strcat(a, b);
    printf("찾은 문자열: %s\n", strstr(a, b));
    return 0;
}