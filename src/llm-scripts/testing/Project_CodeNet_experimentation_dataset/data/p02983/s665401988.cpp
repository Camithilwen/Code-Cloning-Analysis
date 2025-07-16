#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
int main() {
  ll l, r;
  cin >> l >> r;
  if(r - l >= 2019){
    cout << 0;
  }
  else{
    ll ans = 2018;
    for(long long i = l; i <= r - 1; i++){
      for(long long j = i + 1; j <= r; j++){
        ll a, b;
        a = i % 2019;
        b = j % 2019;
        
        ll x;
        x = (a * b) % 2019;
        
        ans = min(ans, x);
      }
    }
   cout << ans;
  }
        
  return 0;
}