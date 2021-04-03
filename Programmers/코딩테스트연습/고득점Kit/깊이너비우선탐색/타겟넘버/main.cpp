#include <iostream>
#include <string>
#include <vector>

using namespace std;

int sign[] = {1, -1};

int findTargetSolution(vector<int> &numbers, int current, int target) {
    if (numbers.empty()) {
        if (current == target) return 1;
        else return 0;
    }

    int ret = 0;
    for (int i = 0; i < 2; i++) {
        int number = numbers.back();
        numbers.pop_back();

        int d = number * sign[i];
        ret += findTargetSolution(numbers, current + d, target);

        numbers.push_back(number);
    }
    return ret;
}

int solution(vector<int> numbers, int target) {
    return findTargetSolution(numbers, 0, target);
}

int main() {
    vector<int> numbers = {1, 1, 1, 1, 1};
    cout << solution(numbers, 3) << endl;
    return 0;
}