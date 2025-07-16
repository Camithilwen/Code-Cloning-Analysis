#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(ll i = 0, i##_len = (n); i < i##_len; ++i)
#define rep2(i, x, n) for(ll i = x, i##_len = (n); i < i##_len; ++i)
#define all(n) begin(n), end(n)
using ll = long long;
using P = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;
using vd = vector<double>;
vi dir = {-1, 0, 1, 0, -1, -1, 1, 1, -1};

int main() {
  ll n;
  cin >> n;
  vl a(n);
  rep(i, n) cin >> a[i];
  bool ok = true;
  if(a[0] != 0) ok = false;
  rep(i, n - 1) if(a[i] + 1 < a[i + 1]) ok = false;
  if(!ok) {
    cout << -1 << endl;
    return 0;
  }
  ll ans = 0;
  rep(i, n - 1) {
    if(a[i + 1] - 1 == a[i])
      ans++;
    else
      ans += a[i + 1];
  }
  cout << ans << endl;
}