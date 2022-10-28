#include <iostream>
#include <string>

using namespace std;

class Person {
    private:
        string name;
    public:
        Person() {
            name = "임꺽정";
        }
        Person(string name) : name(name) { }

        // operator + 라고 연산자를 오버로딩 하겠다고 명시함
        Person operator + (const Person& other) {
            return Person(name + " & " + other.name);
        }
        void showName() {
            cout << "이름 : " << name << '\n';
        }
};

int main(void) {
    Person person1;
    Person person2("김수민");
    Person result = person1 + person2;
    result.showName();

    return 0;
}