#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {

    vector<vector<int>> cache(triangle.size(), vector<int>(triangle.back().size(), 0));

    cache[0][0] = triangle[0][0];

    for (int y = 1; y < triangle.size(); y++) {
        for (int x = 0; x < triangle[y].size(); x++) {
            int p1 = x > 0 ? cache[y - 1][x - 1] : 0;
            int p2 = x < y ? cache[y - 1][x] : 0;
            cache[y][x] = triangle[y][x] + max(p1, p2);
        }
    }

    int answer = 0;

    for (int val : cache.back()) {
        answer = max(answer, val);
    }

    return answer;
}

int main() {
    vector<vector<int>> input = {
        {7},
        {3, 8},
        {8, 1, 0},
        {2, 7, 4, 4},
        {4, 5, 2, 6, 5}
    };

    cout << solution(input) << endl; 
    
    return 0;
}

// 0
// 0 1
// 01 12 

// f(0, 0) = 7
// f(1, 0) = 

// 0 <- 0
// 1 <- 0, 1
// 2 <- 1, 2