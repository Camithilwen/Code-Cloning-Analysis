#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define sz(x) ((int) (x).size())
#define TASK "text"

const int inf = (int) 1.01e9;
const long long infll = (long long) 1.01e18;
const ld eps = 1e-9;
const ld pi = acos((ld) -1);

#ifdef DEBUG
mt19937 mrand(300); 
#else
mt19937 mrand(chrono::steady_clock::now().time_since_epoch().count()); 
#endif

int rnd(int x) {
  return mrand() % x;
}

void precalc() {
}

const int mod = (int) 1e9 + 7;

int mul(int a, int b) {
  return (long long) a * b % mod;
}

void add(int &a, int b) {
  a += b;
  if (a >= mod) {
    a -= mod;
  }
}

const int maxn = (int) 3e5 + 5;
char tmp[maxn];
int n;
string s;

bool read() {
  if (scanf("%s", tmp) < 1) {
    return false;
  }
  s = tmp;
  n = sz(s);
  return true;
}

const int k = 9;
const int go[k][2] = {{1, 2}, {3, 4}, {5, 6}, {1, 1}, {1, 2}, {7, 2}, {8, 8}, {5, 5}, {6, 6}};
const int good = ((1 << 2) | (1 << 8));
int dp[k], ndp[k];

void solve() {
  memset(dp, 0, sizeof(dp));
  dp[0] = 1;
  for (int i = 0; i < n; i++) {
    memset(ndp, 0, sizeof(ndp));
    for (int v = 0; v < k; v++) {
      auto cur = dp[v];
      if (!cur) {
        continue;
      }
      for (int c = 0; c < 2; c++) {
        if (s[i] == (char) ('0' + (c ^ 1))) {
          continue;
        }
        add(ndp[go[v][c]], cur);
      }
    }
    swap(dp, ndp);
  }
  int res = 0;
  for (int v = 0; v < k; v++) {
    if (good & (1 << v)) {
      add(res, dp[v]);
    }
  }
  printf("%d\n", res);
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}
