#include <iostream>
#include <string>

using namespace std;

class Person {
    private:
        const int id;   // 상수처리
        string name;
    public:
        static int count;
        Person(int id, string name) : id(id), name(name) {
            count ++;
        }
        // 상수이기 떄문에 값을 변경할 수 없음
        // void setId(int id) {
        //     this->id = id;  // 오류 발생 수정 불가능
        // }
};

int Person::count = 0;

int main(void) {
    Person p1(1, "김수민");
    Person p2(2, "이순신");
    Person p3(3, "홍길동");
    cout << "사람의 수 : " << Person::count << '\n';

    return 0;
}