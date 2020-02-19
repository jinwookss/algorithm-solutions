#include <iostream>

using namespace std;

int main() {

    string a, b;
    cin >> a >> b;

    int diff = 0;
    if (a.size() == b.size()) {
        for (int i=0; i<a.size(); i++) {
            if (a[i] != b[i]) {
                diff++;
            }
        }
    } else {
        int maxMatched = 0;
        for (int i=0; i<= b.size() - a.size(); i++) {
            int matched = 0;
            for (int j=0; j<a.size(); j++) {
                if (a[j] == b[i+j]) {
                    matched++;
                }
            }

            if (matched > maxMatched) {
                maxMatched = matched;
            }
        }

        diff = a.size() - maxMatched;
    }

    cout << diff << endl;

    return 0;
}