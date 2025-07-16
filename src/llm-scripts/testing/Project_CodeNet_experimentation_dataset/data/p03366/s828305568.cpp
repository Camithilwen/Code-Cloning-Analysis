#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for (int i = (a); i <= (b); ++ i)
#define rrp(i,a,b) for (int i = (a); i >= (b); -- i)
#define gc() getchar()
#define fir first
#define sec second
typedef pair<int,int> pii;
typedef double db;
typedef long long ll;
template <typename tp>
inline void read(tp& x) {
  x = 0; char tmp; bool key = 0;
  for (tmp = gc(); !isdigit(tmp); tmp = gc())
    key = (tmp == '-');
  for (; isdigit(tmp); tmp = gc())
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

const int N = 100010;
int n, s, x[N], m;
ll p[N];
pair<int,ll> solve(int l,int r) {
  if (l > m) return make_pair(x[r], x[r] - s);
  if (r <= m) return make_pair(x[l], s - x[l]);
  if (p[r] <= p[l]) {
    p[l] += p[r];
    pair<int,ll> tmp = solve(l, r-1);
    return make_pair(x[r], tmp.sec + x[r] - tmp.fir);
  } else {
    p[r] += p[l];
    pair<int,ll> tmp = solve(l+1, r);
    return make_pair(x[l], tmp.sec + tmp.fir - x[l]);
  }
}
int main() {
  read(n), read(s);
  rep (i, 1, n)
    read(x[i]), read(p[i]);
  m = 0;
  while (x[m+1] < s && m < n) ++ m;
  cout << solve(1, n).sec << endl;
  return 0;
}
