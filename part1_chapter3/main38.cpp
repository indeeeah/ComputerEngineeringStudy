#include <iostream>
#include <queue>

using namespace std;

int main(void) {
    int n, x;
    cin >> n;
    priority_queue<int> pq;
    for (int i = 0 ; i < n ; i++) {
        cin >> x;
        pq.push(x);
    }
    while (!pq.empty()) {
        cout << pq.top() << ' ';
        pq.pop();
    }
    
    return 0;
}