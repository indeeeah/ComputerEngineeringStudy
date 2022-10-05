#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(){
    char a[100];
    gets(a);    // scnf()와 다르게 공백까지 포함하여 한 줄을 입력받음
    printf("%s\n", a);
    return 0;
}