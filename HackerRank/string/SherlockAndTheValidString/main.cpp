/**
 * 해커랭크
 * Sherlock and the Valid String
 * https://www.hackerrank.com/challenges/sherlock-and-valid-string/problem
 */
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

string isValid(string s) {
    vector<int> count(26, 0);
    for (char &c : s) {
        count[c - 'a']++;
    }

    int base = -1;
    bool result = true;
    for (int j = 0; j < 26; j++) {
        if (count[j] == 0) continue;
        if (base == -1) base = count[j];
        else {
            if (base != count[j]) {
                result = false;
                break;
            }
        }
    }
    if (result) return "YES";

    for (int i = 0; i < 26; i++) {
        if (count[i] > 0) {
            count[i]--;

            base = -1;
            result = true;
            for (int j = 0; j < 26; j++) {
                if (count[j] == 0) continue;
                if (base == -1) base = count[j];
                else {
                    if (base != count[j]) {
                        result = false;
                        break;
                    }
                }
            }
            if (result) return "YES";

            count[i]++;
        }
    }
    return "NO";
}

int main() {
    ifstream cin("input.txt");
    if (cin.fail()) return -1;

    string s;
    cin >> s;

    cout << isValid(s) << endl;

    return 0;
}