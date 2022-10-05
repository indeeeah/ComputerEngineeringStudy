#define _CRT_SECURE_NO_WARINGS  // 없어도 빌드가 됐음... 머징?
#include <stdio.h>

int main(void){
    int a;
    scanf("%d", &a);    // 보안에 취약한 함수로 VSCode에서 _CRT_SECURE_NO_WARINGS이 없으면 Error를 발생시킨다고 한다.
    // &기호는 특정한 변수의 주소를 의미
    // %는 int 정수형 데이터를 입력 및 출력
    // double형 데이터는 입력 받을 때 %lf를 사용하고 출력할 때 %f를 사용하는데 둘이 다른 이유는 출력할 때 주소가 아닌 값 자체를 이용해 출력하기 떄문에 구체적인 크기를 지정하지 않아도 됨.
    // % 자체를 문자로 출력하고 싶으면 %%로 해야 함
    printf("입력한 숫자는 %d입니다. \n", a);
    return 0;
}