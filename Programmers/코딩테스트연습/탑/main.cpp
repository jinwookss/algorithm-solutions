/**
 * 프로그래머스
 * 탑
 * https://programmers.co.kr/learn/courses/30/lessons/42588
 */
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> heights) {
    vector<int> answer(heights.size(), 0);
    // 정방향으로 검색할 수 있도록 입력 역순으로 정렬
    // 1 2 3 4<-5 를 5->4 3 2 1로 변경
    reverse(heights.begin(), heights.end());

    // 현재 탑 오른쪽 탑들을 검사하면서 현재 신호보다 강한 신호의 탑을 찾으면 해당 탑의 위치를 입력
    for (int i = 0; i < heights.size() - 1; i++) {
        int signal = heights[i];
        for (int j = i + 1; j < heights.size(); j++) {
            if (heights[j] > signal) {
                // 입력을 역순으로 정렬했기 때문에 실제 탑의 번호를 5 4 3 2 1 처럼 거꾸로 카운팅
                answer[i] = heights.size() - j;
                break;
            }
        }
    }
    // 정답을 출력하기 위해 다시 역순으로 정렬
    reverse(answer.begin(), answer.end());

    return answer;
}

int main() {
    ifstream cin("input.txt");
    if (cin.fail()) return -1;

    int n;
    vector<int> heights;

    cin >> n;
    heights.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    for (int i : solution(heights)) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}