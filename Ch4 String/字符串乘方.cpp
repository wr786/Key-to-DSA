#include<string>
#include<iostream>
using namespace std;
#define endl '\n'

string s;
int len;
int nxt[1000001];

void get_next() {	// 计算next数组
	int i = 0;
	int j = -1;
	nxt[0] = -1;
	while(i < len) {	// 不是len-1，因为就是要计算nxt[len]
		if(j == -1 || s[i] == s[j]) {
			nxt[++i] = ++j;
		} else {
			j = nxt[j];
		}
	}
}

int main() {
	ios::sync_with_stdio(false); cin.tie(0);	// 我偏要用cin！
	while(cin >> s && s != ".") {
		len = s.length();
		get_next();
		if(len % (len - nxt[len])) {
			cout << 1 << endl;
		} else {
			cout << len / (len - nxt[len])<< endl;
		}
	}
}