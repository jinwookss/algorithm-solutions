/**
 * 백준 14502번
 * 연구소
 * https://www.acmicpc.net/problem/14502
 */
#include <fstream>
#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> Point;

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

const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1, 1};

int maxSafeZone = 0;

int getNext(int pos) {
    while (pos < N * M) {
        int y = pos / M;
        int x = pos % M;

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
            int y = wall[i] / M;
            int x = wall[i] % M;
            map[y][x] = EMPTY;
        }

        while (true) {
            if (wall[2] == -1 || (wall[2] = getNext(wall[2] + 1)) == -1) {
                if (wall[1] == -1 || (wall[1] = getNext(wall[1] + 1)) == -1) {
                    if ((wall[0] = getNext(wall[0] + 1)) == -1) {
                        return false;
                    }
                    wall[1] = getNext(wall[0] + 1);
                }
                wall[2] = getNext(wall[1] + 1);
            } 

            if (wall[0] != -1 && wall[1] != -1 && wall[2] != -1) break;
        }
    }

    return wall[0] < wall[1] && wall[1] < wall[2];
}

void spreadVirus() {
    
    int tempMap[8][8] = {0, };
    queue<Point> q;
    bool visited[8][8] = {false, };

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            tempMap[y][x] = map[y][x];
            if (tempMap[y][x] == VIRUS) {
                q.push(Point(y, x));
                visited[y][x] = true;
                // cout << "virus(" << y << ", " << x << ")" << endl;
            }
        }
    }

    while (!q.empty()) {
        Point p = q.front(); q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int ny = p.first + dy[dir];
            int nx = p.second + dx[dir];
            
            if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;

            if (tempMap[ny][nx] == EMPTY && !visited[ny][nx]) {
                visited[ny][nx] = true;
                tempMap[ny][nx] = VIRUS;
                q.push(Point(ny, nx));
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

int main() {
    ifstream cin("input.txt");
    if (cin.fail()) return -1;

    cin >> N >> M;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            cin >> map[y][x];
        }
    }

    // 벽을 세울 수 있는 모든 경우의 수를 체크하면서 
    while (makeWall()) {
        // cout << wall[0] << ", " << wall[1] << ", " << wall[2] << endl;
        // 지도에 벽을 그리고
        for (int i = 0; i < 3; i++) {
            int y = wall[i] / M;
            int x = wall[i] % M;
            map[y][x] = WALL;
        }
        // 바이러스를 확산시켜보며 최대 안전 영역 계산
        spreadVirus();
    }

    cout << maxSafeZone << endl;

    return 0;
}