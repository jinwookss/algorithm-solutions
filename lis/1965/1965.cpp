#include <iostream>
#include <vector>

using namespace std;

int main() {

    int n;
    cin >> n;

    vector<int> lis;
    int val;
    
    // First element
    cin >> val;
    lis.push_back(val);
    // Remained elements
    for (int i = 0; i < n - 1; i++) {
        cin >> val;
        if (val < lis.back()) {
            auto it = lower_bound(lis.begin(), lis.end(), val);
            *it = val;
        } else if (val > lis.back()) {
            lis.push_back(val);
        }
    }

    cout << lis.size() << endl;

    return 0;
}