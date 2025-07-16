#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main () {
  ll x; cin >> x; ll ans = (x / 11) * 2, b = x % 11;
  if (b > 6) ans += 2;
  else if (b > 0) ans++;
  cout << ans << endl;
}                                                