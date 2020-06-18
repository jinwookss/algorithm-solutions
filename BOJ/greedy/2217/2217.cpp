/**
 * N: 로프 개수 (1 ~ 100000)
 * w/k: k개의 로프를 병렬로 연결해 w의 물체를 드는 경우 각 로프에 걸리는 중량
 * 로프들을 이용하여 들어올릴 수 있는 물체의 최대 중량 출력
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int N;
    vector<int> ropes;

    cin >> N;
    for (int i=0; i<N; i++) {
        int w;
        cin >> w;
        ropes.push_back(w);
    }

    sort(ropes.begin(), ropes.end(),
         [](int w1, int w2) -> bool {
             return w1 < w2;
    });

    // for (auto w : ropes) {
    //     cout << w << endl;
    // }

    int count = 0;
    int maxWeight = 0;
    while (ropes.size() > 0) {
        count++;
        int weight = ropes.back() * count;
        ropes.pop_back();
        if (weight > maxWeight) {
            maxWeight = weight;
        }
    }

    cout << maxWeight << endl;

    return 0;
}