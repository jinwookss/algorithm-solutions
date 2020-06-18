/**
 * 백준 14888번
 * 연산자 끼워넣기
 * https://www.acmicpc.net/problem/14888
 */
#include <fstream>
#include <iostream>

using namespace std;

enum {
    ADD = 0,
    SUB = 1,
    MUL = 2,
    DIV = 3
};

int N; // 수의 개수 (2 <= N <= 11)
int A[11] = {0, };
int operand[4] = {0, };

// 연산자를 어떻게 끼워넣어도 항상 -10억보다 크거나 같고, 10억보다 작거나 같은 결과만 나옴
// signed int로 -21 ~ 21억 표현 가능
int maximum = -1000000000;
int minimum = 1000000000;

void dfs(int count, int result) { 
    // cout << "count = " << count << ", result = " << result << endl;
    if (count == N) {
        if (result > maximum) {
            maximum = result;
        }
        if (result < minimum) {
            minimum = result;
        }
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (operand[i] > 0) {
            operand[i]--;
            int temp = result;
            if (i == ADD) {
                // cout << "ADD: " << A[count] << endl;
                temp += A[count];
            } else if (i == SUB) {
                // cout << "SUB: " << A[count] << endl;
                temp -= A[count];
            } else if (i == MUL) {
                // cout << "MUL: " << A[count] << endl;
                temp *= A[count];
            } else if (i == DIV) {
                // cout << "DIV: " << A[count] << endl;
                temp /= A[count];
            }
            dfs(count + 1, temp);
            operand[i]++;
        }
    }
}

int main() {
    ifstream cin("input.txt");
    if (cin.fail()) return -1;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < 4; i++) {
        cin >> operand[i];
    }

    dfs(1, A[0]);

    cout << maximum << endl << minimum << endl;

    return 0;
}