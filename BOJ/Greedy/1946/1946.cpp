#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> pii;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T, N;
    pii score;

    cin >> T;
    for (int t=0; t<T; t++) {
        cin >> N;
        pii appliers[N];
        for (int i=0; i<N; i++) {
            int a, b;
            cin >> a >> b;
            pii p(a, b);
            appliers[i] = p;
        }

        sort(appliers, appliers + N, [](pii a, pii b) {
            if (a.first == b.first) {
                return a.second > b.second;
            } else {
                return a.first > b.first;
            }
        });

        int cnt = 0;
        int idx = 0;
        while (idx < N) {
            pii p = appliers[idx];

            bool isFailed = false;
            for (int i=idx+1; i<N; i++) {
                pii p2 = appliers[i];

                if (p.second > p2.second) {
                    isFailed = true;
                    break;
                }
            }

            if (isFailed) {
                cnt++;
            }
            idx++;
        }
        cout << N - cnt << endl;
    }

    return 0;
}