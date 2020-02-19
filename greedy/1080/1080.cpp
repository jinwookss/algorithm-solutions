#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    int N, M;
    vector<string> A, B;
    vector<vector<int>> C;

    cin >> N >> M;
    for (int i = 0; i < N * 2; i++) {
        string row;
        cin >> row;
        if (i < N) {
            A.push_back(row);
        } else {
            B.push_back(row);
        }
    }

    C.resize(N);
    for (int i = 0; i < N; i++) {
        C[i].resize(M);
        for (int j = 0; j < M; j++) {
            if (A[i][j] == B[i][j]) {
                C[i][j] = 0;
            } else {
                C[i][j] = 1;
            }
        }
    }

    int count = 0;
    for (int i = 0; i < N - 2; i++) {
        for (int j = 0; j < M - 2; j++) {
            if (C[i][j] == 1) {
                C[i][j] = !C[i][j];
                C[i][j+1] = !C[i][j+1];
                C[i][j+2] = !C[i][j+2];
               
                C[i+1][j] = !C[i+1][j];
                C[i+1][j+1] = !C[i+1][j+1];
                C[i+1][j+2] = !C[i+1][j+2];

                C[i+2][j] = !C[i+2][j];
                C[i+2][j+1] = !C[i+2][j+1];
                C[i+2][j+2] = !C[i+2][j+2];

                count++;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (C[i][j] == 1) {
                cout << "-1" << endl;
                return 0;
            }
        }
    }

    cout << count << endl;
    return 0;
}