#include <iostream>
#include <string>

using namespace std;

class Person {
    private:
        string name;
    public:
        Person(string name) : name(name) { }
        string getName() {
            return name;
        }
        void showName() {
            cout << "이름 : " << getName() << '\n';
        }
};

class Student : Person {
    private:
        int studentID;
    public:
        // 멤버변수 name은 Person으로부터 물려받음
        Student(int studentID, string name) : Person(name) {
            this->studentID = studentID;
        }
        void show() {
            cout << "학생 번호 : " << studentID << '\n';
            // getName()도 Person에서 가져옴
            cout << "학생 이름 : " << getName() << '\n';
        }
};

int main(void) {
    Student student(1, "김수민");
    student.show();

    return 0;
}