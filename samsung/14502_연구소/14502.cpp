/**
 * 백준 14502번
 * 연구소
 * https://www.acmicpc.net/problem/14502
 */
#include <fstream>
#include <iostream>

using namespace std;

enum {
    EMPTY = 0,
    WALL = 1,
    VIRUS = 2,
};

int N, M;  // 세로, 가로 (3 <= N, M <= 8)
int map[8][8] = {
    0,
};
int wall[3] = {
    0,
};

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int getNext(int pos) {
    while (pos < N * M) {
        int y = pos / N;
        int x = pos % N;

        if (map[y][x] == EMPTY) {
            return pos;
        }
        pos++;
    }
    return -1;
}

bool makeWall() {
    // 최초 생성하는 경우
    if (wall[0] == 0 && wall[1] == 0 && wall[2] == 0) {
        wall[0] = getNext(0);
        wall[1] = getNext(wall[0] + 1);
        wall[2] = getNext(wall[1] + 1);
    } else {
        // 기존 벽 삭제
        for (int i = 0; i < 3; i++) {
            int y = wall[i] / N;
            int x = wall[i] % N;
            map[y][x] = EMPTY;
        }

        if ((wall[2] = getNext(wall[2] + 1)) == -1) {
            if ((wall[1] = getNext(wall[1] + 1)) == -1) {
                if ((wall[0] = getNext(wall[0] + 1)) == -1) {
                    return false;
                }
                wall[1] = getNext(wall[0] + 1);
                wall[2] = getNext(wall[1] + 1);
            }
            wall[2] = getNext(wall[1] + 1);
        }
    }
    cout << wall[0] << ", " << wall[1] << ", " << wall[2] << endl;
    return true;
}

int main() {
    ifstream cin("input.txt");
    if (cin.fail()) return -1;

    cin >> N >> M;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            cin >> map[y][x];
        }
    }

    while (makeWall()) {
        for (int i = 0; i < 3; i++) {
            int y = wall[i] / N;
            int x = wall[i] % N;
            map[y][x] = WALL;
        }
    }

    return 0;
}