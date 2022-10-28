#include <iostream>
#include <string>

using namespace std;

// class : private을 써주지 않아도 멤버는 자동으로 private 문법을 따름
// 구조체는 기본적으로 public으로 간주
class Student {
    private:    // 내부적으로 변수를 포함. 외부적으로는 접근 불가. 멤버변수(property) 포함.
        string name;
        int score;
    public: // 일반적으로 다양한 함수 구현. 외부적으로 접근 가능. 멤버함수(method) 포함
        Student(string n, int s) {
            name = n;
            score = s;
        }
        void show() {
            cout << name << " : " << score << "점\n";
        }
};

int main(void) {
    Student a = Student("김수민", 100); // a 인스턴스(객체) 초기화
    a.show();

    return 0;
}