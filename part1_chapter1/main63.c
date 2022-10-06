#include <stdio.h>

void function(){
    printf("It's my function. ");
}

int main(void){
    printf("%d\n", function);   // 이름만 넣으면 주소값을 가져옴
    return 0;
}