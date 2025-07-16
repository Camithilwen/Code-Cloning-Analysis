#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;
ll const INF = 1LL << 60;
ll search(ll l, ll r) {
  ll ret = INF;
  for (ll i = l; i <= r; i++) {
    for (ll j = i + 1; j <= r; j++) {
      ret = min((i * j) % 2019, ret);
    }
  }
  return ret;
}
int main() {
  ll l, r;
  cin >> l >> r;
  if (l <= 2019 && 2019 <= r) {
    cout << 0 << endl;
  } else if (l < 2019 && r < 2019) {
    cout << search(l, r) << endl;
  } else if (r - l < 2019) {
    cout << search(l, r) << endl;
  } else {
    cout << 0 << endl;
  }
  return 0;
}