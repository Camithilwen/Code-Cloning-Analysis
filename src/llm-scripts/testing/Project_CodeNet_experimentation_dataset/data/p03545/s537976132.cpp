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
  string s;
  cin >> s;
  rep(i, 1 << 3) {
    ll n = s[0] - '0';
    rep(j, 3) {
      if(i >> j & 1)
        n += s[j + 1] - '0';
      else
        n -= s[j + 1] - '0';
    }
    if(n != 7) continue;
    cout << s[0];
    rep(j, 3) cout << (i >> j & 1 ? '+' : '-') << s[j + 1];
    cout << "=7" << endl;
    return 0;
  }
}