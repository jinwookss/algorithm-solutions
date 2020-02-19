/**
 * N: 줄 선 인원 (1 ~ 1000)
 * P[i]: i 번 사람의 인출 시간 (1 ~ 1000)
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int N;
    vector<int> P;

    cin >> N;
    for (int i=1; i<=N; i++) {
        int p;
        cin >> p;
        P.push_back(p);
    }

    sort(P.begin(), P.end(), 
        [](int a, int b) -> bool {
            return a < b;
    });

    int minSum = 0;
    for (int i=0; i<N; i++) {
        int localSum = 0;
        for (int j=0; j<=i; j++) {
            localSum += P[j];
        }
        minSum += localSum;
    }
    cout << minSum << endl;;

    return 0;
}