#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct DNAstring {
    static int globalDNAcnt;
    int idx;
    string s;
    int rpairs;
    DNAstring(const string& s_) {
        s = s_;
        // 计算逆序对数，直接暴力罢
        rpairs = 0;
        int l = s.length();
        for(int i=0; i<l; i++) {
            for(int j=i+1; j<l; j++) {
                if(s[j] < s[i])
                    rpairs++;
            }
        }
    }
    bool operator < (const DNAstring& other) const {
        return rpairs == other.rpairs? idx > other.idx: rpairs > other.rpairs;
    }
};
int DNAstring::globalDNAcnt = 0;    // init

int main() {
    int n; cin >> n >> n;
    priority_queue<DNAstring> pq;
    for(int i=1; i<=n; i++) {
        string tmp; cin >> tmp;
        pq.push(DNAstring(tmp));
    }
    while(!pq.empty()) {
        cout << pq.top().s << endl;
        pq.pop();
    }
    return 0;
}
