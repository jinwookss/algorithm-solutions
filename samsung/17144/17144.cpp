#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> A;
int R, C, T;

vector<vector<int>> makeClone() {

    vector<vector<int>> clone; 
    for (auto row : A) {
        vector<int> r;
        for (auto val : row) {
            if (val == -1) {
                r.push_back(-1);
            } else {
                r.push_back(0);
            }
        }
        clone.push_back(r);
    }

    return clone;
}

void diffusion() {

    vector<vector<int>> clone = makeClone();

    for (int y=0; y<A.size(); y++) {
        for (int x=0; x<A[y].size(); x++) {
            // cout << "value = " << A[y][x] << endl;
            // 공기청정기가 있는 칸의 경우
            if (A[y][x] == -1) {
                continue;
            }
            
            // 먼지가 없는 칸의 경우
            if (A[y][x] == 0) {
                continue;
            }

            // 확산값 계산하여 clone의 각 칸에 저장
            int cnt = 0; // 확산된 공간의 수
            int amount = A[y][x] / 5;
            if (x > 0 && A[y][x-1] != -1) {
                // cout << "case 1" << endl;
                cnt++;
                clone[y][x-1] += amount;
            }
            if (x < A[y].size() - 1 && A[y][x+1] != -1) {
                // cout << "case 2" << endl;
                cnt++;
                clone[y][x+1] += amount;
            }
            if (y > 0 && A[y-1][x] != -1) {
                // cout << "case 3" << endl;
                cnt++;
                clone[y-1][x] += amount;
            }
            if (y < A.size() - 1 && A[y+1][x] != -1) {
                // cout << "case 4" << endl;
                cnt++;
                clone[y+1][x] += amount;
            }
            clone[y][x] += A[y][x] - (amount * cnt);
        }
    }
    A = clone;
}

void doWork() {

    vector<vector<int>> clone = makeClone();

    // 공기청정기 위치 찾기
    int topPos, botPos;
    for (int i=0; i<A.size(); i++) {
        if (A[i][0] == -1) {
            topPos = i;
            botPos = i + 1;
            break;
        }
    }

    // 공기 순환 
    // 상단부
    for (int i=0; i<topPos; i++) {
        if (clone[i+1][0] != -1) {
            clone[i+1][0] = A[i][0];
        }
    }

    for (int i=C-1; i>0; i--) {
        clone[0][i-1] = A[0][i];
    }

    for (int i=topPos; i>0; i--) {
        clone[i-1][C-1] = A[i][C-1];
    }

    for (int i=1; i<C-1; i++) {
        clone[topPos][i+1] = A[topPos][i];
    }

    // 하단부
    for (int i=1; i<C-1; i++) {
        clone[botPos][i+1] = A[botPos][i];
    }
    for (int i=botPos; i<R-1; i++) {
        clone[i+1][C-1] = A[i][C-1];
    }
    for (int i=C-1; i>0; i--) {
        clone[R-1][i-1] = A[R-1][i];
    }
    for (int i=R-1; i>botPos; i--) {
        if (clone[i-1][0] != -1) {
            clone[i-1][0] = A[i][0];
        }
    }

    // 나머지 값 복사
    for (int y=1; y<R-1; y++) {
        if (A[y][0] == -1) continue;
        for (int x=1; x<C-1; x++) {
            clone[y][x] = A[y][x];
        }
    }

    A = clone;
}

void run(int sec) {

    for (int s=0; s<sec; s++) {

        diffusion();
        doWork();
    }
}

int main() {

    cin >> R >> C >> T;

    for (int i=0; i<R; i++) {
        vector<int> row;
        for (int j=0; j<C; j++) {
            int val;
            cin >> val;
            row.push_back(val);
        }
        A.push_back(row);
    }
    
    run(T);
    
    int dust = 0;
    for (auto y : A) {
        for (auto x : y) {
            if (x != -1) {
                dust += x;
            }
        }
    }
    cout << dust << endl;
    
    return 0;
}