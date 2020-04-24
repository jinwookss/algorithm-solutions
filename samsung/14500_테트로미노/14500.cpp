#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int map[500][500] = {0, };

struct Tetromino {
    int w, h;
    int shape[4][4] = {0, };

    Tetromino(int type) {
        if (type == 1) { 
            // ㅁㅁㅁㅁ
            w = 4;
            h = 1;
            shape[0][0] = 1;
            shape[0][1] = 1;
            shape[0][2] = 1;
            shape[0][3] = 1;
        } else if (type == 2) { 
            // ㅁㅁ
            // ㅁㅁ
            w = 2;
            h = 2;
            shape[0][0] = 1;
            shape[0][1] = 1;
            shape[1][0] = 1;
            shape[1][1] = 1;
        } else if (type == 3) { 
            // ㅁ
            // ㅁ
            // ㅁㅁ
            w = 2;
            h = 3;
            shape[0][0] = 1;
            shape[1][0] = 1;
            shape[2][0] = 1;
            shape[2][1] = 1;
        } else if (type == 4) {
            //   ㅁ
            //   ㅁ
            // ㅁㅁ
            w = 2;
            h = 3;
            shape[0][1] = 1;
            shape[1][1] = 1;
            shape[2][0] = 1;
            shape[2][1] = 1;
        } else if (type == 5) {
            // ㅁ
            // ㅁㅁ
            //   ㅁ
            w = 2;
            h = 3;
            shape[0][0] = 1;
            shape[1][0] = 1;
            shape[1][1] = 1;
            shape[2][1] = 1;
        } else if (type == 6) {
            //   ㅁ
            // ㅁㅁ
            // ㅁ
            w = 2;
            h = 3;
            shape[0][1] = 1;
            shape[1][0] = 1;
            shape[1][1] = 1;
            shape[2][0] = 1;
        } else if (type == 7) {
            // ㅁ
            // ㅁㅁ
            // ㅁ
            w = 2;
            h = 3;
            shape[0][0] = 1;
            shape[1][0] = 1;
            shape[1][1] = 1;
            shape[2][0] = 1;
        }
    }

    void rotate() {
        int temp[4][4] = {0, };
        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                temp[y][x] = shape[x][]
            }
        }
    }
};

int main() {
    ifstream cin("input.txt");
    if (cin.fail()) return -1;

    int N, M; // 세로, 가로 크기 (4 <= N, M <= 500)
    cin >> N >> M;
    for (int y = 0; y < N; y++) { 
        for (int x = 0; x < M; x++) {
            cin >> map[y][x];
        }
    }

    return 0;
}