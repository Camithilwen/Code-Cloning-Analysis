#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0, i##_len = (n); i < i##_len; ++i)
#define rep2(i, x, n) for(int i = x, i##_len = (n); i < i##_len; ++i)
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
  if(n == 0) {
    cout << 0 << endl;
    return 0;
  }
  vl v(62, 0);
  rep(i, 62) v[i] = pow(2, i);
  ll now = 0;
  vl ans(62, 0);
  ll i = 0;
  if(n < 0) {
    n = abs(n);
    i = 1;
  }
  for(; now < n; i += 2) {
    now += v[i];
    ans[i] = 1;
  }
  for(; i >= 0; i--) {
    if(now - v[i] >= n) {
      now -= v[i];
      ans[i] = 1 - ans[i];
    }
  }
  reverse(all(ans));
  bool ok = false;
  rep(i, 62) {
    if(ans[i] == 1) ok = true;
    if(ok) cout << ans[i];
  }
  cout << endl;
}