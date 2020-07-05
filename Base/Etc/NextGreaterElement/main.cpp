#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void printNextGreaterElement(vector<int> &v) {
    stack<int> s;

    for (int i = 0; i < v.size(); i++) {
        while (!s.empty() && s.top() < v[i]) {
            cout << v[i] << " ";
            s.pop();
        }

        s.push(v[i]);
    }

    while (!s.empty()) {
        cout << "-1 ";
        s.pop();
    }
    cout << endl;
}

int main() {
    vector<int> v = {10, 20, 30, 50, 10, 70, 30};
    // Output: 20, 30, 50, 70, 70, -1, -1
    printNextGreaterElement(v);

    return 0;
}