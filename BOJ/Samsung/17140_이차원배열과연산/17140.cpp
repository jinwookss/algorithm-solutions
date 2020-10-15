#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

bool compare(pair<int, int> a, pair<int, int> b) {
    if (a.second != b.second) {
        return a.second < b.second;
    } else {
        return a.first < b.first;
    }
}

void R(vector<vector<int>> &A) {
    int maxRowSize = 0;

    for (int y = 0; y < A.size(); y++) {
        map<int, int> numberCountMap;
        for (int x = 0; x < A[y].size(); x++) {
            if (A[y][x] == 0) continue;
            map<int, int>::iterator itr = numberCountMap.find(A[y][x]);
            if (itr == numberCountMap.end()) {
                numberCountMap[A[y][x]] = 1;
            } else {
                numberCountMap[A[y][x]]++;
            }
        }

        // 정렬
        vector<pair<int, int>> sortedVector;
        for (map<int, int>::iterator itr = numberCountMap.begin(); itr != numberCountMap.end(); ++itr) {
            sortedVector.push_back(*itr);
        }
        sort(sortedVector.begin(), sortedVector.end(), compare);

        // 재입력
        A[y].clear();
        int rowSize = 0;
        for (int i = 0; i < sortedVector.size(); i++) {
            A[y].push_back(sortedVector[i].first);
            A[y].push_back(sortedVector[i].second);
            rowSize += 2;
            if (rowSize == 100) break;
        }

        // 최대 행 사이즈 업데이트
        maxRowSize = max(maxRowSize, rowSize);
    }

    // 최대 행 사이즈에 맞춰 0 패딩 추가
    for (int y = 0; y < A.size(); y++) {
        int gap = maxRowSize - A[y].size();
        for (int i = 0; i < gap; i++) {
            A[y].push_back(0);
        }
    }
}

void C(vector<vector<int>> &A) {
    int maxColSize = 0;
    vector<vector<int>> newCols;

    for (int x = 0; x < A.front().size(); x++) {
        map<int, int> numberCountMap;
        for (int y = 0; y < A.size(); y++) {
            if (A[y][x] == 0) continue;
            map<int, int>::iterator itr = numberCountMap.find(A[y][x]);
            if (itr == numberCountMap.end()) {
                numberCountMap[A[y][x]] = 1;
            } else {
                numberCountMap[A[y][x]]++;
            }
        }

        // 정렬
        vector<pair<int, int>> sortedVector;
        for (map<int, int>::iterator itr = numberCountMap.begin(); itr != numberCountMap.end(); ++itr) {
            sortedVector.push_back(*itr);
        }
        sort(sortedVector.begin(), sortedVector.end(), compare);

        int colSize = 0;
        vector<int> col;
        for (int i = 0; i < sortedVector.size(); i++) {
            col.push_back(sortedVector[i].first);
            col.push_back(sortedVector[i].second);
            colSize += 2;
            if (colSize == 100) break;
        }
        newCols.push_back(col);
        // 최대 열 사이즈 업데이트
        maxColSize = max(maxColSize, colSize);
    }

    int rows = maxColSize;  // max 100
    int cols = A.front().size();
    vector<vector<int>> newA(rows, vector<int>(cols, 0));
    for (int x = 0; x < cols; x++) {
        for (int y = 0; y < newCols[x].size(); y++) {
            newA[y][x] = newCols[x][y];
        }
    }

    A = newA;
}

void print(vector<vector<int>> &A) {
    for (int y = 0; y < A.size(); y++) {
        for (int x = 0; x < A[y].size(); x++) {
            cout << A[y][x] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    ifstream cin("input.txt");
    if (cin.fail()) return -1;

    int r, c, k;  // [1, 100]
    cin >> r >> c >> k;

    vector<vector<int>> A(3, vector<int>(3, 0));
    for (int y = 0; y < 3; y++) {
        for (int x = 0; x < 3; x++) {
            cin >> A[y][x];
        }
    }

    int time = 0;
    while (time < 100) {
        // print(A);

        if (A.size() >= r && A.front().size() >= c) {
            if (A[r - 1][c - 1] == k) {
                break;
            }
        }

        int rows = A.size();
        int cols = A.front().size();

        if (rows >= cols)
            R(A);
        else
            C(A);

        time++;
    }

    if (A.size() < r || A.front().size() < c || A[r - 1][c - 1] != k) time = -1;
    cout << time << endl;

    return 0;
}