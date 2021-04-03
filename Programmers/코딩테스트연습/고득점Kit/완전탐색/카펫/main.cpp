#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    int yellowLines = 1;
    while (true) {
        if (yellowLines == brown / 2 - yellow / yellowLines - 2) {       

            int h = yellowLines + 2;
            int w = (yellow + brown) / h;
            int remainder = (yellow + brown) % h;
            if (w >= h && remainder == 0) {
                answer.push_back(w);
                answer.push_back(h);
                break;
            }
        }
        yellowLines++;
    }
    return answer;
}

int main() {
    int brown = 16;
    int yellow = 9;

    // ooooo
    // oxxxo
    // oxxxo
    // oxxxo
    // ooooo

    for (int i : solution(brown, yellow)) {
        cout << i << endl;
    }

    return 0;
}