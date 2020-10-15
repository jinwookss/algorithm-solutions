#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int N;  // [5, 20]
int sum;
vector<vector<int>> map(21, vector<int>(21, 0));  // 인구수 맵 (인덱스 1부터 시작)
int result = INT32_MAX;

int calcGap(int x, int y, int d1, int d2) {
    vector<vector<bool>> r5(N + 1, vector<bool>(N + 1, false));
    int n1, n2, n3, n4, n5;
    n1 = n2 = n3 = n4 = n5 = 0;

    // r5
    int r, c;

    r = x;
    c = y;
    while (r <= x + d1 && c >= y - d1) {
        r5[r][c] = true;
        r++;
        c--;
    }

    r = x;
    c = y;
    while (r <= x + d2 && c <= y + d2) {
        r5[r][c] = true;
        r++;
        c++;
    }

    r = x + d1;
    c = y - d1;
    while (r <= x + d1 + d2 && c <= y - d1 + d2) {
        r5[r][c] = true;
        r++;
        c++;
    }

    r = x + d2;
    c = y + d2;
    while (r <= x + d2 + d1 && c >= y + d2 - d1) {
        r5[r][c] = true;
        r++;
        c--;
    }

    for (int r = 1; r <= N; r++) {
        int start = 0, end = 0;
        for (int c = 1; c <= N; c++) {
            if (r5[r][c] && start == 0)
                start = c;

            else if (r5[r][c] && end == 0)
                end = c;
        }

        if (start != 0 && end != 0) {
            for (int c = start; c < end; c++) {
                r5[r][c] = true;
            }
        }
    }

    // test
    // for (int r = 1; r <= N; r++) {
    //     for (int c = 1; c <= N; c++) {
    //         cout << r5[r][c] << " ";
    //     }
    //     cout << endl;
    // }

    // 나머지 카운트
    for (int r = 1; r < x + d1; r++) {
        for (int c = 1; c <= y; c++) {
            if (!r5[r][c]) n1 += map[r][c];
        }
    }

    for (int r = 1; r <= x + d2; r++) {
        for (int c = y + 1; c <= N; c++) {
            if (!r5[r][c]) n2 += map[r][c];
        }
    }

    for (int r = x + d1; r <= N; r++) {
        for (int c = 1; c < y - d1 + d2; c++) {
            if (!r5[r][c]) n3 += map[r][c];
        }
    }

    for (int r = x + d2 + 1; r <= N; r++) {
        for (int c = y - d1 + d2; c <= N; c++) {
            if (!r5[r][c]) n4 += map[r][c];
        }
    }

    n5 = sum - n1 - n2 - n3 - n4;
    // cout << n1 << ", " << n2 << ", " << n3 << ", " << n4 << ", " << n5 << endl;

    return max(n1, max(n2, max(n3, max(n4, n5)))) - min(n1, min(n2, min(n3, min(n4, n5))));
}

void selectPoint() {
    for (int x = 1; x <= N - 2; x++) {
        for (int y = 2; y <= N - 1; y++) {
            int d1 = 1;
            while (d1 <= N - x - 1 && 1 <= y - d1) {
                int d2 = 1;
                while (d2 <= N - x - d1 && 1 <= y - d1 && y + d2 <= N) {
                    int gap = calcGap(x, y, d1, d2);

                    // cout << "x = " << x << ", y = " << y << ", d1 = " << d1 << ", d2 = " << d2 << ", gap = " << gap << endl;
                    if (result > gap) {
                        result = gap;
                    }
                    d2++;
                }
                d1++;
            }
        }
    }
}

int main() {
    ifstream cin("input.txt");
    if (cin.fail()) return -1;

    cin >> N;
    for (int x = 1; x <= N; x++) {
        for (int y = 1; y <= N; y++) {
            cin >> map[x][y];
            sum += map[x][y];
        }
    }

    selectPoint();
    cout << result << endl;

    return 0;
}