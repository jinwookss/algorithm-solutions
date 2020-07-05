/**
 * 백준 13460번
 * 구슬 탈출 2
 * https://www.acmicpc.net/problem/13460
 */
#include <fstream>
#include <iostream>
#include <queue>

using namespace std;

const int MAX_SIZE = 10;
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};
enum {
    EMPTY = '.',
    WALL = '#',
    HOLE = 'O'
};

char map[MAX_SIZE][MAX_SIZE];

struct State {
    int ry, rx, by, bx, cnt;
};

int bfs(State start) {
    int result = -1;
    int visited[MAX_SIZE][MAX_SIZE][MAX_SIZE][MAX_SIZE] = {0, };
    queue<State> q;
    
    q.push(start);
    visited[start.ry][start.rx][start.by][start.bx] = 1;
    int cnt = 0;
    while (!q.empty()) {
        State cur = q.front();
        q.pop();
        // 카운트가 10 초과인 경우 종료
        if (cur.cnt > 10) break;
        // 빨간 구슬만 구멍에 빠진 경우 카운트 저장 후 종료
        if (map[cur.ry][cur.rx] == HOLE && map[cur.by][cur.bx] != HOLE) {
            result = cur.cnt;
            break;
        }

        // 4방향 탐색
        for (int dir = 0; dir < 4; dir++) {
            int nry = cur.ry + dy[dir];
            int nrx = cur.rx + dx[dir];
            int nby = cur.by + dy[dir];
            int nbx = cur.bx + dx[dir];

            // 빨간 구슬 이동
            while (true) { 
                if (map[nry][nrx] != WALL) {
                    // 구멍을 만나면 정지, 아니면 계속 이동
                    if (map[nry][nrx] == HOLE) break;
                    nry += dy[dir];
                    nrx += dx[dir];
                } else {
                    // 벽을 만나면 한 칸 뒤로 이동 후 정지
                    nry -= dy[dir];
                    nrx -= dx[dir];
                    break;
                }
            }

            // 파란 구슬 이동
            while (true) { 
                if (map[nby][nbx] != WALL) {
                    // 구멍을 만나면 정지, 아니면 계속 이동
                    if (map[nby][nbx] == HOLE) break;
                    nby += dy[dir];
                    nbx += dx[dir];
                } else {
                    // 벽을 만나면 한 칸 뒤로 이동 후 정지
                    nby -= dy[dir];
                    nbx -= dx[dir];
                    break;
                }
            }

            // 파란 구슬이 구멍에 빠진 경우
            if (map[nby][nbx] == HOLE) continue;

            // 두 구슬의 위치가 같은 경우, 이동거리를 비교하여 더 멀리서 온 구슬의 위치를 한 칸 뒤로 이동
            if (nry == nby && nrx == nbx) {
                int dr = abs(cur.ry - nry) + abs(cur.rx - nrx);
                int db = abs(cur.by - nby) + abs(cur.bx - nbx);
                if (dr > db) {
                    nry -= dy[dir];
                    nrx -= dx[dir];
                } else {
                    nby -= dy[dir];
                    nbx -= dx[dir];
                }
            }

            // 방문 여부 확인
            if (!visited[nry][nrx][nby][nbx]) {
                visited[nry][nrx][nby][nbx] = 1;
                State next;
                next.ry = nry;
                next.rx = nrx;
                next.by = nby;
                next.bx = nbx;
                next.cnt = cur.cnt + 1;
                q.push(next);
            }
        }
    }
    
    return result;
}

int main() {
    ifstream cin("input.txt");
    assert(!cin.fail());

    // Read map
    State start;
    int N, M; // 세로, 가로
    cin >> N >> M;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            char c; 
            cin >> c;
            map[y][x] = c;
            
            if (c == 'R') {
                start.ry = y;
                start.rx = x;
            } else if (c == 'B') {
                start.by = y;
                start.bx = x;
            }
        }
    }
    start.cnt = 0;

    int result = bfs(start);
    std::cout << result << endl;

    return 0;
}