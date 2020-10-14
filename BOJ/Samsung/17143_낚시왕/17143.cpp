#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

class Shark {
   public:
    int r = 0, c = 0;
    int speed = 0;
    int dir = 0;
    int size = 0;
};

// 이동방향 [1, 4] 위, 아래, 오, 왼
const int dr[] = {0, -1, 1, 0, 0};
const int dc[] = {0, 0, 0, 1, -1};

int main() {
    ifstream cin("input.txt");
    if (cin.fail()) return -1;

    int R, C, M;
    cin >> R >> C >> M;

    // 격자판 초기화
    vector<vector<int>> map(R + 1, vector<int>(C + 1, 0));
    vector<Shark> sharks(M + 1);

    // 상어 정보 입력
    for (int i = 1; i <= M; i++) {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        map[r][c] = i;
        sharks[i].r = r;
        sharks[i].c = c;
        sharks[i].dir = d;
        sharks[i].size = z;

        if (sharks[i].dir == 1 || sharks[i].dir == 2) {
            if (R == 1) sharks[i].speed = 0;
            else sharks[i].speed = s % ((R - 1) * 2);
        } else {
            if (C == 1) sharks[i].speed = 0;
            else sharks[i].speed = s % ((C - 1) * 2);
        }
    }

    int fisher = 0;     // 낚시왕 위치
    int totalSize = 0;  // 잡은 상어 수

    while (fisher < C) {
        // 오른쪽으로 이동
        fisher++;
        // 현재 열에서 상어 잡기
        for (int y = 1; y <= R; y++) {
            int sharkIdx = map[y][fisher];
            if (sharkIdx != 0) {
                map[y][fisher] = 0;  // 격자판에서 상어 삭제
                totalSize += sharks[sharkIdx].size;
                sharks[sharkIdx].speed = -1;
                break;
            }
        }
        // 상어 이동
        for (int i = 1; i <= M; i++) {
            Shark &shark = sharks[i];
            if (shark.speed <= 0) continue;  // 잡힌 상어, 속도 0인 상어

            int nr = shark.r;
            int nc = shark.c;
            for (int s = 0; s < shark.speed; s++) {
                nr += dr[shark.dir];
                nc += dc[shark.dir];
                // 이동 위치가 경계를 넘으면 방향 변경
                if (nr < 1 || nr > R || nc < 1 || nc > C) {
                    switch (shark.dir) {
                        case 1:
                            shark.dir = 2;
                            break;
                        case 2:
                            shark.dir = 1;
                            break;
                        case 3:
                            shark.dir = 4;
                            break;
                        case 4:
                        default:
                            shark.dir = 3;
                            break;
                    }
                    nr += 2 * dr[shark.dir];
                    nc += 2 * dc[shark.dir];
                }
            }
            map[shark.r][shark.c] = 0;
            shark.r = nr;
            shark.c = nc;
        }

        // 같은 칸에 있는 상어끼리 잡아먹기
        for (int s = 1; s <= M; s++) {
            if (sharks[s].speed == -1) continue;
            int &newPos = map[sharks[s].r][sharks[s].c];
            if (newPos != 0) {
                if (sharks[newPos].size > sharks[s].size) {
                    sharks[s].speed = -1;
                } else {
                    sharks[newPos].speed = -1;
                    newPos = s;
                }
            } else {
                newPos = s;
            }
        }
    }
    cout << totalSize << endl;

    return 0;
}