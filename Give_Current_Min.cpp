#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    priority_queue<int, vector<int>, greater<int>> A;

    while (N--) {
        int X;
        cin >> X;
        A.push(X);
    }

    int Q;
    cin >> Q;

    while (Q--) {
        int command;
        cin >> command;

        if (command == 1) {
            if (A.empty()) {
                cout << "Empty" << endl;
            } else {
                cout << A.top() << endl;
            }
        } else if (command == 0) {
            int X;
            cin >> X;
            A.push(X);
            cout << A.top() << endl;
        } else if (command == 2) {
            if (A.empty()) {
                cout << "Empty" << endl;
            } else {
                A.pop();
                if (A.empty()) {
                    cout << "Empty" << endl;
                } else {
                    cout << A.top() << endl;
                }
            }
        }
    }

    return 0;
}
