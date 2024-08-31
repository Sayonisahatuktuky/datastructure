#include <iostream>
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

class MyStack {
public:
    Node* head=NULL;
    int sz=0;
    
    void push(int val) {
        sz++;
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }
    
    void pop() {
        if (sz == 0) return;
        sz--;
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    
    int top() { 
        return head->val;
    }
    
    int size() {
        return sz;
    }
    
    bool empty() {
        return sz == 0;
    }
};

class MyQueue {
public:
    Node* head=NULL;
    Node* tail=NULL;
    int sz=0;
    
    void push(int val) {
        sz++;
        Node* newNode = new Node(val);
        if (tail != NULL) {
            tail->next = newNode;
        }
        tail = newNode;
        if (head == NULL) {
            head = newNode;
        }
    }
    
    void pop() {
        if (sz == 0) return;
        sz--;
        Node* temp = head;
        head = head->next;
        if (head == NULL) {
            tail = NULL;
        }
        delete temp;
    }
    
    int front() {
        return head->val;
    }
    
    int size() {
        return sz;
    }
    
    bool empty() {
        return sz == 0;
    }
};

int main() {
    int N, M;
    cin >> N >> M;

    MyStack s;
    MyQueue q;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        s.push(x);
    }

    for (int i = 0; i < M; i++) {
        int x;
        cin >> x;
        q.push(x);
    }

    if (s.size() != q.size()) {
        cout << "NO" << endl;
        return 0;
    }

    bool flag = true;
    while (!s.empty() && !q.empty()) {
        if (s.top() != q.front()) {
            flag = false;
            break;
        }
        s.pop();
        q.pop();
    }

    if (flag && s.empty() && q.empty()) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
