#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    stack<char> s;
    int removed = 0;

    for (int i = 0; i < number.size(); i++) {
        if (removed == k) {
            s.push(number[i]);
            continue;
        }

        if (s.empty() || s.top() >= number[i]) {
            s.push(number[i]);
        } else {
            while (!s.empty() && s.top() < number[i]) {
                s.pop();
                removed++;
                if (removed == k) break;
            }
            s.push(number[i]);
        }
    }

    while (removed < k && !s.empty()) {
        s.pop();
        removed++;
    }

    string answer = "";
    while (!s.empty()) {
        char c = s.top();
        s.pop();
        answer.push_back(c);
    }
    reverse(answer.begin(), answer.end());
    return answer;
}

string solution2(string number, int k) {
    string answer = number.substr(k);

    for (int i = k - 1; i >= 0; i--) {
        int j = 0;
        while (number[i] >= answer[j]) {
            swap(number[i], answer[j]);
            j++;
        }
    }

    return answer;
}

int main() {
    string number = "4177252841";
    int k = 4;

    cout << solution2(number, k) << endl;

    return 0;
}