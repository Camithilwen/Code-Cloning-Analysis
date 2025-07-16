#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  ll a, b, k;
  cin >> a >> b >> k;
  rep(i, k) {
    if (i%2) {
      if (b%2) {
        b--;
        a += b/2;
        b /= 2;
      } else {
        a += b/2;
        b /= 2;
      }
    } else {
      if (a%2) {
        a--;
        b += a/2;
        a /= 2;
      } else {
        b += a/2;
        a /= 2;
      }
    }
  }
  cout << a << ' ' << b << endl;
}