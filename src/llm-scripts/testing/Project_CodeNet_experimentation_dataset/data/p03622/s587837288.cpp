#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#define N 1001000
typedef long long ll; 
template<typename T> inline void read(T &x) {
  x = 0; char c = getchar(); bool flag = false;
  while (!isdigit(c)) { if (c == '-') flag = true; c = getchar(); }
  while (isdigit(c)) { x = (x << 1) + (x << 3) + (c ^ 48); c = getchar(); }
  if (flag) x = -x; 
}
using namespace std;
const int P = 998244353;
inline ll quickpow(ll x, int k) {
  ll res = 1;
  while (k) {
    if (k & 1)  res = res * x % P;
    x = x * x % P;
    k >>= 1;
  }
  return res;
}
int n, m;
ll jie[N], jieni[N];
inline void init() {
  int up = n + m;
  jie[0] = jieni[0] = 1;
  for (int i = 1; i <= up; ++i) jie[i] = jie[i - 1] * i % P;
  jieni[up] = quickpow(jie[up], P - 2); 
  for (int i = up - 1; i; --i)  jieni[i] = jieni[i + 1] * (i + 1) % P;
}
inline ll get_c(int n, int m) {
  ll res = jie[n] * jieni[m] % P * jieni[n - m] % P;
  return res;
}
inline void work() {
  ll res = 0;
  if (n < m)  swap(n, m); 
  for (int i = 1; i <= m; ++i) {
    res = (res + get_c(i + i - 1, i) * get_c(n - i + m - i, n - i)) % P;
  }
  res = (res + n * get_c(n + m, n)) % P;
  res = res * quickpow(get_c(n + m, n), P - 2) % P;
  printf("%lld\n", (res % P + P) % P); 
}
int main() {
  read(n), read(m); init();
  work();
  return 0;
}
