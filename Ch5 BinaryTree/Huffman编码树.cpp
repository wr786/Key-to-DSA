#include <iostream>
#include <queue>
using namespace std;
struct Node {
    int value;
    Node *left, *right;
    bool isLeaf;
};

class cmp {
public:
    bool operator () (const Node* left, const Node* right) const {
        return left->value > right->value;
    }
};

int calc(Node* root, int depth) {
    int ret = root->isLeaf? root->value * depth: 0;
    if(root->left) ret += calc(root->left, depth+1);
    if(root->right) ret += calc(root->right, depth+1);
    return ret;
}

int main() {
    int t; cin >> t;
    while(t--) {
        priority_queue<Node*, vector<Node*> ,cmp> pq;
        int n; cin >> n;
        for(int i=1; i<=n; i++) {
            int tmp; cin >> tmp;
            pq.push(new Node{tmp, nullptr, nullptr, true});
        }
        while(pq.size() > 1) {
            Node* a = pq.top(); pq.pop();
            Node* b = pq.top(); pq.pop();
            Node* c = new Node{a->value + b->value, a, b, false};
            pq.push(c);
        }
        Node* root = pq.top();
        cout << calc(root, 0) << endl;
    }
}
