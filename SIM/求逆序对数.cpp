#include <iostream>
#include <algorithm>
using namespace std;
int n, cnt;
int a[20001], tmp[20001];

void merge(int l1, int r1, int l2, int r2) {
    if(l1 >= r2) return;
    int k = 0, ol1 = l1;
    while(l1 <= r1 && l2 <= r2) {
        if(a[l1] > a[l2]) {
            tmp[++k] = a[l2++];
            cnt += r1 - l1 + 1;
        } else {
            tmp[++k] = a[l1++];
        }
    }
    while(l1 <= r1) tmp[++k] = a[l1++];
    while(l2 <= r2) tmp[++k] = a[l2++];
    for(int i=ol1; i<=r2; i++)
        a[i] = tmp[i-ol1+1];
}

void merge_sort(int l, int r) {
    if(l >= r) return;
    int m = (l + r) >> 1;
    merge_sort(l, m);
    merge_sort(m+1, r);
    merge(l, m, m+1, r);
}

int main() {
    while(cin >> n && n) {
        cnt = 0;
        for(int i=1; i<=n; i++) {
            cin >> a[i];
        }
        merge_sort(1, n);
        cout << cnt << endl;
    }
}