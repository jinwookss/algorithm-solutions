#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum {
    U = 0,
    D,
    F,
    B,
    L,
    R,
};

class Cube {
   private:
    //   U
    // L F R B
    //   D
    vector<string> cube = {
        "wwwwwwwww",  // U
        "yyyyyyyyy",  // D
        "rrrrrrrrr",  // F
        "ooooooooo",  // B
        "ggggggggg",  // L
        "bbbbbbbbb"   // R
    };

    int getPlainIndex(char plain) {
        switch (plain) {
            case 'U':
                return U;
            case 'D':
                return D;
            case 'F':
                return F;
            case 'B':
                return B;
            case 'L':
                return L;
            case 'R':
                return R;
            default:
                return -1;
        }
    }
    // 시계방향 90도 회전
    void rotatePlain(int idx) {
        // 0 1 2    6 3 0
        // 3 4 5 -> 7 4 1
        // 6 7 8    8 5 2
        vector<string> temp = cube;
        cube[idx][0] = temp[idx][6];
        cube[idx][1] = temp[idx][3];
        cube[idx][2] = temp[idx][0];
        cube[idx][3] = temp[idx][7];
        cube[idx][4] = temp[idx][4];
        cube[idx][5] = temp[idx][1];
        cube[idx][6] = temp[idx][8];
        cube[idx][7] = temp[idx][5];
        cube[idx][8] = temp[idx][2];

        // U -> B R F L
        // D -> F R B L
        // F -> U R D L
        // B -> U L D R
        // L -> U F D B
        // R -> U B D F
        switch (idx) {
            case U:
                for (int i = 0; i < 3; i++) {
                    cube[B][i] = temp[L][i];
                    cube[R][i] = temp[B][i];
                    cube[F][i] = temp[R][i];
                    cube[L][i] = temp[F][i];
                }
                break;
            case D:
                for (int i = 6; i < 9; i++) {
                    cube[F][i] = temp[L][i];
                    cube[R][i] = temp[F][i];
                    cube[B][i] = temp[R][i];
                    cube[L][i] = temp[B][i];
                }
                break;
            case F:
                cube[U][6] = temp[L][8];
                cube[U][7] = temp[L][5];
                cube[U][8] = temp[L][2];

                cube[R][0] = temp[U][6];
                cube[R][3] = temp[U][7];
                cube[R][6] = temp[U][8];

                cube[D][2] = temp[R][0];
                cube[D][1] = temp[R][3];
                cube[D][0] = temp[R][6];

                cube[L][8] = temp[D][2];
                cube[L][5] = temp[D][1];
                cube[L][2] = temp[D][0];
                break;
            case B:
                cube[U][2] = temp[R][8];
                cube[U][1] = temp[R][5];
                cube[U][0] = temp[R][2];

                cube[L][0] = temp[U][2];
                cube[L][3] = temp[U][1];
                cube[L][6] = temp[U][0];

                cube[D][6] = temp[L][0];
                cube[D][7] = temp[L][3];
                cube[D][8] = temp[L][6];

                cube[R][8] = temp[D][6];
                cube[R][5] = temp[D][7];
                cube[R][2] = temp[D][8];
                break;
            case L:
                cube[U][0] = temp[B][8];
                cube[U][3] = temp[B][5];
                cube[U][6] = temp[B][2];

                cube[F][0] = temp[U][0];
                cube[F][3] = temp[U][3];
                cube[F][6] = temp[U][6];

                cube[D][0] = temp[F][0];
                cube[D][3] = temp[F][3];
                cube[D][6] = temp[F][6];

                cube[B][8] = temp[D][0];
                cube[B][5] = temp[D][3];
                cube[B][2] = temp[D][6];
                break;
            case R:
                cube[U][8] = temp[F][8];
                cube[U][5] = temp[F][5];
                cube[U][2] = temp[F][2];

                cube[B][0] = temp[U][8];
                cube[B][3] = temp[U][5];
                cube[B][6] = temp[U][2];

                cube[D][8] = temp[B][0];
                cube[D][5] = temp[B][3];
                cube[D][2] = temp[B][6];

                cube[F][8] = temp[D][8];
                cube[F][5] = temp[D][5];
                cube[F][2] = temp[D][2];
                break;
        }
    }

   public:
    void rotate(string cmd) {
        char plainIdx = getPlainIndex(cmd[0]);
        char dir = cmd[1];

        if (dir == '+') {
            rotatePlain(plainIdx);
        } else {
            for (int i = 0; i < 3; i++) {
                rotatePlain(plainIdx);
            }
        }
    }
    void print() {
        int i = 0;
        while (i < 9) {
            cout << cube[0][i++];
            if (i % 3 == 0) cout << endl;
        }
    }
};

int main() {
    ifstream cin("input.txt");
    if (cin.fail()) return -1;

    int testCase, n;
    cin >> testCase;
    for (int i = 0; i < testCase; i++) {
        Cube cube;
        cin >> n;
        for (int j = 0; j < n; j++) {
            string cmd;
            cin >> cmd;
            cube.rotate(cmd);
        }
        cube.print();
    }

    return 0;
}