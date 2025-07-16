#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

mt19937 mrand(random_device{} ()); 

int rnd(int x) {
  return mrand() % x;
}

typedef long double ld;
typedef long long ll;

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define pb push_back
#define mp make_pair
#define sz(x) ((int) (x).size())
#define TASK "text"

const int inf = (int) 1.01e9;
const ld eps = 1e-9;
const ld pi = acos((ld) -1.0);

const int mod = (int) 1e9 + 7;

void add(int &x, int y) {
  if ((x += y) >= mod) {
    x -= mod;
  }
}

int mult(int x, int y) {
  return (long long) x * y % mod;
}

int myPower(int x, int pw) {
  int res = 1;
  for (; pw; pw >>= 1) {
    if (pw & 1) {
      res = mult(res, x);
    }
    x = mult(x, x);
  }
  return res;
}

void precalc() {
}


const int maxn = 102;
char s[maxn][maxn];
int n, m;

int xe, ye;

int read() {
  if (scanf("%d%d", &n, &m) < 2) {
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%s", s[i]);
    for (int j = 0; j < m; ++j) {
      if (s[i][j] == 'E') {
        xe = i, ye = j;
      }
    }
  }
  return 1;
}

int prec[2][maxn][maxn];

inline int get(int type, int x, int l, int r) {
  auto &cur = prec[type][x];
  return cur[r] - cur[l];
}

short dp[maxn][maxn][maxn][maxn];
short res;

inline void update(int x1, int x2, int y1, int y2, short nval) {
  auto &cur = dp[x1][x2][y1][y2];
  if (cur < nval) {
    cur = nval;
    if (res < nval) {
      res = nval;
    }
  }
}

void solve() {
  for (int i = 0; i < n; ++i) {
    prec[0][i][0] = 0;
    for (int j = 0; j < m; ++j) {
      prec[0][i][j + 1] = prec[0][i][j] + (s[i][j] == 'o');
    }
  }

  for (int i = 0; i < m; ++i) {
    prec[1][i][0] = 0;
    for (int j = 0; j < n; ++j) {
      prec[1][i][j + 1] = prec[1][i][j] + (s[j][i] == 'o');
    }
  }
  memset(dp, -1, sizeof(dp));
  dp[0][0][0][0] = 0;
  int xl = xe + 1, xr = n - xe;
  int yl = ye + 1, yr = m - ye;

  res = 0;

  for (int cxl = 0; cxl < xl; ++cxl) {
  for (int cxr = 0; cxr < xr; ++cxr) {
  for (int cyl = 0; cyl < yl; ++cyl) {
  for (int cyr = 0; cyr < yr; ++cyr) {
    auto cur = dp[cxl][cxr][cyl][cyr];
    if (cur < 0) {
      continue;
    }
    int x1 = max(xe - cxl, cxr);
    int x2 = min(xe + cxr, n - 1 - cxl) + 1;

    int y1 = max(ye - cyl, cyr);
    int y2 = min(ye + cyr, m - 1 - cyl) + 1;

    if (cxr + cxl + 1 < xl) {
      update(cxl + 1, cxr, cyl, cyr, cur + get(0, x1 - 1, y1, y2));
    }
    if (cxr + cxl + 1 < xr) {
      update(cxl, cxr + 1, cyl, cyr, cur + get(0, x2, y1, y2));
    }
    if (cyr + cyl + 1 < yl) {
      update(cxl, cxr, cyl + 1, cyr, cur + get(1, y1 - 1, x1, x2));
    }
    if (cyr + cyl + 1 < yr) {
      update(cxl, cxr, cyl, cyr + 1, cur + get(1, y2, x1, x2));
    }
  }
  }
  }
  }
  printf("%d\n", (int) res);
}

int main() {
  precalc();
#ifdef LOCAL
  freopen(TASK ".out", "w", stdout);
  assert(freopen(TASK ".in", "r", stdin));
#endif

  while (1) {
    if (!read()) {
      break;
    }
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}
