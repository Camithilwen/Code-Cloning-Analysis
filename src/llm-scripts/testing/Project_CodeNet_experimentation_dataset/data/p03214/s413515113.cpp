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
  ll n, sum = 0;
  cin >> n;
  vd a(n);
  rep(i, n) {
    cin >> a[i];
    sum += a[i];
    a[i] *= n;
  }
  ll ans, d = 1e18;
  rep(i, n) {
    ll nd = abs(sum - a[i]);
    if(nd < d) {
      d = nd;
      ans = i;
    }
  }
  cout << ans << endl;
}