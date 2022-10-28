#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string input;
    getline(cin, input);    // 한줄을 모두 문자열 형태로 입력받고자 한다면 getline() 함수 사용
    for(int i = 0 ; i < input.size() ; i++) {
        cout << input[i] << '\n';
    }
    return 0;
}