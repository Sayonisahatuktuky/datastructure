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

// Function to build the binary tree from level order input
Node* inputTree() {
    int val;
    cin >> val;

    if (val == -1) {
        return NULL; // If the first value is -1, the tree is empty
    }

    Node* root = new Node(val);
    queue<Node*> q; // Queue to store nodes for level-order construction
    q.push(root);

    while (!q.empty()) {
        Node* currentNode = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;

        if (l != -1) {
            currentNode->left = new Node(l);
            q.push(currentNode->left);
        }

        if (r != -1) {
            currentNode->right = new Node(r);
            q.push(currentNode->right);
        }
    }

    return root;
}

// Function to calculate the depth of the leftmost path
int calDepth(Node* root) {
    int depth = 0;
    while (root != NULL) {
        depth++;
        root = root->left;
    }
    return depth;
}
int countNodes(Node* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}
bool isPerfectBinaryTree(Node* root) {
    if (root == NULL) {
        return true;
    }

    int depth = calDepth(root);
    int totalNodes = countNodes(root);
    return totalNodes == (pow(2, depth) - 1);
}

int main() {
    Node* root = inputTree();
    if (root == NULL) {
        cout << "NO" << endl;
        return 0;
    }

    if (isPerfectBinaryTree(root)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
