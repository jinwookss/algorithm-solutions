/**
 * 프로그래머스
 * 2020 카카오 블라인드 채용 - 자물쇠와 열쇠
 * https://programmers.co.kr/learn/courses/30/lessons/60059
 */
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> expand(vector<vector<int>> const &key, vector<vector<int>> const &lock) {
    int ks = key.size();
    int ls = lock.size();
    int nls = ls + (ks - 1) * 2;
    vector<vector<int>> newLock(nls, vector<int>(nls, 0));

    int offset = ks - 1;
    for (int y = 0; y < ls; y++) {
        for (int x = 0; x < ls; x++) {
            newLock[y + offset][x + offset] = lock[y][x];
        }
    }

    return newLock;
}

vector<vector<int>> rotate(vector<vector<int>> const &key) {
    vector<vector<int>> newKey(key.size(), vector<int>(key.size(), 0));
    for (int y = 0; y < key.size(); y++) {
        for (int x = 0; x < key.size(); x++) {
            newKey[y][x] = key[key.size() - 1 - x][y];
        }
    }
    return newKey;
}

bool match(int sy, int sx, vector<vector<int>> const &key, vector<vector<int>> lock) {
    int ks = key.size();
    for (int y = sy; y < sy + ks; y++) {
        for (int x = sx; x < sx + ks; x++) {
            lock[y][x] += key[y - sy][x - sx];
        }
    }

    int offset = ks - 1;
    int ls = lock.size() - (ks - 1) * 2;
    for (int y = 0; y < ls; y++) {
        for (int x = 0; x < ls; x++) {
            if (lock[y + offset][x + offset] != 1) return false;
        }
    }

    return true;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    // 자물쇠 범위 확장
    vector<vector<int>> newLock = expand(key, lock);
    // 열쇠를 한 칸씩 이동 후 자물쇠와 맞는지 검사
    int ks = key.size();
    int nls = newLock.size();
    
    for (int y = 0; y <= nls - ks ; y++) {
        for (int x = 0; x <= nls - ks; x++) {
            for (int r = 0; r < 4; r++) {
                if (match(y, x, key, newLock)) return true;
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