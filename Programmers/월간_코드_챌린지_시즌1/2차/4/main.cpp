#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long solution(string s) {
    if (s.size() <= 1) return 0;
    // 단일 문자로 구성된 문자열
    char c = s.front();
    bool hasSingleChar = true;
    for (int i = 1; i < s.size(); i++) {
        if (c != s[i]) {
            hasSingleChar = false;
            break;
        }
    }
    if (hasSingleChar) return 0;

    long long answer = 0;

    for (int i = 0; i < s.size() - 1; i++) {
        int curBeauty = 0;
        int keep = 0;
        for (int j = i + 1; j < s.size(); j++) {
            if (s[i] != s[j]) {
                curBeauty = j - i;
            } 
            answer += curBeauty;
            cout << s[i] << ", " << s[j] << " | " << i << ", " << j << " = " << curBeauty << endl;
        }
    }

    return answer;
}

int main() {
    string s = "zxcz";
    cout << solution(s) << endl;

    return 0;
}