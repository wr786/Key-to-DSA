#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    string s1, s2;
    while(cin >> s1 >> s2) {
        size_t insPos = 0;
        size_t l1 = s1.length();
        for(size_t i=0; i<l1; i++) {
            if(s1[i] > s1[insPos])
                insPos = i;
        }
        cout << s1.insert(insPos+1, s2) << endl;
    }
}