#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main() {

    int number;
    cin >> number;

    vector<pair<int, int>> wire;

    for (int i = 0; i < number; i++) {
        pair<int, int> p;
        cin >> p.first >> p.second;
        wire.push_back(p);
    }

    sort(wire.begin(), wire.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.first < b.first;
    });

    vector<int> lis;
    for (int i = 0; i < number; i++) {
        int val = wire[i].second;
        if (lis.size() == 0) {
            lis.push_back(val);
        } else {
            if (lis.back() < val) {
                lis.push_back(val);
            } else if (lis.back() > val) {
                auto itr = lower_bound(lis.begin(), lis.end(), val);
                *itr = val;
            }
        }
    } 

    cout << number - lis.size() << endl;

    return 0;
}