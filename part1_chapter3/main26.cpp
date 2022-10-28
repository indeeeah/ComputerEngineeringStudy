#include <iostream>

using namespace std;

class A {
    public:
        // virtual 키워드 : 가상함수
        // 가상함수를 사용하면 동적 바인딩이 적용이 된다.
        // 추가적인 컴퓨팅 리소스를 소모하기 떄문에 기본적으로 정적 바인딩을 채택함
        virtual void show() {
            cout << "A 클래스입니다." << endl;
        }
};

class B : public A {
    virtual void show() {
        cout << "B 클래스입니다." << endl;
    }
};

int main(void) {
    A* p;
    A a;
    B b;
    p = &a; 
    p->show();
    p = &b; // b라는 클래스의 인스턴스 주소
    p->show();

    return 0;
}