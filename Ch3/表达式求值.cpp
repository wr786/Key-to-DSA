// 中缀表达式的值稍微改一改就好了
#include <iostream>
#include <string>
#include <cctype>
#include <cstring>
#include <queue>
#include <stack>
#include <cassert>
#include <cmath>
using namespace std;
typedef pair<int, int> bituple;
stack<char> op;	// 用来存运算符，便于转换
stack<int> nums;	// 用来存数字，在后缀表达式中计算
queue<string> rpn;
string expr;

inline bituple get_int(const string& s) {
    // 获得s最前面的数字数值，我们保证输入的第一位是数字
    assert(isdigit(s[0]));
    // 返回(数字数值, 数字位数)
    int ret = s[0] - '0', l = 1;
    while(l <= s.length() && isdigit(s[l])) {
        ret = ret * 10 + s[l] - '0';
        l++;
    }
    return {ret, l};
}

void calc() {
    if(rpn.empty()) return;
    string cur = rpn.front(); rpn.pop();
    // cout << cur << " ";
    if(isdigit(cur[0]) || (cur[0] == '-' && cur.length() > 1)) {
        nums.push(atoi(cur.c_str()));
    } else {
        int num2 = nums.top(); nums.pop();
        int num1 = nums.top(); nums.pop();
        switch(cur[0]) {
        case '+':
            nums.push(num1 + num2);
            break;
        case '-':
            nums.push(num1 - num2);
            break;
        case '*':
            nums.push(num1 * num2);
            break;
        case '/':
            nums.push(num1 / num2);
            break;
        case '^':
            nums.push(pow(num1, num2));
            break;
        }
    }
    calc();
}

int main() {
    int _t; cin >> _t; 
    cin.ignore();   // 配合getline
    while(_t--) {
        // init
        while(!op.empty()) op.pop();
        while(!rpn.empty()) rpn.pop();
        while(!nums.empty()) nums.pop();
        // cin >> expr;
        getline(cin, expr);
        // 转换中缀表达式为后缀表达式
        int curPos = 0, len = expr.length();
        while(curPos < len) {
            char ch = expr[curPos];
            if(isdigit(ch)) {	// 是数字
                bituple ret = get_int(expr.substr(curPos));
                rpn.push(to_string(ret.first));
                curPos += ret.second;
            } else if (ch == '-' && isdigit(expr[curPos+1])) {    // 是负数，(-后面必有字符)
                assert(curPos+1 < len);
                bituple ret = get_int(expr.substr(curPos+1));
                rpn.push(to_string(-1 * ret.first));
                curPos += ret.second + 1;
            } else {	// 是运算符
                switch (ch) {
                case '(':
                    op.push(ch);
                    break;
                case ')':
                    assert(!op.empty()); // 前面必然有(
                    while(op.top() != '(') {	// 将前面的运算符都丢出来
                        rpn.push(string(1, op.top()));
                        op.pop();
                    }
                    op.pop();	// 还得把(也丢了
                    break;
                case '*':
                case '/':
                    // 运算优先级仅次于(
                    while(!op.empty() && (op.top() == '*' || op.top() == '/' || op.top() == '^')) {
                        rpn.push(string(1, op.top()));
                        op.pop();
                    }
                    op.push(ch);
                    break;
                case '+':
                case '-':
                    // 运算优先级最低，只要不是(都可以扔出来了
                    //! 注意这里要用while，不能用if，要把所有的都丢出来！
                    while(!op.empty() && (op.top() != '(')) {
                        rpn.push(string(1, op.top()));
                        op.pop();
                    }
                    op.push(ch);
                    break;
                case '^':
                    // 运算优先级最高
                    while(!op.empty() && op.top() == '^') {
                        rpn.push(string(1, op.top()));
                        op.pop();
                    }
                    op.push(ch);
                    break;
                }
                curPos++;
            }
        }
        while(!op.empty()) {	// 把剩下的也丢出来
            rpn.push(string(1, op.top()));
            op.pop();
        }
        // 计算后缀表达式的值
        calc();
        cout << nums.top() << endl;
    }
    return 0;
}