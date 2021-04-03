#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> m;

    for(vector<string> cloth : clothes) {
        m[cloth[1]]++;
    }

    for (auto p : m) {
        answer *= p.second + 1;
    }

    return answer - 1;
}

int main() {
    vector<vector<string>> clothes1 = {
        {"yellowhat", "headgear"},
        {"bluesunglasses", "eyewear"},
        {"green_turban", "headgear"}};

    vector<vector<string>> clothes2 = {
        {"a", "1"},
        {"b", "2"},
        {"e", "3"},
        {"f", "4"},
        {"c", "5"},
        {"d", "6"}
    };

    cout << solution(clothes1) << endl;
    cout << solution(clothes2) << endl;

    return 0;
}