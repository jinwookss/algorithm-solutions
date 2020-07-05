/**
 * N: 회의 수 (1 ~ 100000)
 * 최대 사용할 수 있는 회의 수 출력
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Meeting {
    public:
    Meeting() {

    }
    ~Meeting() {}

    int start;
    int end;
};

int main() {

    int N;
    vector<Meeting> meetings;

    cin >> N;
    for (int i=0; i<N; i++) {
        Meeting meeting;
        cin >> meeting.start >> meeting.end;
        meetings.push_back(meeting);
    }

    // 종료 시간 기준으로 정렬
    sort(meetings.begin(), meetings.end(), [](Meeting a, Meeting b) -> bool {
        if (a.end == b.end) {
            return a.start > b.start;
        } else {
            return a.end > b.end;
        }
    });

    int count = 0;
    int lastEndTime = 0;
    while (meetings.size() > 0) {
        auto m = meetings.back();
        if (m.start >= lastEndTime) {
            count++;
            lastEndTime = m.end;
        }
        meetings.pop_back();
    }

    cout << count << endl;

    return 0;
}