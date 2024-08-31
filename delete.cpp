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

  void delete_head(Node*&head){
    Node*deletenode=head;
    head=head->next;
    delete deletenode;
    head->prev=NULL;
  }
  void delete_at_pos(Node*&head,int pos){
    Node*temp=head;
    for(int i=1;i<=pos-1;i++){
      temp=temp->next;
    }
    Node*deletenode=temp->next;
    temp->next=temp->next->next;
    temp->next->prev=temp;
    delete deletenode;
  }
  void delete_tail(Node*&tail){
    Node*deletenode=tail;
    tail=tail->prev;
    delete deletenode;
    tail->next=NULL;
  }
  void print_linked_list(Node*head){
    Node*temp=head;
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout<<endl;
  }
  void print_linked_list_re(Node*tail){
    Node*temp=tail;
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp=temp->prev;
    }
    cout<<endl;
  }
   int size(Node*head){
    Node*temp=head;
    int cnt=0;
    while(temp!=NULL){
        cnt++;
        temp=temp->next;
    }
    return cnt;
  }
  
int main()
{
  // Node*head=NULL;
  // Node*tail=NULL;
 Node*head=new Node(10);
 Node*a=new Node(20);
 Node*b=new Node(30);
 Node*c=new Node(40);
 Node*d=new Node(50);
 Node*tail=d;

 head->next=a;
 a->prev=head;
 a->next=b;
 b->prev=a;
 b->next=c;
 c->prev=b;
 c->next=d;
 d->prev=c;
 
 int pos;
 cin>>pos;

 if(pos>=size(head)){
  cout<<"Invalid"<<endl;
 }

 else if(pos==0){
  delete_head(head);
 }

 else if(pos==size(head)-1){
   delete_tail(tail);
 }

else{
  delete_at_pos(head,pos);
}

 print_linked_list(head);
 print_linked_list_re(tail);



  return 0;
}