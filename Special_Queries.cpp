#include<bits/stdc++.h>
using namespace std;
 
int main()
{
  int Q;
    cin >> Q;
    queue<string> q;
    
    for (int i = 0; i < Q; ++i) {
        int cmd;
        cin >> cmd;
        
        if (cmd == 0) {
            string name;
            cin >> name;
            q.push(name);
        } else if (cmd == 1) {
            if (q.empty()) {
                cout << "Invalid" << endl;
            } else {
                cout << q.front() << endl;
                q.pop();
            }
        }
    }
  return 0;
}
