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
  int sumNoLeaf(Node* root) {
    if (!root)
        return 0;
    
    int sum = 0;
    queue<Node*> q;
    q.push(root);
    
    while (!q.empty()) {
        Node* p = q.front();
        q.pop();
        
        
        if (p->left || p->right) {
            sum += p->val;
        }
        
        if (p->left)
            q.push(p->left);
        
        if (p->right)
            q.push(p->right);
    }
    
    return sum;
}
int main()
{
    Node*root=inputtree();
    int sum=sumNoLeaf(root);
    cout<<sum<<endl;

 
  return 0;
}