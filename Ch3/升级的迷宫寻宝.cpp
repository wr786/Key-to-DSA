// bfs
#include <iostream>
#include <unordered_map>
#include <queue>
#include <array>
using namespace std;
typedef pair<int, int> bituple;
enum blockType {
    BLOCK = -1,
    EMPTY,
    KEY,
    FINAL
};
constexpr array<bituple, 4> adj_4 {{
            {-1, 0},
    {0, -1},        {0, 1},
            {1, 0}
}};
int n, m;
int a[100][100];
struct Status {
    bituple pos;
    bool hasKey;
    int time;
    queue<bituple> route;
    Status(int x=1, int y=1, bool k=false, int t=0): pos({x,y}), hasKey(k), time(t) {route.push(pos);}
    Status move_to(int x, int y, bool getkey=false) {
        Status ret = *this;
        ret.pos = {x, y};
        ret.time++;
        ret.route.push({x, y});
        if(getkey) {ret.hasKey = true;}
        return ret;
    }
    bool operator < (const Status& other) const {
        return time > other.time;
    }
};
priority_queue<Status> q;
unordered_map<int, bool> vis[2]; // 0代表没钥匙的，1代表有钥匙的

inline bool check_boundary(int x, int y) {
    return x && y && x < n && y < m;
}

inline int convert(bituple pos) {
    return pos.first * 100 + pos.second;
}

int main() {
    // 读入数据
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    int sx, sy;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            char tmp; cin >> tmp;
            while(tmp == '\n') cin >> tmp;
            if(tmp == '1') {
                a[i][j] = BLOCK;
            } else if(tmp == '0') {
                a[i][j] = EMPTY;
            } else if(tmp == 'Y') {
                a[i][j] = KEY;
            } else if(tmp == 'R') {
                a[i][j] = EMPTY;
                sx = i;
                sy = j;
            } else if(tmp == 'C') {
                a[i][j] = FINAL;
            }
        }
    }
    // 进行bfs
    q.push(Status(sx, sy));
    vis[0][convert({sx, sy})] = true;
    queue<bituple> ans;
    bool flag = false;
    while(!q.empty() && !flag) {
        Status cur = q.top(); q.pop();
        for(auto& dir: adj_4) {
            int nx = cur.pos.first + dir.first;
            int ny = cur.pos.second + dir.second;
            if(!check_boundary) continue;
            if(a[nx][ny] == BLOCK) continue;
            if(vis[cur.hasKey][convert({nx, ny})]) continue;
            if(cur.hasKey && a[nx][ny] == FINAL) {  // 到终点了，准备输出
                ans = cur.route;
                ans.push({nx, ny});
                flag = true;
                break;
            } else {
                Status nxt = cur.move_to(nx, ny, a[nx][ny]==KEY);
                q.push(nxt);
                vis[nxt.hasKey][convert(nxt.pos)] = true;
            }
        }
    }
    while(!ans.empty()) {
        bituple tmp = ans.front(); ans.pop();
        cout << tmp.first << " " << tmp.second << '\n';
    }
    return 0;
}