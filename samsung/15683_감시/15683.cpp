/**
 * 백준 15683번
 * 감시
 * https://www.acmicpc.net/problem/15683
 */
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int N, M; // 사무실의 세로 크기, 가로 크기 (1 <= N, M <= 8)
int map[8][8] = {0, };

struct CCTV {
    int y, x;
    int type;
    const int defaultDir[5][4] = {
        // 우, 하, 좌, 상
        {1, 0, 0, 0},
        {1, 0, 1, 0},
        {1, 0, 0, 1},
        {1, 0, 1, 1},
        {1, 1, 1, 1}
    };
    int dir[4] = {0, };

    CCTV(int _y, int _x, int _type) {
        y = _y;
        x = _x;
        type = _type;
        for (int i = 0; i < 4; i++) {
            dir[i] = defaultDir[type][i];
        }
    }

    // 시계 반대방향으로 90도 회전
    void rotate() {
        int temp = dir[0];
        for (int i = 0; i < 3; i++) {
            dir[i] = dir[i + 1];
        }
        dir[3] = temp;
    }

    void observe(bool enabled) {
        int val = enabled ? 7 : -7;

        for (int i = 0; i < 4; i++) {
            if (dir[i] == 1) {
                if (i == 0) { // 우
                    int nx = x + 1;
                    while (nx < M && map[y][nx] != 6) {
                        map[y][nx] += val;
                        nx++;
                    } 
                } else if (i == 1) { // 하
                    int ny = y + 1;
                    while (ny < N && map[ny][x] != 6) {
                        map[ny][x] += val;
                        ny++;
                    } 
                } else if (i == 2) { // 좌
                    int nx = x - 1;
                    while (nx >= 0 && map[y][nx] != 6) {
                        map[y][nx] += val;
                        nx--;
                    } 
                } else { // 상
                    int ny = y - 1;
                    while (ny >= 0 && map[ny][x] != 6) {
                        map[ny][x] += val;
                        ny--;
                    } 
                }
            }
        }
    }
};

vector<CCTV> v;
int minDeadZone = 0x7fffffff; // output, 사각 지대의 최소 크기

void dfs(int idx) {
    if (idx == v.size()) {
        int count = 0;
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                if (map[y][x] == 0) {
                    count++;
                }
            }
        }

        if (count < minDeadZone) {
            minDeadZone = count;
        }
        return;
    }

    CCTV c = v.at(idx);

    for (int i = 0; i < 4; i++) {
        c.observe(true);
        dfs(idx + 1);
        c.observe(false);
        c.rotate();
    }
}

int main() {
    ifstream cin("input.txt");
    if (cin.fail()) return -1;

    cin >> N >> M;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            cin >> map[y][x];

            // CCTV 위치
            if (map[y][x] != 0 && map[y][x] != 6) {
                CCTV c(y, x, map[y][x] - 1);
                v.push_back(c);
            }
        }
    }

    dfs(0);

    cout << minDeadZone << endl;

    return 0;
}