#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// A: [1..N+1]
int solution(vector<int> &A) {
    if (A.empty()) return 1;

    sort(A.begin(), A.end(), less<int>());
    if (A.front() != 1) return 1;

    int next = 2;
    for (size_t i = 1; i < A.size(); i++) {
        if (A[i] != next) break;
        next++;
    }

    return next;
}

int main() {
    vector<int> A = {4, 2, 1, 3};
    cout << solution(A) << endl;
    return 0;
}