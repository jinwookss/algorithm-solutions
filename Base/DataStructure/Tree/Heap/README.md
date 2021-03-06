# Heap

![Heap](https://upload.wikimedia.org/wikipedia/commons/thumb/3/38/Max-Heap.svg/440px-Max-Heap.svg.png)

- 완전 이진 트리의 일종
- 최댓값 및 최솟값을 찾아내는 연산을 빠르게 하기 위해 고안됨
- 반정렬 상태(느슨한 정렬 상태)를 유지
  - 가장 높은(혹은 가장 낮은) 우선순위를 가지는 노드가 항상 상위 레벨에 있음
- 중복된 키 값을 허용 (이진 탐색 트리에서는 중복 값이 허용되지 않음)
- 힙의 특성을 이용하면 우선순위 큐와 같은 추상적 자료형을 구현 가능

## 힙의 종류

- 최소 힙: 부모노드의 키 값이 자식노드의 키 값보다 항상 작다. (루트 노드가 최소)
- 최대 힙: 부모노드의 키 값이 자식노드의 키 값보다 항상 크다. (루트 노드가 최대)

## 구현

- 배열을 이용하여 힙을 저장
- 구현의 편의성을 위해 배열의 첫 번째 인덱스인 0은 사용하지 않음
- 힙에서의 부모 노드와 자식 노드의 관계
  - 부모의 인덱스: (자식의 인덱스) / 2
  - 왼쪽 자식의 인덱스: (부모의 인덱스) * 2
  - 오른쪽 자식의 인덱스: (부모의 인덱스) * 2 + 1

```c++
const int HEAP_SIZE = 200;
int heap[HEAP_SIZE];

void heapify(int i) {
    
}
```
