#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Shark {
   public:
    int y, x;
    int size = 2;
    int eat = 0;
};

const int dy[] = {1, -1, 0, 0};
const int dx[] = {0, 0, -1, 1};

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

pair<int, int> selectTarget(vector<vector<int>> &map, Shark &shark) {
    int N = map.size();
    int minDistance = INT32_MAX;
    vector<pair<int, int>> targets;
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(N, vector<bool>(N, false));

    q.push(make_pair(shark.y * N + shark.x, 0));
    visited[shark.y][shark.x] = true;

    while (!q.empty()) {
        pair<int, int> p = q.front();
        int pos = p.first;
        q.pop();
        int y = pos / N;
        int x = pos % N;

        // 먹을 수 있는 물고기인 경우
        if (map[y][x] >= 1 && map[y][x] <= 6 && map[y][x] < shark.size) {
            if (p.second == minDistance) {
                targets.push_back(make_pair(y * N + x, p.second));
            } else if (p.second < minDistance) {
                targets.clear();
                targets.push_back(make_pair(y * N + x, p.second));
                minDistance = p.second;
            }
        }
        // 비거나 먹을 수 없는 물고기인 경우
        else {
            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];
                if (ny < 0 || ny >= N || nx < 0 || nx >= N || visited[ny][nx]) continue;
                if (map[ny][nx] > shark.size) continue;
                q.push(make_pair(ny * N + nx, p.second + 1));
                visited[ny][nx] = true;
            }
        }
    }

    if (targets.empty()) {
        return make_pair(0, 0);
    } else {
        sort(targets.begin(), targets.end(), compare);
        return targets.front();
    }
}

int main() {
    ifstream cin("input.txt");
    if (cin.fail()) return -1;

    int N;  // [2, 20]
    cin >> N;

    Shark shark;
    vector<vector<int>> map(N, vector<int>(N, 0));

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            int i;
            cin >> i;
            if (i == 9) {
                shark.y = y;
                shark.x = x;
            }
            map[y][x] = i;
        }
    }

    int time = 0;
    while (true) {
        // 더 이상 먹을 수 있는 물고기가 없는 경우
        pair<int, int> p = selectTarget(map, shark);
        if (p.second == 0) break;
        int y = p.first / N;
        int x = p.first % N;
        // cout << "shark(" << shark.y << ", " << shark.x << ", " << shark.size << "), target(" << y << ", " << x << ") / distance = " << p.second << endl;
        
        // 가장 가까운 물고기를 먹는다.
        map[y][x] = 9;
        // 상어 위치 및 크기 업데이트
        map[shark.y][shark.x] = 0;
        shark.y = y;
        shark.x = x;
        shark.eat++;
        if (shark.eat == shark.size) {
            shark.eat = 0;
            shark.size++;
        }
        // 이동거리만큼 시간 업데이트
        time += p.second;
    }
    cout << time << endl;

    return 0;
}