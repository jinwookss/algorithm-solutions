#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<bool> visited(9, false);

void selectNumber(vector<int> &v, int count) {
    if (count == M) {
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (visited[i]) continue;

        v.push_back(i);
        visited[i] = true;
        selectNumber(v, count + 1);
        v.pop_back();
        visited[i] = false;
    }
}

int main() {
    ifstream cin("input.txt");
    if (cin.fail()) return -1;

    cin >> N >> M;

    vector<int> v;
    selectNumber(v, 0);

    return 0;
}