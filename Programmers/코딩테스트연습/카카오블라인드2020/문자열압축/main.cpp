/**
 * 프로그래머스
 * 2020 카카오 블라인드 채용 - 문자열 압축
 * https://programmers.co.kr/learn/courses/30/lessons/60057
 */
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

void feed(string &compare1, string &compare2, int &count, string &output) {
    if (compare1 == compare2) {
        count++;
    } else {
        if (count > 1) output.append(to_string(count));
        output.append(compare1);

        if (compare1.size() > compare2.size()) {
            output.append(compare2);
        } else {
            compare1 = compare2;
            count = 1;
        }
    }
}

int solution(string s) {
    
    int answer = s.size();
    int size = s.size();

    // 압축 단위가 절반이 넘어가면 압축하지 않는 것과 동일
    for (int w = 1; w <= size / 2; w++) {
        // 변수 초기화
        string compare1 = ""; // 비교 기준
        string compare2 = ""; // 비교 대상 
        int count = 1; // 반복 횟수
        string output = ""; // 압축 결과
        
        int pos = 0;
        compare1 = s.substr(pos, w);
        for (pos = w; pos <= size - w; pos += w) {
            compare2 = s.substr(pos, w);
            feed(compare1, compare2, count, output);
        }
        int remained = size % w;
        compare2 = s.substr(pos, remained);
        feed(compare1, compare2, count, output);

        answer = min(answer, (int) output.size());
        // cout << "output = " << output << endl;
    }

    return answer;
}

int main() {
    ifstream cin("input.txt");
    if (cin.fail()) return -1;

    string s;  // 1 <= s <= 1000
    cin >> s;

    cout << solution(s) << endl;

    return 0;
}