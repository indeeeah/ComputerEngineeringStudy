#include <stdio.h>

int main(void){
    int a[2][5] = {{1,2,3,4,5}, {6,7,8,9,10}};
    // int (*p)[5] = (int*) a[1]; // 행을 의미하는 포인터.. 왜 에러나는지 모르겠음 ㅠㅠ
    int i;
    for(i=0; i < 5; i++){
        // printf("%d ", p[0][i]);
    }
    return 0;
}