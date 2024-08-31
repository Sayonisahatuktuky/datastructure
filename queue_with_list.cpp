#include<bits/stdc++.h>
using namespace std;

 class myqueue
 {
public:
    list<int>l;
    void push(int val){
        l.push_back();
    }
    void pop(){
       l.pop_front();
    }
    int front(){
        return l.front();
    }
    int size(){
        return l.size();
    }
    bool empty(){
        return l.empty();

    }
 };
 
int main()
{
    myqueue qu;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        qu.push(x);
    }
    while(!qu.empty()){
        cout<<qu.front()<<endl;
        qu.pop();
    }
    if(!qu.empty()){
        cout<<qu.front();
    }
 
  return 0;
}