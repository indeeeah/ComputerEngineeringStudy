#include <stdio.h>

void myFunction(){
    printf("It's my function. \n");
}
void yourFunction(){
    printf("It's your function. \n");
}

int main(void){
    void(*fp)() = myFunction;
    fp();
    fp = yourFunction;
    fp();
    return 0;
}