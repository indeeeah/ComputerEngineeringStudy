#include <iostream>

using namespace std;

// class A {
//     public:
//         virtual void show()=0 { // 왜 안되는지 모르겠다..
//             cout << "A 클래스입니다." << endl; 
//         }
// };

// class B : public A {
//     // show() 함수를 재정의 하지 않으면 B 클래스의 객체를 사용할 수 없다.
//     public:
//         virtual void show() {
//             cout << "B 클래스입니다." << endl;
//         }

// };

// int main(void) {
//     A* p;
//     B b;
//     p = &b;
//     p->show();

//     return 0;
// }