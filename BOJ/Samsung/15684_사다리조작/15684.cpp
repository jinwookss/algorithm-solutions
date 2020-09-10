/**
 * 백준 15684번
 * 사다리 조작
 * https://www.acmicpc.net/problem/15684
 */
#include <fstream>
#include <iostream>

using namespace std;

int N, M, H;
int map[31][11];
int result = 4;

// i번 세로선의 결과가 i인지 확인
bool validate() {
    for (int i = 1; i <= N; i++) {
        int cur = i;
        for (int j = 1; j <= H; j++) {
            if (map[j][cur] == 1) cur++;
            else if (map[j][cur - 1] == 1) cur--;
        }

        if (cur != i) return false;
    }
    return true;
}

void dfs(int count, int x, int y) {
    if (count >= result) return;
    if (validate()) {
        result = count;
        return;
    }
    if (count == 3) return;

    for (int i = y; i <= H; i++) {
        for (int j = x; j <= N; j++) {
            if (map[i][j] == 0 && map[i][j - 1] == 0 && map[i][j + 1] == 0) {
                map[i][j] = 1;
                dfs(count + 1, j, i);
                map[i][j] = 0;
            }
        }
        x = 0;
    }
}

int main() {
    ifstream cin("input.txt");
    if (cin.fail()) return -1;

    cin >> N >> M >> H;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        map[a][b] = 1;
    }

    // for (int i = 1; i <= H; i++) {
    //     for (int j = 1; j <= N; j++) {
    //         cout << map[i][j];
    //     }
    //     cout << endl;
    // }

    dfs(0, 1, 1);
    if (result == 4) result = -1;
    cout << result << endl;

    return 0;
}