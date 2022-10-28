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
        Character(string name, int hp, int damage) {
            this->name = name;
            this->ragePoint = 0;
            this->hp = hp;
            this->damage = damage;
        }
        void show() {
            cout << name << "[" << ragePoint << "] " << hp << " " << damage << '\n';
        }
};

int main(void) {
    Character character = Character("슬라임", 50, 10);
    character.show();

    return 0;
}