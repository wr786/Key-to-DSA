#include <iostream>
#include <algorithm>
#include <array>
using namespace std;
// 程设 枚举
#define LIM 0x3f3f3f3f
int ans = LIM;
int oriBoard[5];    // b1w0
int board[5];

inline void flipBit(int & byte, int pos) {
    byte ^= (1<<pos);
}

inline void f(int color) {
    // color代表要全部翻为的颜色
    // 默认状况是全翻为白
    for(int firstRowSwitch = 0; firstRowSwitch < (1<<4); firstRowSwitch++) {
        // copy
        for(int i=1; i<=4; i++) {
            if(color) {
                board[i] = (~oriBoard[i])&((1<<4)-1);   // 把黑当成白的处理即可
            } else {
                board[i] = oriBoard[i];
            }
        }
        int switches = firstRowSwitch;
        int cnt = 0;
        // count the switches
        for(int i=1; i<=4; i++) {
            for(int _i=0; _i<4; _i++)
                if(switches & (1<<_i)) 
                    cnt++;
            // perform switches
            for(int j=0; j<4; j++) {
                if(switches & (1<<j)) {
                    flipBit(board[i], j);
                    if(j == 0) {
                        flipBit(board[i], j+1);
                    } else if(j == 3) {
                        flipBit(board[i], j-1);
                    } else {
                        flipBit(board[i], j+1);
                        flipBit(board[i], j-1);
                    }
                    if(i < 4)
                        flipBit(board[i+1], j);
                }
            }
            switches = board[i];    // coz we have to make it all 0
            if(i == 4 && board[i] == 0) {
                ans = min(ans, cnt);
            }
        }
    }
}

int main() {
    for(int i=1; i<=4; i++)
        for(int j=1; j<=4; j++) {
            char tmp; cin >> tmp;
            oriBoard[i] = (oriBoard[i] << 1 | (tmp == 'b'));
        }
    f(0);
    f(1);
    if(ans != LIM) {
        cout << ans << endl;
    } else {
        cout << "Impossible\n";
    }
    return 0;
}