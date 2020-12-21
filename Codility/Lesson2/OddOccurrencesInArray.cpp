#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> &A) {
    sort(A.begin(), A.end(), less<int>());

    int curNum = -1;
    int count = 0;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] != curNum) {
            if (curNum != -1 && count % 2 == 1) {
                return curNum;
            }
            curNum = A[i];
            count = 1;
        } else {
            count++;
        }
    }
    return curNum;    
}

int main() {
    vector<int> A = {8, 7, 1, 1, 9, 3, 9, 3, 9, 7, 9};
    cout << solution(A) << endl;

    return 0;
}