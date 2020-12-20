#include <iostream>

using namespace std;

int solution(int N) {
    bool isCounting = false;
    int currentCount = 0;
    int maxCount = 0;

    while (N > 0) {
        int remained = N % 2;
        N /= 2;
        if (remained == 1) {
            isCounting = !isCounting;
            if (!isCounting) {
                if (currentCount > maxCount) 
                    maxCount = currentCount;
                currentCount = 0;
                isCounting = true;
            }
        } else {
            if (isCounting) 
                currentCount++;
        }
    }

    return maxCount;
}

int main() {    
    // 1041
    // 520 .. 1
    // 260 .. 0
    // 130 .. 0
    // 65 .. 0
    // 32 .. 1
    // 16 .. 0
    // 8 .. 0
    // 4 .. 0
    // 2 .. 0
    // 1 .. 0
    // 0 .. 1
    cout << solution(0b1111) << endl; // 0
    cout << solution(0b110000) << endl; // 0
    cout << solution(0b000011) << endl; // 0
    cout << solution(0b100001) << endl; // 4
    cout << solution(0b0011100) << endl; // 0
    cout << solution(0b00110001100) << endl; // 3
    cout << solution(0b0010010001100) << endl; // 3

    return 0;
}