#include <iostream>
#include <set>

using namespace std;

int main(void) {
    int array[5] = { 2, 4, 6, 8, 10};

    // 2,4,6,8,10이 하나의 집합
    set<int> s(array, array + 5);
    set<int>::iterator iter = s.begin();
    for ( ; iter != s.end() ; iter++) {
        cout << *iter << ' ';
    }
    cout << '\n';
    s.insert(1);
    s.insert(3);
    s.insert(5);
    // 전체 데이터가 오름차순으로 정렬되어 출력됨
    iter = s.begin();
    for ( ; iter != s.end() ; iter++) {
        cout << *iter << ' ';
    }
    cout << '\n';

    return 0;
}