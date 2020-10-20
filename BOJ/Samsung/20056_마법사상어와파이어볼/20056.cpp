#include <fstream>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Ball {
   public:
    int m, s, d;
};

const int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};

int N, M, K;  // 맵 크기, 파이어볼 개수, 이동 명령 수
vector<vector<queue<Ball>>> map(50, vector<queue<Ball>>(50));

void printMap(string msg) {
    cout << msg << endl;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cout << map[y][x].size() << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    ifstream cin("input.txt");
    if (cin.fail()) return -1;

    cin >> N >> M >> K;
    for (int i = 0; i < M; i++) {
        int r, c;
        Ball b;
        cin >> r >> c >> b.m >> b.s >> b.d;
        map[r - 1][c - 1].push(b);
    }

    for (int i = 0; i < K; i++) {
        // printMap("start");

        // 파이어볼 이동
        queue<pair<int, Ball>> q;  // 이동한 파이어볼 위치 임시 저장할 큐
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                while (!map[y][x].empty()) {
                    Ball b = map[y][x].front();
                    map[y][x].pop();
                    int ds = b.s % N;
                    int ny = (y + dy[b.d] * ds + N) % N;
                    int nx = (x + dx[b.d] * ds + N) % N;
                    q.push(make_pair(ny * N + nx, b));
                }
            }
        }

        while (!q.empty()) {
            pair<int, Ball> p = q.front();
            q.pop();
            map[p.first / N][p.first % N].push(p.second);
        }

        // printMap("after move");

        // 파이어볼 분열
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                int size = map[y][x].size();
                if (size < 2) continue;

                int totalM = 0;
                int totalS = 0;

                int checkDir = -1;
                int nd = 0;
                while (!map[y][x].empty()) {
                    Ball b = map[y][x].front();
                    map[y][x].pop();
                    totalM += b.m;
                    totalS += b.s;
                    if (checkDir == -1) {
                        checkDir = b.d % 2;
                    } else if (checkDir <= 1) {
                        if (checkDir != b.d % 2) {
                            checkDir = 2;
                            nd = 1;
                        }
                    }
                }

                int nm = totalM / 5;
                int ns = totalS / size;
                if (nm == 0) continue;

                for (int d = nd; d < 8; d += 2) {
                    Ball b;
                    b.m = nm;
                    b.s = ns;
                    b.d = d;
                    q.push(make_pair(y * N + x, b));
                }
            }
        }

        while (!q.empty()) {
            pair<int, Ball> p = q.front();
            q.pop();
            map[p.first / N][p.first % N].push(p.second);
        }

        // printMap("after divide");
    }

    int result = 0;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            while (!map[y][x].empty()) {
                result += map[y][x].front().m;
                map[y][x].pop();
            }
        }
    }
    cout << result << endl;

    return 0;
}