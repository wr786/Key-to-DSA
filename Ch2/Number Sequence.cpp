#include <algorithm>
#include <iostream>
#include <string>
#include <cassert>
using namespace std;
#define LIM 50000U
size_t n;
int length[LIM];    // 表示1...i序列的位数

inline void generate_table() {
    for(size_t i=1; i<=LIM; i++) {
        length[i] = length[i-1] + to_string(i).length();
    }
}

int main() {
    generate_table();
    cin >> n;
    for(size_t i=0; i<n; i++) {
        size_t tmp; cin >> tmp;
        for(size_t ending=1; ending<=LIM; ending++) {
            if(tmp > length[ending]) {
                tmp -= length[ending];
            } else {
                for(size_t cur=1; cur<=ending; cur++) {
                    if(tmp > to_string(cur).length()) {
                        tmp -= to_string(cur).length();
                    } else {
                        assert(tmp >= 1);
                        cout << to_string(cur)[tmp-1] << endl;
                        break;
                    }
                }
                break;
            }
        }
    }
    return 0;
}