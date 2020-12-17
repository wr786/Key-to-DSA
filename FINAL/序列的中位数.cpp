#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <queue>
#include <cmath>
#include <iomanip>
#include <vector>
#include <stack>
#include <cassert>
using namespace std;
int n;
long long a[100010];

class cmp {
public: bool operator () (long long a, long long b) const {
    return a > b;
}
};

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> a[i];
    }
    priority_queue<long long> left;
    priority_queue<long long, vector<long long>, cmp> right;    // 分别存放比当前中位数小和大
    long long mid = a[1];
    cout << a[1] << endl;
    if(n <= 1) return 0;
    for(int k = 2; k <= (n+1)/2; k++) {
        long long b = a[2*(k-1)], c = a[2*(k-1) + 1];
        if((b <= mid && mid <= c) || (c <= mid && mid <= b)) {
            cout << mid << endl;
            left.push(min(b,c));
            right.push(max(b, c));
        } else if(b <= mid && c <= mid) {
            left.push(b); left.push(c);
            cout << left.top() << endl;
            right.push(mid);
            mid = left.top();
            left.pop();
        } else if(b >= mid && c >= mid) {
            right.push(b); right.push(c);
            cout << right.top() << endl;
            left.push(mid);
            mid = right.top();
            right.pop();
        }
    }
    return 0;
}