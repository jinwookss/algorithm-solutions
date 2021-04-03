#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int result = 1410065408;

int changeAlphabet(char dst) {
    int distance = abs(dst - 'A');
    if (distance > 13) distance = 26 - distance;
    return distance;
}

void dfs(string &name, vector<int> &idxNotA, vector<bool> &visited, int changeCount, int answer, int cur) {
    if (changeCount == idxNotA.size()) {
        result = min(result, answer);
        return;
    }

    for (int idx : idxNotA) {
        if (visited[idx]) continue;

        int distance = min(abs(idx - cur), (int)(name.size() - abs(idx - cur)));

        visited[idx] = true;
        dfs(name, idxNotA, visited, changeCount + 1, answer + changeAlphabet(name[idx]) + distance, idx);
        visited[idx] = false;
    }
}

int solution(string name) {
    // int answer = 0;

    vector<int> idxNotA;
    vector<bool> visited(name.size(), true);
    for (int i = 0; i < name.size(); i++) {
        if (name[i] != 'A') {
            idxNotA.push_back(i);
            visited[i] = false;
        }
    }

    dfs(name, idxNotA, visited, 0, 0, 0);
    return result;
}

int main() { 
    string name = "CANAANAA";
    string name2 = "CANAAAAANAN";

    cout << solution(name) << endl;
    cout << solution(name2) << endl;

    return 0;
}