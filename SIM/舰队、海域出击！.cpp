// http://dsalgo.openjudge.cn/graph/10/
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;
#define LIMN 100010
#define LIMM 500010
int n, m;
int head[LIMN], to[LIMM], nxt[LIMM], eidx;
int indegree[LIMN];

inline void addEdge(int u, int v) {
    nxt[++eidx] = head[u];
    head[u] = eidx;
    to[eidx] = v;
    indegree[v]++;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while(t--) {
        cin >> n >> m;
        fill(indegree, indegree + n + 1, 0);
        fill(head, head+n, 0);
        fill(to, to+m, 0);
        fill(nxt, nxt+m, 0);
        eidx = 0;   // init
        for(int i=1; i<=m; i++) {
            int u, v; cin >> u >> v;
            addEdge(u, v);
        }
        queue<int> q;
        for(int i=1; i<=n; i++)
            if(!indegree[i]) q.push(i);
        int cnt = 0;
        while(!q.empty()) {
            int cur = q.front(); q.pop();
            cnt++;
            for(auto& e = head[cur]; e; e = nxt[e]) {
                indegree[to[e]]--;
                if(indegree[to[e]] == 0) {
                    q.push(to[e]);
                }
            }
        }
        cout << (cnt == n? "No": "Yes") << '\n';
    }
    return 0;
}