#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
#define fir first
#define sec second
#define rep(i,a,b) for (int i = (a) ; i <= (b) ; ++ i)
#define rrp(i,a,b) for (int i = (a) ; i >= (b) ; -- i)
#define gc() getchar()
template <typename tp>
inline void read(tp& x) {
  x = 0; char tmp; bool key = 0;
  for (tmp = gc() ; !isdigit(tmp) ; tmp = gc())
    key = (tmp == '-');
  for ( ; isdigit(tmp) ; tmp = gc())
    x = (x << 3) + (x << 1) + (tmp ^ '0');
  if (key) x = -x;
}
template <typename tp>
inline void ckmn(tp& x,tp y) {
  x = x < y ? x : y;
}
template <typename tp>
inline void ckmx(tp& x,tp y) {
  x = x < y ? y : x;
}

const int MOD = 998244353;
inline void Add(int& x,int y) {
  x = x + y >= MOD ? x + y - MOD : x + y;
}
inline void Sub(int& x,int y) {
  x = x - y < 0 ? x - y + MOD : x - y;
}
int power(int a,int b) {
  int ret = 1;
  while (b) {
    if (b&1) ret = 1ll * ret * a % MOD;
    a = 1ll * a * a % MOD;
    b >>= 1;
  }
  return ret;
}
const int N = 3000000;
int jc[N], ijc[N], n, m, ans;
void init(int t) {
  jc[0] = 1;
  rep (i, 1, t) jc[i] = 1ll * jc[i-1] * i % MOD;
  ijc[t] = power(jc[t], MOD - 2);
  rrp (i, t-1, 0) ijc[i] = 1ll * ijc[i+1] * (i+1) % MOD;
}
int comb(int a,int b) {
  if (a < b || b < 0) return 0;
  return 1ll * jc[a] * ijc[b] % MOD * ijc[a-b] % MOD;
}
int main() {
  read(n), read(m);
  init(n + 3 * m);
  rep (i, 0, min(n, m)) if ((m-i) % 2 == 0) {
    Add(ans, 1ll * comb(n, i) * comb((3 * m - i) / 2 + n - 1, n - 1) % MOD);
    if (i <= m-2)
      Sub(ans, 1ll * n * comb(n-1,i) % MOD * comb((3*m-i-2*(m+1)) / 2 + n - 1, n - 1) % MOD);
    if (i <= m)
      Sub(ans, 1ll * n * comb(n-1,i-1) % MOD * comb((3*m-i-2*m)/2 + n-1, n-1) % MOD);
  }
  printf("%d\n", ans);
  return 0;
}
