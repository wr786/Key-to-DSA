#include <iostream>
#include <string>
#include <valarray>
#include <unordered_set>
#include <cctype>
using namespace std;
unordered_set<char> p[50];
int pcount; // pattern数

void parse_pattern(string& ptn) {
    int cur = 0;
    while(cur < ptn.length()) {
        if(ptn[cur] == '[') {
            int right = ptn.find(']', cur);
            if(right != string::npos) {
                pcount++;
                for(int i=cur+1; i<right; i++)
                    p[pcount].insert(tolower(ptn[i]));
                ptn = ptn.substr(0, cur) + '\n' + ptn.substr(right+1);  // 以\n标记pattern位置（毕竟输入中必不可能有\n
                cur--;
            }
        }
        cur++;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    valarray<string> hw(n);
    for(int i=0; i<n; i++) 
        cin >> hw[i];
    string pattern; cin >> pattern;
    parse_pattern(pattern);
    int l = pattern.length();
    for(int i=0; i<n; i++) {
        if(hw[i].length() != l)
            continue;   // 那必不可能匹配
        int pc = 0; bool flag = true;
        for(int j=0; j<l; j++) {
            if(pattern[j] == '\n') {
                // 那么就尝试匹配
                if(!p[++pc].count(tolower(hw[i][j]))) {
                    flag = false;
                    break;
                }
            } else if(tolower(hw[i][j]) != tolower(pattern[j])) {
                flag = false;
                break;
            }
        }
        if(flag) {
            cout << i+1 << " " << hw[i] << endl;
        }
    }
    return 0;
}  