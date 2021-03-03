#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    if (participant.size() == 1) return participant.front();

    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    int i = 0;
    while (i < participant.size() && i < completion.size()) {
        if (participant[i] != completion[i]) {
            return participant[i];
        }
        i++;
    }

    return participant.back();
}

int main() {
    vector<string> participant = {
        "leo", "kiki", "eden"
    };
    vector<string> completion = {
        "eden", "kiki"
    };

    cout << solution(participant, completion) << endl;

    return 0;
}