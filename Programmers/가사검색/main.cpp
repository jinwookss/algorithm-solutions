/**
 * 프로그래머스
 * 2020 카카오 블라인드 채용 - 가사 검색
 * https://programmers.co.kr/learn/courses/30/lessons/60060
 */
#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int NUM_OF_ALPHABETS = 26;

class Node {
   private:
    Node *children[NUM_OF_ALPHABETS];

   public:
    void insert() {

    }
    int find() {

    }
};

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;

    // Make a tri 
    
    // Find a query word in the tri
    // answer.push_back();

    return answer;
}

int main() {
    ifstream cin("input.txt");
    if (cin.fail()) return -1;

    vector<string> words, queries;
    int M, N;
    cin >> M >> N;
    words.resize(M);
    queries.resize(N);
    for (int i = 0; i < M; i++) {
        cin >> words[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> queries[i];
    }

    for (int i : solution(words, queries)) {
        cout << i << endl;
    }

    return 0;
}