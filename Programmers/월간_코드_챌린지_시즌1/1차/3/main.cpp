#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a) {
    int size = a.size();
    if (size <= 2) return size;

    vector<vector<int>> dp(size, vector<int>(2));

    int l = a[0];
    int r = a[size - 1];
    for (int i = 1; i < size - 1; i++) {
        dp[i][0] = l;
        if (a[i] < l) {
            l = a[i];
        }
    }
    for (int i = size - 2; i > 0; i--) {
        dp[i][1] = r;
        if (a[i] < r) {
            r = a[i];
        }
    }

    int result = 2;
    for (int i = 1; i < size - 1; i++) {
        if (dp[i][0] > a[i] || dp[i][1] > a[i]) result++;
    }
    return result;
}

int main() {
    vector<int> a = {-16, 27, 65, -2, 58, -92, -71, -68, -61, -33};
    cout << solution(a) << endl;

    return 0;
}