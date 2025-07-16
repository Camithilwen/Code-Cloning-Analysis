#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll N, Q;
  cin >> N >> Q;

  fenwick_tree<ll> ft(N);

  for(ll i = 0; i < N; ++i) {
    ll ai;
    cin >> ai;
    ft.add(i, ai);
  }

  for(;Q-->0;) {
    ll op;
    cin >> op;
    if (op) {
      ll l, r;
      cin >> l >> r;
      cout << ft.sum(l, r) << endl;
    } else {
      ll p, x;
      cin >> p >> x;
      ft.add(p, x);
    }
  }
  return 0;
}
