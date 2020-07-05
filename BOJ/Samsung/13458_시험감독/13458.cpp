/**
 * 백준 13458번
 * 시험 감독
 * https://www.acmicpc.net/problem/13458
 */
#include <fstream>
#include <iostream>

using namespace std;

int main() {

    ifstream cin("input.txt");
    if (cin.fail()) return -1;

    int N; // 시험장의 수 (1 <= N <= 1000000)
    int A[1000001]; // 각 시험장의 응시 인원 (1 <= A[i] <= 1000000)
    int B, C; // 총감독관, 부감독관의 감시 가능 인원 (1 <= B, C <= 1000000)

    cin >> N;
    for (int i = 1; i <= N; i++) { 
        cin >> A[i];
    }
    cin >> B >> C;

    // 감독관들의 감시 가능 인원이 1명이고 시험장과 
    // 각 시험장의 응시 인원이 최대인 경우 int형 범위 초과 발생 가능성 있음
    long long count = 0;
    for (int i = 1; i <= N; i++) {
        count++;
        int remained = A[i] - B;
        if (remained > 0) {
            count += remained / C;
            if (remained % C != 0) {
                count++;
            }
        }
    }
    cout << count << endl;

    return 0;
}