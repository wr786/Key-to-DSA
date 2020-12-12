/* 发现它，抓住它 */
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;
#define LIM 78666
/* 
    f[a] == f[b] 代表 a和b之间是EVEN，则[1, a]与[1, b]奇偶性相同
    f[a] == f[b+LIM] || f[a+LIM] == f[b] 代表 a和b之间是ODD，则[1, a]与[1, b]奇偶性相反
*/
int f[2 * LIM + 10];

int getf(int x) {
    if(f[x] == x) return f[x];
    return f[x] = getf(f[x]);
}

inline void merge(int a, int b) {
    if(b == getf(b)) f[getf(b)] = getf(a);
    else f[getf(a)] = getf(b);
}

unordered_map<int, int> id; // 离散化
int idx;    // 用于离散化
int cnt;    // 用于计数
bool flag;

int main() {
    int n; cin >> n >> n;
    while(n--) {
        int a, b; cin >> a >> b;
        string oddeven; cin >> oddeven;
        if(flag) continue;
        b++;    // 考虑[a, b)
        /* init */
        if(!id[a]) {
            id[a] = ++idx;
            a = id[a];
            f[a] = a;
            f[a+LIM] = a+LIM;
        } else {
            a = id[a];
        }
        if(!id[b]) {
            id[b] = ++idx;
            b = id[b];
            f[b] = b;
            f[b+LIM] = b+LIM;
        } else {
            b = id[b];
        }
        if(oddeven == "even") {
            if(getf(a) == getf(b+LIM) || getf(b) == getf(a+LIM)) {
                // cout << cnt << endl;
                // return 0;
                flag = true;
                continue;
            } else {
                merge(a, b);
                merge(a+LIM, b+LIM);
            }
        } else {
            if(getf(a) == getf(b) || getf(a+LIM) == getf(b+LIM)) {
                // cout << cnt << endl;
                // return 0;
                flag = true;
                continue;
            } else {
                merge(a, b+LIM);
                merge(b, a+LIM);
            }
        }
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}