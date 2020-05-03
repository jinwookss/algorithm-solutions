/**
 * 백준 14503번
 * 로봇 청소기
 * https://www.acmicpc.net/problem/14503
 */
#include <fstream>
#include <iostream>

using namespace std;

enum {
    EMPTY = 0,
    WALL = 1,
    CLEANED = 2
};

const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {-1, 0, 1, 0};

struct Cleaner {
    int y, x;
    int dir;
};

int N, M; // 세로, 가로 크기 (3 <= N, M <= 50)
int map[50][50] = {0, };
int result = 0;

void dfs(Cleaner cur) {
    // 1. 현재 위치 청소
    if (map[cur.y][cur.x] == EMPTY) {
        map[cur.y][cur.x] = CLEANED;
        result++;
        // cout << cur.y << ", " << cur.x << " / dir = " << cur.dir << endl;
    }
    // 2. 현재 방향을 기준으로 왼쪽방향부터 차례대로 탐색
    for (int dir = 0; dir < 4; dir++) {
        int ny = cur.y + dy[(cur.dir) % 4];
        int nx = cur.x + dx[(cur.dir) % 4];
        
        if (map[ny][nx] == EMPTY) {
            // 왼쪽 방향에 아직 청소하지 않은 공간이 있다면, 그 방향으로 회전한 다음 전진
            Cleaner next;
            next.y = ny;
            next.x = nx;
            next.dir = (cur.dir + 1) % 4;
            // cout << "next" << endl;
            dfs(next);
            return;
        } else {
            // 왼쪽 방향에 청소할 공간이 없다면, 그 방향으로 회전
            cur.dir = (cur.dir + 1) % 4;
        }
    }
    
    // 네 방향 모두 청소가 되어있거나 벽인 경우
    int ny = cur.y + dy[(cur.dir + 1) % 4];
    int nx = cur.x + dx[(cur.dir + 1) % 4];
    if (map[ny][nx] != WALL) {
        cur.y = ny;
        cur.x = nx;
        // cout << "back" << endl;
        dfs(cur);
    } else {
        // cout << "end" << endl;
    }
}

int main() {
    ifstream cin("input.txt");
    if (cin.fail()) return -1;

    Cleaner c;
    cin >> N >> M;
    cin >> c.y >> c.x >> c.dir;
    if (c.dir == 3) c.dir = 1;
    else if (c.dir == 1) c.dir = 3;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            cin >> map[y][x];
        }
    }

    dfs(c);

    cout << result << endl;

    return 0;
}