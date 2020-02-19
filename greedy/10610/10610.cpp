#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    string N;
    stringstream ss;
    vector<int> numbers;

    cin >> N;

    for (int i=0; i<N.length(); i++) {
        ss << N.at(i);
        int v;
        ss >> v;
        numbers.push_back(v);
        ss.clear();
    }

    sort(numbers.begin(), numbers.end(), 
        [](int a, int b) {
            return a > b;
    });

    if (numbers.back() != 0) {
        cout << "-1" << endl;
    } else {
        int sum = 0;
        string result = "";
        string tmp;
        for (int i : numbers) {
            sum += i;
            ss << i;
            ss >> tmp;
            result.append(tmp);
            ss.clear();
        }
        
        if (sum % 3 == 0) {
            cout << result << endl;
        } else {
            cout << "-1" << endl;
        }
    }

    return 0;
}