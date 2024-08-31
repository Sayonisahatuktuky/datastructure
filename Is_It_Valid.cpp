#include<bits/stdc++.h>
using namespace std;
 
int main()
{
 int T;
    cin >> T;
    
    while (T--) {
        string S;
        cin >> S;
        
        stack<char> s;
        
        for (char ch : S) {
            if (!s.empty() && ((s.top() == '0' && ch == '1') || (s.top() == '1' && ch == '0'))) {
                s.pop(); 
            } else {
                s.push(ch); 
            }
        }
        
        if (s.empty()) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
  return 0;
}
