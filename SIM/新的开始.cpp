#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define LIM 1010
int n, cnt;
int f[LIM];

class Edge {
public:
    int u;
    int v;
    int price;
    Edge(int from, int to, int cost) : u(from), v(to), price(cost) {}
    bool operator < (const Edge& other) const {
        return price > other.price;
    }
};

int getf(int x) {
    if(x == f[x]) return f[x];
    else return f[x] = getf(f[x]);
}

void merge(int a, int b) { 
    int fa = getf(a), fb = getf(b);
    f[fa] = fb;
}

int main() {
    cin >> n;
    priority_queue<Edge> pq;
    for(int i=1; i<=n; i++) {
        f[i] = i;   // init
        /* 
            创建虚拟结点0，其到i的边值为建立发电站的价格
            这样就可以将结点0视为全图电力之源
            接下来就是很简单的最小生成树问题了
        */
        int tmp; cin >> tmp;
        pq.push(Edge(0, i, tmp));
    }
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++) {
            int tmp; cin >> tmp;
            if(j > i) 
                pq.push(Edge(i, j, tmp));
        }
    while(!pq.empty()) {
        Edge cur = pq.top(); pq.pop();
        if(getf(cur.u) != getf(cur.v)) {
            cnt += cur.price;
            merge(cur.u, cur.v);
        }
    }
    cout << cnt << endl;
    return 0;
}