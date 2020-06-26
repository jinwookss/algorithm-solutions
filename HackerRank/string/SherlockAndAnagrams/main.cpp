/**
 * 해커랭크
 * Sherlock and Anagrams
 * https://www.hackerrank.com/challenges/sherlock-and-anagrams/problem
 */

#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int sherlockAndAnagrams(string s) {
    vector<string> sub;
    for (int l = 1; l <= s.size() - 1; l++) {
        for (int i = 0; i <= s.size() - l; i++) {
            string splitStr = s.substr(i, l);
            sort(splitStr.begin(), splitStr.end());
            sub.push_back(splitStr);
        }
    }
    // 길이, 사전순 정렬
    sort(sub.begin(), sub.end(), [](string s1, string s2) {
        if (s1.size() == s2.size()) {
            return s1 < s2;
        } else {
            return s1.size() < s2.size();
        }
    });
    // 출력
    // for (string &str : sub) {
    //     cout << str << endl;
    // }
    
    int result = 0;
    for (int i = 0; i < sub.size() - 1; i++) {
        for (int j = i + 1; j < sub.size(); j++) {
            if (sub[i] == sub[j]) result++;
        }
    }

    return result;
}

int main() {
    ifstream cin("input.txt");
    if (cin.fail()) return -1;

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        string s;
        cin >> s;
        cout << sherlockAndAnagrams(s) << endl;
    }

    cin.close();
    return 0;
}