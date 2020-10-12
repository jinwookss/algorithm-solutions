#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

enum {
    EMPTY = 0,
    HOME = 1,
    CHICKEN = 2,  
};

int N, M;
vector<int> chickens;
vector<int> homes;
vector<int> selectedChickens;
int minCityDistance = INT32_MAX;

int getDistance(int a, int b) {
    return abs((a / (N + 1)) - (b / (N + 1))) + abs((a % (N + 1)) - (b % (N + 1)));
}

int getCityChickenDistance() {
    int cityDistance = 0;
    for (int i = 0; i < homes.size(); i++) {
        int distance = INT32_MAX;
        for (int j = 0; j < selectedChickens.size(); j++) {
            distance = min(distance, getDistance(homes[i], selectedChickens[j]));
        }
        cityDistance += distance;
    }
    return cityDistance;
}

void selectChickens(int count, int max, int idx) {
    if (count == max) {
        minCityDistance = min(minCityDistance, getCityChickenDistance());
        return;
    }

    for (int i = idx; i < chickens.size(); i++) {
        selectedChickens.push_back(chickens[i]);
        selectChickens(count + 1, max, i + 1);
        selectedChickens.pop_back();
    }
}

int main() {
    ifstream cin("input.txt");
    if (cin.fail()) return -1;

    cin >> N >> M;
    for (int y = 1; y <= N; y++) {
        for (int x = 1; x <= N; x++) {
            int i;
            cin >> i;
            if (i == CHICKEN) {
                chickens.push_back(y * (N + 1) + x);
            } else if (i == HOME) {
                homes.push_back(y * (N + 1) + x);
            }
        }
    }
    
    selectChickens(0, M, 0);
    cout << minCityDistance << endl;

    return 0;
}