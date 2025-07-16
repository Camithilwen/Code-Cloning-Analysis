#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  int max_a = *max_element(a.begin(), a.end());
  int g = a[0];
  rep(i, n) g = gcd(g, a[i]);
  // cerr << g << " " << max_a << endl;
  if (k % g == 0 && k <= max_a) {
    cout << "POSSIBLE" << endl;
  } else {
    cout << "IMPOSSIBLE" << endl;
  }
  return 0;
}
