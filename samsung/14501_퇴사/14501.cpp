/**
 * 백준 14501번
 * 퇴사
 * https://www.acmicpc.net/problem/14501
 */
#include <fstream>
#include <iostream>

using namespace std;

int N; // 퇴사까지 남은 날짜 (1 <= N <= 15)
int T[16] = {0, }; // 상담 필요 기간 (1 <= T <= 5)
int P[16] = {0, }; // 금액 (1 <= P <= 1000)

int result = 0;

void dfs(int day, int sum) {
    if (day > N + 1) {
        return;
    }
    if (sum > result) {
        result = sum;
    }

    for (int i = day; i <= N; i++) {
        int nd = i + T[i];
        int ns = sum + P[i];
        dfs(nd, ns);
    }
}

int main() {
    ifstream cin("input.txt");
    if (cin.fail()) return -1;

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> T[i] >> P[i];
    }

    dfs(1, 0);
    cout << result << endl;

    return 0;
}