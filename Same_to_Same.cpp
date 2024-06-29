#include<bits/stdc++.h>
using namespace std;
 
  class Node {
public:
    int val;
    Node* next;
    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

  void insert_at_tail(Node*& head, int v) {
    Node* newNode = new Node(v);
    if (head == NULL) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}
bool same_to(Node*&head1,Node*&head2){
    while(head1!=NULL&&head2!=NULL){
        if(head1->val!=head2->val)return false;
        head1=head1->next;
        head2=head2->next;
    }
    return(head1==NULL&&head2==NULL);
}
int main()
{
    Node* head1 = NULL;
    int val;

   while(true){
    cin>>val;
    if(val==-1) break;
    insert_at_tail(head1,val);
 }
    Node* head2 = NULL;

   while(true){
    cin>>val;
    if(val==-1) break;
    insert_at_tail(head2,val);
 }
 if(same_to(head1,head2)) cout<<"YES"<<endl;
 else cout<<"NO"<<endl;



  return 0;
}