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

void insert_at_tail(Node* &head,Node* &tail ,int v) {
    Node* newNode = new Node(v);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}
int find_index(Node*head,int x){
    int count=0;
    Node*temp=head;
    while(temp!=NULL){
        if(temp->val==x){
            return count;
        }
        temp=temp->next;
        count++;
    }
    return -1;
}
int main()
{ 
    int T;
    cin>>T;
    while(T--){
        Node* head = NULL;
        Node* tail = NULL;
        int val;
        while(true){
            cin>>val;
            if(val==-1) break;
            insert_at_tail(head,tail,val);
            }
        int x;
        cin>>x;
        int index=find_index(head,x);
        cout<<index<<endl;

    }
 
  return 0;
}