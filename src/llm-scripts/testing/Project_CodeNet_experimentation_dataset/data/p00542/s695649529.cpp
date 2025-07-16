#include<iostream>
#include<queue>
using namespace std;

int main(){
    priority_queue<int>q1,q2;
    int a,b;
    for(int i=0;i<4;i++){
        cin>>a;
        q1.push(a);
    }
    for(int i=0;i<2;i++){
        cin>>a;
        q2.push(a);
    }
    for(int i=0;i<3;i++){
        b+=q1.top();
        q1.pop();
    }
    cout<<b+q2.top()<<endl;
}