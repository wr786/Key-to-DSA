#include <iostream>
#define LIM 500010
using namespace std;
int a[LIM];
int tmp[LIM];   // 免得爆内存
long long cnt;
int n;

void merge(int l1, int r1, int l2, int r2) {
    int ol1 = l1;   // 保存一下l1的位置
    int k = 0;
    while(l1 <= r1 && l2 <= r2) {
        if(a[l2] < a[l1]) {    // a[l2]更小
            tmp[++k] = a[l2++];
            cnt += r1 - l1 + 1; // 所需交换次数
        } else {                // a[l1]更小
            tmp[++k] = a[l1++];
        }
    }
    // 善后
    while(l1 <= r1)
        tmp[++k] = a[l1++];
    while(l2 <= r2)
        tmp[++k] = a[l2++];
    for(int i=1; i<=k; i++) {
        a[ol1 + i - 1] = tmp[i];
    }
}

void merge_sort(int l, int r) {
    if(l < r) {
        int mid = (l + r) >> 1;
        merge_sort(l, mid);
        merge_sort(mid+1, r);
        merge(l, mid, mid+1, r);
    }
}

int main() {
    while(cin >> n && n) {
        cnt = 0;
        for(int i=1; i<=n; i++)
            cin >> a[i];
        merge_sort(1, n);
        cout << cnt << endl;
    }
    return 0;
}