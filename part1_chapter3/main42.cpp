#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(void) {
    map<string, int> m; // 키가 string value가 int
    m["김수민"] = 1;
    m["홍길동"] = 2;
    m["이순신"] = 3;

    map<string, int>::iterator iter = m.begin();
    for( ; iter != m.end() ; iter++) {
        cout << iter->first << ":" << iter->second << '\n';
    }

    m["이태일"] = 4;
    cout << m["없는 사람"] << '\n'; // 0 출력(이태일)
    iter = m.begin();
    for( ; iter != m.end() ; iter++) {
        cout << iter->first << ":" << iter->second << "\n";
    }

    return 0;
}