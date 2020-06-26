# DFS

## DFS using Stack

재귀 함수가 [콜 스택](https://ko.wikipedia.org/wiki/%EC%BD%9C_%EC%8A%A4%ED%83%9D)에 쌓이듯이 `stack` 을 이용하여 특정 조건을 만족하면 현재 상태와 다음 상태를 스택에 저장하는 방식을 이용한다.

```c++
void dfs_stack(int start) {
    stack<int> s;
    s.push(start);

    while (!s.empty()) {
        int cur = s.top();
        s.pop();

        for (int i = 0; i < 4; i++) {
            // Do something
            int next; //  Set next
            if (condition) {
                s.push(cur); // Must push 'cur' to go back to 'cur' later
                s.push(next);
            }
        }
    }
}
```

## DFS using Recursion

```c++
void dfs_recursion(int cur) {
    // Set terminate condition
    for (int i = 0; i < 4; i++) {
        // Do something
        int next; // Set next
        dfs_recursion(next);
    }
}
```

## DFS를 이용하여 풀 수 있는 문제

- [BOJ - 2048](../../BOJ/samsung/12100_2048/)
- [BOJ - 퇴사](../../BOJ/samsung/14501_퇴사/)
- [BOJ - 연구소](../../BOJ/samsung/14502_연구소/)
- [BOJ - 로봇 청소기](../../BOJ/samsu/../samsung/14503_로봇청소기/)
- [BOJ - 연산자 끼워넣기](../../BOJ/samsung/14888_연산자끼워넣기/)
- [BOJ - 스타트와 링크](../../BOJ/samsung/14889_스타트와링크/)
- [BOJ - 감시](../../BOJ/samsung/15683_감시/)