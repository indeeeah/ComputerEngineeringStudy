#include <stdio.h>

void dice(int input){   // return 항목이 없기 때문에 void로 처리
    printf("수민이가 던진 주사위: %d\n", input);
}

int main(void){
    dice(3);
    dice(5);
    dice(1);
    return 0;
}