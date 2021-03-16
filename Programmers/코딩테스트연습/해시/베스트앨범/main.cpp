#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

class Song {
    public: 
    int repeat = 0;
    int id = -1;

    Song(int _repeat, int _id) {
        repeat = _repeat;
        id = _id;
    }
};

class Genre {
    public:
    int totalRepeat = 0;
    vector<Song> songs;
};

/**
 * 노래는 고유 번호로 구분
 * 정렬: 많이 재생된 장르, 많이 재생된 노래, 고유 번호가 낮은 노래
 */
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, Genre> m;

    for (int i = 0; i < genres.size(); i++) {
        if (m.find(genres[i]) == m.end()) {
            m[genres[i]] = Genre();
        }

        Genre &genre = m[genres[i]];      
        genre.songs.push_back(Song(plays[i], i));
        genre.totalRepeat += plays[i];
    }

    vector<Genre> v;
    for (auto p : m) {
        v.push_back(p.second);
    }

    sort(v.begin(), v.end(), [](Genre a, Genre b) {
        return a.totalRepeat > b.totalRepeat;
    });

    for (Genre g : v) {
        sort(g.songs.begin(), g.songs.end(), [](Song a, Song b) {
            if (a.repeat == b.repeat) {
                return a.id < b.id;
            } else {
                return a.repeat > b.repeat;
            }
        });

        int count = 0;
        for (Song s : g.songs) {
            answer.push_back(s.id);
            count++;

            if (count == 2) break;
        }
    }

    return answer;
}

int main() {
    vector<string> genres = {
        "classic", "pop", "classic", "classic", "pop"
    };

    vector<int> plays = {
        500, 600, 150, 800, 2500
    };

    for (int i : solution(genres, plays)) {
        cout << i << endl;
    }

    return 0;
}