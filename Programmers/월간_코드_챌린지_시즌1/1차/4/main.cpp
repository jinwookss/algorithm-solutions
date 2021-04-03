#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> vv;
vector<int> v1;
int height;
int width;
int result;

bool validate() {
    for (vector<int> v : vv) {
        int count = 0;
        for (int i : v) {
            if (i == 1) count++;
        }
        if (count % 2 != 0) return false;
    }
    return true;
}

void dfs(int y, int x) {
    if (x == width) {
        if (validate()) {
            result++;

            for (int y = 0; y < height; y++) {
                for (int x = 0; x < width; x++) {
                    cout << vv[y][x] << " ";
                }
                cout << endl;
            }
            cout << endl;
        }
        return;
    }

    // 현재 열에 배치할 1이 남았으면
    if (v1[x] != 0) {
        for (int j = y; j < height; j++) {
            vv[j][x] = 1;
            v1[x]--;
            dfs(j + 1, x);
            vv[j][x] = 0;
            v1[x]++;
        }
    } else {
        dfs(0, x + 1);
    }
}

int solution(vector<vector<int>> a) {
    vector<vector<int>> temp(a.size(), vector<int>(a.front().size(), 0));
    vv = temp;
    height = vv.size();
    width = vv.front().size();

    // 각 열의 1개수 확인
    for (int x = 0; x < width; x++) {
        int count = 0;
        for (int y = 0; y < height; y++) {
            if (a[y][x] == 1) count++;
        }
        v1.push_back(count);
    }

    dfs(0, 0);
    return result % (10000000 + 19);
}

int main() {
    // vector<vector<int>> a = {{0, 1, 0}, {1, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    // vector<vector<int>> a = {{1, 0, 0}, {1, 0, 0}};
    vector<vector<int>> a = {{1, 0, 0, 1, 1}, {0, 0, 0, 0, 0}, {1, 1, 0, 0, 0}, {0, 0, 0, 0, 1}};
    cout << solution(a) << endl;

    return 0;
}