#include <iostream>
#include <string>

using namespace std;

class Person {
    private:
        string name;
    public:
        static int count;   // 외부에서 쉽게 접근이 가능하나 초기화가 되어있지 않음
        Person(string name) : name(name) {
            count++;
        }
};

int Person:: count = 0; // Person이 가지고 있는 정적변수 count를 0으로 초기화

int main(void) {
    Person p1("김수민");
    Person p2("이순신");
    Person p3("홍길동");
    cout << "사람의 수 : " << Person::count << '\n';

    return 0;
}