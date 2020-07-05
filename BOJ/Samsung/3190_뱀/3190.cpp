/**
 * 백준 3190번
 * 뱀
 * https://www.acmicpc.net/problem/3190
 */
#include <fstream>
#include <iostream>

using namespace std;

enum {
    BLANK = '0',
    APPLE = '1',
    SNAKE = '2',
    LEFT = 'L',
    RIGHT = 'D',
};

int N;  // 보드의 크기 (2 <= N <= 100)
int K;  // 사과의 개수 (0 <= K <= 100)
int L;  // 뱀의 방향 변환 횟수 (1 <= L <= 100)

char map[101][101] = {0, };
char nextDir[100000] = {0, }; // X초일 때의 방향
pair<int, int> head[100000] = {{0, 0}, }; // 뱀의 머리가 지나간 좌표

// 진행 방향: 왼쪽이면 +1, 오른쪽이면 +3
int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};

int play() {
    int time = 0; // 경과 시간
    int dir = 0; // 진행 방향 (초기 오른쪽)
    head[time] = {1, 1}; // time 에서의 head 좌표 (초기 1, 1)
    int tail = time; // 현재 꼬리 위치에 head가 있었던 시간
    map[head[time].first][head[time].second] = SNAKE;

    while (true) {
        int currY = head[time].first;
        int currX = head[time].second;
        int nextY = currY + dy[dir];
        int nextX = currX + dx[dir];
        // 1초 경과 후 뱀 이동
        time++;
        head[time].first = nextY;
        head[time].second = nextX;
        // 충돌 여부 확인
        if (map[nextY][nextX] == SNAKE) {
            break;
        } else if (nextY < 1 || nextY > N || nextX < 1 || nextX > N) {
            break;
        }
        // 이동 위치에 사과 있는지 확인
        if (map[nextY][nextX] != APPLE) {
            map[head[tail].first][head[tail].second] = BLANK;
            tail++;
        }
        // 맵에 머리 위치 갱신
        map[nextY][nextX] = SNAKE;
        // 방향 전환 확인
        if (nextDir[time] == LEFT) {
            dir = (dir + 1) % 4;
        } else if (nextDir[time] == RIGHT) {
            dir = (dir + 3) % 4;
        }
    }

    return time;
}

int main() {
    ifstream cin("input.txt");
    assert(!cin.fail());

    cin >> N;
    cin >> K;
    for (int i = 0; i < K; i++) {
        int y, x;
        cin >> y >> x;
        map[y][x] = APPLE;
    }
    cin >> L;
    for (int i = 0; i < L; i++) { 
        int X;
        char C;
        cin >> X >> C;
        nextDir[X] = C;
    }

    cout << play() << endl;

    return 0;
}