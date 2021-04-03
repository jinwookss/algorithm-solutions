#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end(), less<int>());
    int minIdx = 0;
    int maxIdx = people.size() - 1;
    while (minIdx <= maxIdx) {
        if (people[minIdx] + people[maxIdx] <= limit) {
            minIdx++;
            maxIdx--;
        } else {
            maxIdx--;
        }
        answer++;
    }
    return answer;
}

int main() {
    vector<int> people = {70, 50, 80, 50};
    // vector<int> people = {20, 40, 30, 60, 50}; // 2 3 4 5 6   
    int limit = 100; // 50 50 70 80 

    cout << solution(people, limit) << endl;

    return 0;
}