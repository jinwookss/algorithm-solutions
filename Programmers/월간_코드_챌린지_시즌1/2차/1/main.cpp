#include <iostream>
#include <string>
#include <vector>

using namespace std;

string convertAndReverse(int n) {
    string result;
    while (n > 0) {
        result.append(to_string(n % 3));
        n /= 3;
    }
    return result;
}

int str2decimal(string s) {
    int result = 0;
    int multiplier = 1;
    for (int i = s.size() - 1; i >= 0; i--) {
        char c = s[i];
        result += atoi(&c) * multiplier;
        multiplier *= 3;
    }
    return result;
}

int solution(int n) {
    string s = convertAndReverse(n);
    int answer = str2decimal(s);
    return answer;
}

int main() {
    int n = 45;
    cout << solution(n) << endl;
    cout << solution(125) << endl;

    return 0;
}