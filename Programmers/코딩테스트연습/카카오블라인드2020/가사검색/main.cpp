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
struct Trie {
    int count;  // 하위 단어 개수
    Trie* next[NUM_OF_ALPHABETS];

    Trie() : count(0) {
        for (int i = 0; i < NUM_OF_ALPHABETS; i++) {
            next[i] = nullptr;
        }
    }
    ~Trie() {
        for (int i = 0; i < NUM_OF_ALPHABETS; i++) {
            if (next[i]) delete next[i];
        }
    }
    void insert(const char* word) {
        if (*word == '\0') return;
        int idx = (*word) - 'a';
        if (!next[idx]) {
            next[idx] = new Trie();
        }
        next[idx]->insert(++word);
        count++;
    }
    int find(const char* query) {
        int idx = *query - 'a';
        if (*query != '?') {
            if (next[idx]) return next[idx]->find(++query);
            else return 0;
        } else {
            return count;
        }
    }
};

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;

    // 단어 길이별로 trie 생성
    Trie* trie[10001];
    Trie* reverseTrie[10001];
    for (int i = 0; i < 10001; i++) {
        trie[i] = nullptr;
        reverseTrie[i] = nullptr;
    }

    for (string &word : words) {
        int size = word.size();

        if (!trie[size]) trie[size] = new Trie();
        trie[size]->insert(word.c_str());

        reverse(word.begin(), word.end());
        
        if (!reverseTrie[size]) reverseTrie[size] = new Trie();
        reverseTrie[size]->insert(word.c_str());
    }

    // trie에서 query 검색
    for (string &query : queries) {
        int size = query.size();
        if (query.front() == '?' && query.back() == '?') {
            if (trie[size]) answer.push_back(trie[size]->count);
            else answer.push_back(0);
        } else if (query.front() == '?') {
            reverse(query.begin(), query.end());
            if (!reverseTrie[size]) reverseTrie[size] = new Trie();
            answer.push_back(reverseTrie[size]->find(query.c_str()));
        } else if (query.back() == '?') {
            if (!trie[size]) trie[size] = new Trie();
            answer.push_back(trie[size]->find(query.c_str()));
        }
    }

    return answer;
}

// queries 문자열을 words의 문자열과 문자 하나하나 비교
vector<int> solution2(vector<string> words, vector<string> queries) {
    vector<int> answer;
    for (string &query : queries) {
        int matched = 0;
        for (string &word : words) {
            if (query.size() != word.size()) continue;
            bool isMatched = true;
            for (int i = 0; i < word.size(); i++) {
                if (query[i] != '?' && query[i] != word[i]) {
                    isMatched = false;
                    break;
                }
            }
            if (isMatched) matched++;
        }
        answer.push_back(matched);
    }
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

    for (int &i : solution(words, queries)) {
        cout << i << endl;
    }
 
    return 0;
}