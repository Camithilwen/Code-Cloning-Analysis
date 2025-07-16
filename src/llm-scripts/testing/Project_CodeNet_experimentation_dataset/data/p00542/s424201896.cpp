
#include <bitset>
#include <tuple>
#include <string>
#include <array>
#include <deque>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cstdio>
#include <cmath>
#ifdef LOCAL
  #include <iostream>
#endif
using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)
#define all(v) v.begin(), v.end()

typedef long long ll;

#ifdef LOCAL
  #define debug_echo(e) cout << "L" << __LINE__ << ": " << e << "\n"
  #define debug_repr(e) cout << "L" << __LINE__ << ": " << #e << " -> " << e << "\n"
#else
  #define debug_echo(e)
  #define debug_repr(e)
#endif

#define defread(T, fmt) \
  inline T read_ ## T() { \
    T result; \
    scanf(fmt, &result); \
    return result; \
  }
defread(int, "%d")
defread(ll, "%lld")
defread(float, "%f")
defread(double, "%lf")

int gcd(int m, int n) {
  if ((0 == m) || (0 == n)) return 0;
  while (m != n) {
    if (m > n) m -= n;
    else       n -= m;
  }
  return m;
}
int lcm(int m, int n) {
  if ((0 == m) || (0 == n)) return 0;
  return (m / gcd(m, n)) * n;
}

int main() {
  vector<int> a(4);
  vector<int> b(2);
  a[0] = read_int();
  a[1] = read_int();
  a[2] = read_int();
  a[3] = read_int();
  b[0] = read_int();
  b[1] = read_int();

  sort(all(a));
  sort(all(b));

  printf("%d\n", a[1] + a[2] + a[3] + b[1]);
}