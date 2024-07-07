#include<bits/stdc++.h>
using namespace std;
 
  class Node{
     public:
       int val;
       Node* next;
       Node* prev;
       Node(int val){
         this->val=val;
         this->next=NULL;
         this->prev=NULL;
       }
  };
  void print_linked_list(Node*head){
    cout<<"L -> ";
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout<<endl;
  }
  void print_linked_list_re(Node*tail){
    cout<<"R -> ";
    Node*temp=tail;
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp=temp->prev;
    }
    cout<<endl;
  }
   void insert_at_pos(Node*&head,Node*&tail,int pos,int val){
    Node* newNode=new Node(val);
    if(pos==0){
        if(head==NULL){
          head=newNode;
          tail=newNode;
          print_linked_list(head);
          print_linked_list_re(tail);
          return;
        }
    newNode->next=head;
    head->prev=newNode;
    head=newNode;
    print_linked_list(head);
    print_linked_list_re(tail);
    return;
    }
    Node* temp=head;
    for(int i=1;i<=pos-1;i++){
        if (temp == NULL) {
            cout << "Invalid" << endl;
            delete newNode;
            return;
        }
        temp=temp->next;
    }
    if (temp == NULL) {
        cout << "Invalid" << endl;
        delete newNode;
        return;
    }
    newNode->next=temp->next;
    if(temp->next!=NULL){
        newNode->next->prev=newNode;
    }
    else {
        tail=newNode;
    }
    temp->next=newNode;
    newNode->prev=temp;
    print_linked_list(head);
    print_linked_list_re(tail);
  }
int main()
{
  int Q;
 cin>>Q;
  Node*head=NULL;
  Node*tail=NULL;
 while(Q--){
    int X,V;
    cin>>X>>V;
    insert_at_pos(head,tail,X,V); 
 }

  return 0;
}