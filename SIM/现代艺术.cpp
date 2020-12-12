#include <iostream>
#include <stack>
#include <unordered_map>
#include <algorithm>
using namespace std;
#define LIM 100010

int a[LIM];
int bg[LIM], ed[LIM];   // 记录一个数最早和最晚出现的位置
stack<int> s; 
unordered_map<int, bool> vis;
size_t ans;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
        if(!bg[a[i]]) bg[a[i]] = i;
        ed[a[i]] = i;
    }
    bg[0] = 0, ed[0] = n+1;    // 特殊的：未涂色
    for(int i=0; i<=n+1; i++) {
        if(bg[a[i]] == i) {
            s.push(a[i]);
            ans = max(ans, s.size());
        }
        if(s.top() != a[i]) {
            cout << -1 << endl;
            return 0;
        }
        if(ed[a[i]] == i) {
            s.pop();
        }
    }
    cout << ans-1 << endl;  // 因为多算了一个未涂色的
    return 0;
}