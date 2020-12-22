#include <iostream>

using namespace std;

// 현위치 X에서 Y 보다 같거나 큰 위치로 이동, D칸씩 이동 가능
// Y에 도달하기 위한 최소 점프 횟수
int solution(int X, int Y, int D) {
    int offset = (Y - X) % D == 0 ? 0 : 1;
    return (Y - X) / D + offset;
}

int main() {
    cout << solution(1, 3, 1) << endl;

    return 0;
}