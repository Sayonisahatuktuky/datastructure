#include <bits/stdc++.h>
using namespace std;

int main() {
    list<string> mylist;
    string value;

    while (true) {
        cin>>value;
        if(value=="end"){
            break;
        }
        mylist.push_back(value);
    }
    
    int Q;
    cin >> Q;
    string cmd, address;
    auto it = mylist.begin();
    
    for (int i = 0; i < Q; i++) {
        cin >> cmd;
        if (cmd == "visit") {
            cin >> address;
            auto _it = find(mylist.begin(), mylist.end(), address);
            if (_it != mylist.end()) {
                it = _it;
                cout << *it << endl;
            } else {
                cout << "Not Available" << endl;
            }
        } else if (cmd == "next") {
            if (next(it) != mylist.end()) {
                it++;
                cout << *it << endl;
            } else {
                cout << "Not Available" << endl;
            }
        } else if (cmd == "prev") {
            if (it != mylist.begin()) {
                it--;
                cout << *it << endl;
            } else {
                cout << "Not Available" << endl;
            }
        }
    }
    
    return 0;
}
