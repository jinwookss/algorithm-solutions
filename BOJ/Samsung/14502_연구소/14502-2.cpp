/**
 * 백준 14502번
 * 연구소
 * https://www.acmicpc.net/problem/14502
 */
#include <fstream>
#include <iostream>
#include <queue>

using namespace std;

enum {
    EMPTY = 0,
    WALL = 1,
    VIRUS = 2,
};

const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1, 1};

int N, M;  // 세로, 가로 (3 <= N, M <= 8)
int map[8][8] = {0, };
int maxSafeZone = 0;

// bfs로 현재 지도에서 바이러스를 확신시킨다.
void spreadVirus() {
    queue<int> q;
    bool visited[8][8] = {false, };
    int tempMap[8][8] = {0, };

    // 지도 복사 및 초기 바이러스 위치 큐에 입력
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            tempMap[y][x] = map[y][x];
            if (tempMap[y][x] == VIRUS) {
                q.push(y * 10 + x);
                visited[y][x] = true;
            }
        }
    }

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        int cy = cur / 10;
        int cx = cur % 10;

        for (int dir = 0; dir < 4; dir++) {
            int ny = cy + dy[dir];
            int nx = cx + dx[dir];

            if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;

            if (tempMap[ny][nx] == EMPTY && !visited[ny][nx]) {
                tempMap[ny][nx] = VIRUS;
                q.push(ny * 10 + nx);
                visited[ny][nx] = true;
            }
        }
    }

    int safeZone = 0;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            if (tempMap[y][x] == EMPTY) {
                safeZone++;
            }
        }
    }
    if (safeZone > maxSafeZone) {
        maxSafeZone = safeZone;
    }
}

// dfs로 벽을 3개 세우는 모든 경우의 수를 탐색한다. 
void makeWall(int count, int sy, int sx) {
    //  벽을 3개 세웠으면 바이러스를 확신
    if (count == 3) {
        spreadVirus();
        return;
    }

    for (int y = sy; y < N; y++) {
        for (int x = sx; x < M; x++) {
            if (map[y][x] == EMPTY) {
                map[y][x] = WALL;
                makeWall(count + 1, y, x);
                map[y][x] = EMPTY;
            }
        }
        sx = 0;
    }
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

    makeWall(0, 0, 0);

    cout << maxSafeZone << endl;

    return 0;
}