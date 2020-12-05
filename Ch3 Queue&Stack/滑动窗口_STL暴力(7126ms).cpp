#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
int n, k;
int a[1000001];
vector<int> mins, maxs;
multiset<int> minWindow;
multiset<int> maxWindow;

int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	for(int i=1; i<=n; i++)
		cin >> a[i];

	// init
	for(int i=1; i<=k; i++) {
		minWindow.insert(a[i]);
		maxWindow.insert(-1 * a[i]);
	}
	mins.push_back(*minWindow.begin());
	maxs.push_back(-1 * *(maxWindow.begin()));

	for(int left=2; left+k-1 <= n; left++) {
		// 为了只删除一个元素，所以这里需要加一个find
		minWindow.erase(minWindow.find(a[left-1]));
		maxWindow.erase(maxWindow.find(-1 * a[left-1]));
		minWindow.insert(a[left+k-1]);
		maxWindow.insert(-1 * a[left+k-1]);
		mins.push_back(*minWindow.begin());
		maxs.push_back(-1 * *(maxWindow.begin()));
	}

	for(auto it = mins.begin(); it != mins.end(); it++) {
		if(it != mins.begin()) cout << " ";
		cout << *it;
	}
	cout << '\n';
	for(auto it = maxs.begin(); it != maxs.end(); it++) {
		if(it != maxs.begin()) cout << " ";
		cout << *it;
	}
	cout << '\n';
	return 0;
}