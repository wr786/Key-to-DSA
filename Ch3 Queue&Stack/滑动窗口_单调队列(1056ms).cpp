#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;
int n, k;
int a[1000001];
deque<int> minq;
deque<int> maxq;

// 维护一个存数组下标的单调队列
int main() {
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	for(int i=1; i<=n; i++) cin >> a[i];
	for(int i=1; i<=n; i++) {
		if(!minq.empty() && i - minq.front() >= k)
			minq.pop_front();	// 维护窗口长度为k
		// 如果前面的数比现在的大，那必然可以直接舍弃掉它，因为后面也不会用到它们
		// 反之，若现在的数比前面的大，那需要保留，因为它也是最小值候补之一
		while(!minq.empty() && a[i] <= a[minq.back()])
			minq.pop_back();
		minq.push_back(i);
		if(i >= k) {	// 窗口成型
			cout << a[minq.front()] << ' ';
		}
	}
	cout << '\n';
	// 下类似
	for(int i=1; i<=n; i++) {
		if(!maxq.empty() && i - maxq.front() >= k)
			maxq.pop_front();
		while(!maxq.empty() && a[i] >= a[maxq.back()])
			maxq.pop_back();
		maxq.push_back(i);
		if(i >= k) {
			cout << a[maxq.front()] << ' ';
		}
	}
	cout << '\n';
}