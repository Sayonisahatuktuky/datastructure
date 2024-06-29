#include<bits/stdc++.h>
using namespace std;
 
 class Node{
     public:
       int val;
       Node* next;
       Node(int val){
         this->val=val;
         this->next=NULL;
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
void remove_duplicate(Node*& head) {
  Node* temp = head;
  while (temp != NULL) {
    Node* current = temp;
    while (current->next != NULL) {
      if (current->next->val == temp->val) {
        Node* deletenode = current->next;
        current->next = current->next->next;
        delete deletenode;
      } else {
        current = current->next;
      }
    }
  temp = temp->next;
  }
}
void print_linked_list(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    Node* head = NULL;
    int val;

   while(true){
    cin>>val;
    if(val==-1) break;
    insert_at_tail(head,val);
 }

 remove_duplicate(head);
 print_linked_list(head);

  return 0;
}