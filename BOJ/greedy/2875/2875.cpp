/**
 * 2명의 여학생과 1명의 남학생이 팀 결성
 * N: 여학생 수 (0 ~ 100)
 * M: 남학생 수 (0 ~ 100)
 * K: 인턴십 필수 참여 학생 수 (0 ~ M+N)
 * 만들 수 있는 최대 팀 수 구하기
 */

#include <iostream>
#include <algorithm>

using namespace std;

int main() {

    int N, M, K; 
    cin >> N >> M >> K;

    // 예외
    if (N < 2 || M < 1 || N + M <= K) {
        cout << "0" << endl;
        return 0;
    }
    
    int team = 0;
    int remained = 0;
    if (N > M * 2) {
        team = M;
        remained = N - M * 2;
    } else {
        team = N / 2;
        remained = M - team;
    }

    if (K - remained > 0) {
        team -= (K - remained + 2) / 3;
    }
    cout << team << endl;

    return 0;
}