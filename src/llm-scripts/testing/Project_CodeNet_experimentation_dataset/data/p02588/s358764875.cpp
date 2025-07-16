#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fir first
#define sec second
#define rep(i,a,b) for (int i = (a); i <= (b); ++ i)
#define rrp(i,a,b) for (int i = (a); i >= (b); -- i)
#define gc() getchar()
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
typedef double db;

const int N = 200010;
int n;
ll val[N];
int n2[N], n5[N], num[20][20];
int main() {
  db tmp;
  read(n);
  rep (i, 1, n) {
    scanf("%lf",&tmp);
    val[i] = (ll)(tmp * 1e9 + 0.5);
  }
  rep (i, 1, n) {
    while (val[i] % 2 == 0)
      ++ n2[i], val[i] /= 2;
    while (val[i] % 5 == 0)
      ++ n5[i], val[i] /= 5;
  }
  ll ans = 0;
  int mx2 = 0, mx5 = 0;
  rep (i, 1, n) {
    rep (a, 0, mx2) rep (b, 0, mx5) {
      if (a + n2[i] >= 18 && b + n5[i] >= 18)
        ans += num[a][b];
    }
    n2[i] = min(n2[i], 18);
    n5[i] = min(n5[i], 18);
    mx2 = max(n2[i], mx2);
    mx5 = max(n5[i], mx5);
    ++ num[n2[i]][n5[i]];
  }
  cout << ans << endl;
  return 0;
}