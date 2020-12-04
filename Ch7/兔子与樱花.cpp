#include <unordered_map>
#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;
#define LIM 100
int graph[LIM][LIM];    // 邻接矩阵
unordered_map<string, int> mid; // 给地点编号
unordered_map<int, string> ids; // 获取地点
int n, m;
int visited[LIM], dist[LIM], viapath[LIM];

int main() {
    cin >> n;
    for(int i=1; i<=n; i++) {
        string tmp; cin >> tmp;
        mid[tmp] = i;
        ids[i] = tmp;
    }
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
            graph[i][j] = 0x3f3f3f3f;   // init
    cin >> m;
    for(int i=1; i<=m; i++) {
        string su, sv;
        int u, v, w;
        cin >> su >> sv >> w;
        u = mid[su], v = mid[sv];
        graph[u][v] = min(graph[u][v], w);  // 防止有多条路的情况
        graph[v][u] = graph[u][v];
    }
    cin >> m;
    while(m--) {
        string start, end;
        cin >> start >> end;
        int s = mid[start], e = mid[end];
        for(int i=1; i<=n; i++) {
            visited[i] = 0;
            dist[i] = 0x3f3f3f3f;
            viapath[i] = s;
        }
        dist[s] = 0;
        bool flag = true;
        while(flag) {
            int minu = -1, mind = 0x3f3f3f3f;
            for(int i=1; i<=n; i++) {
                if(!visited[i] && dist[i] < mind) {
                    mind = dist[i];
                    minu = i;
                }
            }
            if(minu == -1) {
                flag = false;
                break;
            }
            visited[minu] = 1;
            for(int i=1; i<=n; i++) {
                if(dist[i] > dist[minu] + graph[minu][i]) {
                    dist[i] = dist[minu] + graph[minu][i];
                    viapath[i] = minu;
                }
            }
        }
        stack<int> path;
        int cur = e;
        while(cur != s) {
            path.push(viapath[cur]);
            cur = viapath[cur];
        }
        while(!path.empty()) {
            int cur = path.top(); path.pop();
            int tmp = path.empty()? e: path.top();
            cout << ids[cur] << "->(" << graph[cur][tmp] << ")->";
            cur = tmp;
        }
        cout << ids[e] << endl;
    }
    return 0;
}