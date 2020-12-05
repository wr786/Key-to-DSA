#include <iostream>
#include <algorithm>
using namespace std;

int f(int apples, int plates) {
    if(plates <= 1 || apples <= 0) return 1;
    int ret = 0;
    ret += f(apples, plates-1); // 这个盘子不放
    if(apples >= plates) ret += f(apples - plates, plates);  // 所有盘子放一个苹果
    return ret;
}

int main() {
    int t; cin >> t;
    while(t--) {
        int m, n; cin >> m >> n;
        cout << f(m, n) << endl;
    }
    return 0;
}