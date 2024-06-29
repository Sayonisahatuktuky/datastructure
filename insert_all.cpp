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

void insert_at_head(Node*& head, int v) {
    Node* newNode = new Node(v);
    newNode->next = head;
    head = newNode;
}

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

void insert_at_position(Node*& head, int pos, int v) {
    if (pos == 0) {
        insert_at_head(head, v);
        return;
    }
    Node* newNode = new Node(v);
    Node* temp = head;
    for (int i = 1; i < pos; i++) {
        if (temp == NULL) {
            cout << "Invalid position" << endl;
            delete newNode;
            return;
        }
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void delete_from_head(Node*& head) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    Node* deleteNode = head;
    head = head->next;
    delete deleteNode;
}

void delete_from_tail(Node*& head) {
    if (head == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }
    Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    Node* deleteNode = temp->next;
    temp->next = NULL;
    delete deleteNode;
}

void delete_from_pos(Node*& head, int pos) {
    if (pos == 0) {
        delete_from_head(head);
        return;
    }
    Node* temp = head;
    for (int i = 1; i < pos; i++) {
        if (temp == NULL || temp->next == NULL) {
            cout << "Invalid position" << endl;
            return;
        }
        temp = temp->next;
    }
    Node* deleteNode = temp->next;
    if (deleteNode == NULL) {
        cout << "Invalid position" << endl;
        return;
    }
    temp->next = deleteNode->next;
    delete deleteNode;
}

void print_linked_list(Node* head) {
    cout << endl;
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;

    while (true) {
        cout << "Option 1: Insert at the tail" << endl;
        cout << "Option 2: Insert at the head" << endl;
        cout << "Option 3: Insert at any position" << endl;
        cout << "Option 4: Delete tail" << endl;
        cout << "Option 5: Delete head" << endl;
        cout << "Option 6: Delete at any position" << endl;
        cout << "Option 7: Print linked list" << endl;
        cout << "Option 8: Terminate" << endl;
        int op;
        cin >> op;
        if (op == 1) {
            cout << "Enter the value: ";
            int v;
            cin >> v;
            insert_at_tail(head, v);
            cout << "Inserted value at tail: " << v << endl;
        } else if (op == 2) {
            cout << "Enter the value: ";
            int v;
            cin >> v;
            insert_at_head(head, v);
            cout << "Inserted value at head: " << v << endl;
        } else if (op == 3) {
            cout << "Enter the value and position: ";
            int v, pos;
            cin >> v >> pos;
            insert_at_position(head, pos, v);
            cout << "Inserted value at position " << pos << endl;
        } else if (op == 4) {
            delete_from_tail(head);
            cout << "Deleted value from tail" << endl;
        } else if (op == 5) {
            delete_from_head(head);
            cout << "Deleted value from head" << endl;
        } else if (op == 6) {
            cout << "Enter the position: ";
            int pos;
            cin >> pos;
            delete_from_pos(head, pos);
            cout << "Deleted value from position " << pos << endl;
        } else if (op == 7) {
            cout << "The linked list: ";
            print_linked_list(head);
        } else if (op == 8) {
            break;
        }
    }

    return 0;
}
