#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n;
bool a[50][50];
int ans[50];

/* 高斯消元 */
void gauss() {
    int k = 0;  /* 行 */
    for(int col=0; k<n && col<n; k++, col++) {
        int i = k;
        while(i<n && !a[i][col]) i++;
        if(!a[i][col]) {
            k--;
            continue;
        }
        if(i > k) {
            for (int r=col; r<=n; r++) {
                swap(a[i][r], a[k][r]);
            }
        }
        for(i=k+1; i<n; i++) {
            if (a[i][col]) {
                for (int j=col; j<=n; j++) {
                    a[i][j] ^= a[k][j];
                }
            }
        }
    }
    /* 化简的增广阵中存在(0, 0, ..., a)这样的行，无解！ */
    for(int i=k; i<n; i++) {
        if(a[i][n]) {
            cout << "Oh,it's impossible~!!\n";
            return;
        }
    }
    /* n-k为自由变元的数量 */
    cout << (1 << (n-k)) << '\n';
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        memset(a, false, sizeof(a));
        cin >> n;
        for(int i=0; i<n; i++) {
            cin >> a[i][n];
            a[i][i] = true;
        }
        int x;
        for(int i=0; i<n; i++) {
            cin >> x;
            a[i][n] = a[i][n] ^ x;
        }
        int m, n;
        while(cin >> m >> n && m && n) {
            a[n-1][m-1] = true;
        }
        gauss();
    }
}