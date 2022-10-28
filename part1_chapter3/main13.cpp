#include <iostream>
#include <string>

using namespace std;

class Character {
    private:
        string name;
        int ragePoint;
        int hp;
        int damage;
    public: // 별도로 생성자를 구현하지 않으면 기본생성자가 사용되고 0또는 null 등의 값으로 초기화 됨
        void show() {
            cout << name << "[" << ragePoint << "] " << hp << " " << damage << '\n';
        }
};

int main(void) {
    Character character = Character();
    character.show();

    return 0;
}