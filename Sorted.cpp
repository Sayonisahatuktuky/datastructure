#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        set<int> A;

        while(N--) {
            int x;
            cin >> x;
            A.insert(x); 
        }

        for (auto it = A.begin(); it != A.end(); ++it) {
            cout << *it<<" ";
        }
        cout << endl;
    }

    return 0;
}
