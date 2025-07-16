#include <bits/stdc++.h>
#define INF 5000000000000000000
#define ll long long
#define pll pair<ll, ll>
using namespace std;

int main() {
  ll a, b;
  cin >> a >> b;
  ll ans = max(a + b, a - b);
  ans = max(ans, a * b);
  cout << ans << endl;
}