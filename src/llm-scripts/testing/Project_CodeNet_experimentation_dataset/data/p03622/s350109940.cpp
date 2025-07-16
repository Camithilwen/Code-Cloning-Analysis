#include <bits/stdc++.h>

using namespace std;

const int md = 998244353;

inline void add(int &a, int b) {
  a += b;
  if (a >= md) {
    a -= md;
  }
}

inline int mul(int a, int b) {
  return (long long) a * b % md;
}

inline int power(int a, int b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = mul(res, a);
    }
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}

inline int inv(int x) {
  return power(x, md - 2);
}

const int N = 2000010;

int fact[N], inv_fact[N];

inline int C(int n, int k) {
  if (k < 0 || k > n) {
    return 0;
  }
  return mul(fact[n], mul(inv_fact[k], inv_fact[n - k]));
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  fact[0] = inv_fact[0] = 1;
  for (int i = 1; i <= n + m; i++) {
    fact[i] = mul(fact[i - 1], i);
    inv_fact[i] = inv(fact[i]);
  }
  int ans = 0;
  int cur = 0;
  int val = C(n + m, n);
  for (int s = 1; s <= n + m; s++) {
    add(cur, val);
    add(ans, mul(cur, inv(s)));
    int x = C(n + m - (s + 1), n - (s + 1) / 2);
    int y = C(n + m - (s + 1), m - (s + 1) / 2);
    int z = C(s - 1, s / 2);
    int ways = mul(z, x + y);
    if (s % 2 == 0) {
      add(val, ways);
    } else {
      add(val, md - ways);
    }
  }
  ans = mul(ans, inv(C(n + m, n)));
  printf("%d\n", ans);
  cerr << "time = " << clock() << " ms" << endl;
  return 0;
}
