#include <iostream>
#include <queue>

using namespace std;

int N;
bool G[100][100] = {
    {0, 0},
};

bool result[100][100] = {
    {0, 0},
};

void bfs(int startNode) {
    
    bool visited[N] = {
        0,
    };

    queue<int> q;
    q.push(startNode);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int i = 0; i < N; i++) {
            if (G[node][i] && !visited[i]) {
                q.push(i);
                visited[i] = 1;
                result[startNode][i] = 1;
            }
        }
    }
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int val;
            cin >> val;
            G[i][j] = val;
        }
    }

    for (int i = 0; i < N; i++) {
        bfs(i);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}