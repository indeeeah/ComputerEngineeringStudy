#include <iostream>
#include <string>

using namespace std;

class Person {
    private:
        string name;
    public:
        // 생성자가 동일하지만 매개변수가 있음과 없음이 있음
        // 매개변수때문에 서로 다르게 초기화를 할 수 있다.
        Person() {
            name = "임꺽정";
        }
        Person(string name) : name(name) { }
        void showName() {
            cout << "이름 : " << name << '\n';
        }
};

int main(void) {
    Person person1;
    person1.showName();
    Person person2("김수민");
    person2.showName();

    return 0;
}