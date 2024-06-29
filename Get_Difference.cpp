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

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    int val;

   while(true){
    cin>>val;
    if(val==-1) break;
    insert_at_tail(head,tail,val);
 }

   
    if (head == NULL) {
        cout << 0 << endl;
        return 0;
    }

    int max_val = head->val;
    int min_val = head->val;
    Node* temp = head;

    while (temp != NULL) {
        if (temp->val > max_val) {
            max_val = temp->val;
        }
        if (temp->val < min_val) {
            min_val = temp->val;
        }
        temp = temp->next;
    }

    int dif = max_val - min_val;
    cout << dif<< endl;

    return 0;
}
