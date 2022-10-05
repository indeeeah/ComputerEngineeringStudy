#include <stdio.h>
#include <limits.h>

int main(void){
    int a[10] = { 6, 5, 4, 3, 9, 8, 0, 1, 2, 7};
    int i, maxValue = INT_MIN;  // limits.h에 있는 약 -20억의 수 INT_MAX도 있다.
    for (i = 0 ; i < 10 ; i++) {
        if(maxValue < a[i]){
            maxValue = a[i];
        }
    }
    printf("%d\n", maxValue);
    return 0;
}