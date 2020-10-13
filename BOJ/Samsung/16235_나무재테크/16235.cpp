#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Land {
   public:
    int energy = 5;
    vector<int> trees;
    vector<int> deadTrees;
};

int main() {
    ifstream cin("input.txt");
    if (cin.fail()) return -1;

    int N, M, K;
    cin >> N >> M >> K;

    // 양분 5를 갖는 토지 생성 (인덱스 1부터 시작)
    vector<vector<Land>> map(N + 1, vector<Land>(N + 1, Land()));
    // 양분 맵
    vector<vector<int>> A(N + 1, vector<int>(N + 1, 0));
    for (int y = 1; y <= N; y++) {
        for (int x = 1; x <= N; x++) {
            cin >> A[y][x];
        }
    }
    // 심은 나무 정보 반영
    for (int i = 0; i < M; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        map[x][y].trees.emplace_back(z);
    }

    for (int year = 0; year < K; year++) {
        // 봄: 나이만큼 양분을 먹고 나이 1 증가. 어린 나무부터 먹음. 양분이 부족한 나무는 죽음.
        for (int y = 1; y <= N; y++) {
            for (int x = 1; x <= N; x++) {
                int &energy = map[y][x].energy;
                vector<int> &trees = map[y][x].trees;
                sort(trees.begin(), trees.end(), less<int>());

                auto itr = trees.begin();
                while (itr != trees.end()) {
                    int &age = *itr;
                    if (energy >= age) {
                        energy -= age;
                        age++;
                        itr++;
                    } else {
                        map[y][x].deadTrees.emplace_back(age);
                        itr = trees.erase(itr);
                    }
                }
            }
        }
        // 여름: 봄에 죽은 나무가 나이/2 만큼의 양분이 됨.
        for (int y = 1; y <= N; y++) {
            for (int x = 1; x <= N; x++) {
                while (!map[y][x].deadTrees.empty()) {
                    int &age = map[y][x].deadTrees.back();
                    map[y][x].deadTrees.pop_back();
                    map[y][x].energy += (age / 2);
                }
            }
        }
        // 가을: 나이가 5의 배수인 나무가 번식. 인접한 8칸에 나이 1인 나무 생성.
        for (int y = 1; y <= N; y++) {
            for (int x = 1; x <= N; x++) {
                vector<int> &trees = map[y][x].trees;
                for (int i = 0; i < trees.size(); i++) {
                    if (trees[i] % 5 == 0) {
                        int d[] = {-1, 0, 1};
                        for (int yy = 0; yy < 3; yy++) {
                            int ny = y + d[yy];
                            if (ny < 1 || ny > N) continue;
                            for (int xx = 0; xx < 3; xx++) {
                                int nx = x + d[xx];
                                if (ny == y && nx == x) continue;
                                if (nx < 1 || nx > N) continue;
                                map[ny][nx].trees.emplace_back(1);
                            }
                        }
                    }
                }
            }
        }
        // 겨울: S2D2가 각 칸에 A[r][c]만큼의 양분을 추가.
        for (int y = 1; y <= N; y++) {
            for (int x = 1; x <= N; x++) {
                map[y][x].energy += A[y][x];
            }
        }
    }

    // K년이 지난 후 나무의 개수 구하기.
    int result = 0;
    for (int y = 1; y <= N; y++) {
        for (int x = 1; x <= N; x++) {
            result += map[y][x].trees.size();
        }
    }
    cout << result << endl;
    return 0;
}