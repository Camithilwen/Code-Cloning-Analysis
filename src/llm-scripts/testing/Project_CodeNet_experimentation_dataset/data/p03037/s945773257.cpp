#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n); for(ll i = 0; i < (ll)n; i++)

int main() {
  int n,m; cin >> n >> m;
  int l,u; l = 0; u = (int)1e6;
  rep(i, m){
    int p, q; cin >> p >> q;
    if(l < p) l = p;
    if(q < u) u = q;
  }
  
  cout << max(u - l + 1, 0) << endl;
}