#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

vector<int> solution(vector<int> numbers) {

    set<int, less<int>> s;

    for (int i = 0; i < numbers.size(); i++) {
        for (int j = i + 1; j < numbers.size(); j++) {
            s.insert(numbers[i] + numbers[j]);
        }
    }

    vector<int> answer(s.size());
    copy(s.begin(), s.end(), answer.begin());

    return answer;
}

int main() {
    vector<int> numbers = {2, 1, 3, 4, 1};
    for (int i : solution(numbers)) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}