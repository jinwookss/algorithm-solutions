#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(int N, int number) {
    if (N == number) return 1; // N과 number가 같은 경우

    vector<set<int>> cache(8);

    // 5, 55, 555, 5555, ... 입력
    string temp = "";
    for (int i = 0; i < 8; i++) {
        temp.append(to_string(N));
        cache[i].insert(atoi(temp.c_str()));
    }

    // N을 2~8번 사용하는 경우
    for (int i = 2; i <= 8; i++) {
        // cout << "use: " << i << endl;
        // 시작 인덱스
        for (int j = 1; j <= i / 2; j++) {
            for (int first : cache[j - 1]) {
                for (int second : cache[i - j - 1]) {
                    cache[i - 1].insert(first + second);
                    cache[i - 1].insert(first - second);
                    cache[i - 1].insert(second - first);
                    cache[i - 1].insert(first * second);
                    if (first > 0) 
                        cache[i - 1].insert(second / first);
                    if (second > 0) 
                        cache[i - 1].insert(first / second);
                }
            }
        }

        // for (int j : cache[i - 1]) {
        //     cout << j << ", ";
        // }
        // cout << endl;
        if (cache[i - 1].find(number) != cache[i - 1].end()) {
            return i;
        }
    }

    return -1;
}

int main() {
    // cout << solution(5, 12) << endl;
    // cout << solution(2, 11) << endl;
    cout << solution(5, 20) << endl;

    return 0;
}