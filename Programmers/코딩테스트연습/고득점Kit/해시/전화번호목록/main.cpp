#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Node {
    public:
    int cur;
    vector<Node*> next;
    bool isEndpoint = false;

    Node(int _cur) {
        cur = _cur;
        next.assign(10, nullptr);
    }
};

bool solution(vector<string> phone_book) {
    
    sort(phone_book.begin(), phone_book.end());

    Node head = Node(-1);
    
    for (string s : phone_book) {
        Node *cur = &head;

        for (char c : s) {
            int i = atoi(&c);

            if (cur->next[i] != nullptr) {
                cur = cur->next[i];
                cout << cur->cur << endl;
                
                if (cur->isEndpoint) {
                    cout << "prefix" << endl;
                    return false;
                }
            
            } else {
                cur->next[i] = new Node(i);
                cur = cur->next[i];
                cout << "create " << cur->cur << endl;
            }
        }
        cur->isEndpoint = true;
        cout << "set endpoint " << cur->cur << endl;
    }
    return true;
}

int main() {
    vector<string> phone_book1 = {
        "119", "97674223", "1195524421"
    };

    vector<string> phone_book2 = {
        "123", "456", "789", "4567"
    };

    vector<string> phone_book3 = {
        "123456", "123"
    };

    cout << solution(phone_book1) << endl;
    cout << solution(phone_book2) << endl;
    cout << solution(phone_book3) << endl;

    return 0;
}