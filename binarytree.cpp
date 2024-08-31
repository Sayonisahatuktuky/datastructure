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
  void level_oder(Node*root){
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node*f=q.front();
        q.pop();
        
        cout<<f->val<<" ";
        if(f->left!=NULL) q.push(f->left);
        if(f->right!=NULL) q.push(f->right);
    }
  }
int main()
{
 
  return 0;
}