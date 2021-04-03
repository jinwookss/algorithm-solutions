#include <string>
#include <vector>
#include <map>

using namespace std;

// 0번 섬에서 시작해 가능한 선택지를 하니씩 모두 선택
int minCost = 2100000000;
void dfs(map<int, vector<pair<int, int>>> &m, vector<bool> &visited, int cur, int visitedCount, int cost) {
    if (visitedCount == m.size()) {
        if (cost < minCost) {
            minCost = cost;
            return;
        }
    }

    
}

int solution(int n, vector<vector<int>> costs) {
    map<int, vector<pair<int, int>>> m;
    for (vector<int> v : costs) {
        m[v[0]].push_back(make_pair(v[1], v[2]));
    }
    
    // int cost = 0;

    // vector<bool> used(costs.size(), false);
    // vector<bool> visited(n, false);
    
    // vector<int> front = costs.front();
    // used[0] = true;
    // visited[front[0]] = true;
    // int cur = front[1];


}

int main() {

    return 0;
}