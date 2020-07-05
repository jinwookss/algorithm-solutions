/**
 * 백준 12100번
 * 2048 (Easy)
 * https://www.acmicpc.net/problem/12100
 */
#include <fstream>
#include <iostream>

using namespace std;

const int MAX_SIZE = 20;

int result = 0;

struct State { 
    int count = 0;
    int mapSize = 0;
    int map[MAX_SIZE][MAX_SIZE] = {0, };
    
    int getMax() { 
        int maxVal = 0;
        for (int y = 0; y < mapSize; y++) {
            for (int x = 0; x < mapSize; x++) { 
                if (map[y][x] > maxVal) {
                    maxVal = map[y][x];
                }
            }
        }
        return maxVal;
    }

    void up() {
        for (int x = 0; x < mapSize; x++) {
            int base = 0;
            if (base + 1 >= mapSize) continue;
            for (int y = base + 1; y < mapSize; ) {
                if (map[y][x] != 0) {
                    // base가 0이면 base로 이동
                    if (map[base][x] == 0) { 
                        map[base][x] = map[y][x];
                        map[y][x] = 0;
                    }
                    // base와 같은 값이면 합치고 지움
                    else if (map[y][x] == map[base][x]) { 
                        map[base][x] *= 2;
                        map[y][x] = 0;
                        base++;
                    }
                    // base와 다른 값이면 base 다음으로 이동
                    else {
                        if (base + 1 != y) { 
                            map[base + 1][x] = map[y][x];
                            map[y][x] = 0;
                        }
                        base++;
                    }
                }
                y++;
            }
        }
    }

    /**
     * map을 시계방향으로 90도 회전
     */
    void rotate() {
        int temp[MAX_SIZE][MAX_SIZE] = {0, };
        int newY, newX = mapSize - 1;
        for (int y = 0; y < mapSize; y++) { 
            for (int x = 0; x < mapSize; x++) { 
                newY = x;
                temp[newY][newX] = map[y][x];
            }
            newX--;
        }

        for (int y = 0; y < mapSize; y++) { 
            for (int x = 0; x < mapSize; x++) { 
                map[y][x] = temp[y][x];
            }
        }
    }

    void print() {
        for (int y = 0; y < mapSize; y++) { 
            for (int x = 0; x < mapSize; x++) { 
                cout << map[y][x] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};

void dfs(State state) { 
    if (state.count == 5) {
        int currentMax = state.getMax();
        if (result < currentMax) {
            result = currentMax;
        }
        return;
    }

    state.count++;
    for (int dir = 0; dir < 4; dir++) {
        State next = state;
        next.up();
        dfs(next);
        state.rotate();
    }
}

int main() {
    ifstream cin("input.txt");
    assert(!cin.fail());

    int N; // 보드의 크기 (1 <= N <= 20)
    State state;
    
    // 보드 입력
    cin >> N;
    for (int y = 0; y < N; y++) {
        for (int x = 0; x < N; x++) {
            int n;
            cin >> n;
            state.map[y][x] = n;
        }
    }
    state.mapSize = N;

    dfs(state);

    cout << result << endl;

    return 0;
}