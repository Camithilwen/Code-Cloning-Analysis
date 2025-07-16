#include <algorithm>
#include <bitset>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <vector>
#define ll long long
using namespace std;
const int MOD = 1000000007;
const long long INF = 1LL << 60;
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll n;
  cin >> n;
  vector<ll> a(n);
  bool flag = false;
  ll m = INF;
  ll cnt = 0;
  for (ll i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == 0) {
      flag = true;
    }
    if (a[i] < 0) cnt++;
    m = min(m, abs(a[i]));
  }

  if (flag || cnt % 2 == 0) {
    ll num = 0;
    for (ll i = 0; i < n; i++) {
      num += abs(a[i]);
    }
    cout << num << endl;
    return 0;
  } else {
    ll num = 0;
    for (ll i = 0; i < n; i++) {
      num += abs(a[i]);
    }
    num -= 2 * m;
    cout << num << endl;
  }
}