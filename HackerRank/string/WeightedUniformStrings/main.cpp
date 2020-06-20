/**
 * 해커랭크
 * Weighted Uniform Strings
 * https://www.hackerrank.com/challenges/weighted-uniform-string/problem
 */
#include <fstream>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<string> weightedUniformStrings(string s, vector<int> queries) {

    vector<string> result;
    set<int> val;

    for (int i = 0; i < s.size(); ) {
        char c = s[i];
        int start = i;
        int end = s.size() - 1;
        for (int j = i + 1; j < s.size(); j++) {
            if (c != s[j]) {
                end = j - 1;
                break;
            }
        }
        // cout << start << ", " << end << endl;

        int count = end - start + 1;
        int w = c - 'a' + 1;
        for (int j = 1; j <= count; j++) {
            val.insert(w * j);
        }
        
        i = end + 1;
    }

    for (int i : queries) {
        if (val.find(i) != val.end()) {
            result.push_back("Yes");
        } else {
            result.push_back("No");
        }
    }

    return result;
}

int main() {
    ifstream cin("input.txt");
    if (cin.fail()) return -1;

    string s;
    int n;
    vector<int> queries;

    cin >> s >> n;
    for (int i = 0; i < n; i++) {
        int query;
        cin >> query;
        queries.push_back(query);
    }

    for (string s : weightedUniformStrings(s, queries)) {
        cout << s << endl;
    }

    return 0;
}