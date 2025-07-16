#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  ll n;cin>>n;
  int ans=1e9;
  for(int i=1;i<=sqrt(n);i++){
    if(n%i!=0)continue;
    ll j=n/i;
    string I=to_string(i),J=to_string(j);
    int a=I.size(),b=J.size();
    int f=max(a,b);
    ans=min(ans,f);
  }
  cout<<ans<<endl;
}