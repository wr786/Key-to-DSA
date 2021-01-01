#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
unordered_map<string, bool> vis;
unordered_map<string, vector<int>> dict;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    for(int i=1; i<=n; i++) {
        int m; cin >> m;
        vis.clear();
        while(m--) {
            string word; cin >> word;
            if(!vis[word]) {    // 去重
                dict[word].push_back(i);
                vis[word] = true;
            }
        }
    }
    cin >> n;
    while(n--) {
        string lookup; cin >> lookup;
        if(dict.find(lookup) != dict.end()) {
            int l = dict[lookup].size();
            for(int i=0; i<l; i++) {
                if(i) cout << " ";
                cout << dict[lookup][i];
            }
        } else {
            cout << "NOT FOUND";
        }
        cout << "\n";
    }
    return 0;
}