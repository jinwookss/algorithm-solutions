/**
 * 백준 14890번
 * 경사로
 * https://www.acmicpc.net/problem/14890
 */
#include <fstream>
#include <iostream>

using namespace std;

int N; // (2 <= N <= 100)
int L; // (1 <= L <= N)
int map[100][100] = {0, };
int result = 0;

int main() {
    ifstream cin("input.txt");
    if (cin.fail()) return -1;

    int copy[100][100] = {0, };

    cin >> N >> L;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            cin >> map[y][x];
            copy[y][x] = map[y][x];
        }
    }

    // 가로 방향 길 탐색
    for (int y = 0; y < N; y++) {
        int cur = map[y][0];
        bool isPassed = true;
        for (int x = 1; x < N; x++) {
            if (map[y][x] == 0) continue;
            else if (map[y][x] != cur) {
                int gap = map[y][x] - cur;
                // 한 칸 높아진 경우
                if (gap == 1) {
                    // 범위 초과 체크
                    if (x - L < 0) {
                        isPassed = false;
                        break;
                    }
                    // 경사로가 놓일 자리가 평탄한지 체크
                    for (int i = 1; i <= L; i++) {
                        if (map[y][x - i] != cur) {
                            isPassed = false;
                            break;
                        }
                    }
                    if (!isPassed) break;
                    for (int i = 1; i <= L; i++) {
                        map[y][x - i] = 0;
                    }
                } 
                // 한 칸 낮아진 경우
                else if (gap == -1) {
                    // 범위 초과 체크
                    if (x + L - 1 >= N) {
                        isPassed = false;
                        break;
                    }
                    // 경사로가 놓일 자리가 평탄한지 체크
                    for (int i = 0; i < L; i++) {
                        if (map[y][x + i] != cur - 1) {
                            isPassed = false;
                            break;
                        }
                    }
                    if (!isPassed) break;
                    for (int i = 0; i < L; i++) {
                        map[y][x + i] = 0;
                    }
                }
                // 나머지 경우 -> 지나갈 수 없음
                else {
                    isPassed = false;
                    break;
                }
                cur += gap; // 현재 높이 갱신
            }
        }
        if (isPassed) {
            result++;
            // cout << "pass y: " << y << endl;
        }
    }

    // 세로 방향 길 탐색
    for (int x = 0; x < N; x++) {
        int cur = copy[0][x];
        bool isPassed = true;
        for (int y = 1; y < N; y++) {
            if (copy[y][x] == 0) continue;
            else if (copy[y][x] != cur) {
                int gap = copy[y][x] - cur;
                // 한 칸 높아진 경우
                if (gap == 1) {
                    // 범위 초과 체크
                    if (y - L < 0) {
                        isPassed = false;
                        break;
                    }
                    // 경사로가 놓일 자리가 평탄한지 체크
                    for (int i = 1; i <= L; i++) {
                        if (copy[y - i][x] != cur) {
                            isPassed = false;
                            break;
                        }
                    }
                    if (!isPassed) break;
                    for (int i = 1; i <= L; i++) {
                        copy[y - i][x] = 0;
                    }
                } 
                // 한 칸 낮아진 경우
                else if (gap == -1) {
                    // 범위 초과 체크
                    if (y + L - 1 >= N) {
                        isPassed = false;
                        break;
                    }
                    // 경사로가 놓일 자리가 평탄한지 체크
                    for (int i = 0; i < L; i++) {
                        if (copy[y + i][x] != cur - 1) {
                            isPassed = false;
                            break;
                        }
                    }
                    if (!isPassed) break;
                    for (int i = 0; i < L; i++) {
                        copy[y + i][x] = 0;
                    }
                }
                // 나머지 경우 -> 지나갈 수 없음
                else {
                    isPassed = false;
                    break;
                }
                cur += gap; // 현재 높이 갱신
            }
        }
        if (isPassed) {
            result++;
            // cout << "pass x: " << x << endl;
        }
    }

    cout << result << endl;

    return 0;
}