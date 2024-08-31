#include<bits/stdc++.h>
using namespace std;
 class Node{
     public:
       int val;
       Node* left;
       Node* right;
       Node(int val){
         this->val=val;
         this->left=NULL;
         this->right=NULL;
       }
  };
  Node* inputtree(){
    int val;
    cin>>val;
    Node*root;
    if(val==-1) root==NULL;
    else root=new Node(val);
    queue<Node*>q;
    if(root)q.push(root);
    while(!q.empty()){
        Node*f=q.front();
        q.pop();

        int l,r;
        cin>>l>>r;
        Node*left;
        Node*right;
        if(l==-1) left=NULL;
        else left= new Node(l);
        if(r==-1) right=NULL;
        else right= new Node(r);

        f->left=left;
        f->right=right;
        if(f->left) q.push(f->left);
        if(f->right) q.push(f->right);

    }
    return root;
  }
 void findLeafNodes(Node* root, vector<int>& leafNodes) {
    if (root == NULL) {
        return;
    }

    if (root->left == NULL && root->right == NULL) {
        leafNodes.push_back(root->val);
    }

    findLeafNodes(root->left, leafNodes);
    findLeafNodes(root->right, leafNodes);
}

int main() {
    Node* root = inputtree();
    vector<int> leafNodes;

    findLeafNodes(root, leafNodes);

    sort(leafNodes.rbegin(), leafNodes.rend());

    for (int val : leafNodes) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}