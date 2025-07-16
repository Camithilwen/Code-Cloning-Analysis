#include <bits/stdc++.h>
#define ri register int
using namespace std;
const int rlen = 1 << 20 | 5;
char buf[rlen], *ib = buf, *ob = buf;
#define gc() (((ib == ob) && (ob = (ib = buf) + fread(buf, 1, rlen, stdin))), ib == ob ? -1 : *ib++)
#define pb push_back
#define rez resize
#define fi first
#define se second
typedef long long ll;
typedef pair <int, int> pii;
inline int read() {
  static int ans, f;
  static char ch;
  for (ans = 0, f = 1, ch = gc(); !isdigit(ch); ch = gc()) f ^= ch == '-';
  while (isdigit(ch)) ans = ((ans << 2) + ans << 1) + (ch ^ 48), ch = gc();
  return f ? ans : -ans;
}
const int N = 2e5 + 5;
int n, m, a, b;
int main() {
  #ifdef ldxcaicai
  freopen("lx.in", "r", stdin);
  #endif
  n = read(), m = read(), a = read(), b = read();
  for (ri i = 1; i <= n; ++i, puts("")) for (ri j = 1; j <= m; ++j) cout << ((j <= a) ^ (i <= b));
  return 0;
}