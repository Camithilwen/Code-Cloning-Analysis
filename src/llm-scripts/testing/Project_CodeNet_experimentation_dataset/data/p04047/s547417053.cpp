#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    long long a;
    cin>>a;
    vector<long long>v(2*a);
    for(long long i=0;i<2*a;i++){
         cin>>v[i];
    }
    priority_queue<long long> p(v.begin(),v.end());
    long long sum=0;
    while(!p.empty()){
        p.pop();
        sum+=p.top();
        p.pop();
    }
    cout<<sum;
}