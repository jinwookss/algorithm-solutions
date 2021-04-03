#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;

    int count = 0;
    int maxLeft = 0;
    for (int i = 0; i < progresses.size(); i++) {

        int progressLeft = 100 - progresses[i];
        int dayLeft = progressLeft / speeds[i];
        if (progressLeft % speeds[i] != 0) dayLeft++;

        if (maxLeft == 0) {
            count++;
            maxLeft = dayLeft;
        } else if (maxLeft < dayLeft) {
            answer.push_back(count);
            count = 1;
            maxLeft = dayLeft;
        } else {
            count++;
        }
    }

    if (count != 0) answer.push_back(count);

    return answer;
}

int main() {
    vector<int> progresses = {
        4, 3, 2, 1, 2, 3
    };
    vector<int> speeds = {
        1, 1, 1, 1, 1, 1
    };

    for (int i : solution(progresses, speeds)) {
        cout << i << endl;
    }

    return 0;
}