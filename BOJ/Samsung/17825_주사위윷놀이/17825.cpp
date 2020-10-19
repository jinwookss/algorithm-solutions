#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

vector<int> inputs(10);
vector<vector<int>> map;
vector<int> idx = {0, 0, 0, 0};
vector<int> course = {0, 0, 0, 0};
int maxScore = 0;

// vector<int> v;
// vector<int> v2;

void dfs(int diceIdx, int score) {
    if (diceIdx == 10) {
        maxScore = max(maxScore, score);
        // if (score > maxScore) {
        //     cout << "score = " << score << endl;
        //     for (int i : v) {
        //         cout << i << " ";
        //     }
        //     cout << endl;
        //     maxScore = score;

        //     for (int i : v2) {
        //         cout << i << " ";
        //     }
        //     cout << endl;
        //     maxScore = score;
        // }
        return;
    }

    for (int mal = 0; mal < 4; mal++) {
        // 말이 이미 도착한 경우
        if (idx[mal] == map[course[mal]].size() - 1) continue;

        // 다음 주사위 위치
        int before = idx[mal];
        if (idx[mal] + inputs[diceIdx] >= map[course[mal]].size()) {
            idx[mal] = map[course[mal]].size() - 1;
        } else
            idx[mal] += inputs[diceIdx];

        int shortcut = 0;
        if (course[mal] == 0) {
            if (map[course[mal]][idx[mal]] == 10) {
                course[mal] = 1;
                shortcut = 1;
            } else if (map[course[mal]][idx[mal]] == 20) {
                course[mal] = 2;
                shortcut = 2;
            } else if (map[course[mal]][idx[mal]] == 30) {
                course[mal] = 3;
                shortcut = 3;
            }
        }

        // 말 위치 중복 체크
        bool isDuplicated = false;
        for (int mal2 = 0; mal2 < 4; mal2++) {
            if (mal == mal2) continue;

            if (course[mal] == course[mal2] && idx[mal] == idx[mal2] && idx[mal] != map[course[mal]].size() - 1) {
                isDuplicated = true;
                break;
            }

            if ((map[course[mal]][idx[mal]] == 25 && map[course[mal2]][idx[mal2]] == 25) 
                || (map[course[mal]][idx[mal]] == 30 && map[course[mal2]][idx[mal2]] == 30 && map[course[mal]][idx[mal] - 1] == 25 && map[course[mal2]][idx[mal2] - 1] == 25) 
                || (map[course[mal]][idx[mal]] == 35 && map[course[mal2]][idx[mal2]] == 35) 
                || (map[course[mal]][idx[mal]] == 40 && map[course[mal2]][idx[mal2]] == 40)) {
                isDuplicated = true;
                break;
            }
        }
        if (isDuplicated) {
            idx[mal] = before;
            if (shortcut != 0) course[mal] = 0;
            continue;
        }

        // v.push_back(map[course[mal]][idx[mal]]);
        // v2.push_back(mal + 1);
        dfs(diceIdx + 1, score + map[course[mal]][idx[mal]]);
        // v.pop_back();
        // v2.pop_back();

        idx[mal] = before;
        if (shortcut != 0) course[mal] = 0;
    }
}

int main() {
    ifstream cin("input.txt");
    if (cin.fail()) return -1;

    for (int i = 0; i < 10; i++) {
        cin >> inputs[i];
    }

    vector<int> v1 = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40, 0};
    vector<int> v2 = {0, 2, 4, 6, 8, 10, 13, 16, 19, 25, 30, 35, 40, 0};
    vector<int> v3 = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 25, 30, 35, 40, 0};
    vector<int> v4 = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 28, 27, 26, 25, 30, 35, 40, 0};

    // 0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38,                         40, 0
    //                10, 13, 16, 19,                                                         25, 30, 35, 40, 0
    //                                    20, 22, 24,                                         25, 30, 35, 40, 0
    //                                                        30,                 28, 27, 26, 25, 30, 35, 40, 0

    map.push_back(v1);
    map.push_back(v2);
    map.push_back(v3);
    map.push_back(v4);

    dfs(0, 0);
    cout << maxScore << endl;

    return 0;
}