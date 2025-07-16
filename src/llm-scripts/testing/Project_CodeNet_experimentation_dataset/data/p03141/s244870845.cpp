#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define INF 1000000000
#define LLINF 10000000000000000ll
#define MOD 1000000007LL

bool dbgflag = false;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<pll> each(n);
  vector<pll> dish;
  for (int i = 0; i < n; i++) {
    ll a, b;
    cin >> a >> b;
    each[i] = pll(a, b);
    dish.emplace_back(pll(a+b, i));
  }

  sort(dish.begin(), dish.end());
  reverse(dish.begin(), dish.end());
  
  ll d = 0;
  bool flag = true;
  for (pll ds: dish) {
    if (flag) d += each[ds.second].first;
    else d -= each[ds.second].second;
    flag = !flag;
  }
  
  cout << d << endl;
}
