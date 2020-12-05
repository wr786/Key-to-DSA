#include <algorithm>
#include <iostream>
#include <cassert>
using namespace std;
#define LIM 100000
int n, m;
int f[2*LIM + 10];

inline int getf(int x) {
    if(f[x] == x) return f[x];
    return f[x] = getf(f[x]);
}

inline void merge(int a, int b) {
    int fa = getf(a), fb = getf(b);
    f[fa] = fb;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int _t; cin >> _t;
    while(_t--) {
        cin >> n >> m;
        //init
        for(int i=1; i<=2*n; i++) {
            f[i] = i;
        }
        while(m--) {
            char op; int a, b;
            cin >> op >> a >> b;
            if(op == 'A') {
                if(getf(a) == getf(b)) {
                    cout << "In the same gang.\n";
                } else if(getf(a) == getf(b + n) || getf(a + n) == getf(b)) {
                    cout << "In different gangs.\n";
                } else {
                    cout << "Not sure yet.\n";
                }
            } else if(op == 'D') {
                // maintain hostile rel.
                merge(a, b+n);
                merge(a+n, b);
            }
        }
    }
}