#include <iostream>
#include <queue>
#include <vector>

using namespace std;

enum {
    EMPTY = '.',
    FENCE = '#',
    WOLF = 'v',
    SHEEP = 'k'
};

typedef pair<int, int> P;
P dir[4] = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}};

bool contains(queue<P> q, P p) {
    while (!q.empty()) {
        if (q.front().first == p.first && q.front().second == p.second) {
            return true;
        }
        q.pop();
    }
    return false;
}

int main() {
    int R, C;  // 세로, 가로
    cin >> R >> C;

    // 맵 입력
    int sheep = 0, wolf = 0;
    vector<vector<bool>> checked(R, vector<bool>(C, false));
    vector<vector<char>> field(R, vector<char>(C, EMPTY));
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            char c;
            cin >> c;
            field[i][j] = c;
            if (c == WOLF)
                wolf++;
            else if (c == SHEEP)
                sheep++;
        }
    }

    // BFS
    for (int yy = 0; yy < R; yy++) {
        for (int xx = 0; xx < C; xx++) {
            if (!checked[yy][xx]) {
                if (field[yy][xx] == FENCE) {
                    checked[yy][xx] = true;
                    continue;
                }

                queue<P> q;
                q.push(make_pair(yy, xx));

                int w = 0, s = 0;
                while (!q.empty()) {
                    int y = q.front().first;
                    int x = q.front().second;
                    q.pop();
                    checked[y][x] = true;

                    if (field[y][x] == WOLF)
                        w++;
                    else if (field[y][x] == SHEEP)
                        s++;

                    for (int i = 0; i < 4; i++) {
                        int ny = y + dir[i].first;
                        int nx = x + dir[i].second;

                        if (0 < ny && ny < R && 0 < nx && nx < C) {
                            if (!checked[ny][nx]) {
                                if (field[ny][nx] == FENCE)
                                    checked[ny][nx] = true;
                                else {
                                    if (!contains(q, make_pair(ny, nx))) {
                                        q.push(make_pair(ny, nx));
                                    }
                                }
                            }
                        }
                    }
                }

                if (s != 0 && w != 0) {
                    if (s > w) {
                        wolf -= w;
                    } else {
                        sheep -= s;
                    }
                }
            }
        }
    }

    cout << sheep << " " << wolf << endl;

    return 0;
}