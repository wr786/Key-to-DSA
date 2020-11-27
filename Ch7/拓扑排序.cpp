#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;
#define LIM 100010
int n, m;
int head[LIM], to[LIM], nxt[LIM], idx;
int inDegree[LIM];
unordered_map<int, bool> printed;

inline void addEdge(int u, int v) {
    nxt[++idx] = head[u];
    head[u] = idx;
    to[idx] = v;
    inDegree[v]++;
}

int main() {
    cin >> n >> m;
    for(int i=1; i<=m; i++) {
        int u, v; cin >> u >> v;
        addEdge(u, v);
    }
    int cnt = 0;
    while(cnt < n) {
        for(int i=1; i<=n; i++) {
            if(inDegree[i] == 0 && !printed[i]) {
                if(cnt++) cout << " ";
                cout << "v" << i;
                printed[i] = true;
                for(int e=head[i]; e; e=nxt[e]) {
                    inDegree[to[e]]--;
                }
                break;
            }
        }
    }
}