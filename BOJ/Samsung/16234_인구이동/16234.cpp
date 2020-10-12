#include <fstream>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

bool searchUnion(vector<vector<int>> &map, int N, int L, int R) {
    int result = 0;

    int dy[] = {1, -1, 0, 0};
    int dx[] = {0, 0, -1, 1};

    queue<int> q;
    vector<vector<bool>> visited(N, vector<bool>(N, false));

    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            if (visited[y][x]) continue;

            queue<int> unionCountries;
            int sum = 0, count = 0;

            q.push(y * N + x);

            sum += map[y][x];
            count++;
            unionCountries.push(y * N + x);
            visited[y][x] = true;

            while (!q.empty()) {
                int pos = q.front();
                q.pop();
                int yy = pos / N;
                int xx = pos % N;

                for (int d = 0; d < 4; d++) {
                    int ny = yy + dy[d];
                    int nx = xx + dx[d];
                    if (ny < 0 || ny >= N || nx < 0 || nx >= N || visited[ny][nx]) continue;

                    int gap = abs(map[yy][xx] - map[ny][nx]);
                    if (gap >= L && gap <= R) {
                        q.push(ny * N + nx);

                        sum += map[ny][nx];
                        count++;
                        unionCountries.push(ny * N + nx);
                        visited[ny][nx] = true;
                    }
                }
            }

            if (unionCountries.size() > 1) {
                int avg = sum / count;
                while (!unionCountries.empty()) {
                    int pos = unionCountries.front();
                    unionCountries.pop();
                    int yy = pos / N;
                    int xx = pos % N;
                    map[yy][xx] = avg;
                }
                result++;
            }
        }
    }
    return result > 0;
}

int main() {
    ifstream cin("input.txt");
    if (cin.fail()) return -1;

    int N, L, R;
    cin >> N >> L >> R;

    vector<vector<int>> map(N, vector<int>(N, 0));
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> map[y][x];
        }
    }

    int result = 0;
    while (searchUnion(map, N, L, R)) {
        result++;
    }
    cout << result << endl;

    return 0;
}