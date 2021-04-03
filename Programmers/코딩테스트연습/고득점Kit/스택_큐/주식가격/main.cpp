#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), -1);
    stack<int> s;

    for (int i = 0; i < prices.size(); i++) {

        while (!s.empty() && prices[s.top()] > prices[i]) {
            int idx = s.top();
            s.pop();

            int in = idx + 1;
            int out = i + 1;
            
            answer[idx] = out - in;
        }

        s.push(i);
    }

    while (!s.empty()) {
        int idx = s.top();
        s.pop();

        int in = idx + 1;
        int out = prices.size();
        
        answer[idx] = out - in;
    }

    
    return answer;
}

int main() {
    vector<int> prices = {
        1, 2, 3, 2, 3
    };

    for (int i : solution(prices)) {
        cout << i << endl;
    }

    return 0;
}