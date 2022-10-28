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

class Student: Person {
    private:
        int studentID;
    public:
        Student(int studentId, string name) : Person(name) {
            this->studentID = studentID;
        }
        void show() {
            cout << "학생 번호 : " << studentID << '\n';
            cout << "학생 이름 : " << getName() << '\n';
        }

        // Student에서 재정의된 것으로 따라감
        void showName() {
            cout << "학생 이름 : " << getName() << '\n';
        }
};

int main(void) {
    Student student(1, "김수민");
    student.showName();
    return 0;
}