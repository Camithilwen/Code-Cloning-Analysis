#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <vector>
typedef long long ll;
const int maxn = 1e5 + 5;
const ll mod = 1e9 + 7;
const double PI = acos(-1.0);
ll a[maxn];

int main (int argc, char **argv) {
  int n;
  std::cin >> n;
  int cnt = 0;
  for (int i=1; i <= n; i++) {
    std::cin >> a[i];
    if (a[i] < 0) {
      cnt++;
    }
  }
  
  ll ans = 0;
  if (cnt&1) {
    ll min_val = a[1] > 0 ? a[1]:-a[1];
    for (int i=2; i <= n; i++) {
      min_val = std::min(min_val, a[i] > 0 ? a[i]:-a[i]);
    }
    ans -= 2*min_val;
  } 
  
  for (int i=1; i <= n; i++) {
    if (a[i] < 0) {
      ans -= a[i];  
    } else {
      ans += a[i];
    }
  }
  std::cout << ans << std::endl;
  return 0;
}
