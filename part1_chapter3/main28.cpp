#include <iostream>
#include <string>

using namespace std;

template <typename T>

// string이라고 자료형을 기입하지 않았는데 동작함.
void change(T& a, T& b) {
    T temp;
    temp = a;
    a = b;
    b = temp;
}

template <>
// int형일때는 이 함수가 호출되고 아닌 경우에는 위의 함수가 호출됨
// 명시적 특수화
void change<int>(int& a, int& b) {
    cout << "정수형 데이터를 교체합니다.\n";
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int main(void) {
    string a = "김수민";
    string b = "홍길동";
    change(a, b);
    cout << a << ":" << b << endl;

    return 0;
}