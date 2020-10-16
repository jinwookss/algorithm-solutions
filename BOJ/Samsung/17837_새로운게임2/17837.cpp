#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

enum {
    WHITE = 0,
    RED,
    BLUE,
};

// 이동 방향. 인덱스 1~4
const int dy[] = {0, 0, 0, -1, 1};
const int dx[] = {0, 1, -1, 0, 0};

class Item {
   public:
    int id;
    int y, x, d;
};

int N;  // [4, 12]
int K;  // [4, 10]
// map[행][열] = pair(칸의 색, 쌓여있는 체스말들의 번호 벡터)
vector<vector<pair<int, vector<int>>>> map(13, vector<pair<int, vector<int>>>(13));
vector<Item> items;  // item[체스말 번호] = 이동 방향

void printMap() {
    for (int y = 1; y <= N; y++) {
        for (int x = 1; x <= N; x++) {
            cout << map[y][x].first << "(";
            for (int i = 0; i < map[y][x].second.size(); i++) {
                cout << map[y][x].second[i];
            }
            cout << ") ";
        }
        cout << endl;
    }
    cout << endl;
}

bool move(Item &item) {
    int id = item.id;
    int ny = item.y + dy[item.d];
    int nx = item.x + dx[item.d];
    // cout << "move " << id << ": (" << item.y << ", " << item.x << ") -> (" << ny << ", " << nx << ")" << endl;
    int color = map[ny][nx].first;
    // 체스판을 벗어나는 경우에는 파란색과 같은 경우
    if (ny < 1 || ny > N || nx < 1 || nx > N) {
        color = BLUE;
    }

    if (color == WHITE) {
        vector<int> &src = map[item.y][item.x].second;
        vector<int> &dst = map[ny][nx].second;

        bool isFound = false;
        vector<int>::iterator itr = src.begin();
        while (itr != src.end()) {
            if (*itr == id) {
                isFound = true;
            }

            if (isFound) {
                dst.push_back(*itr);
                items[*itr].y = ny;
                items[*itr].x = nx;
                itr = src.erase(itr);
            } else {
                itr++;
            }
        }
        if (dst.size() >= 4) return true;
    } else if (color == RED) {
        vector<int> &src = map[item.y][item.x].second;
        vector<int> &dst = map[ny][nx].second;

        bool isFound = false;
        vector<int>::iterator itr = src.begin();
        while (itr != src.end()) {
            if (*itr == id) {
                isFound = true;
                reverse(itr, src.end());  // 순서 반대로 바꾸기
            }

            if (isFound) {
                dst.push_back(*itr);
                items[*itr].y = ny;
                items[*itr].x = nx;
                itr = src.erase(itr);
            } else {
                itr++;
            }
        }
        if (dst.size() >= 4) return true;
    } else if (color == BLUE) {
        // 방향 반대로 변경
        switch (item.d) {
            case 1:
            case 3:
                item.d++;
                break;
            case 2:
            case 4:
                item.d--;
                break;
        }
        // 이동 위치 재계산
        ny = item.y + dy[item.d];
        nx = item.x + dx[item.d];
        // 방향을 반대로 바꾼 후에 이동하려는 칸이 파란색인 경우에는 이동하지 않고 가만히
        if (ny >= 1 && ny <= N && nx >= 1 && nx <= N && map[ny][nx].first != BLUE) {
            return move(item);
        }
    }
    return false;
}

int play() {
    int turn = 0;
    int isOver = false;
    while (true) {
        for (int i = 0; i < K; i++) {
            Item &item = items[i];
            if (move(item)) {
                isOver = true;
                break;
            }
        }
        turn++;
        // printMap();
        if (turn > 1000) return -1;
        else if (isOver) return turn;
    }
}

int main() {
    ifstream cin("input.txt");
    if (cin.fail()) return -1;

    cin >> N >> K;
    for (int y = 1; y <= N; y++) {
        for (int x = 1; x <= N; x++) {
            cin >> map[y][x].first;
        }
    }

    for (int i = 0; i < K; i++) {
        int y, x, d;
        cin >> y >> x >> d;
        map[y][x].second.push_back(i);

        Item item;
        item.id = i;
        item.y = y;
        item.x = x;
        item.d = d;
        items.push_back(item);
    }

    // 말이 4개 이상 쌓여 게임이 종료되는 턴의 번호
    // 1000보다 크거나 게임이 종료되지 않는 경우에는 -1 출력
    cout << play() << endl;

    return 0;
}