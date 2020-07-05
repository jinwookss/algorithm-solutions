# Sorting Algorithms

정렬 알고리즘은 n개의 원소가 입력으로 주어졌을 때, 이를 정렬하는 알고리즘을 말한다. 다양한 정렬 알고리즘이 존재하며, 구현 방식에 따라 시간 복잡도가 달라진다.

## Selection Sort

선택 정렬은 입력 배열에서 최솟값을 찾아 첫 번째 인덱스부터 채워나가는 정렬 알고리즘이다.

1. 입력 배열에서 최솟값을 찾는다.
2. 최솟값을 첫 번째 인덱스 값과 교체한다.
3. 최솟값을 넣은 인덱스를 제외한 나머지를 같은 방법으로 정렬한다.

시간 복잡도는 n-1개 원소를 순회하면서 n-1, n-2, ..., 1개와 비교를 진행하므로 항상 O(n^2)이다.

![Selection sort](https://upload.wikimedia.org/wikipedia/commons/9/94/Selection-Sort-Animation.gif)

### Implementation

```c++
void selectionSort(vector<int> &v) {
    for (int i = 0; i < v.size() - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < v.size(); j++) {
            if (v[minIdx] > v[j]) minIdx = j;
        }
        swap(v[i], v[minIdx]);
    }
}
```

## Insertion Sort

삽입 정렬은 배열의 모든 원소를 앞에서부터 차례대로 이미 정렬된 배열 부분과 비교하여 현재 원소가 들어갈 위치를 찾아 삽입함으로써 정렬을 완성하는 알고리즘이다. 각 반복에서 정렬되지 않은 나머지 부분 중 첫 번째 원소는 제거되어 정확한 위치에 삽입된다.

1. 두 번째 인덱스부터 마지막 인덱스까지 순회를 시작한다.  
현재 인덱스 값을 변수에 저장하고 비교 인덱스를 현재 인덱스 -1로 설정한다.
2. 비교 인덱스부터 배열의 첫 번째 인덱스까지 순회하면서 현재 인덱스의 값과 비교 인덱스의 값을 비교한다.
3. 만약 비교 인덱스의 값이 더 크면, 비교 인덱스+1에 비교 인덱스의 값을 저장하고 비교 인덱스를 1만큼 감소시켜 비교를 계속한다.
4. 만약 비교 인덱스의 값이 더 작거나 순회가 끝나면, 비교 인덱스+1에 현재 인덱스 값을 저장한다.

시간 복잡도는 최악의 경우(역순으로 정렬) O(n^2)이고, 최선의 경우(정렬) O(n)이다.

![Insertion sort](https://upload.wikimedia.org/wikipedia/commons/9/9c/Insertion-sort-example.gif)

### Implementation

```c++
void insertionSort(vector<int> &v) {
    for (int i = 1; i < v.size(); i++) {
        int cur = v[i];
        int j = i;
        while (--j >= 0 && v[j] > cur) {
            v[j + 1] = v[j];
        }
        v[j + 1] = cur;
    }
}
```

## Bubble Sort

거품 정렬은 매 번 인접한 두 원소를 비교하여 정렬 규칙에 따라 두 값을 정렬해나가는 알고리즘이다. 예를 들어, 오름차순으로 정렬하는 경우 비교시마다 더 큰 값이 뒤로 이동하게 된다.

시간 복잡도는 O(n^2)이다.

![Bubble sort](https://upload.wikimedia.org/wikipedia/commons/0/06/Bubble-sort.gif)

### Implementation

```c++
void bubbleSort(vector<int> &v) {
    for (int i = 0; i < v.size() - 1; i++) {
        for (int j = 0; j < v.size() - 1 - i; j++) {
            if (v[j] > v[j + 1]) {
                swap(v[j], v[j + 1]);
            }
        }
    }
}
```

## Merge Sort

합병 정렬은 [분할 정복](https://ko.wikipedia.org/wiki/%EB%B6%84%ED%95%A0_%EC%A0%95%EB%B3%B5_%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98) 방식을 이용한 정렬 알고리즘으로 아래와 같이 동작한다.

1. 분할: 길이가 2 이상이면 배열을 절반으로 나눈다.
2. 정복: 나눈 배열을 입력으로 합병 정렬을 재귀 호출한다.
3. 합병: 배열을 다시 하나의 정렬된 배열로 합병한다.

시간 복잡도는 분할 과정에서 O(log n)의 시간 복잡도가 필요하고 합병 과정에서 두 배열을 정렬하면서 O(n)이 필요하므로 총 O(n log n)이다.

![Merge sort](https://upload.wikimedia.org/wikipedia/commons/c/cc/Merge-sort-example-300px.gif)

### Implementation

```c++
void mergeSort(vector<int> &v, int left, int right) {
    // 1. base condition
    if (left >= right) return;

    // 2. divide
    int mid = (left + right) / 2;

    // 3. conquer
    mergeSort(v, left, mid);
    mergeSort(v, mid + 1, right);

    // 4. combine
    vector<int> copy = v;
    int i, j, k;
    i = left; // 왼쪽 배열 인덱스
    j = mid + 1; // 오른쪽 배열 인덱스
    k = left; // 병합 배열 인덱스

    while (i <= mid && j <= right) {
        if (v[i] <= v[j]) {
            copy[k] = v[i];
            i++;
        } else {
            copy[k] = v[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        copy[k] = v[i];
        i++;
        k++;
    }

    while (j <= right) {
        copy[k] = v[j];
        j++;
        k++;
    }

    v = copy;
}
```

## Quick Sort

퀵 정렬은 다른 원소와의 비교만으로 정렬을 수행하는 비교 정렬에 속하는 알고리즘이다. 합병 정렬[(Merge Sort)](#merge-sort)와 마찬가지로 분할 정복 방법을 이용한다.

1. 배열에서 하나의 원소를 고른다. 이를 피벗(pivot)으로 설정한다.
2. 분할: 피벗 앞에는 피벗보다 작은 원소들이 오고, 피벗 뒤에는 피벗보다 큰 원소들이 오도록 나눈다.
3. 정복: 분할된 두 개의 배열에 대해 배열의 크기가 0 또는 1이 될 때까지 재귀적으로 위의 과정을 반복한다.

시간 복잡도는 최악의 경우 O(n^2)이고, 평균적으로 O(n log n)이다.

![Quick sort](https://upload.wikimedia.org/wikipedia/commons/9/9c/Quicksort-example.gif)

### Implementation

```c++
void quickSort(vector<int> &v, int left, int right) {
    // 1. base condition
    if (left >= right) return;

    // 2. divide
    int i, j;
    i = j = left;
    int &pivot = v[right];
    while (j < right) {
        if (v[j] < pivot) {
            swap(v[i++], v[j]);
        }
        j++;
    }
    swap(v[i], pivot);

    // 3. conquer
    quickSort(v, left, i - 1);
    quickSort(v, i + 1, right);
}
```

## C++ STL sort

퀵 정렬[(Quick Sort)](#quick-sort) 알고리즘을 기반으로 만들어진 정렬 알고리즘이다. 퀵 정렬이 최악의 경우 O(n^2)의 시간 복잡도를 갖는다는 점을 개선하여 어떠한 경우에도 O(n log n)의 시간 복잡도를 만족한다.

### Usage

시작과 끝 반복자를 파라미터로 넣어주면 오름차순으로 정렬해 준다. 이 외에도 사용자 정의 정렬 규칙을 지정해 주거나 STL에서 제공하는 정렬 규칙을 사용할 수 있다.

```c++
template <class RandomAccessIterator>
void sort (RandomAccessIterator first, RandomAccessIterator last);

template <class RandomAccessIterator, class Compare>
void sort (RandomAccessIterator first, RandomAccessIterator last, Compare comp);
```

```c++
#include <algotirhm>

...

vector<int> v = {5, 3, 2, 8, 6, 7, 1, 4, 9};

// 디폴트는 오름차순 정렬
sort(v.begin(), v.end());

// 사용자 지정 정렬 규칙 사용
sort(v.begin(), v.end(), [](int a, int b) {
    return a > b;
});

// STL 제공 정렬 규칙 사용
sort(v.begin(), v.end(), greater<int>());
sort(v.begin(), v.end(), less<int>());
```
