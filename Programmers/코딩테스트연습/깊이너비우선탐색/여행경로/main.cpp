#include <iostream>
#include <functional>
#include <string>
#include <vector>

using namespace std;

bool findPath(int count, string start, vector<vector<string>> &tickets, vector<bool> &visited, vector<string> &path) {
   if (count == tickets.size()) {  
       path.push_back(start);
       return true;
   }

   for (int i = 0; i < tickets.size(); i++) {
       if (visited[i]) continue;
       
       string from = tickets[i][0];
       string to = tickets[i][1];

       if (start == from) {
           visited[i] = true;
           path.push_back(start);
           if (findPath(count + 1, to, tickets, visited, path)) {
               return true;
           }
           visited[i] = false;
           path.pop_back();   
       }
   }
   return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    // 사전순으로 정렬
    sort(tickets.begin(), tickets.end());

    string start = "ICN";
    vector<string> answer;
    vector<bool> visited(tickets.size(), false);

    findPath(0, start, tickets, visited, answer);
    return answer;
}

int main() {
    // vector<vector<string>> tickets = {{"ICN", "JFK"}, {"ICN", "IAD"}, {"JFK", "ICN"}};
    vector<vector<string>> tickets = {{"ICN", "SFO"}, {"ICN", "ATL"}, {"SFO", "ATL"}, {"ATL", "ICN"}, {"ATL", "SFO"}};
    for (string dst : solution(tickets)) {
        cout << dst << endl;
    }

    return 0;
}