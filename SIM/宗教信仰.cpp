// http://noi.openjudge.cn/ch0403/1526/
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;
int n, m;
int f[50001];

int getf(int x) {
    if(x == f[x]) return f[x];
    return f[x] = getf(f[x]);
}

inline void merge(int a, int b) {
    f[getf(a)] = getf(b);
}

int main() {
    int t = 0;
    while(cin >> n >> m && n && m) {
        for(int i=1; i<=n; i++) f[i] = i;
        int cnt = 0, a, b;
        while(m--) {
            cin >> a >> b;
            if(getf(a) != getf(b)) {
                merge(a, b);
            }
        }
        unordered_map<int, int> vis;
        for(int i=1; i<=n; i++) {
            if(!vis[getf(i)]) {
                vis[getf(i)] = ++cnt;
            }
        }
        cout << "Case " << ++t << ": " << cnt << endl;
    }
}
