#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

set<string> subNumbers;
vector<bool> visited(7, false);

bool isPrime(string s) {
    int number = atoi(s.c_str());
    int divider = sqrt(number);

    if (number < 2) return false;
    else if (number == 2) return true;

    for (int i = 2; i <= divider; i++) {
        if (number % i == 0) return false;
    }
    return true;
}

void makeNum(string &numbers, string number) {
    if (number.size() == numbers.size()) return;

    for (int i = 0; i < numbers.size(); i++) {
        if (visited[i]) continue;
        if (number.empty() && numbers[i] == '0') continue;

        number.push_back(numbers[i]);
        visited[i] = true;

        cout << number << endl;
        subNumbers.insert(number);
        makeNum(numbers, number);

        number.pop_back();
        visited[i] = false;
    }
}

int solution(string numbers) {
    int answer = 0;

    string number = "";
    makeNum(numbers, number);

    for (string s : subNumbers) {
        if (isPrime(s)) answer++;
    }

    return answer;
}

int main() {
    string numbers = "17";

    cout << solution(numbers) << endl;

    return 0;
}