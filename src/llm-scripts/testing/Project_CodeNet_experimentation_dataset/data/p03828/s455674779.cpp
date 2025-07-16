#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>
#define rep(i, f, n) for (ll i = (f); i < (ll)(n); i++)
#define repe(i, f, n) for (ll i = (f); i <= (ll)(n); i++)
#define accum(x) accumulate((x).begin(), (x).end(), 0)
using namespace std;
using ll = long long;
using pint = pair<int, int>;

const ll MOD = 1e9 + 7;

int a[1001];

void f(int X) {
  int x = X;
  for (int i = 2; i * i <= X; i++) {
    if (x % i != 0) continue;
    while (x % i == 0) {
      a[i]++;
      x /= i;
    }
  }
  if (x != 1) a[x]++;
}

int main() {
  int n;
  cin >> n;

  repe(i, 2, n) f(i);

  ll ans = 1;
  repe(i, 2, n) {
    if (a[i] == 0) continue;
    ans *= a[i] + 1;
    ans %= MOD;
  }

  cout << ans << endl;

  return 0;
}
