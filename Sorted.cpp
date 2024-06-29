#include<bits/stdc++.h>
using namespace std;
 
int main()
{
 int T;
 cin>>T;
 while(T--){
    int N;
    cin>>N;
    bool flag=false;
    vector<int>A(N);
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    for(int i=1;i<A.size();i++){
        if(A[i-1]>A[i]){
            flag=false;
            break;
        } 
        else flag=true;
    }
    if(flag==true) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
 }
  return 0;
}