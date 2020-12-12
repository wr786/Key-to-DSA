#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;
unordered_map<string, string> dict;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    // 我就要用iostream
    string a, b;
    while(cin >> a >> b) {
        dict[b] = a;
        cin.ignore();
        if(cin.peek() == '\n') 
            break;
    }
    while(cin >> a) {
        if(dict[a] != "") cout << dict[a] << '\n';
        else cout << "eh\n";
    }
    return 0;
}