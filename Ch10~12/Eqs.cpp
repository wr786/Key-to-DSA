#include <iostream>
#include <unordered_map>
using namespace std;
int a[6];
unordered_map<int, int> cube;
unordered_map<int, int> sol;
int ans;

inline int get_cube(int x) {
    if(cube[x]) return cube[x];
    return cube[x] = x * x * x;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    for(int i=1; i<=5; i++)
        cin >> a[i];
    // 用空间换时间，降低时间复杂度
    for(int i=-50; i<=50; i++) {
        if(i == 0) continue;
        for(int j=-50; j<=50; j++) {
            if(j == 0) continue;
            int sum = a[1] * get_cube(i) + a[2] * get_cube(j);
            sol[-sum]++;
        }
    }
    for(int i=-50; i<=50; i++) {
        if(i == 0) continue;
        for(int j=-50; j<=50; j++) {
            if(j == 0) continue;
            for(int k=-50; k<=50; k++) {
                if(k == 0) continue;
                int sum = a[3] * get_cube(i) + a[4] * get_cube(j) + a[5] * get_cube(k);
                ans += sol[sum];
            }
        }
    }
    cout << ans << endl;
    return 0;
}