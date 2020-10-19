#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

class Block {
    public:
    int d = 0; // 내구도
    bool p = false; // 사람
};

int N; // [2, 100]
int K; // [1, 2N]
vector<Block> belt;

int main() {
    ifstream cin("input.txt");
    if (cin.fail()) return -1;

    cin >> N >> K;
    int len = N * 2;
    for (int i = 0; i < len; i++) {
        Block b;
        cin >> b.d;
        belt.push_back(b);
    }

    int time = 0;
    int offset = 0;
    while (true) {

        // cout << "time = " << time << endl;

        // 벨트가 한 칸 회전한다.
        offset--;
        if (offset == -len) offset = 0;

        // 마지막 칸에 로봇이 있는 경우 내린다.
        int end = (N - 1 + offset + len) % len;
        if (belt[end].p) {
            belt[end].p = false;
        }

        // 가장 먼저 벨트에 올라간 로봇부터, 벨트가 회전하는 방향으로 한 칸 이동할 수 있다면 이동한다. 만약 이동할 수 없다면 가만히 있는다.
        // 로봇이 이동하기 위해서는 이동하려는 칸에 로봇이 없으며, 그 칸의 내구도가 1 이상 남아 있어야 한다.
        // [offset, N - 1 + offset]
        for (int ii = N - 2; ii >= 0; ii--) {
            int i = (ii + offset + len) % len;
            int ni = (i + 1 + len) % len;
            if (belt[i].p && !belt[ni].p && belt[ni].d >= 1) {
                belt[i].p = false;
                belt[ni].p = true;
                belt[ni].d--;
            }
        }

        // 마지막 칸에 로봇이 있는 경우 내린다.
        if (belt[end].p) {
            belt[end].p = false;
        }

        // 올라가는 위치에 로봇이 없다면 로봇을 하나 올린다.
        int begin = (offset + len) % len;
        if (!belt[begin].p && belt[begin].d >= 1) {
            belt[begin].p = true;
            belt[begin].d--;
        }

        time++;

        // 내구도가 0인 칸의 개수가 K개 이상이라면 과정을 종료한다. 그렇지 않다면 1번으로 돌아간다.
        int count = 0;
        for (int i = 0; i < len; i++) {
            if (belt[i].d == 0) count++;
        }

        if (count >= K) {
            cout << time << endl;
            break;
        }

        // for (int ii = 0; ii < len; ii++) {
        //     int i = (ii + offset + len) % len;
        //     cout << belt[i].d << " ";
        // }
        // cout << endl;
    }


    return 0;
}