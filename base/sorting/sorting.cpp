#include <iostream>
#include <vector>

using namespace std;

void printVector(string msg, vector<int> &v) {
    cout << msg << ": ";
    for (int i : v) {
        cout << i << " ";
    }
    cout << endl;
}

void selectionSort(vector<int> v) {
    for (int i = 0; i < v.size() - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < v.size(); j++) {
            if (v[minIdx] > v[j]) minIdx = j;
        }
        swap(v[i], v[minIdx]);
    }
    printVector("Selection", v);
}

void insertionSort(vector<int> v) {
    for (int i = 1; i < v.size(); i++) {
        int cur = v[i];
        int j = i;
        while (--j >= 0 && v[j] > cur) {
            v[j + 1] = v[j];
        }
        v[j + 1] = cur;
    }
    printVector("Insertion", v);
}

void bubbleSort(vector<int> v) {
    for (int i = 0; i < v.size() - 1; i++) {
        for (int j = 0; j < v.size() - 1 - i; j++) {
            if (v[j] > v[j + 1]) {
                swap(v[j], v[j + 1]);
            }
        }
    }
    printVector("Bubble", v);
}

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

int main() {
    vector<int> v = {5, 3, 2, 8, 6, 7, 1, 9, 4};
    printVector("Input", v);

    selectionSort(v);

    insertionSort(v);

    bubbleSort(v);

    // mergeSort(v, 0, v.size() - 1);
    // printVector("Merge", v);

    quickSort(v, 0, v.size() - 1);
    printVector("Quick", v);

    return 0;
}