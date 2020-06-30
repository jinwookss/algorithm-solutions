# Next Greater Element

정수형 배열이 주어졌을 때, 각 원소의 오른쪽에서 첫 번째로 더 큰 값을 갖는 원소를 찾는 알고리즘.

스택을 이용하면 시간 복잡도 O(n)으로 풀이가 가능하다.

1. 원소들을 하나씩 순회하는 루프문에서 다음 로직을 수행한다.
   1. 스택이 비어있다면 현재 원소를 push한다.
   2. 스택이 비어있지 않다면, top과 현재 원소를 비교한다.
   3. top이 더 크다면, top이 더 작을 떄까지 스택에서 pop을 수행한다. 이 때, 현재 원소가 pop 원소의 첫 번째로 더 큰 값을 갖는 원소가 된다.
   4. 현재 원소를 스택에 push한다.
2. 루프가 종료 이후에 스택에 남은 원소들은 오른쪽에 더 큰 값을 갖는 원소가 없는 원소들이다.

```c++
void printNextGreaterElement(vector<int> &v) {
    stack<int> s;

    for (int i = 0; i < v.size(); i++) {
        while (!s.empty() && s.top() < v[i]) {
            cout << v[i] << " ";
            s.pop();
        }

        s.push(v[i]);
    }

    while (!s.empty()) {
        cout << "-1 ";
        s.pop();
    }
    cout << endl;
}
```

## 응용 문제

[Maximum of minimum for every window size]([../../../HackerRank/KakaoEnterprise/DiskSpaceAnalysis/](https://practice.geeksforgeeks.org/problems/maximum-of-minimum-for-every-window-size/0))