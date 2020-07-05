#include <iostream>

using namespace std;

int main() {
    
    int M;
    cin >> M;
    M = 1000 - M;

    int count = 0;
    int coins[] = {500, 100, 50, 10, 5, 1};

    for (int i=0; i<6; i++) {
        count += M / coins[i];
        M = M % coins[i];
    }
    
    cout << count << endl;

    return 0;
}