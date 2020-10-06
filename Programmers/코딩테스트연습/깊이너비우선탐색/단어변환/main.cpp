#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int INF = INT32_MAX;

bool isTransformable(string &src, string &dst) {
    if (src == dst) return false;

    int count = 0;
    for (int i = 0; i < src.size(); i++) {
        if (src[i] != dst[i]) count++;
        if (count > 1) return false;
    }
    return true;
}

int transformWord(string begin, string &target, vector<string> &words, vector<bool> &visited) {
    // cout << begin << endl;
    if (begin == target) {
        int visitedCount = 0;
        for (bool b : visited) {
            if (b) visitedCount++;
        }
        return visitedCount;
    }

    int ret = INF;
    for (int i = 0; i < words.size(); i++) {
        string word = words[i];
        if (!isTransformable(begin, word) || visited[i]) continue;

        visited[i] = true;
        ret = min(ret, transformWord(word, target, words, visited));
        visited[i] = false;
    }

    return ret;
}

int solution(string begin, string target, vector<string> words) {
    // target이 words 안에 없는 경우
    bool isExist = false;
    for (string word : words) {
        if (word == target) {
            isExist = true;
            break;
        }
    }
    if (!isExist) return 0;

    vector<bool> visited(words.size(), false);
    return transformWord(begin, target, words, visited);
}

int main() {
    string begin = "hit";
    string target = "cog";
    vector<string> words = {"hot", "dot", "dog", "lot", "log", "cog"};
    // vector<string> words = {"hot", "dot", "dog", "lot", "log"};

    cout << solution(begin, target, words) << endl;

    return 0;
}