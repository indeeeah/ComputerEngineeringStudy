#include <iostream>
#include <string>

using namespace std;

class Student {
    private:
        string name;
        int englishScore;
        int mathScore;
        int getSum() {  // 정보 은닉
            return englishScore + mathScore;
        }
    public:
        Student(string n, int e, int m) {
            name = n;
            englishScore = e;
            mathScore = m;
        }
        void show() {
            cout << name << " : [함계 " << getSum() << "점]\n";
        }
};

int main(void) {
    Student a = Student("김수민", 100, 98);
    a.show();
    // cout << a.getSum(); // private 접근 한정자는 외부에서 접근할 수 없음 Error
    return 0;
}