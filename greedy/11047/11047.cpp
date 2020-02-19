/**
 * N: 동전 종류 (1 ~ 10)
 * K: 가치의 합 (1 ~ 100000000)
 * A[i]: 동전의 가치 (1 ~ 1000000, A[i]는 A[i-1]의 배수)
 * 
 * K원을 만드는데 필요한 동전 개수의 최솟값 출력
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    int N, K;
    vector<int> A;

    cin >> N >> K;
    for (int i=0; i<N; i++) {
        int Ai;
        cin >> Ai;
        A.push_back(Ai);
    }

    sort(A.begin(), A.end(), 
        [](int a, int b) -> bool {
            return a > b;
    });

    int result = 0;
    while (K != 0) {
        for (auto a : A) {
            int quotient = K / a;
            if (quotient > 0) {
                K -= a * quotient;
                result += quotient;
                break;
            }
        }
    }

    cout << result << endl;

    return 0;
}