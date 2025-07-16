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
  ll n;
  cin >> n;
  auto divs = divisor(n);
  sort(divs.begin(), divs.end());
  ll left = -1;
  ll right = divs.size();
  while (right - left > 1) {
    ll mid = left + (right - left) / 2;
    ll v1 = divs[mid];
    ll v2 = n / divs[mid];
    if (to_string(v1).size() >= to_string(v2).size())
      right = mid;
    else
      left = mid;
  }
  ll v1 = divs[right];
  ll v2 = n / divs[right];
  cout << max(to_string(v1).size(), to_string(v2).size()) << endl;
  return 0;
}