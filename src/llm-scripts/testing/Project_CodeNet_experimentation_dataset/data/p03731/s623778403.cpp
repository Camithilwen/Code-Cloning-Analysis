#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll=long long;
using Graph=vector<vector<ll>>;
int main(){
  ll n,t;cin>>n>>t;
  vector<ll> ti(n);
  rep(i,n)cin>>ti[i];
  ll c=t;
  for(int i=n-1;i>0;--i){
    c+=min(t,ti[i]-ti[i-1]);
  }
  cout<<c;
}