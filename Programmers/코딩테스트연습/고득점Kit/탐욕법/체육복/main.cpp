#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {

    vector<int> students(n + 2, 1);

    students.front() = 0;
    students.back() = 0;

    for (int i : lost) {
        students[i]--;
    }

    for (int i : reserve) {
        students[i]++;
    }

    for (int i : students) {
        cout << i << " ";
    }
    cout << endl;

    for (int i = 1; i <= n; i++) {
        if (students[i] == 0) {
            if (students[i - 1] == 2) {
                students[i - 1]--;
                students[i]++;
            } else if (students[i + 1] == 2) {
                students[i + 1]--;
                students[i]++;
            }
        }
    }

    int answer = 0;
    for (int i : students) {
        if (i > 0) answer++;
        cout << i << " ";
    }
    cout << endl;

    return answer;
}

int main() {
    int n = 5;
    vector<int> lost = {2, 4};
    vector<int> reserve = {1, 3, 5};

    cout << solution(n, lost, reserve) << endl;

    return 0;
}