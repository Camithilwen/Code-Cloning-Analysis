#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 998244353;

ll Ep(int x, int y){
  if(y == 1) return x;
  ll r = Ep(x,y/2);
  if(y%2 == 1) return r *r%MOD *x%MOD;
  else return r *r%MOD;
}

int main(){
  int n, x;
  cin >> n;
  cin >> x;
  if(x != 0){
    cout << 0 << endl;
    return 0;
  }
  map<int, int> mp;
  for(int i=1; i<n; ++i){
    cin >> x;
    if(x == 0){
      cout << 0 << endl;
      return 0;
    }
    ++mp[x];
  }
  ll ans = 1;
  for(auto p: mp){
    if(p.first == 1) continue;
    ans *= Ep(mp[p.first-1], p.second);
    ans %= MOD;
  }
  cout << ans << endl;
}