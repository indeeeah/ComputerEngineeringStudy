#include <stdio.h>
#include <string.h>

int main(){
    char a[20] = "Soomini";
    char b[20] = "hihihihihihi";
    printf("두 배열의 사전 순 비교: %d\n", strcmp(a, b));
    return 0;
}