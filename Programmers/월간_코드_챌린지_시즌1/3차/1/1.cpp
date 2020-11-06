#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a, vector<int> b) {
    int answer = 0;
    int size = a.size();
    for (int i = 0; i < size; i++) {
        answer += a[i] * b[i];
    }
    return answer;
}

int main() {
    // Case 1
    // vector<int> a = {1, 2, 3, 4};
    // vector<int> b = {-3, -1, 0, 2};

    // Case 2
    vector<int> a = {-1, 0, 1};
    vector<int> b = {1, 0, -1};

    cout << solution(a, b) << endl;

    return 0;
}