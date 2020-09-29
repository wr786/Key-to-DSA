#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
vector<string> dict;
unordered_map<string, bool> inDict;

bool is_similar(string word, string lookup, int chances) {
    int l1 = word.length(), l2 = lookup.length();
    if(chances < abs(l1 - l2)) return false;    // prune
    int i1 = 0, i2 = 0;
    while(i1 < l1 && i2 < l2) {
        if(word[i1] != lookup[i2]) {
            if(chances <= 0) return false;
            // rm
            if(is_similar(word.substr(i1+1), lookup.substr(i2), chances-1)) return true;
            // mv
            if(is_similar(word.substr(i1+1), lookup.substr(i2+1), chances-1)) return true;
            // add
            if(is_similar(word.substr(i1), lookup.substr(i2+1), chances-1)) return true;
            return false;
        }
        i1 ++;
        i2 ++;
    }
    return (i1 == l1 && i2 == l2) || (chances && ((i1 == l1 && l2 - i2 <= chances) || (i2 == l2 && l1 - i1 <= chances)));
}

int main() {
    string tmp;
    while (cin >> tmp) {
        if(tmp == "#") {
            break;
        } else {
            dict.push_back(tmp);
            inDict[tmp] = true;
        }
    }
    while (cin >> tmp) {
        if(tmp == "#") {
            break;
        } else {
            if(inDict[tmp]) {
                cout << tmp << " is correct\n";
            } else {
                cout << tmp << ":";
                for(auto& word: dict) {
                    if(is_similar(word, tmp, 1)) {
                        cout << " " << word;
                    }
                }
                cout << '\n';
            }
        }
    }
}