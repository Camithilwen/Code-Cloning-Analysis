#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define rrep(ri,n) for(int ri = (int)(n-1); ri >= 0; ri--)
#define rep2(i,x,n) for(int i = (int)(x); i < (int)(n); i++)
#define rrep2(ri,x,n) for(int ri = (int)(n-1); ri >= (int)(x); ri--)
#define repit(itr,x) for(auto itr = x.begin(); itr != x.end(); itr++)
#define rrepit(ritr,x) for(auto ritr = x.rbegin(); ritr != x.rend(); ritr++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  ll ans = 1001001001;
  for(ll i = 1; i*i <= m; i++){
    if(m % i != 0) continue;
    ll j = m / i;
    if(i >= n){
      ans = min(ans, i);
    }
    if(j >= n){
      ans = min(ans, j);
    }
  }
  if(ans == 1001001001) ans = m;
  ans = m/ans;
  cout << ans << endl;
  return 0;
}