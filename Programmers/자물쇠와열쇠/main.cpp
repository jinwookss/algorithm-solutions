/**
 * 자물쇠와 열쇠
 * https://programmers.co.kr/learn/courses/30/lessons/60059
 */
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> expand(vector<vector<int>> const &lock) {
    int size = lock.size();
    int newSize = size * 3 - 2;
    vector<vector<int>> newLock(newSize);
    for (int i = 0; i < newSize; i++) {
        newLock[i].resize(newSize, 0);
    }

    int ny, nx;
    ny = nx = size - 1;
    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            newLock[y + ny][x + nx] = lock[y][x];
        }
    }

    return newLock;
}

vector<vector<int>> rotate(vector<vector<int>> &v) {
    vector<vector<int>> nv(v.size(), vector<int>(v.size(), 0));
    for (int y = 0; y < v.size(); y++) {
        for (int x = 0; x < v.size(); x++) {
            nv[y][x] = v[v.size() - 1 - x][y];
        }
    }
    return nv;
}

bool match(int size, vector<vector<int>> &lock) {
    int ny, nx;
    ny = nx = size - 1;
    for (int y = ny; y < ny + size; y++) {
        for (int x = nx; x < nx + size; x++) {
            if (lock[y][x] != 1) return false;
        }
    }
    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    vector<vector<int>> newLock = expand(lock);
    int s = lock.size();
    int ns = newLock.size();
    for (int y = 0; y < ns - s; y++) {
        for (int x = 0; x < ns - s; x++) {
            for (int r = 0; r < 4; r++) {
                vector<vector<int>> nv = newLock;
                bool isFailed = false;

                for (int ny = 0; ny < s; ny++) {
                    for (int nx = 0; nx < s; nx++) {
                        if (key[ny][nx] == 1 && nv[ny + y][nx + x] == 1) {
                            isFailed = true;
                            break;
                        } else if (key[ny][nx] == 1 && nv[ny + y][nx + x] == 0) {
                            nv[ny + y][nx + x] = 1;
                        }
                    }
                    if (isFailed) break;
                }

                if (match(s, nv)) return true;
                key = rotate(key);
            }
        }
    }
    
    return false;
}

int main() {
    ifstream cin("input.txt");
    if (cin.fail()) return -1;

    int M, N; // 3 <= M <= N <= 20
    cin >> M >> N;

    vector<vector<int>> key(M, vector<int>(M, 0));
    vector<vector<int>> lock(N, vector<int>(N, 0));
    
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            cin >> key[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> lock[i][j];
        }
    }
    
    cout << (solution(key, lock) ? "true" : "false") << endl;

    return 0;
}