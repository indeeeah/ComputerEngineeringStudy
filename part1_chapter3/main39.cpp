#include <iostream>
#include <deque>

using namespace std;

int main(void) {
    deque<int> d;
    d.push_front(3);
    d.push_back(7);
    d.pop_front();
    d.push_front(4);

    for (int i = 0 ; i < d.size() ; i++) {
        cout << d[i] << ' ';
    }
    cout << '\n';   // 4 7
    
    // 시퀀스
    deque<int>::iterator iter;
    iter = d.begin();   // 첫번째원소
    d.insert(iter + 1, 3, 5);   // 첫번째원소의 + 1번째 원소
    // 4 5 5 5 7

    iter = d.begin();
    d.insert(iter + 1, 1, 9);
    // 4 9 5 5 5 7

    for (int i = 0 ; i < d.size() ; i++) {
        cout << d[i] << ' ';
    }
    cout << '\n';

    d.clear();
    cout << d.empty() << '\n';  // 비어있으면 1을 출력함

    return 0;
}