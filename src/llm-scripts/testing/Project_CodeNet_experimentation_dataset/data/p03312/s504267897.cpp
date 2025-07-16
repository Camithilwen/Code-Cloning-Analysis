#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(n);i++)
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
const int INF=1e9;
const int MOD=1e9+7;
const double pi=acos(-1);


int main(){
  int n;
  cin >> n;
  ll s[200010];
  s[0]=0;
  rep(i,n){
    ll a;
    cin >> a;
    s[i+1]=s[i]+a;
  }
  
  ll ans=1e18;
  for(int i=2;i<n-1;i++){
    ll *l,*r;
    ll gap;
    l=lower_bound(s+1,s+i+1,s[i]/2+1);
    r=lower_bound(s+i+1,s+n+1,(s[n]+s[i])/2+1);
    rep(j,2){
      rep(k,2){
        gap=max({*l,s[i]-*l,*r-s[i],s[n]-*r})-min({*l,s[i]-*l,*r-s[i],s[n]-*r});
        ans=min(ans,gap);
        l--;
      }
      l+=2;
      r--;
    }
  }
  cout << ans << endl;
}
