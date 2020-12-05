#include <iostream>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;

int main() {
    int n, k, p;
    cin >> n >> k >> p;
    set<int> goodCardIdx;
    queue<int> deck;
    for(int i=1; i<=k; i++) 
        deck.push(i);
    int curPlayer = 1;  // 0代表自己
    while(!deck.empty()) {
        if(curPlayer == 0) {
            goodCardIdx.insert(deck.front());
        }
        deck.pop();
        if(deck.empty()) break;
        for(int i=1; i<=p; i++) {
            deck.push(deck.front());
            deck.pop();
        }
        curPlayer = (curPlayer+1) % n;
    }
    for(auto& goodCard: goodCardIdx) {
        cout << goodCard << '\n';
    }
    return 0;
}