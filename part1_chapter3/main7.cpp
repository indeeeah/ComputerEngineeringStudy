#include <iostream>
#define SIZE 100

using namespace std;

int *arr;

int main(void) {
    arr = new int[SIZE];    // 동적할당 (c언어에서 쓴것처럼 malloc함수를 쓰지 않는다)
    for (int i = 0 ; i < SIZE ; i++) {
        arr[i] = i;
    }
    for (int i = 0 ; i < SIZE ; i++) {
        cout << arr[i] << ' ';
    }
    delete arr; // 할당 해제 (free 함수 대신)

    return 0;
}