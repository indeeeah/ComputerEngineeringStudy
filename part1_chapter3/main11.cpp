#include <iostream>
#include <string>

using namespace std;

class Student {
    private:
        string name;
        int englishScore;
        int mathScore;
        int getSum() {
            return englishScore + mathScore;
        }
    public:
        Student(string name, int englishScore, int mathScore) {
            this->name = name;  //자기 자신의 멤버 변수에 접근
            this->englishScore = englishScore;
            this->mathScore = mathScore;
        }
        void show() {
            cout << name << " : [합계 " << getSum() << "점]\n";
        }
};

int main(void) {
    Student a = Student("김수민", 100, 98);
    a.show();
    return 0;
}