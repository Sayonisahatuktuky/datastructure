#include <bits/stdc++.h>
using namespace std;

class Student {
public:
    string name;
    int roll;
    int marks;

    Student(string name, int roll, int marks) {
        this->name = name;
        this->roll = roll;
        this->marks = marks;
    }
};

class cmp {
public:
    bool operator()(Student& a, Student& b) {
        if (a.marks != b.marks)
            return a.marks < b.marks; 
        return a.roll > b.roll;  
    }
};

int main() {
    int N;
    cin >> N;

    priority_queue<Student, vector<Student>, cmp> pq;

    for (int i = 0; i < N; ++i) {
        string name;
        int roll, marks;
        cin >> name >> roll >> marks;
        Student obj(name, roll, marks);
        pq.push(obj);
    }

    int Q;
    cin >> Q;

    while (Q--) {
        int command;
        cin >> command;

        if (command == 1) {
            if (pq.empty()) {
                cout << "Empty" << endl;
            } else {
                Student top = pq.top();
                cout << top.name << " " << top.roll << " " << top.marks << endl;
            }
        } else if (command == 2) {
            if (pq.empty()) {
                cout << "Empty" << endl;
            } else {
                pq.pop(); 
                if (pq.empty()) {
                    cout << "Empty" << endl;
                } else {
                    Student top = pq.top();
                    cout << top.name << " " << top.roll << " " << top.marks << endl;
                }
            }
        } else if (command == 0) {
            string name;
            int roll, marks;
            cin >> name >> roll >> marks;
            Student s(name, roll, marks);
            pq.push(s);
            Student top = pq.top();
            cout << top.name << " " << top.roll << " " << top.marks << endl;
        }
    }

    return 0;
}
