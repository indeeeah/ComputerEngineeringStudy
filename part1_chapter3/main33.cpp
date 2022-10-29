#include <iostream>

using namespace std;

int main(void) {
    int* arr = new int[10]; // 동적할당
    unique_ptr<int> p1(arr);    // 스마트 포인터가 arr 관리
    for (int i = 0 ; i < 10 ; i++) {
        arr[i] = i;
    }
    for (int i = 0 ; i < 10 ; i++) {
        cout << arr[i] << ' ';
    }
    p1.reset();
    cout << '\n';

    // reset() 으로 메모리 해제 후에는 쓰레기값만 출력됨
    for (int i = 0 ; i < 10 ; i++) {
        cout << arr[i] << ' ';
    }
    return 0;
}