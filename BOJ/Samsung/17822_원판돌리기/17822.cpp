#include <deque>
#include <fstream>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;  // 원판 최대 크기, 정수의 개수 [2, 50]
int T;     // 회전수 [1, 50]
vector<deque<int>> circles(51);

void printCircles() {
    for (int i = 1; i <= N; i++) {
        for (int m = 0; m < M; m++) {
            cout << circles[i][m] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// 1123 -> 3112 시계 / 1123 -> 1231 반시계
void rotate(int i, int dir) {
    deque<int> &numbers = circles[i];
    if (dir == 0) {
        numbers.push_front(numbers.back());
        numbers.pop_back();
    } else if (dir == 1) {
        numbers.push_back(numbers.front());
        numbers.pop_front();
    }
}

int findAdjacentNumber() {
    int totalCount = 0;
    vector<vector<bool>> visited(51, vector<bool>(M, false));

    for (int i = 1; i <= N; i++) {
        for (int m = 0; m < M; m++) {
            if (visited[i][m] || circles[i][m] == 0) continue;

            int count = 0;
            queue<pair<int, int>> q;
            int number = circles[i][m];

            q.push(make_pair(i, m));
            visited[i][m] = true;
            count++;

            while (!q.empty()) {
                pair<int, int> p = q.front();
                q.pop();
                int ii = p.first;
                int mm = p.second;
                // cout << "pop " << ii << ", " << mm << endl;

                if (mm == 0) {
                    for (int pmm = circles[ii].size() - 1; pmm > mm; pmm--) {
                        if (visited[ii][pmm] || circles[ii][pmm] != number) break;
                        q.push(make_pair(ii, pmm));
                        visited[ii][pmm] = true;
                        circles[ii][pmm] = 0;
                        count++;
                        // cout << "erase " << ii << ", " << pmm << endl;
                    }
                } else {
                    for (int pmm = mm - 1; pmm >= 0; pmm--) {
                        if (visited[ii][pmm] || circles[ii][pmm] != number) break;
                        q.push(make_pair(ii, pmm));
                        visited[ii][pmm] = true;
                        circles[ii][pmm] = 0;
                        count++;
                        // cout << "erase " << ii << ", " << pmm << endl;
                    }
                }

                if (mm == M - 1) {
                    for (int nmm = 0; nmm < mm; nmm++) {
                        if (visited[ii][nmm] || circles[ii][nmm] != number) break;
                        q.push(make_pair(ii, nmm));
                        visited[ii][nmm] = true;
                        circles[ii][nmm] = 0;
                        count++;
                        // cout << "erase " << ii << ", " << nmm << endl;
                    }
                } else {
                    for (int nmm = mm + 1; nmm < M; nmm++) {
                        if (visited[ii][nmm] || circles[ii][nmm] != number) break;
                        q.push(make_pair(ii, nmm));
                        visited[ii][nmm] = true;
                        circles[ii][nmm] = 0;
                        count++;
                        // cout << "erase " << ii << ", " << nmm << endl;
                    }
                }

                for (int iii = ii + 1; iii <= N; iii++) {
                    if (visited[iii][mm] || circles[iii][mm] != number) break;
                    q.push(make_pair(iii, mm));
                    visited[iii][mm] = true;
                    circles[iii][mm] = 0;
                    count++;
                    // cout << "erase " << iii << ", " << mm << endl;
                }

                for (int iii = ii - 1; iii > 0; iii--) {
                    if (visited[iii][mm] || circles[iii][mm] != number) break;
                    q.push(make_pair(iii, mm));
                    visited[iii][mm] = true;
                    circles[iii][mm] = 0;
                    count++;
                    // cout << "erase " << iii << ", " << mm << endl;
                }
            }

            if (count > 1) {
                circles[i][m] = 0;
                // cout << "erase " << i << ", " << m << endl;
                totalCount += count;
            }
        }
    }
    return totalCount;
}

int main() {
    ifstream cin("input.txt");
    if (cin.fail()) return -1;

    cin >> N >> M >> T;

    for (int i = 1; i <= N; i++) {
        for (int m = 0; m < M; m++) {
            int number;
            cin >> number;
            circles[i].push_back(number);
        }
    }

    for (int t = 0; t < T; t++) {
        int x, d, k;
        cin >> x >> d >> k;

        // 번호가 x의 배수인 원판을 d방향으로 k칸 회전
        // d = 0: 시계 방향, d = 1: 반시계 방향
        for (int i = 1; i <= N; i++) {
            if (i % x == 0) {
                for (int j = 0; j < k; j++) {
                    rotate(i, d);
                }
            }
        }

        // printCircles();
        // 인접한 수가 없는 경우
        if (findAdjacentNumber() == 0) {
            int sum = 0, left = 0;
            for (int i = 1; i <= N; i++) {
                for (int m = 0; m < M; m++) {
                    if (circles[i][m] != 0) {
                        left++;
                        sum += circles[i][m];
                    }
                }
            }

            double average = (double)sum / (double)left;
            // cout << "average = " << average << endl;
            for (int i = 1; i <= N; i++) {
                for (int m = 0; m < M; m++) {
                    if (circles[i][m] == 0) continue;
                    if (circles[i][m] > average) {
                        circles[i][m]--;
                    } else if (circles[i][m] < average) {
                        circles[i][m]++;
                    }
                }
            }
        }

        // printCircles();
    }

    // 원판에 적힌 수의 합
    int result = 0;
    for (int i = 1; i <= N; i++) {
        for (int m = 0; m < M; m++) {
            result += circles[i][m];
        }
    }
    cout << result << endl;

    return 0;
}