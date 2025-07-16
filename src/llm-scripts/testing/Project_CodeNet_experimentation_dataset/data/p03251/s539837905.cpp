#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
#define rep(i,n) for(int i=0;i<(n);i++)


int main(){
    int n,m,x,y;
    cin>>n>>m>>x>>y;
    vector<int>a(n);
    vector<int>b(m);
    rep(i,n)cin>>a[i];
    rep(i,m) cin>>b[i];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    if(max(a[n-1],x)<min(b[0],y))cout<<"No War"<<endl;
    else cout<<"War"<<endl;
}