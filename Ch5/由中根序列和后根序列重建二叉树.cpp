#include <iostream>
#include <vector>
#define infixArray inputArray
#define suffixArray (&inputArray[n])
using namespace std;
struct Node {
    int val;
    Node* left;
    Node* right;
};
int n;

vector<int> inputArray;

void dfs(Node*& root, int infixStart, int infixEnd, int suffixStart, int suffixEnd) {
    if(infixStart > infixEnd || suffixStart > suffixEnd) return;
    root = new Node{suffixArray[suffixEnd], nullptr, nullptr};
    int div = infixStart;
    for(; div <= infixEnd; div++) {
        if(infixArray[div] == suffixArray[suffixEnd]) {
            break;
        }
    }
    dfs(root->left, infixStart, div-1, suffixStart, suffixStart + div-1 - infixStart);
    dfs(root->right, div+1, infixEnd, suffixStart + div - infixStart, suffixEnd-1);
}

void print_prefix(Node* root) {
    if(!root) return;
    cout << root->val << " ";
    print_prefix(root->left);
    print_prefix(root->right);
}

int main() {
    for(int tmp; cin>>(tmp); ) {
        inputArray.push_back(tmp);
    }
    n = inputArray.size() / 2;
    Node* root = nullptr;
    dfs(root, 0, n-1, 0, n-1);
    print_prefix(root);
    return 0;
}