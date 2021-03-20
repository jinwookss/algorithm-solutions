#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

class Truck {
    public:
    int weight;
    int timeout;
    Truck(int _weight, int _timeout) {
        weight = _weight;
        timeout = _timeout;
    }
};

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int time = 1;

    int idx = 1;
    int totalWeight = 0;
    queue<Truck> bridge;

    bridge.push(Truck(truck_weights.front(), bridge_length));
    totalWeight += truck_weights.front();

    while (!bridge.empty()) {
        if (bridge.front().timeout == time) {
            totalWeight -= bridge.front().weight;
            // cout << "pop: " << bridge.front().weight << endl;
            bridge.pop();
        }

        if (idx < truck_weights.size() && totalWeight + truck_weights[idx] <= weight) {
            bridge.push(Truck(truck_weights[idx], time + bridge_length));
            totalWeight += truck_weights[idx];
            // cout << "push: " << truck_weights[idx] << "/" << time + bridge_length + 1 << endl;

            idx++;
        }

        // cout << "time: " << time << ", totalWeight: " << totalWeight << endl;

        time++;
    }

    return time;
}

int main() {
    int bridge_length = 100;
    int weight = 100;
    vector<int> truck_weight = {10,10,10,10,10,10,10,10,10,10};

    cout << solution(bridge_length, weight, truck_weight) << endl;

    return 0;
}