#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i,n) for(int i=0;i<n;i++)
const ll MOD=1000000007;
const long double PI=3.14159265358979;
const ll MAX=0;

int main() {
  ll a,b,m;
  cin>>a>>b>>m;
  ll A[a];ll B[b];ll Maxa=MOD,Maxb=MOD;
  rep(i,a){
    cin>>A[i];
    Maxa=min(Maxa,A[i]);
  }
  rep(i,b){
    cin>>B[i];
    Maxb=min(Maxb,B[i]);
  }
  ll ans=Maxa+Maxb;
  rep(i,m){
    ll x,y,c;
    cin>>x>>y>>c;
    ans=min(ans,A[x-1]+B[y-1]-c);
  }
  cout<<ans;
}
