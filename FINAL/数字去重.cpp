#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);cin.tie(0);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        unordered_map<int, bool> vis;
        for(int i=1; i<=n; i++) {
            int tmp; cin >> tmp;
            if(!vis[tmp]) {
                vis[tmp] = true;
                cout << tmp;
                if(i == n) cout << endl;
                else cout << " ";
            }
        }
    }
}