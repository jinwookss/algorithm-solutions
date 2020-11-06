#include <iostream>
#include <string>
#include <vector>

using namespace std;

int isZippable(vector<vector<int>> &arr, int y, int x, int windowSize) {
    int number = -1;
    for (int yy = y; yy < y + windowSize; yy++) {
        for (int xx = x; xx < x + windowSize; xx++) {
            if (number == -1) number = arr[yy][xx];
            else {
                if (arr[yy][xx] != number) return -1;
            }
        }
    }
    return number;
}

vector<int> zip(vector<vector<int>> &arr, int y, int x, int windowSize) {
    vector<int> answer(2, 0);
    if (windowSize == 1) return answer;

    int ret = isZippable(arr, y, x, windowSize);
    if (ret == -1) {
        // 4개로 분할
        windowSize /= 2;
        int d[] = {0, windowSize};
        for (int ny = 0; ny < 2; ny++) {
            for (int nx = 0; nx < 2; nx++) {
                vector<int> v = zip(arr, y + d[ny], x + d[nx], windowSize);
                answer[0] += v[0];
                answer[1] += v[1];
            }
        }
    } else {
        if (ret == 0) answer[0] = windowSize * windowSize - 1;
        else answer[1] = windowSize * windowSize - 1;
    }
    return answer;
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer;
    // 초기 0, 1 값의 개수 카운트
    int n0 = 0, n1 = 0;
    for (int y = 0; y < arr.size(); y++) {
        for (int x = 0; x < arr.size(); x++) {
            if (arr[y][x] == 0)
                n0++;
            else
                n1++;
        }
    }
    answer.push_back(n0);
    answer.push_back(n1);

    vector<int> result = zip(arr, 0, 0, arr.size());
    answer[0] -= result[0];
    answer[1] -= result[1];

    return answer;
}

int main() {
    // vector<vector<int>> arr = {
    //     {1, 1, 0, 0},
    //     {1, 0, 0, 0},
    //     {1, 0, 0, 1},
    //     {1, 1, 1, 1}
    // };
    vector<vector<int>> arr = {
        {1,1,1,1,1,1,1,1},
        {0,1,1,1,1,1,1,1},
        {0,0,0,0,1,1,1,1},
        {0,1,0,0,1,1,1,1},
        {0,0,0,0,0,0,1,1},
        {0,0,0,0,0,0,0,1},
        {0,0,0,0,1,0,0,1},
        {0,0,0,0,1,1,1,1}
    };
    for (int i : solution(arr)) {
        cout << i << endl;
    }
    return 0;
}