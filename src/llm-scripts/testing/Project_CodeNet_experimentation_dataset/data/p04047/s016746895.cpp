#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> l(n*2);
    rep(i,n*2) cin>>l.at(i);
    sort(l.begin(),l.end());
    int ans=0;
    rep(i,n){
        ans+=l.at(2*i);
    }
    cout<<ans;
}