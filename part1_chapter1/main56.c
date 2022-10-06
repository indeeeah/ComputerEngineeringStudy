#include <stdio.h>


int main(void){
    int a[5] = {1, 2, 3, 4, 5};
    int i;
    for(i = 0; i < 5; i++){
        printf("%d ", *(a+i));
        // printf("%d\n ", a+i);   // 자료형의 크기만큼 이동 (int 이므로 4byte)
    }
    return 0;
}