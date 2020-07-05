#include <iostream>
#include <vector>
#include <deque>

using namespace std;

void solution(vector<int> &v, int k) {
    // k개의 원소를 저장할 deque 생성
    deque<int> d;

    // 첫 번째 인덱스부터 k개의 인덱스를 순회
    for (int i = 0; i < k; i++) {
        // 현재 인덱스의 원소보다 작은 back 인덱스의 원소들을 삭제 후 현재 인덱스를 삽입
        while (!d.empty() && v[d.back()] < v[i]) {
            d.pop_back();
        }
        d.push_back(i);
    }

    // k 부터 마지막 인덱스까지 순회
    for (int i = k; i < v.size(); i++) {
        // front 원소를 출력
        cout << v[d.front()] << endl;
        // 윈도우 범위를 벗어나는 원소 삭제
        while (!d.empty() && d.front() <= i - k) {
            d.pop_front();
        }
        // 현재 인덱스의 원소보다 작은 back 인덱스의 원소들을 삭제 후 현재 인덱스를 삽입
        while (!d.empty() && v[d.back()] < v[i]) {
            d.pop_back();
        }
        d.push_back(i);
    }
    cout <<v[d.front()] << endl;
}

int main() {
    vector<int> v = { 12, 1, 78, 90, 57, 89, 56 };
    solution(v, 3);

    return 0;
}