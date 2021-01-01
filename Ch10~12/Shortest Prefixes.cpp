#include <iostream>
#include <algorithm>
#include <string>
#include <cassert>
#include <vector>
using namespace std; 

vector<string> words;

/* Trie Tree */
struct Node {
    Node* ch[26]{};
    int cnt = 1;
};

inline void insert(Node* root, const string& str) {
    int l = str.length();
    Node* cur = root;
    for(int i=0; i<l; i++) {
        if(cur->ch[str[i] - 'a'] == nullptr) {
            cur->ch[str[i] - 'a'] = new Node();
        } else {
            cur->ch[str[i] - 'a']->cnt += 1;
        }
        cur = cur->ch[str[i] - 'a'];
    }
}

inline string find_prefix(Node* root, const string& str) {
    int l = str.length();
    string ret;
    Node* cur = root;
    for(int i=0; i<l; i++) {
        assert(cur->ch[str[i] - 'a'] != nullptr);
        ret += str[i];
        if(cur->ch[str[i] - 'a']->cnt <= 1) {
            return ret;
        }
        cur = cur->ch[str[i] - 'a'];
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    string tmp;
    Node* root = new Node();
    while(cin >> tmp) {
        words.push_back(tmp);
        insert(root, tmp);
    }
    for(auto& s: words) {
        cout << s << " ";
        cout << find_prefix(root, s) << endl;
    }
    return 0;
}