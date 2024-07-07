#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    string val;
    Node* next;
    Node* prev;
    Node(string val) {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insert_at_tail(Node*& head, Node*& tail, string v) {
    Node* newNode = new Node(v);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

Node* find(Node* head,string& address) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->val == address) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    string val;
 while(true){
     cin>>val;
 if(val=="end"){
    break;
   }
        insert_at_tail(head, tail, val);
 }
    
    int Q;
    cin >> Q;
    Node* current = head;
    string command, address;
    
    for (int i = 0; i < Q; ++i) {
        cin >> command;
        if (command == "visit") {
            cin >> address;
            Node* visit = find(head, address);
            if (visit) {
                current = visit;
                cout << current->val << endl;
            } else {
                cout << "Not Available" << endl;
            }
        } else if (command == "next") {
            if (current->next) {
                current = current->next;
                cout << current->val << endl;
            } else {
                cout << "Not Available" << endl;
            }
        } else if (command == "prev") {
            if (current->prev) {
                current = current->prev;
                cout << current->val << endl;
            } else {
                cout << "Not Available" << endl;
            }
        }
    }
    
    return 0;
}
