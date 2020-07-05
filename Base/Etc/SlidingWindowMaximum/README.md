# Sliding Window Maximum

[문제 바로가기](https://www.geeksforgeeks.org/sliding-window-maximum-maximum-of-all-subarrays-of-size-k/)

윈도우 사이즈 k와 n개의 원소를 가지는 정수형 배열이 주어졌을 때, 첫 번째 인덱스부터 인접한 윈도우를 탐색하면서 각 윈도우의 최댓값을 출력하는 문제. (Maximum of all subarrays of size k)

## Nested Loop을 이용한 풀이

윈도우 시작 인덱스를 결정하는 첫 번째 반복문과 시작 인덱스 다음부터 남은 윈도우 크기만큼을 순회하는 두 번째 반복문을 이용해 각 윈도우에서 최댓값을 찾는다.

시간 복잡도는 O(n * k)가 된다.

```c++
void solution(vector<int> arr, int k) {
    for (int i = 0; i <= arr.size() - k; i++) {
        int windowMax = arr[i];
        for (int j = 1; j < k; j++) {
            windowMax = max(windowMax, arr[i + j]);
        }
        cout << windowMax << endl;
    }
}
```

## Deque를 이용한 풀이

k개의 원소를 저장할 deque 자료구조를 만들고 아래의 규칙대로 원소들을 삽입 또는 삭제한다.

deque의 모든 원소는 현재 윈도우 내의 인덱스 값들로 구성되며 front에는 현재 윈도우의 최댓값이 존재한다. 좌측에 존재하는 최댓값 미만의 값들은 윈도우 이동시 의미가 없으므로 deque에서 삭제된다. 우측에 존재하는 최댓값 미만의 값들은 윈도우 이동시 다음 최댓값 후보가 되므로 deque에 인덱스 순으로 삽입된다.

1. k개의 원소를 저장할 deque 생성
2. 첫 번째 인덱스부터 k개의 인덱스를 순회
   1. 현재 인덱스의 원소보다 작은 back 인덱스의 원소들을 삭제 후 현재 인덱스를 삽입
3. k 부터 마지막 인덱스까지 순회
   1. front 인덱스의 원소를 출력
   2. front에서 현재 윈도우 범위를 벗어나는 인덱스 삭제
   3. 현재 인덱스의 원소보다 작은 back 인덱스의 원소들을 삭제 후 현재 인덱스를 삽입

많으면 배열의 모든 원소가 deque에 추가되고 삭제되는 연산이 발생할 수 있으므로 최대 2n번의 연산을 하게될 수 있으므로 시간 복잡도는 O(n)이 된다.

```c++
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
```