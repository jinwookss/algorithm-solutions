#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int trim0(string &s) {
    int numberOfZeros = 0;
    for (string::iterator itr = s.begin(); itr != s.end();) {
        if (*itr == '0') {
            itr = s.erase(itr);
            numberOfZeros++;
        } else {
            ++itr;
        }
    }
    return numberOfZeros;
}

string decimalToBinary(string s) {
    string result("");
    int i = s.size();
    
    while (i > 0) {
        char c = (i % 2) + '0';
        result.push_back(c);
        i /= 2;
    }
    reverse(result.begin(), result.end());
    return result;
}

vector<int> solution(string s) {
    int deletedZeros = 0;
    int conversionCount = 0;
    while (s != "1") {
        deletedZeros += trim0(s);
        s = decimalToBinary(s);
        conversionCount++;
    }

    vector<int> answer = {conversionCount, deletedZeros};
    return answer;
}

int main() {
    // Case 1
    // string s = "110010101001";
    // string s = "01110";
    string s = "1111111";

    for (int i : solution(s)) {
        cout << i << endl;
    }

    return 0;
}