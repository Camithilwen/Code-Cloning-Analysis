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

vector<ll> divisor(ll n) {
  vector<ll> res;
  for (ll i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      res.push_back(i);
      if (i != n / i) res.push_back(n / i);
    }
  }
  return res;
}

int main() {
  ll N, M;
  cin >> N >> M;
  vector<ll> divs = divisor(M);
  ll ans = 1;
  for (int i = 0; i < divs.size(); i++) {
    if (M / divs[i] >= N) ans = max(ans, divs[i]);
  }
  cout << ans << endl;
  return 0;
}