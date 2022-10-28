#include <iostream>
#include <string>

using namespace std;

class Student {
    private:
        int studentId;
        string name;
    public:
        Student(int studentId, string name) : studentId(studentId), name(name) { }

        // friend 키워드를 이용해 이름에 private 멤버 변수에 즉시 접속할 수 있음
        // friend 키워드가 없으면 연산자 오버로딩을 사용할 수 없다. 매개변수를 하나만 받기 떄문에
        // friend 키워드를 없애고 매개변수를 하나만 사용하는 방법도 있다.
        friend Student operator + (const Student &student, const Student &other) {
            return Student(student.studentId, student.name + " & " + other.name);
        }
        void showName() {
            cout << "이름 : " << name << '\n';
        }
};

int main(void) {
    Student student(1, "김수민");
    Student result = student + student;
    result.showName();

    return 0;
}