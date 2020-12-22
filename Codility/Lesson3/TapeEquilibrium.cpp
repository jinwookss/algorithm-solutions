#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// [0, P - 1], [P, N - 1] 두 구간합의 차이의 절대값이 최소가 되는 P를 찾기
int solution(vector<int> &A) {
    int minVal = 2100000000;
    int s1 = 0;
    int s2 = 0;
    
    for (int i = 0; i < A.size(); i++) {
        s2 += A[i];
    }

    for (int p = 1; p < A.size(); p++) {
        s1 += A[p - 1];
        s2 -= A[p - 1];
        int gap = abs(s1 - s2);
        minVal = min(minVal, gap);
    }

    return minVal;
}

int main() {
    vector<int> A = {3, 1};
    cout << solution(A) << endl;

    return 0;
}