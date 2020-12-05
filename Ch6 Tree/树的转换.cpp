#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

struct Node {
    Node* left;
    Node* right;
};

int calc_depth(Node* root) {
    if(!root) return 0;
    return max(calc_depth(root->left), calc_depth(root->right)) + 1;
}

int main() {   
    string s; int t = 0;
    while(cin >> s, s != "#") {
        t++;
        int beforeDepth = 0;
        int depth = 0;
        for(auto& c: s) {
            if(c == 'd') depth++;
            else depth--;
            beforeDepth = max(beforeDepth, depth);
        }
        Node* root = new Node{nullptr, nullptr};    // 虚拟根
        Node* cur = root;
        stack<Node*> st;
        int l = s.length();
        for(int i=0; i<l; i++) {
            if(s[i] == 'd') {
                if(!i || s[i-1] == 'd') {
                    st.push(cur);
                    cur->left = new Node{nullptr, nullptr};
                    cur = cur->left;
                } else {
                    cur->right = new Node{nullptr, nullptr};
                    cur = cur->right;
                }
            } else {
                // 第一个一定是d，所以st必定不为空
                if(!st.empty() && s[i-1] == 'u') {
                    cur = st.top();
                    st.pop();
                }
            }
        }
        int afterDepth = calc_depth(root->left);
        cout << "Tree " << t << ": " << beforeDepth << " => " << afterDepth << '\n';
    }
    return 0;
}