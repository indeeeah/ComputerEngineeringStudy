#include <iostream>

// std::를 쓰기 귀찮으면
using namespace std;

int main(void) {
    string input;
    cin >> input;   // >>는 공백을 기준으로 입력을 받음
    for (int i = 0 ; i < input.size() ; i++) {
        cout << input[i] << '\n';
    }

    return 0;
}