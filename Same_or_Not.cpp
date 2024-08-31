#include<bits/stdc++.h>
using namespace std;
 
int main()
{
 int N,M;
 cin>>N>>M;
 stack<int>s;
 queue<int>q;

 for(int i=0;i<N;i++){
        int x;
        cin>>x;
        s.push(x);
    }
 for(int i=0;i<M;i++){
        int x;
        cin>>x;
        q.push(x);
    }

    if(N!=M){
        cout<<"NO"<<endl;
        return 0;
    }
    while(!s.empty()&&!q.empty()){
        if(s.top()!=q.front()){
            break;
        }
        s.pop();
        q.pop();
    }
    if(s.empty()&&q.empty()){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
  return 0;
}