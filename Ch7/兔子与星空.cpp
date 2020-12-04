#include <iostream>
#include <queue>
#define LIM 100
using namespace std;
int n, sum;
int f[LIM]; // 用来记录不同的连通分量
struct Edge {
    int from;
    int to;
    int weight;
    bool operator < (const Edge& other) const {
        return weight > other.weight;
    }
};

priority_queue<Edge> pq;    // 用来存边

inline int get_node_id(char c) {
    return c - 'A' + 1;
}

int getf(int x) {
    if(x == f[x]) return x;
    return f[x] = getf(f[x]);
}

inline void merge(int a, int b) {
    int fa = getf(a), fb = getf(b);
    if(fa != fb) {
        f[fa] = fb;
    }
}

int main() {
    cin >> n;
    for(int i=1; i<=n; i++) f[i] = i;   // 刚开始都属于不同的连通分量
    for(int i=1; i<n; i++) {
        char cu; cin >> cu;
        int u = get_node_id(cu);
        int k; cin >> k;
        while(k--) {
            char cv; int v, w;
            cin >> cv >> w;
            v = get_node_id(cv);
            pq.push({u, v, w}); // 虽然是无向边，但其实没必要存两次，存一次就得了
        }
    }
    while(!pq.empty()) {
        Edge cur = pq.top(); pq.pop();
        if(getf(cur.from) == getf(cur.to)) {
            continue;   // 都已经加入了，不用再加入一边
        }
        // 不然就将其加入到最小生成树之中
        sum += cur.weight;
        merge(cur.from, cur.to);
    }
    cout << sum << endl;
    return 0;
}