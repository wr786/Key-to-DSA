#include <iostream>
#include <algorithm>
using namespace std;
int m[41][41], n;

int main() {
	cin >> n;
	int cnt = 1;
	pair<int, int> pos = {1, n};
	n = 2*n-1;
	while(cnt <= n*n) {
		m[pos.first][pos.second] = cnt++;
		if(pos.first == 1 && pos.second == n) {
            pos = {2, n};
        } else if (pos.first == 1) {
            pos = {n, pos.second+1};
        } else if (pos.second == n) {
            pos = {pos.first-1, 1};
        } else if(m[pos.first-1][pos.second+1]) {
            pos = {pos.first+1, pos.second};
        } else {
            pos = {pos.first-1, pos.second+1};
        }
	}
    for(size_t i=1; i<=n; i++) {
        for(size_t j=1; j<=n; j++) {
            if(j > 1) cout << ' ';
            cout << m[i][j];
        }
        cout << '\n';
    }
    return 0;
}