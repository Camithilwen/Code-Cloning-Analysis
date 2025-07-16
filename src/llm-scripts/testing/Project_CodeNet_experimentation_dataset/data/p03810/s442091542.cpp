#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <random>
#include <iomanip>
#include <functional>
#include <cassert>
 
using namespace std;
 
typedef long long ll;

int gcd(int a, int b) {
  return (b == 0 ? a : gcd(b, a % b));
}
 
int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  vector <int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  function <int(vector <int>)> get = [&] (vector <int> v) {
    ll sum = 0;
    for (int i = 0; i < n; ++i) sum += v[i] - 1;
    if (sum % 2 == 1) return 0;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      if (v[i] % 2 == 1) {
        if (v[i] == 1) {
          cnt += 2;
        } else {
          ++cnt;
        }
      }
    }
    if (cnt != 1) {
      return 1;
    } else {
      int g = 0;
      for (int i = 0; i < n; ++i) {
        if (v[i] % 2 == 1) {
          --v[i];
        }
        g = gcd(g, v[i]);
      }
      for (int i = 0; i < n; ++i) v[i] /= g;
      return 1 ^ get(v);
    }
  };
  if (get(a) == 0) {
    cout << "First\n";
  } else {
    cout << "Second\n";
  }
}
