#include <iostream>

using namespace std;

int main(void) {
    int* arr = new int[10];
    arr[7] = 100;

    shared_ptr<int> p1(arr);
    cout << p1.use_count() << '\n'; // 1
    shared_ptr<int> p2(p1);
    cout << p1.use_count() << '\n'; // 2
    shared_ptr<int> p3 = p2;
    cout << p1.use_count() << '\n'; // 3

    p1.reset();
    p2.reset();

    cout << "arr[7] : " << arr[7] << '\n';
    p3.reset();

    // 원래 동적 할당 해제해줘야되는데 되지 않음. 그래서 값이 제대로 나오지 않음
    cout << p1.use_count() << '\n';
    cout << "arr[7] : " << arr[7] << '\n';

    return 0;
}