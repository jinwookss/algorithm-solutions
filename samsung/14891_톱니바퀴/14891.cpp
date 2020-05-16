/**
 * 백준 14891번
 * 톱니바퀴
 * https://www.acmicpc.net/problem/14891
 */
#include <fstream>
#include <iostream>
#include <cmath>

using namespace std;

struct Gear {
    string state;
    bool isRotated = false;

    void rotate(int dir) {
        if (dir == 1) {
            char temp = state[7];
            for (int i = 7; i > 0; i--) {
                state[i] = state[i - 1]; 
            }
            state[0] = temp;
        } else {
            char temp = state[0];
            for (int i = 0; i < 7; i++) {
                state[i] = state[i + 1];
            }
            state[7] = temp;
        }
    }
};

Gear gear[4];
int K; // 회전 횟수 (1 <= K <= 100)
int score = 0;

void rotate(int number, int dir) {
    // cout << "rotate: " << number << ", " << dir << endl;
    gear[number].isRotated = true;
    // 회전 여부 판단: 현재 6과 이전 2를 비교, 현재 2와 다음 6을 비교
    // 이전 톱니바퀴의 회전 여부
    if (number > 0) {
        if (!gear[number - 1].isRotated 
            && gear[number].state[6] != gear[number - 1].state[2]) {
            rotate(number - 1, dir * -1);
        }
    } 
    // 다음 톱니바퀴의 회전 여부
    if (number < 3) {
        if (!gear[number + 1].isRotated 
            && gear[number].state[2] != gear[number + 1].state[6]) {
            rotate(number + 1, dir * -1);
        }
    }
    gear[number].rotate(dir);
}

int main() {
    ifstream cin("input.txt");
    if (cin.fail()) return -1;

    for (int i = 0; i < 4; i++) {
        cin >> gear[i].state;
        // cout << gear[i].state << endl;
    }
    cin >> K;
    for (int i = 0; i < K; i++) {
        int number, dir;
        cin >> number >> dir;
        number--;

        for (int j = 0; j < 4; j++) {
            gear[j].isRotated = false;
        }
        rotate(number, dir);

        // for (int j = 0; j < 4; j++) {
        //     cout << gear[j].state << endl;
        // }
    }

    for (int j = 0; j < 4; j++) {
        if (gear[j].state[0] == '1') {
            score += pow(2, j);
        }
    }

    cout << score << endl;

    return 0;
}