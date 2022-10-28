#include <iostream>

using namespace std;

class A {
    public:
        void show() {
            cout << "A 클래스입니다." << endl;
        }
};

class B : public A {
    void show() {
        cout << "B 클래스입니다." << endl;
    }
};

int main(void) {
    // p라는 포인터가 A로 명시가 되어있기 때문에 다형성 기법을 사용하기 어렵다.
    // B라는 함수를 상속받음에도 불구하고 B를 사용할 수 없다.
    // 일반적인 함수의 정적 바인딩의 문제라고 할 수 있다.
    A* p;   

    A a;
    B b;
    p = &a;
    p->show();
    p = &b;
    p->show(); // 여전히 A클래스의 show() 함수를 호출합니다.

    return 0;
}