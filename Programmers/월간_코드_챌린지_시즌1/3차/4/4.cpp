#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

map<int, vector<int>> m;

int result = 0;

int findLongestLength(int prev, int cur) {
    // cout << "prev: " << prev << ", cur: " << cur << endl;
    int big1 = 0;
    int big2 = 0;

    for (int next : m[cur]) {
        if (next == prev) continue;

        int localMax = findLongestLength(cur, next);
        if (big1 <= localMax) {
            big2 = big1;
            big1  = localMax;
        }
    }

    cout << cur << ": " << big1 + big2 + 1 << endl;
    return big1 + big2 + 1;
}

void makeMap(vector<vector<int>> &t) {
    for (int i = 0; i < t.size(); i++) {
        int v1 = t[i][0];
        int v2 = t[i][1];
        m[v1].push_back(v2);
        m[v2].push_back(v1);
    }
}

int solution(vector<vector<int>> t) {

    makeMap(t);
    int i = findLongestLength(0, 0);
    if (result == 0) result = i;
    return result;
}

int main() {
    // vector<vector<int>> t = {
    //     {5, 1}, {2, 5}, {3, 5}, {3, 6}, {2, 4}, {4, 0}, {1, 8}, {6, 7}, {0, 9}, {9, 10}, {10, 11}, {11, 12}, {12, 13}, {13, 14}};

    vector<vector<int>> t = {
        {0, 1},
        {1, 3},
        {1, 2},
        {2, 4},
        {4, 5},
        {4, 6},
        {6, 7}, 
        {2, 8}    
    };

    cout << solution(t) << endl;

    return 0;
}