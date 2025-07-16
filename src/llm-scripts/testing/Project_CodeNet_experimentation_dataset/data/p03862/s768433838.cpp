#ifndef _TEMPLATE_ROOT
#define _TEMPLATE_ROOT
#include "bits/stdc++.h"
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define repl(i, a, b) for(ll i = a; i < (b); ++i)
#define repd(i, a, b) for(int i = a; i >= (b); --i)
#define repdl(i, a, b) for(ll i = a; i >= (b); --i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
template<typename H> bool chmin(H& v1, const H v2) { if (v1 > v2) { v1 = v2; return true; } return false; }
template<typename H> bool chmax(H& v1, const H v2) { if (v1 < v2) { v1 = v2; return true; } return false; }
#endif
#ifndef _TEMPLATE_IO
#define _TEMPLATE_IO

template<typename H> void read(H& head) { cin >> head; }
template<typename H, typename ...T> void read(H& head, T& ...tail) { cin >> head; read(tail...); }
template<typename H> void write(H head) { cout << head << '\n'; }
template<typename H, typename ...T> void write(H head, T ...tail) { cout << head << " "; write(tail...); }
template<typename ...T> void writef(T ...tail) { write(tail...); cout << flush; }
template<typename ...T> void die(T ...tok) { write(tok...); exit(0); }
template<typename T>
ostream& operator<<(ostream& out, const vector<T>& v) {
  if (v.size()) {
    rep(i, 0, sz(v) - 1)
      out << v[i] << " ";
    out << v.back();
  }
  return out;
}
#endif
using namespace std;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

  int n; ll x;
  read(n, x);
  ll a[n];
  rep(i, 0, n) read(a[i]);
  ll ans = 0;
  if (a[0] > x) {
    ans += a[0] - x;
    a[0] = x;
  }
  rep(i, 1, n) {
    if (a[i] + a[i - 1] > x) {
      ll d = a[i] + a[i - 1] - x;
      a[i] -= d;
      ans += d;
    }
  }
  write(ans);
}

