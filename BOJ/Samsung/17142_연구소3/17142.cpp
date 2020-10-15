#include <fstream>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

enum {
    EMPTY = 0,
    WALL,
    VIRUS,
    ACTIVE_VIRUS,
};

// 상하좌우
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};

int N;  // [4, 50]
int M;  // [1, 10]
int result = INT32_MAX;
vector<pair<int, int>> viruses;
vector<vector<int>> map(50, vector<int>(50, EMPTY));

int spreadVirus() {
    queue<pair<int, int>> q;  // pos, generation
    vector<vector<bool>> visited(N, vector<bool>(N, false));

    // 활성화 바이러스 큐에 추가
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (map[y][x] == ACTIVE_VIRUS) {
                q.push(make_pair(y * N + x, 0));
                visited[y][x] = true;
            }
        }
    }

    int time = -1;
    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        int y = p.first / N;
        int x = p.first % N;
        int generation = p.second;
        // VIRUS는 ACTIVE_VIRUS가 닿았을 때부터 활동을 시작하지만 VIRUS만 남았을 때 굳이 시간을 들여 확산시키지 않아도 됨
        if (time < generation && map[y][x] != VIRUS) time = generation;

        for (int d = 0; d < 4; d++) {
            int ny = y + dy[d];
            int nx = x + dx[d];
            // 경계 및 중복 방문 제외
            if (ny < 0 || ny >= N || nx < 0 || nx >= N || visited[ny][nx]) continue;
            if (map[ny][nx] != WALL) { 
                q.push(make_pair(ny * N + nx, generation + 1));
                visited[ny][nx] = true;
            }
        }
    }

    bool isCompleted = true;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (map[y][x] == EMPTY && !visited[y][x]) {
                isCompleted = false;
                break;
            }
        }
    }

    if (isCompleted)
        return time;
    else
        return INT32_MAX;
}

void selectVirus(int count, int current) {
    if (count == M) {
        result = min(result, spreadVirus());
        return;
    }

    for (int i = current; i < viruses.size(); i++) {
        pair<int, int> pos = viruses[i];
        map[pos.first][pos.second] = ACTIVE_VIRUS;
        selectVirus(count + 1, i + 1);
        map[pos.first][pos.second] = VIRUS;
    }
}

int main() {
    ifstream cin("input.txt");
    if (cin.fail()) return -1;

    cin >> N >> M;

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> map[y][x];
            if (map[y][x] == VIRUS)
                viruses.push_back(make_pair(y, x));
        }
    }

    selectVirus(0, 0);
    if (result == INT32_MAX) result = -1;
    cout << result << endl;

    return 0;
}