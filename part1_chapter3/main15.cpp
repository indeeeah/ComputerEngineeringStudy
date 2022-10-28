#include <iostream>
#include <string>

using namespace std;

class Character {
    private:
        string name;
        int ragePoint;
        int hp;
        int damage;
    public:
        Character(string name, int hp, int damage) : name(name), ragePoint(0), hp(hp), damage(damage) { }
        ~Character() {  // 객체가 소멸 될때
            cout << "[객체가 소멸됩니다.]\n";
        }
        void pointUp() {
            ragePoint++;
        }
        void show() {
            cout << name << "[" << ragePoint << "] " << hp << " " << damage << '\n';
        }
};

int main(void) {
    Character* character1 = new Character("슬라임", 10, 20);    // 동적할당
    character1->pointUp();
    Character character2(*character1);
    character2.pointUp();
    character1->show();
    character2.show();

    delete character1;  // 동적 할당을 이용했으므로 성공적으로 소멸됨
    // delete &character2; // 동적 할당을 이용하지 않았으므로 오류가 발생함

    return 0;
}