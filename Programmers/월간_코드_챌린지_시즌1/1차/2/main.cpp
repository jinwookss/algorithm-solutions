#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n) {
    vector<vector<int>> v;

    for (int i = 1; i <= n; i++) {
        vector<int> vv(i);
        v.push_back(vv);
    }

    int y = 0, x = 0, dir = 0;
    int count = 0;
    for (int i = n; 0 < i; i--) {
        for (int j = 0; j < i; j++) {
            v[y][x] = ++count;

            if (j != i - 1) {
                switch (dir % 3) {
                    case 0:
                        y++;
                        break;
                    case 1:
                        x++;
                        break;
                    case 2:
                        y--;
                        x--;
                        break;
                }
            } else {
                switch (dir % 3) {
                    case 0:
                        x++;
                        break;
                    case 1:
                        y--;
                        x--;
                        break;
                    case 2:
                        y++;
                        break;
                }
            }
        }
        dir++;
    }

    vector<int> answer;
    for (vector<int> vv : v) {
        for (int i : vv) {
            answer.push_back(i);
        }
    }
    return answer;
}

int main() {
    for (int i : solution(5)) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}