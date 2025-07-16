#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for (ll i=0; i<n; ++i)
#define all(c) begin(c),end(c)
/*

*/
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  
  ll N,M; cin>>N>>M;
  if(M==0){
    if (N==1)
      cout<<0<<endl;
    if (N==2)
      cout<<10<<endl;
    if (N==3)
      cout<<100<<endl;
    return 0;
  }
  vector<pair<ll,ll>> Z(M,{0,0});
  rep(i, M){
    ll s,c; cin>>s>>c;
    Z[i]={N-s,c};
  }
  ll end=1;
  ll low = 1;
  rep(i,N) end *= 10;
  low = end/10;
  if (low < 10) low = 0;
  for(ll i=low; i<=end; i++){
    ll a,b,c;
    a = i/100;
    b = (i/10)%10;
    c = i%10;
    rep(j,M){
      ll z1=Z[j].first, z2=Z[j].second;
      if (z1 == 0 && c != z2)
        break;
      if (z1 == 1 && b != z2)
        break;
      if (z1 == 2 && a != z2)
        break;
      if (j==M-1){
        cout <<i <<endl;
        return 0;
      }
    }
  }
  cout <<-1 <<endl;
}
