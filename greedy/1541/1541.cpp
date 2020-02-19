#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {

    string s;
    cin >> s;

    stringstream ss;

    int result = 0;
    bool minus = false;
    for (char c : s) {
        if (c == '-' || c == '+') {
            int i;
            ss >> i;
            ss.clear();
            if (minus) {
                result -= i;
            } else {
                result += i;
            }

            if (c == '-') {
                minus = true;
            }
        } else {
            ss << c;
        }
    }
    int i;
    ss >> i;
    ss.clear();
    if (minus) {
        result -= i;
    } else {
        result += i;
    }

    cout << result << endl;

    return 0;
}