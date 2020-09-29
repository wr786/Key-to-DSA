#include <iostream>
#include <algorithm>
using namespace std;
// fake segment-tree, actually prefix-sum
#define MOD 65535
int lazyTag;
int num[100001];

int main() {
    int n, m; cin >> n >> m;
    for(int i=1; i<=n; i++)
        cin >> num[i];
    while(m--) {
        char op; int k;
        cin >> op >> k;
        if(op == 'Q') {
            int cnt = 0;
            for(int i=1; i<=n; i++) {
                num[i] = (long long)(num[i] + lazyTag) % MOD;
                if(num[i] & (1<<k)) cnt++;
            }
            lazyTag = 0;
            cout << cnt << endl;
        } else if(op == 'C') {
            lazyTag = (long long)(lazyTag + k) % MOD;
        }
    }
}