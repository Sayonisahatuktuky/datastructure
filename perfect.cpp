#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* inputTree() {
    int val;
    cin >> val;

    if (val == -1) {
        return NULL;
    }

    Node* root = new Node(val);
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* p = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;

        if (l != -1) {
            p->left = new Node(l);
            q.push(p->left);
        }

        if (r != -1) {
            p->right = new Node(r);
            q.push(p->right);
        }
    }

    return root;
}


bool isPerfectBinaryTree(Node* root) {
    if (!root) return true; 

    int depth = 0;
    int nodeCount = 0;
    queue<pair<Node*, int>> q;
    q.push({root, 1});

    int CurrentDepth = 1;

    while (!q.empty()) {
        Node* p = q.front().first;
        int d = q.front().second;
        q.pop();

        if (d != depth) {
            if (nodeCount != CurrentDepth - 1) {
                return false;
            }
            depth = d;
            CurrentDepth *= 2;
        }

        nodeCount++;

        if (p->left) q.push({p->left, d + 1});
        if (p->right) q.push({p->right, d + 1});
    }

    return nodeCount == CurrentDepth - 1;
}

int main() {
    Node* root = inputTree();

    if (isPerfectBinaryTree(root)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
