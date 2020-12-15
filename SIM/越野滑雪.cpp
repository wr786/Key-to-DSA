/* [USACO14JAN]Cross Country Skiing S */
#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
int m, n;
int a[501][501], cnt[501][501];
int totcnt;
int f[500010], tag[500010];

struct Edge {
    int u;
    int v;
    int deltah;
    bool operator < (const Edge& other) const {
        return deltah > other.deltah;
    }
};

priority_queue<Edge> pq;

inline int getf(int x) {
    if(x == f[x]) return f[x];
    tag[f[x]] += tag[x];
    tag[x] = 0;
    return f[x] = getf(f[x]);
}

inline void merge(int a, int b) {
    int fa = getf(a), fb = getf(b);
    if(fa != fb) {
        tag[fb] += tag[fa];
        tag[fa] = 0;
        f[fa] = fb;
    }
}

int main() {
    /* input */
    cin >> m >> n;
    for(int i=1; i<=m; i++)
        for(int j=1; j<=n; j++) {
            cin >> a[i][j];
        }
    for(int i=1; i<=m; i++)
        for(int j=1; j<=n; j++) {
            cin >> cnt[i][j];
            /* init unionfind */
            f[i*500 + j] = i*500 + j;
            tag[i*500 + j] = cnt[i][j];
            totcnt += cnt[i][j];
        }
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            if(j != n) {
                pq.push(Edge{i*500 + j, i*500 + j + 1, abs(a[i][j] - a[i][j+1])});
            }
            if(i != m) {
                pq.push(Edge{i*500 + j, i*500 + 500 + j, abs(a[i][j] - a[i+1][j])});
            }
        }
    }
    while(!pq.empty()) {
        Edge cur = pq.top(); pq.pop();
        if(getf(cur.u) != getf(cur.v)) {
            merge(cur.u, cur.v);
            if(tag[getf(cur.u)] == totcnt) {
                cout << cur.deltah << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
}