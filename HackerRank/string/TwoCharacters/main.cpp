/**
 * 해커랭크
 * Two Characters
 * https://www.hackerrank.com/challenges/two-characters/problem
 */

#include <fstream>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int alternate(string s) {
    int max = 0;
    set<char> ss;
    vector<char> v;
    
    // 문자 종류 set, vector 생성
    for (char c : s) {
        ss.insert(c);
    }
    
    for (char c : ss) {
        v.push_back(c);
    }

    // 문자 2개 선택
    int size = v.size();
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            // cout << v[i] <<  ", " << v[j] << endl;

            // 나머지 제거
            string s2 = "";
            for (char c : s) {
                if (c == v[i] || c == v[j]) {
                    s2.push_back(c);
                }
            }

            // alternate 판단
            bool isAlternate = true;
            for (int k = 0; k < s2.size() - 1; k++) {
                if (s2[k] == s2[k + 1]) {
                    isAlternate = false;
                    break;
                }
            }
            if (isAlternate && s2.size() > max) {
                max = s2.size();
            }
        }
    }

    return max;    
}

int main() {
    ifstream cin("input.txt");
    if (cin.fail()) return -1;

    int l;
    string s;
    cin >> l >> s;

    cout << alternate(s) << endl;

    return -1;
}