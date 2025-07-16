#include <bits/stdc++.h>
using namespace std;
 
using ll = int64_t;
constexpr ll mod = ll(1e9 + 7);
 
int main () {
  ios::sync_with_stdio(0); cin.tie(0);
 
  int TT = 1;
  // cin >> TT;
  while (TT--) {
    ll n,h,w;
    cin >> n >> h >> w;
    --h;
    --w;
    cout << max(ll(0), ((n-h)*(n-w))) << endl;
  }
}
