/**
 * 백준 14499번
 * 주사위 굴리기
 * https://www.acmicpc.net/problem/14499
 */
#include <fstream>
#include <iostream>

using namespace std;

enum {
    EAST = 1,
    WEST = 2,
    NORTH = 3,
    SOUTH = 4,
};

struct Dice {
    int x, y; // 주사위 위치
    int bottom, top; // 현재 바닥면 값
    int left, right, up, down; // 바닥면 좌우상하 값

    void roll(int dir) {
        int temp;
        switch (dir) {
            case EAST:
                temp = left;
                left = bottom;
                bottom = right;
                right = top;
                top = temp;
                break;
            case WEST:
                temp = right;
                right = bottom;
                bottom = left;
                left = top;
                top = temp;
                break;
            case NORTH:
                temp = down;
                down = bottom;
                bottom = up;
                up = top;
                top = temp;
                break;
            case SOUTH:
                temp = up;
                up = bottom;
                bottom = down;
                down = top;
                top = temp;
                break;
        }
    }
};

int main() {
    ifstream cin("input.txt");
    if (cin.fail()) return -1;

    int N, M; // 지도의 세로, 가로 크기 (1 <= N, M <= 20)
    int x, y; // 주사위 좌표 (0 <= x <= N-1, 0 <= y <= M-1) 
    int K; // 명령의 개수 (1 <= K <= 1000)
    int cmd[1000] = {0, }; // 명령
    int map[20][20] = {0, }; // 지도

    // 문제에서 값의 범위를 보면 x가 세로 y가 가로를 나타내는 값임
    // 문제 풀이시에는 y를 세로, x를 가로가 나타내도록 입력받는다.
    cin >> N >> M >> y >> x >> K;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < M; x++) {
            cin >> map[y][x];
        }
    }
    for (int i = 0; i < K; i++) {
        cin >> cmd[i];
    }

    Dice dice;
    dice.x = x;
    dice.y = y;
    // 초기 주사위는 모든 면이 0
    dice.top = 0;
    dice.bottom = 0;
    dice.left = 0;
    dice.right = 0;
    dice.up = 0;
    dice.down = 0;

    for (int i = 0; i < K; i++) {
        int ny = dice.y;
        int nx = dice.x;
        // 주사위의 다음 위치 계산 & 지도의 바깥이면 무시
        int dir = cmd[i];
        if (dir == WEST) nx--;
        else if (dir == EAST) nx++;
        else if (dir == NORTH) ny--;
        else if (dir == SOUTH) ny++;

        if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;

        // 주사위 굴리기
        dice.roll(dir);
        dice.y = ny;
        dice.x = nx;
        
        // 상단값 출력
        cout << dice.top << endl;

        // 값 복사
        if (map[ny][nx] == 0) {
            map[ny][nx] = dice.bottom;
        } else {
            dice.bottom = map[ny][nx];
            map[ny][nx] = 0;
        }
    }

    return 0;
}