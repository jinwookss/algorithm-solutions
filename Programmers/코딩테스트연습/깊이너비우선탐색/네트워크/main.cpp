#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visited(n, false);
    queue<int> q;

    for (int y = 0; y < n; y++) {
        if (visited[y]) continue;
        answer++;
        q.push(y);
        visited[y] = true;

        while(!q.empty()) {
            int y = q.front(); 
            q.pop();

            for (int x = 0; x < n; x++) {
                if (y != x && computers[y][x] == 1 && !visited[x]) {
                    q.push(x);
                    visited[x] = true;
                }
            }
        }
    }

    return answer;
}

int main() {
    // vector<vector<int>> computers = {
    //   {1, 1, 0},
    //   {1, 1, 0},
    //   {0, 1, 1}  
    // };
    vector<vector<int>> computers = {
      {1, 1, 0},
      {1, 1, 1},
      {0, 1, 1}  
    };
    cout << solution(3, computers) << endl;
    return 0;
}