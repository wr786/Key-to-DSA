#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
int idx;
unordered_map<string, int> dict;
unordered_set<string> similars;
vector<string> vs;

void del_redundant(string tolookup) {
    int l = tolookup.length();
    for(int i=0; i<l; i++) {
        string comb = tolookup.substr(0, i) + tolookup.substr(min(l, i+1));
        if(dict[comb]) {
            similars.insert(comb);
        }
    }
}

void replace(string tolookup) {
    int l = tolookup.length();
    for(char c='a'; c<='z'; c++) {
        for(int i=0; i<l; i++) {
            string comb = tolookup.substr(0, i) + c + tolookup.substr(min(l, i+1));
            if(dict[comb]) {
                similars.insert(comb);
            }
        }
    }
}

void add(string tolookup) {
    int l = tolookup.length();
    for(char c='a'; c<='z'; c++) {
        for(int i=0; i<=l; i++) {
            string comb = tolookup.substr(0, i) + c + tolookup.substr(i);
            if(dict[comb]) {
                similars.insert(comb);
            }
        }
    }
}

bool cmp(const string a, const string b) {
    return dict[a] < dict[b];
}

void search(const string& tolookup) {
    cout << tolookup;
    if(dict[tolookup]) {
        cout << " is correct";
    } else {
        similars.clear();
        vs.clear();
        del_redundant(tolookup); 
        replace(tolookup); 
        add(tolookup);
        cout << ":";
        for(auto& item: similars) {
            vs.push_back(item);
        }
        sort(vs.begin(), vs.end(), cmp);
        for(auto& item: vs) {
            cout << " " << item;
        }
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    string tmp;
    while(cin >> tmp && tmp != "#") {
        dict[tmp] = ++idx;
    }
    while(cin >> tmp && tmp != "#") {
        search(tmp);
    }
    return 0;
}