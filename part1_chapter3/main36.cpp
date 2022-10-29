#include <iostream>
#include <stack>

using namespace std;

int main(void) {
    stack<int> s;   // template형태로 되어있음
    
    s.push(7);
    s.push(5);
    s.push(4);
    s.pop();
    s.push(6);
    s.pop();
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

    return 0;
}