#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(void){
  int n;
  cin>>n;
  vector<ll> a(n),b(n),c(n);
  for(int i=0;i<n;i++){
    cin>>a[i];
  }
  for(int i=0;i<n;i++){
    cin>>b[i];
  }
  for(int i=0;i<n;i++){
    cin>>c[i];
  }
  sort(a.begin(),a.end());
  sort(c.begin(),c.end());
  ll ans=0;
  for(int i=0;i<n;i++){
    auto it=lower_bound(a.begin(),a.end(),b[i]);
    ll Adis=distance(a.begin(),it);
    it=upper_bound(c.begin(),c.end(),b[i]);
    ll Cdis=distance(it,c.end());
    ans+=(Adis*Cdis);
  }
  cout<<ans<<endl;
  return 0;
}