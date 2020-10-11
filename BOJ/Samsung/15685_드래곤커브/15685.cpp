#include <fstream>
#include <iostream>

using namespace std;

const int SIZE = 101;
int map[SIZE][SIZE];
int dy[] = {0, -1, 0, 1};
int dx[] = {1, 0, -1, 0};
// 0, 0 1, 0 1 2 1, 0 1 2 1 2 3 2 1

bool isIncluded(int x, int y) {
    return map[y][x] && map[y][x + 1] && map[y + 1][x] && map[y + 1][x + 1];
}

void drawDragonCurve(int x, int y, int d, int g) {

    int curve[1024] = {0, };
    int curveSize = 0;

    // 0세대 방향 입력
    curve[curveSize++] = d;
    // 1~10세대 방향 입력
    for (int i = 0; i < g; i++) {
        for (int j = curveSize - 1; j >= 0; j--) {
            curve[curveSize++] = (curve[j] + 1) % 4;
        }
    }
    
    // 커브 그리기
    map[y][x]++;
    for (int i = 0; i < curveSize; i++) {
        y += dy[curve[i]];
        x += dx[curve[i]];
        if (y < 0 || y > 100 || x < 0 || x > 100) continue;
        map[y][x]++;
    }
}

int main() {
    ifstream cin("input.txt");
    if (cin.fail()) return -1;

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        // 시작 점, 시작 방향, 세대
        int x, y, d, g;
        cin >> x >> y >> d >> g;

        drawDragonCurve(x, y, d, g);
    }

    int answer = 0;
    for (int y = 0; y < SIZE; y++) {
        for (int x = 0; x < SIZE; x++) {
            // cout << map[y][x] << " ";
            if (isIncluded(x, y)) answer++;
        }
        // cout << endl;
    }
    cout << answer << endl;

    return 0;
}