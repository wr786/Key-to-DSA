// 模拟就vans了
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
using namespace std;
stack<int> s;
vector<string> sol;
bool flag = true;
int n, tar;
int nxt = 1;

void solve() {
	while(tar > nxt) {
		s.push(nxt);
		sol.push_back("PUSH " + to_string(nxt));
		nxt++;
	}
	if(tar == nxt) {
		sol.push_back("PUSH " + to_string(tar));
		sol.push_back("POP " + to_string(tar));
		nxt++;
		return;
	} else {	// 此时必有tar < nxt
		if(!s.empty() && tar == s.top()) {
			s.pop();
			sol.push_back("POP " + to_string(tar));
			return;
		} else {
			flag = false;
			return;
		}
	}

}

int main() {
	cin >> n;
	for(int i=1; i<=n; i++) {
		cin >> tar;
		solve();
		if(!flag) {
			cout << "NO\n";
			return 0;
		}
	}
	for(auto& op: sol) {
		cout << op << '\n';
	}
	return 0;
}