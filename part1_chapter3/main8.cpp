#include <iostream>
#include <string>

using namespace std;

// 구조체
struct student {
    string name;
    int score;
};

int main(void) {
    struct student a;
    a.name = "김수민";
    a.score = 100;
    cout << a.name << " : " << a.score << "점\n";

    return 0;
}