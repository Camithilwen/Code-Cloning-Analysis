#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define REP(i, n) for (ll i = 0; i < n; i++)
#define INF 9223372036854775807
#define all(x) (x).begin(), (x).end()

ll ts = 1000000007;

int main() {
  ll a, b, c, k;
  cin >> a >> b >> c >> k;
  cout << a + b + c + max(a, max(b, c)) * ((1 << k) - 1) << endl;
}