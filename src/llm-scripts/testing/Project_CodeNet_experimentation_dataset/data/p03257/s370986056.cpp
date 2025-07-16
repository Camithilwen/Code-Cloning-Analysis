#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for (int i = (a); i <= (b); ++ i)
#define rrp(i,a,b) for (int i = (a); i >= (b); -- i)
#define gc() getchar()
#define fir first
#define sec second
typedef pair<int,int> pii;
typedef long double db;
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

const int N = 510, MAX = 10000;
int isp[MAX + 10], pri[MAX], pcnt;
void prework() {
  rep (i, 2, MAX) {
    if (!isp[i]) pri[++pcnt] = i;
    for (int j = 1; pri[j] * i <= MAX; ++ j) {
      isp[pri[j] * i] = 1;
      if (i % pri[j] == 0) break;
    }
  }
}
ll mat[N][N];
int n, arr[2][N];
set<ll> st;
ll lcm(ll x,ll y) {
  return x / __gcd(x, y) * y;
}
int main() {
  prework();
  read(n);
  if (n == 2) {
    puts("4 7");
    puts("23 10");
    return 0;
  }
  int p = 0;
  rep (i, 1, n) arr[0][i] = pri[++ p];
  rrp (i, n, 1) arr[1][i] = pri[++ p];
  int tmp = (n+1) / 2;
  rep (i, 1, n) rep (j, 1, n) if ((i+j) % 2 == 0) {
    int vx = i + j, vy = i - j;
    vx /= 2;
    vy /= 2;
    vy += tmp;
    mat[i][j] = 1ll * arr[0][vx] * arr[1][vy];
  }
  rep (i, 1, n) rep (j, 1, n) if ((i+j)&1) {
    mat[i][j] = 1;
    if (i > 1) mat[i][j] = lcm(mat[i][j], mat[i-1][j]);
    if (i < n) mat[i][j] = lcm(mat[i][j], mat[i+1][j]);
    if (j > 1) mat[i][j] = lcm(mat[i][j], mat[i][j-1]);
    if (j < n) mat[i][j] = lcm(mat[i][j], mat[i][j+1]);
    mat[i][j] ++;
  }
  // (i-j, i+j)
  // rep (i, 1, n) rep (j, 1, n) {
  //   assert(!st.count(mat[i][j]));
  //   assert(mat[i][j] <= (ll)1e15);
  //   st.insert(mat[i][j]);
  // }
  rep (i, 1, n) {
    rep (j, 1, n) printf("%lld ", mat[i][j]);
    puts("");
  }
  return 0;
}
