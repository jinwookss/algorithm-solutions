#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> testers = {
    {1, 2, 3, 4, 5},
    {2, 1, 2, 3, 2, 4, 2, 5},
    {3, 3, 1, 1, 2, 2, 4, 4, 5, 5}};

vector<int> solution(vector<int> answers) {
    vector<int> numberOfCorrect(3, 0);

    for (int i = 0; i < answers.size(); i++) {
        int answer = answers[i];

        for (int j = 0; j < 3; j++) {
            if (answer == testers[j][i % testers[j].size()]) {
                numberOfCorrect[j]++;
            }
        }
    }

    int maxCorrect = *max_element(numberOfCorrect.begin(), numberOfCorrect.end());
    
    vector<int> answer;
    for (int i = 0; i < 3; i++) {
        if (numberOfCorrect[i] == maxCorrect) answer.push_back(i + 1);
    }
    return answer;
}

int main() {
    // vector<int> answers = {1, 2, 3, 4, 5};
    vector<int> answers = {1, 3, 2, 4, 2};

    for (int i : solution(answers)) {
        cout << i << endl;
    }

    return 0;
}