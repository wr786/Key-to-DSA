#include <iostream>
#include <string>
using namespace std;
char cur, nxt;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    while(cin.get(cur)) {
        // 转义字符只能在字符串中有效，所以只用在第一个判断中再考虑
        if(cur == '\'' || cur == '"') { // '或者"，即引号
            // 那么直到下一个相同的引号为止，都不用考虑是否为注释
            cout.put(cur);
            while(cin.get(nxt) && nxt != cur) {
                cout.put(nxt);
                if(nxt == '\\') {   // 那么就是转义，不管下一个是啥，直接输出
                    cin.get(nxt);
                    cout.put(nxt);
                }
            } 
            cout.put(nxt);  // 把最后一个引号也输出
        } else if(cur == '/') { // 判断是否/*
            cin.get(nxt);
            if(nxt == '*') {    // /*，开始注释，因为不允许嵌套，直接读到下一个*/
                while(cin.get(nxt)) {
                    if(nxt == '*') {
                        cin.get(nxt);
                        if(nxt == '/') {    // 注释结束
                            break;
                        } else {
                            cin.putback(nxt);   // 不好意思，认错了，放回去
                        }
                    }
                }
            } else {    // 不好意思，认错了，输出
                cout.put(cur);
                cout.put(nxt);
            }
        } else {
            cout.put(cur);
        }
    }
}