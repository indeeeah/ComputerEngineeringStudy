#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(){
    int a; char c;
    scanf("%d", &a);
    printf("%d\n", a);
    int temp;
    // 한 자씩 받아서 파일의 끝이거나 개행 문자(줄바꿈)를 만나면 입력을 멈ㅊ므로 항상 입력 버퍼를 비운다.
    while (((temp = getchar()) != EOF && temp != '\n')){ }  // EOF : end of file
    scanf("%c", &c);
    printf("%c\n", c);
    return 0;
}