#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <iomanip>
#include <vector>
using namespace std;
int n;
int f[1001];

int getf(int x) {
    if(x == f[x]) return f[x];
    return f[x] = getf(f[x]);
}

inline void merge(int a, int b) {
    f[getf(a)] = getf(b);
}

struct Edge {
    int u, v, w;
    bool operator < (const Edge& other) const {
        return w > other.w;
    }  
};

inline int getid(char c) {  // 0 to n-1
    return c - 'A' + 1;
}

int main() {
    cin >> n;
    priority_queue<Edge> pq;
    for(int i=0; i<n-1; i++) {
        char c; cin >> c;
        f[getid(c)] = getid(c);
        int m; cin >> m;
        while(m-- > 0) {
            char v; int w; cin >> v >> w;
            pq.push({getid(c), getid(v), w});
            // pq.push({getid(v), getid(c), w});
        }
    }
    int sum = 0;
    while(!pq.empty()) {
        Edge cur = pq.top(); pq.pop();
        if(getf(cur.u) != getf(cur.v)) {
            merge(cur.u, cur.v);
            sum += cur.w;
        }
    }
    cout << sum << endl;
    return 0;
}