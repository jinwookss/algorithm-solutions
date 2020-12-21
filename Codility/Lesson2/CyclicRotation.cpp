#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(vector<int> &A, int K) {
    if (K == 0 || A.empty()) return A;

    int size = A.size();
    int offset = K % size;

    vector<int> answer;
    for (int i = 0; i < size; i++) {
        int idx = (size - offset + i) % size;
        answer.push_back(A[idx]);
    }
    return answer;
}

int main() {
    vector<int> A;
    for (int i : solution(A, 100)) {
        cout << i << endl;
    }

    return 0;
}