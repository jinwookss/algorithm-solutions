/**
 * 백준 14889번
 * 스타트와 링크
 * https://www.acmicpc.net/problem/14889
 */
#include <fstream>
#include <iostream>

using namespace std;

int N; // 축구를 하기 위해 모인 사람 (4 <= N <= 20, N은 짝수)
int S[20][20] = {0, };
int team[20] = {0, };
int minimum = 0x7fffffff;

int calcScoreGap() {
    int s1 = 0;
    int s2 = 0;

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) { 
            if (team[x] == 1 && team[y] == 1) {
                s1 += S[y][x];
            } else if (team[x] == 0 && team[y] == 0) {
                s2 += S[y][x];
            }
        }
    }
    return abs(s1 - s2);
}

void dfs(int count, int idx) {
    if (count == N / 2) {
        // 결과 업데이트
        int result = calcScoreGap();
        if (result < minimum) {
            minimum = result;
        }
        return;
    }

    for (int i = idx; i < N; i++) {
        if (team[i] != 1) {
            team[i] = 1;
            if (team[0] == 0) return; // 2개의 팀이므로 0, 1이 반전된 결과는 계산할 필요 없으므로 제외
            dfs(count + 1, i + 1);
            team[i] = 0;
        }
    }
}

int main() {
    ifstream cin("input.txt");
    if (cin.fail()) return -1;

    cin >> N;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> S[y][x];
        }
    }

    dfs(0, 0);
    cout << minimum << endl;

    return 0;
}