#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Cow {
    int id;
    int round1;
    int round2;
};

bool cmp1(const Cow& a, const Cow& b) {
    return a.round1 > b.round1;
}

bool cmp2(const Cow& a, const Cow& b) {
    return a.round2 > b.round2;
}

int n, k;

int main() {
    cin >> n >> k;
    vector<Cow> round1Champions;
    for(int i=1; i<=n; i++) {
        int t1, t2; cin >> t1 >> t2;
        round1Champions.push_back(Cow{i, t1, t2});
    }
    sort(round1Champions.begin(), round1Champions.end(), cmp1);
    vector<Cow> round2Champions;
    for(auto it=round1Champions.begin(); it!=round1Champions.end(); ++it) {
        if(k-- <= 0) break;
        round2Champions.push_back(*it);
    }
    sort(round2Champions.begin(), round2Champions.end(), cmp2);
    cout << round2Champions[0].id << endl;
    return 0;
}