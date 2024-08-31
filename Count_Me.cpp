#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    cin.ignore(); 

    while(T--) {
        string S;
        getline(cin, S);
        map<string, int> mp;
        stringstream ss(S);
        string word;
        string frequentword;
        int max = 0;

        while (ss >> word) {
            mp[word]++;
            if (mp[word] > max) {
                max = mp[word];
                frequentword = word;
            }
        }

        cout << frequentword << " " << max << endl;
    }

    return 0;
}
